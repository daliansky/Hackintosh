#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
sync_to_blog.py — 将 Hackintosh README.md 的机型/硬件章节同步到 Hexo 博客文章

用法:
    python3 Tools/sync_to_blog.py              # 同步 + hexo 构建发布
    python3 Tools/sync_to_blog.py --dry-run    # 只显示差异，不写入
    python3 Tools/sync_to_blog.py --no-deploy  # 只同步文件，不 hexo 构建
    python3 Tools/sync_to_blog.py --blog ~/Blog/source/_posts/xxx.md

同步策略（按标题定位、逐段替换，保留博客 front-matter 等原始内容）:
    1. 从 README.md 按 Markdown 标题切出区块
    2. 在博客文章中定位同名标题，替换「该标题 → 下一个同级或更高级标题」之间内容
    3. 从头文件起直到 ## 目录 之前保持不动
"""

import argparse
import os
import re
import subprocess
import sys
from pathlib import Path

REPO_ROOT = Path(__file__).resolve().parent.parent
README = REPO_ROOT / "README.md"

DEFAULT_BLOG = Path.home() / "Blog/source/_posts/【黑果小兵】Hackintosh黑苹果长期维护机型整理清单.md"

# (README 中起始标题, 结束标题(不含), 说明)
# 注意：相邻区块的边界必须首尾相接，不能重叠，否则后一个区块会被前一个吞掉
SECTIONS = [
    ("<details>\n<summary>更新日志</summary>", None, "更新日志折叠块"),
    ("### NVIDIA 机型（台式机）", "### 台式机其它机型", "NVIDIA 台式机机型"),
    ("## 硬件兼容列表", "### NVIDIA（NullMoth 驱动）", "硬件兼容列表 (Intel/AMD/Core Ultra)"),
    ("### NVIDIA（NullMoth 驱动）", "### 无线网卡（WiFi）支持列表", "NVIDIA NullMoth"),
    ("### 无线网卡（WiFi）支持列表", None, "无线网卡 WiFi"),  # None = 到下一个 ##
]


def read(path: Path) -> str:
    with open(path, "r", encoding="utf-8") as f:
        return f.read()


def write(path: Path, text: str) -> None:
    with open(path, "w", encoding="utf-8") as f:
        f.write(text)


def extract_section(text: str, start_heading: str, end_heading: str | None) -> str | None:
    """从 text 中提取从 start_heading 开始到 end_heading（或下一个同级/更高级标题）的区块。"""
    start = text.find(start_heading)
    if start < 0:
        return None

    if end_heading:
        end = text.find(end_heading, start + len(start_heading))
        if end < 0:
            end = _next_heading(text, start, start_heading)
    elif start_heading.startswith("<"):
        end = text.find("\n## 目录", start)
        if end < 0:
            end = len(text)
    else:
        end = _next_heading(text, start, start_heading)

    if end < 0:
        end = len(text)

    return text[start:end].rstrip() + "\n"


def _next_heading(text: str, offset: int, heading: str) -> int:
    """找到 offset 之后的下一个级别 <= heading 的标题位置。"""
    level = len(heading) - len(heading.lstrip("#"))
    pattern = re.compile(r"^#{1,%d} .+$" % level, re.MULTILINE)
    m = pattern.search(text, offset + len(heading))
    return m.start() if m else -1


def replace_section(blog: str, start_heading: str, end_heading: str | None, new_body: str) -> tuple[str, bool]:
    """在 blog 中替换区块，返回 (新内容, 是否发生改动)。"""
    start = blog.find(start_heading)
    if start < 0:
        return blog, False

    if end_heading:
        end = blog.find(end_heading, start + len(start_heading))
        if end < 0:
            end = _next_heading(blog, start, start_heading)
    elif start_heading.startswith("<"):
        end = blog.find("\n## 目录", start)
        if end < 0:
            end = len(blog)
    else:
        end = _next_heading(blog, start, start_heading)

    if end < 0:
        end = len(blog)

    old = blog[start:end].rstrip() + "\n"
    if old == new_body:
        return blog, False

    return blog[:start] + new_body + "\n" + blog[end:], True


def run_hexo(blog_dir: Path) -> bool:
    print("\n>>> hexo clean && hexo g && hexo d")
    for cmd in (["hexo", "clean"], ["hexo", "g"], ["hexo", "d"]):
        print(f"    $ {' '.join(cmd)}")
        res = subprocess.run(cmd, cwd=str(blog_dir))
        if res.returncode != 0:
            print(f"    ✗ 命令失败: {' '.join(cmd)}", file=sys.stderr)
            return False
    return True


def main() -> int:
    ap = argparse.ArgumentParser(description="同步 README.md 到 Hexo 博客文章")
    ap.add_argument("--blog", type=Path, default=DEFAULT_BLOG, help="博客文章路径")
    ap.add_argument("--dry-run", action="store_true", help="只显示差异不写入")
    ap.add_argument("--no-deploy", action="store_true", help="不执行 hexo 构建发布")
    args = ap.parse_args()

    if not README.exists():
        print(f"✗ 找不到 {README}", file=sys.stderr)
        return 1
    if not args.blog.exists():
        print(f"✗ 找不到博客文章: {args.blog}", file=sys.stderr)
        return 1

    readme = read(README)
    original = read(args.blog)
    blog = original
    changed_sections = []

    for start_heading, end_heading, label in SECTIONS:
        body = extract_section(readme, start_heading, end_heading)
        if body is None:
            print(f"⊘ README 中未找到区块: {label}")
            continue

        blog, changed = replace_section(blog, start_heading, end_heading, body)
        if changed:
            changed_sections.append(label)
            print(f"✓ 已更新: {label}")
        else:
            print(f"= 无变化: {label}")

    if not changed_sections:
        print("\n没有需要同步的改动。")
        return 0

    if args.dry_run:
        print(f"\n[dry-run] 将修改 {args.blog}，共 {len(changed_sections)} 个区块")
        return 0

    write(args.blog, blog)
    print(f"\n✓ 已写入 {args.blog}")

    if args.no_deploy:
        print("（跳过 hexo 发布，使用 --no-deploy）")
        return 0

    if not run_hexo(args.blog.parent.parent.parent):
        return 1

    print("\n✓ 博客同步发布完成")
    return 0


if __name__ == "__main__":
    sys.exit(main())
