## Hackintosh 黑苹果长期维护机型 EFI 及安装教程整理

[![img](https://img.shields.io/github/stars/daliansky/Hackintosh.svg?color=ff69b4&label=%E7%82%B9%E8%B5%9E&logoColor=ff69b4&style=social)](https://github.com/daliansky/Hackintosh) [![img](https://img.shields.io/github/followers/daliansky.svg?label=%E7%B2%89%E4%B8%9D&logoColor=success&style=social)](https://github.com/daliansky/Hackintosh) ![img](https://img.shields.io/github/contributors/daliansky/Hackintosh.svg?color=red&label=%E8%B4%A1%E7%8C%AE%E4%BA%BA%E6%95%B0) [![img](https://img.shields.io/github/last-commit/daliansky/Hackintosh.svg?color=orange&label=%E6%9C%80%E8%BF%91%E6%8F%90%E4%BA%A4)](https://github.com/daliansky/Hackintosh)

## English Version: [Hackintosh long-term maintenance model EFI and installation tutorial](README_en.md)

	今天采用关键词OPENCORE搜索的方式，采用最近更新排序，搜索了前10页的维护信息，再筛出未进入清单，但维护得不错得REPO,更新时间只是最近2天得，肯定又很多漏的，一一核对很费精力，readme文档内内容太多，整理了一下思路,列出列出了以下几个点，希望大家一起看看如何整理比较方便。
  
  
	  (1)拆分文档：拆分成笔记本和台式机两份文件,readme文档内将厂商链接过去，这样再更新文件的时候会轻松一些。
  
	  (2).自动化脚本：目前更新的方式还是靠人去对，筛出新增的然后再增加进去，比较费时间。从我自己找的方式看，是可以通过脚本实现的，这个可以节省很多时间和精力。
			   范围：github.com，
			   更新时间：最近3个月，
			   限制条件：commit的提交次数大于20次的。（另外的一点将已经在清单里面的去掉,不去也行，直接更换清单）
			   其他：排序和合并，排序后需要人工将命名不规范的补齐。
			   
	  (3).搜索引擎：当然，能够做到一个搜索引擎，专门针对黑苹果优化的，这或许就是这份清单的终点，也就失去了一些意义，变为纯粹的白嫖工具了。
大家有更好的思路也可以提出来，一起完成，虽然我不确定现在继续做这些的意义还有多少。
------
- 黑苹果论坛：

  - **国内** [远景论坛](http://bbs.pcbeta.com)、[威锋论坛](http://bbs.feng.com)
  - **国外** [insanelymac 论坛](https://www.insanelymac.com/forum/)、[tonymacx86 论坛](https://www.tonymacx86.com/)、[德国黑苹果论坛](https://www.hackintosh-forum.de/)、[俄罗斯黑苹果论坛](https://www.applelife.ru)、[法国黑苹果论坛](https://www.hackintosh-montreal.com)、 [osxlatitude 论坛](https://osxlatitude.com/forums/)

- 一些黑苹果常用的软件或者驱动开发者的主页，希望大家能及时更新驱动和软件，驱动需要自己去对应驱动开发者的主页去更新。

- _[RehabMan](https://bitbucket.org/RehabMan/)_ 维护了很多黑苹果驱动和相关补丁
- _[Vit9696](https://github.com/acidanthera)_ lilu 和相关插件、applealc 的主要开发或维护者
- _[Clover 更新地址](https://sourceforge.net/projects/cloverefiboot/)_ Clover 团队更新 clover 的主要发布渠道
- _[常用软件和驱动清单](./LinkList.md)_ 整理了常用软件和驱动的主要发布地址，持续修改……

## 同步更新：[黑果小兵的部落阁](https://blog.daliansky.net/Hackintosh-long-term-maintenance-model-checklist.html)

## 机型讨论：[远景 pcbeta.com](http://bbs.pcbeta.com/viewthread-1795904-1-1.html)

<details>
<summary>更新日志</summary>

更新日期：

- `2021年4月2日`
  - 新增机型：
	- Asus VivoBook FL8000u
	- Dell Inspiron 3568
	- Dell Latitude E7370
	- Dell Vostro 3468
	- Dell Vostro 5581
	- HP Pavilion 15 au624tx
	- HP Pavilion 15G BR011TX
	- Lenovo Ideapad S540 14IWL
	- Gigabyte H410M S2H

完整的更新日志：[更新日志](./Changelog.md)

</details>

## [笔记本部分](https://github.com/daliansky/Hackintosh/blob/alpha/NeteBook%26Laptop)

##	[台式机部分](https://github.com/daliansky/Hackintosh/blob/alpha/Desktop)




## 参考及引用：

- https://deviwiki.com/wiki/Dell
- https://deviwiki.com/wiki/Dell_Wireless_1820A_(DW1820A)
- [Hervé](<[https://osxlatitude.com/profile/4953-herv%C3%A9/](https://osxlatitude.com/profile/4953-hervé/)>) 更新的 Broadcom 4350:https://osxlatitude.com/forums/topic/12169-bcm4350-cards-registry-of-cardslaptops-interop/
- [Hervé](<[https://osxlatitude.com/profile/4953-herv%C3%A9/](https://osxlatitude.com/profile/4953-hervé/)>) 更新的 DW1820A 支持机型列表:https://osxlatitude.com/forums/topic/11322-broadcom-bcm4350-cards-under-high-sierramojave/
- [nickhx](https://osxlatitude.com/profile/129953-nickhx/) 提供的蓝牙驱动：https://osxlatitude.com/forums/topic/11540-dw1820a-for-7490-help/?do=findComment&comment=92833
- [xjn819](https://blog.xjn819.com/)： [使用 OpenCore 引导黑苹果](https://blog.xjn819.com/?p=543) [300 系列主板正确使用 AptioMemoryFix.efi 的姿势(重写版）](https://blog.xjn819.com/?p=317)
- [insanelymac.com](https://www.insanelymac.com/)
- [tonymacx86.com](https://www.tonymacx86.com/)
- [远景论坛](http://bbs.pcbeta.com)
- [applelife.ru](https://applelife.ru/)
- [olarila.com](https://www.olarila.com/)

## QQ 群列表：

553283949 [黑果小兵黑苹果技术群 6](https://qm.qq.com/cgi-bin/qm/qr?k=kr_hZc5pKK4TCDRaFPwRlfAiB4528InP&jump_from=webapi) 2000 人收费群 新开群

630724380 [黑果小兵黑苹果技术群 7](https://qm.qq.com/cgi-bin/qm/qr?k=JyGkfKK7U3Xq3TDtpqKOTq_gW7SBg4Uh&jump_from=webapi) 2000 人收费群，新开群

713810838 [黑果小兵黑苹果技术群 8](https://qm.qq.com/cgi-bin/qm/qr?k=e8E-1Ge2lCoBSTlj8Y4zMxX7l7-V63Iv&jump_from=webapi) 2000 人收费群，新开群

688324116 [一起黑苹果](https://qm.qq.com/cgi-bin/qm/qr?k=Fp4HZ5e8A61oCu0GMS5YUqP6COc43-AO&jump_from=webapi) 2000 人收费群，请加 6 群

331686786 [一起吃苹果](https://qm.qq.com/cgi-bin/qm/qr?k=No8zvDfvDicT-GfSApw1RMBI-3MQ7zM3&jump_from=webapi) 2000 人收费群，请加 6 群

257995340 [一起啃苹果](https://qm.qq.com/cgi-bin/qm/qr?k=acztqL9efoqAOoptc_3moZ9b3Sgczu9_&jump_from=webapi) 2000 人群 远景报备群

875482673 [黑果小兵黑苹果技术群](https://qm.qq.com/cgi-bin/qm/qr?k=aZNyoRum_er2mruqmnbX_93ncHNgsyak&jump_from=webapi) 2000 人收费群 已满员，请加 6 群

1058822256 [黑果小兵黑苹果技术群 2](https://qm.qq.com/cgi-bin/qm/qr?k=1sIT0BDaejgr9t1Hlw16cMnw_Z96zleV&jump_from=webapi) 2000 人收费群 已满员，请加 6 群

819662911 [黑果小兵黑苹果技术群 3](https://qm.qq.com/cgi-bin/qm/qr?k=aJx9xO7vAmyslCuOdK0bRMmDLpvOCeRw&jump_from=webapi) 2000 人收费群，请加 6 群

954098809 [黑果小兵黑苹果技术群 4](https://qm.qq.com/cgi-bin/qm/qr?k=iu042k0X5snr--dzAxOzcsvD9Zft9yx7&jump_from=webapi) 2000 人收费群，请加 6 群

1161377948 [黑果小兵黑苹果技术群 5](https://qm.qq.com/cgi-bin/qm/qr?k=kBV9vCnz-NqtXXJiwnUhaLyJN1D7G0n6&jump_from=webapi) 2000 人收费群，请加 6 群

701278330 [黑苹果无线网卡交流群](https://qm.qq.com/cgi-bin/qm/qr?k=x57TlUmxz88oXGDWjMOOsWokYi8klE11&jump_from=webapi) 1000 人群 DW1820A 技术支持群

891434070 [Catalina 黑苹果交流群](https://qm.qq.com/cgi-bin/qm/qr?k=TUAxSUUtw_T1N62V0kF1sWvMcDr_eoxc&jump_from=webapi) 2000 人群 远景报备群

939122730 [Catalina 黑苹果交流 II 群](https://qm.qq.com/cgi-bin/qm/qr?k=g_rpf7m0LJllE6WHY9c0gVvCTBm1MtuN&jump_from=webapi) 2000 人群

891677227 [黑果小兵高级群](https://qm.qq.com/cgi-bin/qm/qr?k=xsuIOzF7RXYaRTTbJ5o_UjzohRDUx5UY&jump_from=webapi) 2000 人群

943307869 [黑果小兵高级群 II](https://qm.qq.com/cgi-bin/qm/qr?k=aoSvqrbysdjPo0Wa_XvvPuMG9NMEtOie&jump_from=webapi) 2000 人群

538643249 [OpenCore 技术交流群](https://qm.qq.com/cgi-bin/qm/qr?k=si7f9Mfzs82wHGvKLVhBLmW87YA31y92&jump_from=webapi) 2000 人群 大神众多非 OC 适配者慎入

942112153 [天逸 510s Mini 黑苹果交流群](https://qm.qq.com/cgi-bin/qm/qr?k=N5cjw5ksrnmk-RMQ4fPCOo5D_Dxiu47B&jump_from=webapi) 1000 人群 非专用机型请勿加入

673294583 [小新 Pro 黑苹果技术群](https://qm.qq.com/cgi-bin/qm/qr?k=GgcMJM5-98yB-fc6zyGcTI3OuesrSBRk&jump_from=webapi) 2000 人群 非专用机型请勿加入

946132482 [小新 Pro 黑苹果](https://qm.qq.com/cgi-bin/qm/qr?k=r-m99xC-BPIRdVkEjU6duvqXMJ-1FOwA&jump_from=webapi) 500 人群 非专用机型请勿加入

943181023 [联想小新 Air 黑苹果交流群](https://qm.qq.com/cgi-bin/qm/qr?k=OGO_GSX9ZhtbQ_HNns57Vdxm5pR1wH6V&jump_from=webapi) 500 人群 非专用机型请勿加入

247451054 [小米 PRO 黑苹果高级群](https://qm.qq.com/cgi-bin/qm/qr?k=mnawqS-p0Djpx-B1sgjJPtMfUtVpn-2-&jump_from=webapi) 2000 人群，限小米机型

## Telegram 群：

黑果小兵的部落阁 [http://t.me/daliansky](https://t.me/daliansky)
黑果小兵的部落阁 #安装问题讨论 [https://t.me/macos_installer](https://t.me/macos_installer)

## 微信扫一扫，订阅/直达【黑果小兵的部落阁】

![WeChat](https://blog.daliansky.net/uploads/WeChatandShop.png)

## 关于打赏

如果您认可我的工作，请通过打赏支持我后续的更新

| paypal                                                                                              | 微信                                                       | 支付宝                                               |
| --------------------------------------------------------------------------------------------------- | ---------------------------------------------------------- | ---------------------------------------------------- |
| [![paypal_daliansky](http://7.daliansky.net/paypal_daliansky.png)](https://www.paypal.me/daliansky) | ![wechatpay_160](http://7.daliansky.net/wechatpay_160.jpg) | ![alipay_160](http://7.daliansky.net/alipay_160.jpg) |

[![img](https://img.shields.io/github/stars/daliansky/Hackintosh.svg?color=ff69b4&label=%E7%82%B9%E8%B5%9E&logoColor=ff69b4&style=social)](https://github.com/daliansky/Hackintosh) [![img](https://img.shields.io/github/followers/daliansky.svg?label=%E7%B2%89%E4%B8%9D&logoColor=success&style=social)](https://github.com/daliansky/Hackintosh) ![img](https://img.shields.io/github/contributors/daliansky/Hackintosh.svg?color=red&label=%E8%B4%A1%E7%8C%AE%E4%BA%BA%E6%95%B0) [![img](https://img.shields.io/github/last-commit/daliansky/Hackintosh.svg?color=orange&label=%E6%9C%80%E8%BF%91%E6%8F%90%E4%BA%A4)](https://github.com/daliansky/Hackintosh)
