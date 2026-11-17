#!/bin/sh
# install.sh — 安装 Git 钩子到当前仓库
#
# 用法:
#   sh Tools/git-hooks/install.sh          # 安装 post-commit（提交后自动同步博客）
#   sh Tools/git-hooks/install.sh --remove # 卸载

REPO_ROOT=$(git rev-parse --show-toplevel)
HOOK_DIR="$REPO_ROOT/.git/hooks"
SRC_DIR="$REPO_ROOT/Tools/git-hooks"

if [ "$1" = "--remove" ]; then
    rm -f "$HOOK_DIR/post-commit"
    echo "已移除 post-commit 钩子"
    exit 0
fi

mkdir -p "$HOOK_DIR"
cp "$SRC_DIR/post-commit" "$HOOK_DIR/post-commit"
chmod +x "$HOOK_DIR/post-commit"

echo "✓ 已安装 post-commit 钩子 → $HOOK_DIR/post-commit"
echo ""
echo "行为: 每次提交若包含 README.md 变更，自动执行"
echo "      Tools/sync_to_blog.py 同步并发布到博客"
echo ""
echo "跳过方式:"
echo "  临时跳过:   SYNC_BLOG=0 git commit -m '...'"
echo "  只同步不发: SYNC_BLOG_DEPLOY=0 git commit -m '...'"
echo "  卸载钩子:   sh Tools/git-hooks/install.sh --remove"
