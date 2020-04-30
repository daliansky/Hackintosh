# Hackintosh黑苹果长期维护机型EFI及安装教程整理

[![img](https://img.shields.io/github/stars/daliansky/Hackintosh.svg?color=ff69b4&label=%E7%82%B9%E8%B5%9E&logoColor=ff69b4&style=social)](https://github.com/daliansky/Hackintosh) [![img](https://img.shields.io/github/followers/daliansky.svg?label=%E7%B2%89%E4%B8%9D&logoColor=success&style=social)](https://github.com/daliansky/Hackintosh) ![img](https://img.shields.io/github/contributors/daliansky/Hackintosh.svg?color=red&label=%E8%B4%A1%E7%8C%AE%E4%BA%BA%E6%95%B0) [![img](https://img.shields.io/github/last-commit/daliansky/Hackintosh.svg?color=orange&label=%E6%9C%80%E8%BF%91%E6%8F%90%E4%BA%A4)](https://github.com/daliansky/Hackintosh) [![img](https://img.shields.io/badge/link-996.icu-red.svg)](https://996.icu/)

## English Version: [Hackintosh long-term maintenance model EFI and installation tutorial](README_en.md)

## 黑苹果长期维护机型整理 by @[我意](https://github.com/y010204025)

> 整理这份清单的目的：在于给想体验黑苹果的人一个方向，也想减少大家重复造轮子，节约大家的时间。
> 所有文件均归属于原作者，本清单只列出链接。如果您不希望你的链接被这份清单收录，请发送邮件到 [y010204025@126.com](mailto:y010204025@126.com),我将移除链接
> 清单收录了 4 个月以内的有人长期维护并更新过 EFI 的机型链接，如果有新的链接希望收录到这份清单，请发送邮件到 [y010204025@126.com](mailto:y010204025@126.com)
> 致谢：感谢一直为黑苹果进行开发的各位开发者和愿意共享出 EFI 文件的开发者，谢谢！
> 最近有部分github作者删除了repo,有失效的请大家反馈，我会及时跟进删除相关链接。

- 建议大家使用[yandex搜索引擎](https://yandex.ru)、[github](https://github.com)先搜索下有没有自己的机型，型号一样，机型配置有差异可以忽略，使用你的机器型号+clover、型号+EFI、型号+mac、型号+Hackintosh等进行搜索。例如我最近更新了 elitebook840g3、840g4等几个机型的 EFI，就可以使用840g3+clover 840g3+EFI 等关键词进行搜索。

- 黑苹果论坛：

  - **国内** [远景论坛](http://bbs.pcbeta.com)、[威锋论坛](http://bbs.feng.com)
  - **国外** [insanelymac 论坛](https://www.insanelymac.com/forum/)、[tonymacx86论坛](https://www.tonymacx86.com/)、[德国黑苹果论坛](https://www.hackintosh-forum.de/)、[俄罗斯黑苹果论坛](https://www.applelife.ru)、[法国黑苹果论坛](https://www.hackintosh-montreal.com)、 [osxlatitude论坛](https://osxlatitude.com/forums/)

- 一些黑苹果常用的软件或者驱动开发者的主页，希望大家能及时更新驱动和软件，驱动需要自己去对应驱动开发者的主页去更新。
  
- *[RehabMan](https://bitbucket.org/RehabMan/)* 维护了很多黑苹果驱动和相关补丁
- *[Vit9696](https://github.com/acidanthera)* lilu和相关插件、applealc的主要开发或维护者
- *[Clover更新地址](https://sourceforge.net/projects/cloverefiboot/)* Clover团队更新 clover的主要发布渠道
- *[常用软件和驱动清单](./LinkList.md)* 整理了常用软件和驱动的主要发佈地址，持续修改……

 *关于黑苹果，希望大家能摆正心态，容忍小问题的存在，某些功能无法实现或者是体验不好「触摸板、指点杆、触摸屏、雷电端口等等」，系统运行不稳定，容易卡机或者死机或者是开机不认引导、升级系统失败等都属于正常现象。 **每次升级前请先从各种驱动了解本次升级有没有大的改动，在升级前首先升级 Clover 和相关的 kext 驱动，需要添加补丁或者是更新补丁的请做好相关工作，不要等著出了问题再去寻找解决方案。** 在自己遇到问题的时候，请先通过网络寻找解决办法，无法解决再询问别人，请别人帮忙解决问题的时候，首先端正自己的态度，把问题描述清楚，能提供 log 日志或者是相关文件的先提供文件，提供不了文件的拍照拍清楚。*

**解决问题，需要努力的是自己，不是让别人帮你努力；帮你解答是情分，不是义务**

**为了感谢这份清单内机型的维护人员的长期的付出，希望大家在下载 EFI 的时候点一下 'star',顺便可以点一下 'watch',这样你将会收到你关注机型 efi 的更新提醒，这是对维护人员的一种肯定和鼓励。**

**感谢各位维护人员的辛勤付出，希望在更新时能够提供必要的更新内容说明，在引用别人的补丁、或者是某些特殊版本的驱动是给出驱动的来源链接，必要时还请加入一些 credit，黑苹果更多的是大家群策群力、开放共享努力的结果。**

*希望整个黑苹果领域能够进入良性循环状态，不用再重复造很多轮子，也希望那些使用别人成果收费的人，必要时还请留出文件来源和相关致谢。*

### 同步更新：[黑果小兵的部落阁](<https://blog.daliansky.net/Hackintosh-long-term-maintenance-model-checklist.html>)

### 机型讨论：[远景pcbeta.com](<http://bbs.pcbeta.com/viewthread-1795904-1-1.html>)

### 更新日志：[Changelog](./Changelog.md)



### 笔记本部分机型

#### Acer 宏碁

| 机型名称                | 发布地址                                                     | 教程地址                                                     | 备注                |
| ----------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------- |
| Acer Aspire 3 A315-51   | [链接](https://github.com/ZeroInfinityXDA/Acer-A315-51-Hackintosh) |                                                              |                     |
| Acer Aspire A515-51G    | [链接](https://github.com/h-okon/Acer-Aspire-A515-Hackintosh) |                                                              |                     |
| Acer Aspire A515-51G    | [链接](https://github.com/Siddhesh1197/Acer-A515-51G-Hackintosh) | [链接](https://github.com/Siddhesh1197/Acer-A515-51G-Hackintosh/blob/master/README.md) |                     |
| Acer A515-51G-58VH      | [链接](https://github.com/Rodrigmatrix/Acer-A515-51G-58VH)   |                                                              |                     |
| Acer Aspire E1-471G     | [链接](https://github.com/matthew728960/Clover-ACER-E1-471G) | [链接](https://github.com/matthew728960/Clover-ACER-E1-471G/blob/master/README.md) | ACER Aspire E1-471g |
| Acer Aspire E5-471G     | [链接](https://github.com/THLIVSQAZ/ACER-E5-471G-OpenCore) [链接](https://github.com/THLIVSQAZ/ACER-E5-471G-Clover) |                                                              |                     |
| Acer Aspire E5 475G     | [链接](https://github.com/hilmanshini/Acer-Aspire-E5-475G-Clover-Hackintosh) |                                                              |                     |
| Acer Aspire E5-476G     | [链接](https://github.com/DijaminGila/Hackintosh-Mojave-Acer-E5-476G) [链接](https://github.com/budhilaw/Acer-E5-476G-Hackintosh) |                                                              | i3-6006U            |
| Acer Aspire E5-571-5552 | [链接](https://github.com/GaryDoooo/acer_e51_osx)            |                                                              |                     |
| Acer Aspire E1-571G     | [链接](https://github.com/DiogoSilva48/Acer-E1-571G-Hackintosh) |                                                              |                     |
| Acer Aspire E1-572G     | [链接](https://github.com/TonyStark10006/Acer_E1-572G_Hackintosh_EFI) |                                                              |                     |
| Acer ES1-572-37pz       | [链接](https://github.com/joodrew/hackintosh-acer-es1-572-37pz) |                                                              |                     |
| Acer F5-573G            | [链接](https://github.com/johnnywolinger/ACER-F5-573G-Hackintosh) |                                                              |                     |
| Acer F5-573G-55PJ       | [链接](https://github.com/zoothz/Hackintosh-acer-f5-573g-55pj) |                                                              |                     |
| Acer F5-573g-75A3       | [链接](https://github.com/vinicioslc/HACKINTOSH-ACER-F5-573G-75A3) |                                                              |                     |
| Acer nitro 5 an517-51 | [链接](https://github.com/SaeedHaidar/Nitro-5-an517-51-Hackintosh) | | |
| Acer Swift 3            | [链接](https://github.com/FallenChromium/Acer-Swift3-2018-hackintosh) |                                                              | SF315-51-518S       |
| Acer Swift 3 52G | [链接](https://github.com/geekcjj/Clover-Acer-Swift3-SF315-52G) | | Acer-Swift3-SF315-52G |
| Acer Swift 3 SF314-55G | [链接](https://github.com/cjtim/SF314-55G-hackintosh) [链接](https://github.com/cjtim/SF314-55G-hackintosh) | | Acer Swift 3 2019 SF314-55G |
| Acer V3-471G            | [链接](https://github.com/oneveb/Acer-V3-471G)               |                                                              |                     |
| Acer-V3-572G-51MR       | [链接](https://github.com/AnoldmanLiSir/Acer-V3-572G-51MR)   | [链接](https://github.com/AnoldmanLiSir/Acer-V3-572G-51MR/blob/master/README.md) |                     |
| Acer V5-572             | [链接](https://github.com/7ack/Acer-V5-572-Hackintosh)       | [链接](https://github.com/7ack/Acer-V5-572-Hackintosh/blob/master/readme.md) |                     |
| Acer VN7-793g           | [链接](https://github.com/cedric-bour/Acer-VN7-793g-Hackintosh) |                                                              |                     |
| Acer-K50-10-525V       | [链接](https://github.com/mingslife/Acer-K50-10-525V-Hackintosh) |                                                              |                     |
|宏碁暗影骑士3          |[链接](https://github.com/Chakid/Acer-VX15-Hackintosh)  |    |    |
|ACER-ASPIRE-C24-865          |[链接](https://github.com/Sevendaye/ACER-ASPIRE-C24-865-Clover)  |    |    |
|ACER Travelmate P248 |[链接](https://github.com/jamesciq/Acer-Travelmate-P248-hackintosh-EFI) | | |
|Acer P258-MG          |[链接](https://github.com/lgs3137/ACER_P258_MG-macOS)  |    |    |

#### Asus 华硕

| 机型名称                          | 发布地址                                                     | 教程地址                                                     | 备注                                                       |
| --------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ---------------------------------------------------------- |
| Asus A43SJ                        | [链接](https://github.com/badruzeus/Hackintosh-Asus-A43SJ)   | [链接](https://github.com/badruzeus/Hackintosh-Asus-A43SJ/blob/master/README.md) | Asus A43SJ                                                 |
| Asus A411UF                       | [链接](https://github.com/faizauthar12/Asus_A411UF_Hackintosh) |                                                              |                                                            |
| Asus A442UF                       | [链接](https://github.com/ryansat/Hackintosh-A442UF)         |                                                              |                                                            |
| Asus A455LA                       | [链接](https://github.com/brilliantedgar/Hackintosh-A455LA-Intel-Core-i3-5005U) | [链接](https://github.com/brilliantedgar/Hackintosh-A455LA-Intel-Core-i3-5005U/blob/master/README.md) | Asus S455LA                                                |
| Asus A455LF-WX039D Series         | [链接](https://github.com/asepms92/Hackintosh-Asus-A455LF-Notebook) |                                                              |                                                            |
| Asus A456UF(X456UF)               | [链接](https://github.com/alfinauzikri/Asus-A456UF-Hackintosh) |                                                              |                                                            |
| Asus A550JK4200                   | [链接](https://github.com/hehuapei/ASUS-a550jk-4200---macOS) |                                                              |                                                            |
| Asus F455LD                       | [链接](https://github.com/athlonreg/Asus-F455LD-i5-4210u)    |                                                              |                                                            |
| Asus FX504GE-ES72                 | [链接](https://github.com/MegaStood/Hackintosh-FX504GE-ES72) |                                                              |                                                            |
| Asus FX505GD                      | [链接](https://github.com/kreactnative/hackintosh-mojave-fx505gd) |                                                              | ASUS TUF GAMING FX505GD-BQ071T                             |
| Asus F556U (X556UQK)              | [链接](https://github.com/systemfaliure/Asus-X556UQK-hackintosh#Asus-f556u-x556uqk---high-sierra-hackintosh) | [链接](https://github.com/systemfaliure/Asus-X556UQK-hackintosh/blob/master/README.md) | Asus F556U (X556UQK)                                       |
| Asus FX50J                        | [链接](https://github.com/Xc2333/Hackintosh-Asus-FX50J)      |                                                              |                                                            |
| Asus FX50V                        | [链接](https://github.com/Cyberhan123/Hackintosh-ASUS--FX50V) |                                                              |                                                            |
| Asus FX533VD                      | [链接](https://github.com/kue-kid/Asus-FX533VD-HACKINTOSH)   |                                                              |                                                            |
| Asus GL503GE                      | [链接](https://github.com/Bimoaryo5/ASUS-GL503GE-Hackintosh-master) |                                                              |                                                            |
| Asus GL551JW                      | [链接](https://github.com/zacharyrs/GL551JW-Hackintosh)      |                                                              |                                                            |
| Asus GL552VW | [链接](https://github.com/originman521/Hackintosh-ASUS-FXPRO-GL552VW) | | 飞行堡垒2016 FXPRO |
| Asus G60VW                        | [链接](https://github.com/PtNan/G60VW-Hackintosh)            |                                                              |                                                            |
| Asus K501LB                       | [链接](https://github.com/ApolloRisky/EFI_Clover-Asus-K501LB-Mojave) |                                                              |                                                            |
| Asus K55VD                        | [链接](https://github.com/southernvevo/Asus-K55VD-HACKINTOSH) | [链接](https://github.com/southernvevo/Asus-K55VD-HACKINTOSH/blob/master/README.md) | Asus K55VD                                                 |
| Asus K555LD                       | [链接](https://github.com/kongbg/asus-k555ld-4210U) | [链接](https://github.com/kongbg/asus-k555ld-4210U/blob/master/README.md) | Asus K555LD                                                 |
| Asus Laptop N56VZ                 | [链接](https://github.com/signxer/N56VZ-Hackintosh)          |                                                              |                                                            |
| Asus P8P67 PRO                    | [链接](https://github.com/rafaelmaeuer/Asus-P8P67Pro-Hackintosh) | [链接](https://github.com/rafaelmaeuer/Asus-P8P67Pro-Hackintosh/blob/master/readme.md) |                                                            |
| Asus R414U                        | [链接](https://github.com/srole-xiaoxian/ASUS-R414U-Clover)  |[链接](https://github.com/LHB6540/Asus-R414-Hackintosh-10.15.4)| 10.13&10.15 |
| Asus ROG GL552JX                  | [链接](https://github.com/javanesse/Asus-ROG-GL552JX-High-Sierra-10.13-Hackintosh) | [链接](https://github.com/javanesse/Asus-ROG-GL552JX-High-Sierra-10.13-Hackintosh/blob/master/README.md) | Asus ROG GL552JX                                           |
| Asus ROG GL552VX                  | [链接](https://github.com/xuanquydsr/Gl552VX-Mojave)         |                                                              |                                                            |
| Asus ROG GL553VD                  | [链接](https://github.com/MohammadtaghiFarkhondekar/macOS-Mojave-For-Asus-ROG-GL553VD) |                                                              |                                                            |
| Asus ROG Zephyrus M GM501GS       | [链接](https://github.com/kylergib/Asus-Zephyrus-M-gm501gs-Mojave) |                                                              |                                                            |
| Asus ROG Zephyrus S GX531GS       | [链接](https://github.com/williambj1/Hackintosh-EFI-Asus-Zephyrus-S-GX531) |                                                              | 华硕玩家国度冰刃 3                                         |
| ASUS S4000VA                      | [链接](https://github.com/stonexing/Asus-S4000VA8550-Hackintosh) |                                                              | 华硕灵耀 i7-8550U                                          |
| Asus S4100V                       | [链接](https://github.com/loong1992/Asus_S4100VN8250U_Hackintosh) |                                                              |                                                            |
| Asus S510UQ | [链接](https://github.com/KINGKONG2808/Hackintosh_ASUSS510UQ) | | |
| Asus S5300FN | [链接](https://github.com/Jie2GG/Hackintosh-ASUS-S5300FN) | | 华硕灵耀2代 |
| Asus S530UN                       | [链接](https://github.com/tunglamvghy/AsusS530UN-hackintosh) |                                                              |                                                            |
| Asus TUF Gaming FX504             | [链接](https://github.com/PoomSmart/Asus-FX504GE-Hackintosh) [链接](https://github.com/angeljavan/AUSU-FX80GE-FX504Ge-efi) | [链接](https://github.com/PoomSmart/Asus-FX504GE-Hackintosh/blob/master/README.md) | 华硕 FX80GE FX504GE                                        |
| Asus UX501JW                      | [链接](https://github.com/firefly917/Hackintosh_Asus-UX501JW_Mojave) |                                                              |                                                            |
| Asus VivoBook 15 X510UQ / S5100UQ | [链接](https://github.com/wishayne/hackintosh-Asus-S5100UQ-X510UQ) |                                                              |                                                            |
| Asus X441U                        | [链接](https://github.com/jundanaalbasyir/Hackintosh-Asus-X441U) |                                                              |                                                            |
| Asus X441UB                       | [链接](https://github.com/alfinauzikri/Asus-X441UB-Hackintosh) |                                                              |                                                            |
| Asus X441UV                       | [链接](https://github.com/MinorityCode/asus-x441uv-hackintosh-files) |                                                              |                                                            |
| Asus VivoBook FL8000UQ         | [链接](https://github.com/KKKIIINNN/ASUS-FL8000UQ-Hackintosh) |                                                              |           华硕顽石五代FL8000UQ i7-8550U GeForce 940MX        |
| Asus VivoBook Max X441UVK         | [链接](https://alfinauzikri.github.io/Asus-Vivobook-Max-X441UVK-Hackintosh/) |                                                              |                                                            |
| Asus VivoBook S15 S510UA          | [链接](https://github.com/tctien342/Asus-Vivobook-S510UA-High-Sierra-10.13-Hackintosh) | [链接](https://github.com/tctien342/Asus-Vivobook-S510UA-High-Sierra-10.13-Hackintosh/blob/master/README.md) | Vivobook S510UA                                            |
| Asus Vivobook S530UA BQ100T       | [链接](https://github.com/superzeldalink/Asus-Vivobook-S530-hackintosh) |                                                              |                                                            |
| Asus VivoBook X510UQR             | [链接](https://github.com/nguyentrucxinh/Asus-VivoBook-X510UQR-Hackintosh) | [链接](https://github.com/nguyentrucxinh/Asus-VivoBook-X510UQR-Hackintosh/blob/master/README.md) |                                                            |
| Asus VivoBook Y5000U (X507UBR) | [链接](https://github.com/lgs3137/ASUS_Y5000U_X507UBR-macOS) |  | |
| Asus W419LD | [链接](https://github.com/Yasin27878/Hackintosh-ASUS-W419LD) |  | |
| Asus X45C | [链接](https://github.com/ipang-dwi/efi-high-sierra) |  | |
| Asus X450JB                       | [链接](https://github.com/xiaoMGitHub/Asus_X450JB_Hackintosh) |                                                              |                                                            |
| Asus X455LJ | [链接](https://github.com/umarhadi/asus-x455lj-mojave) | | |
| Asus X542UN | [链接](https://github.com/yCatDev/asus_x542un-hackintosh) | | |
| Asus X550JX                       | [链接](https://github.com/gaoliang/Asus-X550JX-Hackintosh)   |                                                              |                                                            |
| Asus X555LB                       | [链接](https://github.com/emre1393/Asus-x555lb-mojave-efi)   |                                                              |                                                            |
| Asus X550VX | [链接](https://github.com/lramadhan/hackintosh-asus-x550vx) | | |
| Asus X556UQ | [链接](https://github.com/IlhamSevensky/ASUS-X556UQ-HACKINTOSH) | | A556U |
| Asus X556UV                       | [链接](https://github.com/Amview/ASUS-X556UV-Hackintosh)   |                                                              |                                                            |
| Asus X75VC-TY056D                 | [链接](https://github.com/Jesterjke/ASUS-X75VC-Hackintosh)   |                                                              |                                                            |
| Asus X751LJ | [链接](https://github.com/leandro1988n/ASUS-X751LJ-Hackintosh) | | |
| Asus ZenBook 系列                 | [链接](https://github.com/hieplpvip/Asus-ZENBOOK-HACKINTOSH) | [链接](https://www.tonymacx86.com/threads/guide-Asus-zenbook-using-clover-uefi-hotpatch.257448/) | 支持型号: UX310 - UX330 - UX330<br />UX410 - UX430 - UX430 |
| Asus ZenBook Flip UX360UAK        | [链接](https://github.com/Frizz925/UX360UAK-Hackintosh)      | [链接](https://github.com/Frizz925/UX360UAK-Hackintosh/blob/master/README.md) |                                                            |
| Asus ZenBook UX32VD               | [链接](https://github.com/rafaelmaeuer/Asus-UX32VD-Hackintosh) | [链接](https://github.com/rafaelmaeuer/Asus-UX32VD-Hackintosh/blob/master/readme.md) | Asus UX32VD                                                |
| Asus ZenBook UX330UAK             | [链接](https://github.com/Rybo713/UX330UA-macOS)             | [链接](https://github.com/Rybo713/UX330UA-macOS/blob/master/README.md) | Asus UX330UAK (Kabylake）                                  |
| Asus Zenbook UX450FDX | [链接](https://github.com/xvAcid/Hackintosh_Zenbook_UX450FDX) |  |  |
| Asus Zenbook 3 UX490 | [链接](https://github.com/VillenaDeveloper/asus-ux490-hackintosh) |  |  |
| Asus ux305fa | [链接](https://github.com/nganhquoc95/clover-ux305fa) |  |  |
| 华硕zx50jx4200                    | [链接](https://github.com/sxz799/zx50jx4200_hackintosh)      |                                                              |                                                            |
| 华硕A407UB                         | [链接](https://github.com/xinguisoft/Hackintosh-EFI-Asus-A407UB/)   |      |     |
| 玩家国度枪神3                       | [链接](https://github.com/DongLinghe/ROG-SCAR-III-Hackintosh-EFI)   |      |这个应该是华硕的吧     |

#### DELL 戴尔

| 机型名称                                   | 发布地址                                                     | 教程地址                                                     | 备注                                                  |
| ------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ----------------------------------------------------- |
| Alienware 17 R4 i7-7700HQ                  | [链接](https://github.com/RockJesus/Alienware-17-R4-I7-7700HQ-MacOS-High-Sierra) | [链接](https://github.com/RockJesus/Alienware-17-R4-I7-7700HQ-MacOS-High-Sierra/blob/master/README.md) | 外星人 17 R4，网卡推荐：[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html) |
| Alienware Aurora-R7                        | [链接](https://github.com/jianghaizhi/DELL-Alienware-Aurora-R7-macOS) |                                                              |                                                       |
| Alienware-Aurora-R6/R7/R8                  | [链接](https://github.com/jianghaizhi/DELL-Alienware-Aurora-R7-macOS) |                                                              |                                                       |
| DELL Latitude E7440                        | [链接](https://github.com/ameeno/Dell-E7440-Hackintosh)      |                                                              |                                                       |
| **Alienware外星人更多机型**                | [链接](https://github.com/RockJesus/Alienware-Hackintosh)    |                                                              | 引用自：RockJesus维护的仓库                           |
|                                            |                                                              |                                                              |                                                       |
| Dell G3 3579                               | [链接](https://github.com/JiangHoumin/Dell_G3_3579_Hackintosh) [链接](https://github.com/CerteKim/Dell-G3-3579-Hackintosh-Clover) [链接](https://github.com/CerteKim/Dell-G3-3579-Hackintosh-OpenCore) [链接](https://github.com/tonyleelyy/OpenCore-Hackintosh-Dell-G3-3579) |                                                              | 网卡推荐：[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html)；链接3,4为`OpenCore`|
| Dell G3 3779 | [链接](https://github.com/djlucas123456/Dell-G3-3779-Mojave-Catalina-Clover-) | | |
| Dell G7 7588                               | [链接](https://github.com/geraldoandradee/Hackintosh-Dell-G7-7588) [链接](https://github.com/flyfeng2002/FYQ-Hackintosh) [链接](https://github.com/Juan-VC/Hackintosh-macOS-Catalina-on-Dell-G7-7588) |                                                              | 链接2和链接3包括`OpenCore`                                 |
| Dell Inspiron 14 5447                      | [链接](https://github.com/SinhLv/Dell-Ins-14-5447-hackintosh) | [链接](https://github.com/SinhLv/Dell-Ins-14-5447-hackintosh/blob/master/README.md) | Dell-Ins-14-5447                                      |
| Dell Inspiron 14 7447                      | [链接](https://github.com/Am1nCmd/Dell-Inspiron-14-7447-Pandora-Hackintosh) | [链接](https://github.com/Am1nCmd/Dell-Inspiron-14-7447-Pandora-Hackintosh/blob/master/README.md) | Dell-Inspiron-14-7447                                 |
| Dell Inspiron 15 7000 (i7-8550U)           | [链接](https://github.com/athlonreg/Dell-Inspiron-15-7000-i7-8550u) |                                                              |                                                       |
| Dell Inspiron 3442                         | [链接](https://github.com/kkzzhizhou/Dell-3443-Hackintosh)   | [链接](https://github.com/kkzzhizhou/Dell-3443-Hackintosh/blob/master/README.md) | Dell 3443                                             |
| Dell Inspiron 3443                         | [链接](https://github.com/kkzzhizhou/Dell-3443-Hackintosh)   |                                                              |                                                       |
| Dell Inspiron 3543                         | [链接](https://github.com/arisskz6/Dell-3543-Hackintosh) [链接](https://github.com/meikeeit/Hackintosh_Dell3543) |                                                              |                                                       |
| Dell Inspiron 3568                         | [链接](https://github.com/YGQ8988/dell-3568)                 | [链接](https://github.com/YGQ8988/dell-3568)                 | Dell Inspiron 3568                                    |
| Dell Inspiron 3670                         | [链接](https://github.com/inyan600/Dell-Inspiron-3670-Hackintosh) |                                                              |                                                       |
| Dell Inspiron 5370 | [链接](https://github.com/dreamwhite/dell-inspiron-5370-hackintosh) | | |
| Dell Inspiron 5447                         | [链接](https://github.com/SinhLv/Dell-Ins-14-5447-hackintosh) |                                                              |                                                       |
| Dell Inspiron 5459 | [链接](https://github.com/lzhoang2601/Dell-Insprison-5459-Hackintosh) | | |
| Dell Inspiron 5488                         | [链接](https://github.com/daggeryu/DELL-inspiron-5488)       |                                                              |                                                       |
| Dell Inspiron 5548(4528S) | [链接](https://github.com/yuppiesnotzhuhao/Hackintosh-Dell-Inspiron-5548) | | |
| Dell Inspiron 5559                         | [链接](https://github.com/cbabb/dell-5559)                   |                                                              | Dell 5559                                             |
| Dell Inspiron 5567                         | [链接](https://github.com/MuntashirAkon/HackintoshDellInspiron5567) |                                                              | i3-7100u, Intel HD620                                 |
| Dell Inspiron 5570                        | [链接](https://github.com/Mateo1234454545/Dell-5570-hackintosh) |                                                              |                                                       |
| Dell Inspiron 5577                         | [链接](https://github.com/imAmouse/Clover-EFI-For-Dell-5577) [链接](https://github.com/sachangregory/Dell-Inspiron-5577-Hackintosh)|                                                              |                                                       |
| Dell Inspiron 7000 系列                    | [链接](https://github.com/daliansky/dell7000)                | [链接](https://github.com/daliansky/dell7000/blob/master/README.md) | Dell Inspiron 7000 I/II (7x60/7x72)<br />网卡推荐：[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html) |
| Dell Inspiron 7348 | [链接](https://github.com/MoozIiSP/dell-7348-hackintosh) |  |  |
| Dell Inspiron 14 7447 Pandora              | [链接](https://github.com/Am1nCmd/Dell-Inspiron-14-7447-Pandora-Hackintosh) |                                                              |                                                       |
| Dell Inspiron 7460 和 7560                 | [链接](https://github.com/xzhih/dell-7460-7560-hackintosh)   | [链接](https://github.com/xzhih/dell-7460-7560-hackintosh/blob/master/README.md) | 戴尔 7460 和 7560，网卡推荐：[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html) |
| Dell Inspiron 7472 | [链接](https://github.com/ic005k/DELL7472) |  |  |
| Dell Inspiron 7548 | [链接](https://github.com/mbrula/hackintosh-dell-inspiron) | | |
| Dell Inspiron 7559                         | [链接](https://github.com/crackself/Dell-7559-Hackintosh) [链接](https://github.com/JiangHoumin/Dell_G3_3579_Hackintosh) [链接](https://github.com/fengwenhua/dell-7559-hackintosh)| [链接](https://github.com/crackself/Dell-7559-Hackintosh/blob/Hotpatch/README.md) | Dell 7559，网卡推荐：[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html) |
| Dell Inspiron 7567                         | [链接](https://github.com/Doapeat/Dell7567)                  |                                                              |                                                       |
| Dell Inspiron 7577 | [链接](https://github.com/yakimka/Hackintosh-Dell-7577) | | |
| Dell Inspiron 7580 | [链接](https://github.com/rogerioadris/hackintosh-dell-7580) | | |
| Dell Inspiron 7591 | [链接](https://github.com/tctien342/Dell-Inspiron-7591-Hackintosh) [链接](https://github.com/Skimige/Inspiron-759x-Hackintosh)[链接](https://github.com/Pinming/Dell-Inspiron-7590-Hackintosh-Opencore)| | |
| Dell Latitude E5270 | [链接](https://github.com/thebinh-lg051/Dell-Latitude-E5270-Hackintosh) | | |
| Dell Latitude E5290 | [链接](https://github.com/laelsirus/Dell-Latitude-5290-2-in-1-UHD620-iGPU-CLOVER) | [链接](https://github.https://github.com/laelsirus/Dell-Latitude-5290-2-in-1-UHD620-iGPU-CLOVER/blob/master/README.md) | Dell-Latitude-5290 |
| Dell Latitude E5440                        | [链接](https://github.com/soejin/hackintosh-dell-e5440)      |                                                              | Dell E5440                                            |
| Dell Latitude E5470 | [链接](https://github.com/txt1994/dell_latitude5470_i7-6820hq) | |  |
| Dell Latitude E5490 | [链接](https://github.com/lijun215021/DELL-5490-hackintosh) | | |
| Dell Latitude E5591 | [链接](https://github.com/geowoden/DELL-Latitude-5591_osx-clover) | |  |
| Dell Latitude E6330                        | [链接](https://github.com/BladeScraper-Designs/Dell-Latitude-E6330-Mojave-Hackintosh-EFI) |                                                              |                                                       |
| Dell Latitude E6430                        | [链接](https://github.com/kinoute/Hack-Dell-Latitude-E6430)  |                                                              |                                                       |
| Dell Latitude E7250                         | [链接](https://github.com/SkyrilHD/Dell-E7250-Hackintosh)  |                                                              |                                                       |
| Dell Latitude E7280                        | [链接](https://github.com/conradlyn/Hackintosh-EFI-Dell-Latitude_7280) |                                                              |                                                       |
| Dell Latitude E7370 | [链接](https://github.com/mikeTOliu/dell-latitude7370-Hackintosh-EFI-backup) | | |
| Dell Latitude E7440                        | [链接](https://github.com/ameeno/Dell-E7440-Hackintosh)      |                                                              |                                                       |
| Dell Latitude E74890 | [链接](https://github.com/TranNgocKhoa/Dell-Latitude-7480-Hackintosh) | | |
| Dell Latitude E7490 | [链接](https://github.com/Swung0x48/Dell-Latitude-7490-Hackintosh-EFI) | | |
| Dell OptiPlex 3050                         | [链接](https://github.com/Leif160519/Dell-OptiPlex-3050-EFI) | [链接](https://github.com/Leif160519/Dell-OptiPlex-3050-EFI/blob/master/README.md) |                                                       |
| Dell OptiPlex 3060 | [链接](https://github.com/Drovosek01/hackintosh_DELL_OptiPlex_3060_i5-8500) |  | |
| Dell Optiplex 7020 | [链接](https://github.com/zearp/optimac) | | |
| Dell OptiPlex 7070 mff                     | [链接](https://github.com/liaoyudong2/Dell-7070-mff-hackintosh) |                                                              |                                                              |
| Dell OptiPlex 7070 SFF                     | [链接](https://github.com/webleon/Hackintosh-OptiPlex-7070-SFF) |                                                              |                                                              |
| Dell OptiPlex 9020 | [链接](https://github.com/kyroschow/Dell-Optiplex-9020-Hackintosh-Clover-EFI) | | |
| Dell Precision 5510                        | [链接](https://github.com/soulomoon/Dell-Precision-5510-OSX) [链接](https://github.com/PLChinDev/Dell-Precision-5510-Mojave) |                                                              | Dell-Precision-5510<br />链接2支持`Catalina`          |
| Dell Precision 5591                         | [链接](https://github.com/n0faith/Dell-Precision-5591-Hackintosh) |||
| Dell Precision M3800<br />Dell XPS 15-9530 | [链接](https://github.com/syscl/M3800)                       | [链接](https://github.com/syscl/M3800/blob/M3800/README.md)  | Dell M3800 和 XPS 9530                                |
| Dell Vostro 3267 | [链接](https://github.com/Drovosek01/hackintosh_DELL_Vostro_3267_i5-6400/blob/master/docs/ENG/README.md) |  |  |
| Dell Vostro 3578 | [链接](https://github.com/ABCDFAS/dell-vostro-3578-hackintosh-clover-efi) | | |
| Dell Vostro 5370                           | [链接](https://github.com/hellmonky/Hackintosh/tree/master/dell-vostro-5370) |                                                              |                                                       |
| Dell Latitude 5290 2-in-1                  | [链接](https://github.com/laelsirus/Dell-Latitude-5290-2-in-1-UHD620-iGPU-CLOVER) |                                                              |                                                     |
| Dell Vostro 5581 | [链接](https://github.com/nghetienhiep/Dell-Vostro-5581-Hackintosh) | | |
| Dell XPS 15 7590 | [链接](https://github.com/daliansky/XPS15-7590-Hackintosh) | | Dell XPS 15 7590，网卡推荐：[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html) |
| Dell XPS13  9343                           | [链接](https://github.com/SiGae/macOS-Mojave-on-xps-13-9343) | [链接](https://github.com/haos001/XPS13-9343-Clover)         |                                                       |
| Dell XPS 9350                              | [链接](https://github.com/syscl/XPS9350-macOS)               | [链接](https://github.com/syscl/XPS9350-macOS/blob/master/README.md) | Dell XPS 9350                                         |
| Dell XPS 9360                              | [链接](https://github.com/hoanX/xps13-9360-i7-7560u)         | [链接](https://github.com/hoanX/xps13-9360-i7-7560u/blob/master/README.md) | Dell XPS 9360，网卡推荐：[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html) |
| Dell XPS 9360                              | [链接](https://github.com/ymmshi/XPS-9360) [链接](https://github.com/MasonGao/XPS-9360-Hackintosh) <br />[链接](https://github.com/the-marcus/XPS-9360-hackintosh) [链接](https://github.com/the-darkvoid/XPS9360-macOS) <br />[链接](https://github.com/0xHJK/XPS13-9360-i5-8250U-macOS) [链接](https://github.com/samuelshi/XPS13-9360) | [链接](https://github.com/ymmshi/XPS-9360/blob/master/README.md) | Dell XPS 9360，网卡推荐：[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html) |
| Dell XPS 9370                              | [链接](https://github.com/jieelin/XPS9370-Hackintosh)        |                                                              |                                                       |
| Dell XPS 9380 | [链接](https://github.com/wdubaiyu/Hackintosh-Dell-XPS-9380) | | |
| Dell XPS 9530                              | [链接](https://github.com/the-darkvoid/XPS9530-OSX/tree/10.13) | [链接](https://www.tonymacx86.com/threads/guide-dell-xps-9530-clover-uefi-hotpatch.235558/) | XPS 9530                                              |
| Dell XPS 9550                              | [链接](https://github.com/wmchris/DellXPS15-9550-OSX) [链接](https://github.com/corenel/XPS9550-macOS)[链接](https://github.com/xxxzc/xps15-9550-macos) | [链接](https://github.com/wmchris/DellXPS15-9550-OSX/blob/10.14/README.md) [链接](https://github.com/corenel/XPS9550-macOS/blob/master/README.md) | Dell XPS 9550                                         |
| Dell XPS 9560                              | [链接](https://github.com/gunslinger23/XPS15-9560-High-Sierra) | [链接](https://github.com/gunslinger23/XPS15-9560-High-Sierra/blob/master/README.md) | Dell XPS 9560，网卡推荐：[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html) |
| Dell XPS 9570                              | [链接](https://github.com/Xigtun/xps-9570-mojave) [链接](https://github.com/bavariancake/XPS9570-macOS) <br />[链接](https://github.com/LuletterSoul/Dell-XPS-15-9570-macOS-Mojave) |                                                              | 感谢：[LuletterSoul](https://github.com/LuletterSoul)，网卡推荐：[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html) |

#### Gigabyte 技嘉

| 机型名称           | 发布地址                                                 | 教程地址                                                     | 备注 |
| ------------------ | -------------------------------------------------------- | ------------------------------------------------------------ | ---- |
| Gigabyte Aero 15X  | [链接](https://github.com/zacmks/Hackintosh-Aero-15X)    | [链接](https://github.com/zacmks/Hackintosh-Aero-15X/blob/master/README.md) |      |
| Gigabyte Aero 15W  | [链接](https://github.com/Errrneist/Hackintosh-Aero-15W) |                                                              |      |
| Gigabyte Sabre 15K | [链接](https://github.com/gnehs/Sabre15KClover)          |                                                              |      |

#### Hasse 神舟

| 机型名称               | 发布地址                                                     | 教程地址                                                     | 备注              |
| ---------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ----------------- |
| 神舟 k610d-i5D3 | [链接](https://github.com/1zilc/K610d-i5-d3-10.14.5-efi-clover) |  |  |
| 神舟 K650D              | [链接](https://github.com/wklesss/k650D-Hackintosh)          |                                                              | 神舟K650D       |
| 神舟 K650D-SL5S1      |   [链接](http://bbs.pcbeta.com/forum.php?mod=viewthread&tid=1800662)  |    [链接](https://blog.nyaasu.top/front-end/111.html)      |  EFI文件部分有效，无线网卡和电池无法驱动      |
| 神舟 K650D-i5D2        | [链接](https://github.com/ivothgle/Hackintosh)          |                                                              | 神舟K650D i5 D2      |
| 神舟 K680E-G6D1 | [链接](https://github.com/Vnzen/Hackintosh_hasee_k680e-g6d1_clover) | |  |
| 神舟战神 K770E-i7D1 | [链接](https://github.com/Gitawake/Hasee-K770e-i7-D1-Clover) | | p170sm-a |
| 神舟战神 Z6-SL5D1        | [链接](https://github.com/Measureless/Hackintosh_Hasee_Z6-SL5D1) |                                                              |                   |
| 神舟战神 Z7-KP7D1 | [链接](https://github.com/ConnersHua/Clevo-P65xHP-Hackintosh) | | Clevo P65xHP<br />HASEE Z7-KP7S1 |
| 神舟战神<br>Z7(M)-KP7/5GZ<br>Z7(M)-KP7/5Z<br>Z7-KP7EC<br>Z7(M)-KP7/5GC<br>Z7(M)-KP7/5GA<br>Z7(M)-KP7/5GE<br>Z7(M)-KP7/5GH<br>Z7-CT7/5GK<br>Z7M-CT7GS<br>G7-CT7VK、G7-CT7RA<br>Z7(M)-CT7/5GA<br>Z7(M)-CT7/5VH  | [链接](https://github.com/kirainmoe/hasee-tongfang-macos) | [链接](https://www.bilibili.com/video/av81263778) | 神舟战神 8/9 代同方模具全系标压机型，适配以下模具：<br>GK5CN6X, GK5CN5X <br> GJ5CN64, GI5CN54 <br>GK5CP6X, GK5CP5X <br> GK7CP6R <br>GK5CP6V,GK5CP5V |
| 神舟战神 Z7M-KP5GC        | [链接](https://github.com/CharlesZhou959/Hasee-Z7M-KP5GC-Hackintosh) |                                                              |                   |
| 神舟战神 Z7(M)-CT7/5NA | [链接](https://github.com/bufsnake/Z7-CT7NA-HackIntosh) |  |  |
| 神舟战神<br> Z7(M)-CT7/5NA (NK/NT)<br> G7-CT7NA (NK/NT) <br> G8-CT7NA (NK/NT) | [链接](https://github.com/a328661276/Clevo-NH50-NH70-Hackintosh-macOS10.15.3) | | 适用于蓝天Clevo NH5xRD_RC_RA_RH(Q)/NH70RD_RC_RA_RH(Q)  |
| 神舟精盾系列 T96E       | [链接](https://github.com/L0ngxhn/Hackintosh-Hasee-T96E)     |  |                   |
| 神舟精盾系列 K590S      | [链接](https://github.com/JokerHYC/K590S-HACKINTOSH)     |  |                   |
| 神舟 GX8-P775TM      | [链接](https://github.com/JokerHYC/P775TM-HACKINTOSH)     |  |       未来人类X711，战神GX8-CP5，战神GX8-CR6，炫龙V87等使用蓝天p775tm模具的10*0系显卡都支持   |
| 神舟战神Z6-KP7S1     |[链接](https://github.com/hevervie/Hackintosh_HASEE_Z6-KP7S1)        |       |       | |
| 神舟战神<br> ZX7-CP5SC<br>ZX6-CP5S1<br>K680E-G6E3<br>K680E-G6D3 | [链接](https://github.com/bavelee/NB5TK1_TJ1-Hackintosh/) | [链接](https://bavelee.cn/archives/60.html) | 蓝天 NB50/60 TJ1/TK1 模具 |


#### HP 惠普

| 机型名称                                | 发布地址                                                     | 教程地址                                                     | 备注                                                         |
| --------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| HP ProBook/EliteBook<br />ZBook 系列    | [链接](https://github.com/RehabMan/HP-ProBook-4x30s-DSDT-Patch) | [链接](https://www.tonymacx86.com/threads/guide-hp-probook-elitebook-zbook-using-clover-uefi-hotpatch.261719/) | 除 8x60W,8x70W 系列之外的机型，<br />二代 CPU 及之前的机型仅支持到 10.13.x |
| HP Envy Haswell J/K/Q/N<br />系列笔记本 | [链接](https://github.com/RehabMan/HP-Envy-DSDT-Patch)       | [链接](https://www.tonymacx86.com/threads/guide-hp-envy-haswell-series-j-k-q-n-using-clover-uefi.261724/) | 仅 4 代 envy 机型                                            |
| HP 15 D062TU                            | [链接](https://github.com/trqukhanh0104/hp-15-d062tu-hackintosh) [链接](https://github.com/khanhtran-cse/hp-15-d062tu-hackintosh) |                                                              |                                                              |
| HP Laptop 15-da0233ur                   | [链接](https://github.com/DmitriyyyyS/Hackintosh-HP-Laptop-15-da0233ur) |                                                              | i3-7020U                                                     |
| HP 17 BY0062ST                          | [链接](https://github.com/emilevirus/HP-BY00000-HACKINTOSH)  |                                                              |                                                              |
| HP Envy 13 ad024TU | [链接](https://github.com/Astrobr/HackintoshForEnvy13-ad0xx) | | |
| HP Envy 13 ad1xxx                       | [链接](https://github.com/ArisHub/Hackintosh_Envy13_10.13.6-10.14.4) | [链接](https://github.com/ArisHub/Hackintosh_Envy13_10.13.6/blob/master/README.md) | 惠普 envy13                                                  |
| HP Envy15 as109tu                       | [链接](https://github.com/TianNes/Hackintosh-Clover)         |                                                              |                                                              |
| HP Envy 15 as110tu                      | [链接](https://github.com/wing-ho/HP-AS110TU-Hackintosh)     |                                                              |                                                              |
| HP Envy x360 15-aq160sa | [链接](https://github.com/KaylumJ/Hackintosh-HP-Envy-x360) | | |
| HP Envy DV6 7303ef                      | [链接](https://github.com/TehOrange/hackintosh_configs/tree/master/HP-Envy-DV6-7303ef) |                                                              |                                                              |
| Hp Omen Ce020tx | [链接](https://github.com/thanatath/hp-omen-ce020tx-mojave-osx) | | |
| HP Omen Laptop 15-ce0xx | [链接](https://github.com/shimakazechan/OMEN-by-HP-Laptop-15-ce007TX-Hackintosh) | | |
| HP 348 G5 | [链接](https://github.com/zsakvo/hp-348-g5-hackintosh) | | |
| HP ProBook 650 G1 | [链接](https://github.com/Hologos/hackintosh-hp-probook-650-g1) | | |
| HP 840-G1                               | [链接](https://github.com/blint01/hackintosh-mojave-HP-840-G1) | [链接](https://github.com/blint01/hackintosh-mojave-HP-840-G1/blob/master/README.md) |                                                              |
| HP Elitebook 840 G2 | [链接](https://github.com/AktasC/Hackintosh-Elitebook-840-G2-Broadwell) |  | |
| HP Pavilion 15-au028ur | [链接](https://github.com/Drovosek01/hackintosh_HP_Pavilion_15-au028ur_i5-6200U/blob/master/docs/ENG/README.md) |  | |
| HP Pavilion 15 au067tx | [链接](https://github.com/FzeNiX/HPPavilion15-au067tx-Mojave-Hackintosh) |  | |
| HP Pavilion15 AU157TX | [链接](https://github.com/sxrhd/HP-AU157TX-EFI) | | |
| HP Pavillion ck069tx                    | [链接](https://github.com/Blizzard57/Hackintosh)             |                                                              |                                                              |
| HP Pavilion 15 cs1xxx | [链接](https://github.com/JaeSeoKim/HP-Pavilion-Laptop-15-cs1xxx-Hackintosh) | | |
| Hp spectre X360                         | [链接](https://github.com/Just-maple/Hp-spectre-X360-hackintosh) |                                                              |                                                              |
| EliteDesk 800-G3-Mini                   | [链接](https://github.com/francoisminh/Hackintosh-EliteDesk-800-G3-Mini-65W) | [链接](https://github.com/francoisminh/Hackintosh-EliteDesk-800-G3-Mini-65W/blob/master/README.md) |                                                              |
| HP Zhan 66 Pro G1                       | [链接1](https://github.com/A-Linz/Hackintosh-HP-Zhan-66-Pro-G1) [链接2](https://github.com/RenAmamiya/HP-Zhan-66-Pro-G1) |                                                              |                                                              |
| HP ZHAN 66 PRO 14 G2 | [链接](https://github.com/peihexian/HP-ZHAN-66-Pro-14-G2) | | |
| HP ZHAN99 WorkStation G1                | [链接](https://github.com/MacsedProtoss/hackintosh)          |                                                              | HP ZBook 15v G5                                     |
| 暗影精灵4 i5-8300H GTX1050Ti            | [链接](https://github.com/canwdev/omen15dc-hackintosh)       |                                                              |                                                              |
| 暗影精灵2                            |[链接](https://github.com/Arecall/-Mac-os) |            |          |
| 暗影精灵 II 代Pro <br />HP OMEN 15-ax214TX |[链接](https://github.com/ZGGSONG/HP-OMEN-15-ax214TX-Hackintosh) | | |
| 暗影精灵2 Pro HP OMEN 15-ax225TX                             |[链接](https://github.com/Cruii/HP-OMEN-15-ax225TX) [链接](https://github.com/XStar-Dev/HP_OMEN-2Pro_Hackintosh) |            |          |
| HP暗影精灵3 |[链接](https://github.com/bessyjl/HP-OMEN-3-Hackintosh) | | 还有挖坑的，看看啥时候能埋人 |
| 暗影精灵I (惠普PAVILION Gaming NB 15-ak039TX) |[链接](https://github.com/lgs3137/PAVILION_Gaming_NB-macOS) | | 除了独显、Intel无线网卡，其他功能模块正常(包括HDMI视频) |
| HP Pavillion Gaming Laptop 15-cx0xxx |[链接](https://github.com/mechtifs/hackintosh-clover-hp-pavillion-15-cx0xxx) | | 光影精靈4代 |
|惠普光影精靈5 |[链接](https://github.com/Tonymiugrey/Garden-by-miugrey) | | 內含搞定PM981的補丁，可以試試 |
|ProBook 430 G6 |[链接](https://github.com/YGQ8988/HP-ProBook430G6) | | i5-8265U 已卸载内置镁光nvme SSD(此硬盘不识别) |

#### Huawei 华为

| 机型名称                 | 发布地址                                                     | 教程地址                                                     | 备注                               |
| ------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ---------------------------------- |
| 华为 Matebook X Pro 2019 | [链接](https://github.com/laozhiang/MateBook_X_Pro_2019-Hackintosh) | [链接](https://github.com/laozhiang/MateBook_X_Pro_2019-Hackintosh) | 华为 Matebook X Pro 2019           |
| 华为 Matebook X Pro      | [链接](https://github.com/gnodipac886/MatebookXPro-hackintosh) [链接](https://github.com/gnodipac886/MatebookXPro-hackintosh) | [链接](https://github.com/gnodipac886/MatebookXPro-hackintosh/blob/master/README-CN.md) | 华为 Matebook X Pro 2018           |
| 华为 Matebook X          | [链接](https://github.com/4323770/Hackintosh-For-Matebook-X) |                                                              |                                    |
| 华为 Matebook 13         | [链接](https://github.com/FIU001/huawei-matebook-13-) [链接](https://github.com/Edoardo001/Matebook-13-Hackintosh) |                                                              |                                    |
| 华为 Matebook 14         | [链接](https://github.com/frezs/MateBook14-Hackintosh)       |                                                              |                                    |
| 华为 Matebook D          | [链接](https://github.com/MOJUNSHOU/MateBooK-D) [链接](https://github.com/Zero-zer0/Matebook_D_2018_Hackintosh_OpenCore) |                                                              | 华为MateBook D2018 i5-8250U 15.6寸<br />网卡推荐：[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html) |
| 荣耀 Magicbook           | [链接](https://github.com/hjmmc/Honor-Magicbook) [链接](https://github.com/buseQ/magicbook-hackintosh-opencore-i7-8550u) | [链接](https://github.com/hjmmc/Honor-Magicbook/blob/master/README_CN.md) | 网卡推荐：[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html) |
| 荣耀 Magicbook-Pro-16.1           | [链接](https://github.com/GatesYang/Magicbook-Pro-16.1-Hackintosh)             |  |                                    |
| 华为 Matebook 14 2020款 | [链接](https://github.com/Zero-zer0/Matebook_13_14_2020_Hackintosh_OpenCore) | | 华为 Matebook 13 / 14 2020 十代 通用 |

#### Lenovo 联想

| 机型名称                           | 发布地址                                                     | 教程地址                                                     | 备注                                                         |
| ---------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Lenovo Flex 15                     | [链接](https://github.com/aytic/Lenovo-Flex-15-Hackintosh)   | [链接](https://github.com/aytic/Lenovo-Flex-15-Hackintosh/blob/master/README.md) | Lenovo Flex 15                                               |
| Lenovo Ideapad 310-14IKB           | [链接](https://github.com/29satnam/LenovoHackintosh)         | [链接](https://github.com/29satnam/LenovoHackintosh/blob/master/README.md) |                                                              |
| Lenovo Ideapad 320-15ISK           | [链接](https://github.com/gajjartejas/Lenovo-Ideapad-320-15ISK-Laptop-Hackintosh) |                                                              |                                                              |
| Lenovo Ideapad 330s-14IKB | [链接](https://github.com/chrisru26/LenovoIdeapad330s-14ikb-Hackintosh) | | |
| Lenovo Ideapad S340 | [链接](https://github.com/4mitabh/Ideapad_S340) | | |
| Lenovo Ideapad 510-15IKB | [链接](https://github.com/trgcyln/Lenovo-Hackintosh) | | |
| Lenovo Ideapad 700-15ISK           | [链接](https://github.com/athlonreg/Lenovo-XiaoXin700-15ISK) | [链接](https://github.com/athlonreg/Lenovo-XiaoXin700-15ISK/blob/master/README.md) | Lenovo-XiaoXin700-15ISK                                      |
| Lenovo Ideapad 720s 13IKB | [链接](https://github.com/xiaominglei001/ideapad-720s-13IKB) |  | 网卡推荐：[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html) |
| Lenovo Flex 3-1580                 | [链接](https://github.com/gdllzkusi/Lenovo-Fex3-1580-hackintosh) |                                                              |                                                              |
| Lenovo G40-70M | [链接](https://github.com/jinmu333/Lenovo_G40_70M_EFI) | | |
| Lenovo G400                      | [链接](https://github.com/autersu/Lenovo_G400_EFI)     |||
| Lenovo G50-80                      | [链接](https://github.com/upupming/Lenovo-G50-80-Clover)     |                                                              |                                                              |
| Lenovo G510                        | [链接](https://github.com/Z39/G510-OS-X-Clover-Hotpatch)     | [链接](https://github.com/Z39/G510-OS-X-Clover-Hotpatch/blob/master/README-CN.md) | 感谢：[39军小兵张](http://i.pcbeta.com/space-uid-4472739.html) |
| ThinkPad E440 | [链接](https://github.com/ZzMark/Thinkpad-E440-Hackintosh) |  |  |
| ThinkPad E450C                     | [链接](https://github.com/zhangxuan1340/Hackintosh_E450C)    |                                                              |                                                              |
| ThinkPad E470                     | [链接](https://github.com/y010204025/E470-clover)    |                                                              |                                                              |
| ThinkPad E480                      | [链接](https://github.com/aliyoge/Hackintosh-ThinkPad-E480)  | [链接](https://github.com/aliyoge/Hackintosh-ThinkPad-E480/blob/master/README.md) |                                                              |
| ThinkPad E490 | [链接](https://github.com/dievdmitry/Thinkpad-E490-hackintosh) |  | |
| ThinkPad E540                      | [链接](https://github.com/wwbhl/E540)                        |                                                              |                                                              |
| ThinkPad E550                      | [链接](https://github.com/the-braveknight/Lenovo-ThinkPad-E550-DSDT-Patch) | [链接](https://www.tonymacx86.com/threads/guide-lenovo-thinkpad-e550-haswell-using-clover-uefi-10-11.214675/) | E550 四代 CPU                                                |
| ThinkPad E560                      | [链接](https://github.com/rsdev69/Lenovo-E560-Clover)        | [链接](https://www.tonymacx86.com/threads/stable-lenovo-e560-full-work.248842/) |                                                              |
| ThinkPad E570                      | [链接](https://github.com/SysConKonn/E570-Hackintosh)        | [链接](https://www.tonymacx86.com/threads/stable-lenovo-e560-full-work.248842/) |                                                              |
| ThinkPad L440                      | [链接](https://github.com/BesnikRrustemi/Lenovo-ThinkPad-L440) |                                                              |                                                              |
| Lenovo miix 520                    | [链接](https://github.com/acai66/lenovo-miix-520-hackintosh-10.14-CLOVER) |                                                              |                                                              |
| ThinkPad P51                       | [链接](https://github.com/MirkoCovizzi/thinkpad-p51-hackintosh) | [链接](https://github.com/MirkoCovizzi/thinkpad-p51-hackintosh/blob/master/README.md) | Thinkpad P51                                                 |
| ThinkPad P52                       | [链接](https://github.com/liuyishengalan/ThinkPad-P52-Hackintosh-10.14.X-)  [P52/P53/P72/P73](https://github.com/liuyishengalan/ThinkPad-P52-P53-P72-P73-Hackintosh-10.15.x)|                                                              | 网卡推荐：[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html) |
| 锐 7000                            | [链接](https://github.com/839891627/Lenovo_RUI7000_Hackintosh) |                                                              | 联想 80WB 笔记本电脑                                         |
| ThinkPad S1 2017 | [链接](https://github.com/bugprogrammer/hackintosh/tree/ThinkPad-S1-2017) | | ThinkPad S1 2017 |
| ThinkPad S1 2018 | [链接](https://github.com/bugprogrammer/hackintosh/tree/ThinkPad-S1-2018) | | ThinkPad S1 2018 |
| ThinkPad T420 系列                 | [链接](https://github.com/tluck/Lenovo-T420-Clover)          | [链接](https://www.insanelymac.com/forum/topic/285678-lenovo-thinkpad-t420-with-uefi-only/?page=20&tab=comments#comment-1952283) | 包含 T420、T420s、T520、X220X220，<br />可通过修改支持到 10.14.x |
| ThinkPad T430 | [链接](https://github.com/hai666l/T430-EFI) |  |  |
| ThinkPad T430s | [链接](https://github.com/hunga1ok/hackintosh-t430si7vga-clover-config) | | |
| ThinkPad T440s | [链接](https://github.com/thebinh-lg051/ThinkPad-T440s-Hackintosh) | | |
| ThinkPad T440p                     | [链接](https://github.com/evy0311/t440p) [链接](https://github.com/jloisel/t440p) [链接](https://github.com/notthebee/t440p-hackintosh)| [链接](https://github.com/evy0311/t440p/blob/master/README.md) |                                                              |
| ThinkPad T450 | [链接](https://github.com/jsassu20/ThinkPad-T450-Mojave) |  | |
| ThinkPad T450s | [链接](https://github.com/EchoEsprit/Hackintosh-Catalina-OpenCore-Lenovo-T450s-efi) [链接](https://github.com/jianzhao0806/ThinkPad-T450S-Hackintosh)|  | |
| ThinkPad T460 系列                 | [链接](https://github.com/tluck/Lenovo-T460-Clover)          | [链接](http://www.insanelymac.com/forum/topic/315451-guide-lenovo-t460-macos-with-clover/) | 可支持 T460、T560、T470<br /> 和 T470p4 款机型               |
| ThinkPad T460p                     | [链接](https://github.com/totemofwolf/Thinkpad-T460p-OSX-EFI) |                                                              |                                                              |
| ThinkPad T460s | [链接](https://github.com/nicogig/T460s-Clover) | | |
| Thinkpad T470                      | [链接](https://github.com/nguyenduy98/Hackintosh)            |                                                              | I7-7500u                                                     |
| Thinkpad T470S                     | [链接](https://github.com/Altairko/Lenovo-T470s-Clover)            |                                                              |                                                    |
| ThinkPad T470p                     | [链接](https://github.com/lohcve/EFI_T470P)                  | [链接](https://github.com/lohcve/EFI_T470P/blob/master/README.md) | ThinkPad T470p                                               |
| ThinkPad T480                      | [链接](https://github.com/rhkjyn/T480-Hackintosh-FULL)       |                                                              | 网卡推荐：[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html) |
| ThinkPad T480s                     | [链接](https://github.com/kk1987/T480s-hackintosh)           | [链接](https://github.com/kk1987/T480s-hackintosh/blob/master/README.md) | 网卡推荐：[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html) |
| ThinkPad T480s                     | [链接](https://github.com/kk1987/T480s-hackintosh) [链接](https://github.com/linusyang92/macOS-ThinkPad-T480s) <br />[链接](https://github.com/samuelshi/Thinkpad-T480S) | [链接](https://github.com/linusyang92/macOS-ThinkPad-T480s/blob/master/README.md) [链接](https://github.com/kk1987/T480s-hackintosh/blob/master/README.md) | ThinkPad T480s<br />网卡推荐：[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html) |
| ThinkPad T580                      | [链接](https://github.com/CrazyPegAsus/ThinkPad-T580-Hackintosh) |                                                              | 鸣谢：[CrazyPegasus](https://github.com/CrazyPegasus)        |
| Lenovo U330/U430/U530 系列         | [链接](https://github.com/RehabMan/Lenovo-U430-Touch-DSDT-Patch) | [链接](https://www.tonymacx86.com/threads/guide-lenovo-ideapad-u330-u430-u530-using-clover-uefi.261722/) |                                                              |
| Lenovo V1000                       | [链接](https://github.com/LiuJiangshan/Lenovo-V1000-FHD)     |                                                              | 联想小新笔记本V1000 FHD                                      |
| Lenovo V3000                       | [链接](https://github.com/Xc2333/Hackintosh-Lenovo-v3000-ISE) | [链接](https://github.com/Xc2333/Hackintosh-Lenovo-v3000-ISE/blob/master/README.md) | Lenovo V3000                                                 |
| Lenovo V310 15iKB | [链接](https://github.com/jacobmesier/V310-Hackintosh) |  |  |
| Lenovo V330 15IKB                  | [链接](https://github.com/BesnikRrustemi/Lenovo-V330-15IKB)  | [链接](https://www.tonymacx86.com/threads/guide-lenovo-v330-15ikb-using-clover-uefi-hotpatch.265841/) |                                                              |
| Lenovo-WEI6(威6) | [链接](https://github.com/Tamshen/Lenovo-WEI6-Pro-13-IWL-Hackintosh) |  | **Lenovo Thinkbook 13S** |
| Lenovo xiaoxin air13 6th           | [链接](https://github.com/gdllzkusi/Lenovo-xiaoxin-air13-6th-Hackintosh) |                                                              | Intel 酷睿i5 6200U                                           |
| Lenovo XiaoXin Air 13 IWL          | [链接](https://github.com/daliansky/Lenovo-Air13-IWL) [链接](https://github.com/darpaxyz/Lenovo-Air13-IWL-Hackintosh) <br />[链接](https://github.com/xlivans/Air13IWL) | [链接](https://blog.daliansky.net/Lenovo-Xiaoxin-Air-13-macOS-Mojave-installation-tutorial.html) | 联想小新 Air 13 2018 IWL<br />网卡推荐：[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html) |
| Lenovo XiaoXin14 IWL 2019 | [链接](https://github.com/superbboy/Lenovo-XIAOXIN-14-2019-IWL-Hackintosh) [链接](https://github.com/4flr/XiaoXin-14IWL-2019-Hackintosh) |  | 网卡推荐：[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html) |
| Lenovo XiaoXin Air 14 2019 IML | [链接](https://github.com/lietxia/XiaoXinAir14IML_2019_hackintosh) |  | 小新 Air14-2019 IML 10代 i5-10210u |
| Lenovo XiaoXin Pro 13 2019 | [链接](https://github.com/daliansky/XiaoXinPro-13-2019-hackintosh) |  | 联想小新Pro 2019，网卡推荐：[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html) |
| Lenovo XiaoXin Chao 5000           | [链接](https://github.com/Xc2333/Hackintosh-Lenovo-chao5000) |                                                              | 联想潮 5000                                                  |
| Lenovo XiaoXin Rui 7000            | [链接](https://github.com/Erf172/Lenovo_XiaoXin_Rui7000_Hackintosh) | [链接](https://github.com/Erf172/Lenovo_XiaoXin_Rui7000_Hackintosh/blob/10.12/README.md) |                                                              |
| Lenovo XiaoXin Chao 7000           | [链接](https://github.com/penghubingzhou/Lenovo-Xiaoxin-Chao-7000--EFI) | [链接](https://github.com/penghubingzhou/Lenovo-Xiaoxin-Chao-7000--EFI/blob/master/Readme.md) | 联想小新潮 7000，已支持 14 寸、<br />12.5 寸、13.3 寸，15 寸以及 <br />13.3 寸的完美支持后续会添加，<br />请期待…… |
| ThinkPad X1 3rd                    | [链接](https://github.com/shockingpants/ThinkpadX1Y3)        | [链接](https://www.tonymacx86.com/threads/guide-thinkpad-x1-yoga-3rd-gen-20ld-with-mojave.261823/) | ThinkPad X1 3 代                                             |
| ThinkPad X1 Carbon 2015 | [链接](https://github.com/transtone/hackintosh/tree/master/x1c-2015) |  |  |
| ThinkPad X1 Carbon 5th gen         | [链接](https://github.com/B0hrer/Thinkpad-x1c-5th-gen-Hackintosh) |                                                              | (5th gen, released 2017)                                     |
| ThinkPad X1 Carbon 6th Gen         | [链接](https://github.com/tylernguyen/x1c6-hackintosh)       | [链接](https://github.com/tylernguyen/x1c6-hackintosh/blob/master/README.md) | Thinkpad X1 Carbon 6th Gen                                   |
| ThinkPad X1 Yoga / Carbon          | [链接](https://github.com/LukaJankovic/Thinkpad-X1-20FQ-Hackintosh) | [链接](https://github.com/LukaJankovic/Thinkpad-X1-20FQ-Hackintosh/blob/master/README.md) | Thinkpad X1 Yoga / Carbon                                    |
| ThinkPad X1 Yoga 2018 | [链接](https://github.com/Jamesxxx1997/thinkpad-x1-yoga-2018-hackintosh) |  |  |
| ThinkPad X1 Extreme                | [链接](https://github.com/Errrneist/Hackintosh-Thinkpad-X1-Extreme) [链接](https://github.com/zysuper/Thinkpad-X1-extreme-EFI) | [链接](https://www.tonymacx86.com/threads/macos-10-14-0-thinkpad-x1-extreme-igpu-issue.263916/) | 如果没猜错，这货就是 x1 隐士，<br />好几个人问过，这下省事了 |
| ThinkPad X1C 6th                   | [链接](https://github.com/tylernguyen/x1c6-hackintosh)       | [链接](https://github.com/tylernguyen/x1c6-hackintosh/blob/master/README.md) | ThinkPad X1c 6th                                             |
| ThinkPad X220                      | [链接](https://github.com/b-ggs/x220-hackintosh)             | [链接](https://github.com/b-ggs/x220-hackintosh/blob/master/README.md) | 支持 10.14+                                                  |
| ThinkPad X220                      | [链接](https://github.com/laris/Hackintosh-ThinkPad-X220-MacOS) |                                                              | ThinkPad-X220                                                |
| ThinkPad X230                      | [链接](https://github.com/littlegtplr/Hackintosh-X230-macOS) | [链接](https://github.com/littlegtplr/Hackintosh-X230-macOS/blob/master/README.md) | ThinkPad X230                                                |
| ThinkPad X230                      | [链接](https://github.com/banhbaoxamlan/X230-Hackintosh) [链接](https://github.com/SynneK1337/ThinkPad_X230_Hackintosh) | [链接](https://github.com/SynneK1337/ThinkPad_X230_Hackintosh/blob/master/README.md) | ThinkPad X230                                                |
| ThinkPad X230i | [链接](https://github.com/fivestrong/Hackintosh-X230i-macOS) |  |  |
| ThinkPad X250                      | [链接](https://github.com/Janolan/x250-hackintosh) [链接](https://github.com/qwerty12/X250-Hackintosh) [链接10.15](https://github.com/teddytaod/mac-catalina-thinkpad-x250) [链接](https://github.com/banhbaoxamlan/X250-Hackintosh)|                                                              |                                                              |
| ThinkPad X260 系列                 | [链接](https://github.com/daliansky/ThinkPad-X260-hackintosh) | [链接](https://github.com/daliansky/ThinkPad-X260-hackintosh/blob/master/README.md) | ThinkPad X260<br />网卡推荐：[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html) |
| Thinkpad x390-yoga        |[链接](https://github.com/Liu-wenxiang/Thinkpad-X390-Yoga-Clover)      |       |       |
| Lenovo Y50(70) 系列                | [链接](https://github.com/RehabMan/Lenovo-Y50-DSDT-Patch)    | [链接](https://www.tonymacx86.com/threads/guide-lenovo-y50-uhd-or-1080p-using-clover-uefi.261723/) | Y50(70)1080P 和 4K 版本<br />网卡推荐：[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html) |
| Lenovo IdeaPad 530s        | [链接](https://github.com/corint1/Hackintosh-Lenovo-IdeaPad-530s-14ikb)    |                                                              | 感谢：[39军小兵张](http://i.pcbeta.com/space-uid-4472739.html) |
| Lenovo IdeaPad Y410P               | [链接](https://github.com/Z39/Y410p-OS-X-Clover-Hotpatch)    |                                                              | 感谢：[39军小兵张](http://i.pcbeta.com/space-uid-4472739.html) |
| Lenovo IdeaPad Y430P               | [链接](https://github.com/Z39/Y430p-OS-X-Clover-Hotpatch)    |                                                              | 感谢：[39军小兵张](http://i.pcbeta.com/space-uid-4472739.html) |
| Lenovo IdeaPad Y510P               | [链接](https://github.com/Z39/Y510p-OS-X-Clover-Hotpatch)    |                                                              | 感谢：[39军小兵张](http://i.pcbeta.com/space-uid-4472739.html) |
| Lenovo Y520/Y720                   | [链接](https://github.com/the-braveknight/Lenovo-Y520-macOS) | [链接](https://www.tonymacx86.com/threads/guide-lenovo-legion-y520-y720-using-clover-uefi.261009/) | 联想 Y520 及 Y720                                            |
| Lenovo Legion Y7000                | [链接](https://github.com/hnie-xwz/EFI)                      | [链接](https://github.com/hnie-xwz/EFI/blob/macOs10.14/readme.md) | 网卡推荐：[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html) |
| Lenovo Legion Y7000-1060           | [链接](https://github.com/TioaTyan/Lenovo_Legion_Y7000-1060_Hackintosh) | [链接](https://github.com/TioaTyan/Lenovo_Legion_Y7000-1060_Hackintosh/blob/master/README.md) | Lenovo_Legion_Y7000-1060                                     |
| Lenovo Legion Y7000<br />Y530 系列 | [链接](https://github.com/xiaoMGitHub/Lenovo_Y7000-Y530_Hackintosh/) [链接](https://github.com/ahossny/Legion-Y530-Hackintosh) | | 全新完美 EFI，舍弃了小键盘                                   |
| Lenovo Y9000X | [链接](https://github.com/programbw/y9000x) [链接](https://github.com/hsd815/Y9000X-4K-hackintosh) [链接](https://github.com/WangRicky/Y9000X-HACKINTOSH) [链接](https://github.com/snxiang/Y9000X-Hackintosh-FHD-OpenCore) | | 支持CNVi直插m.2网卡，推荐：[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html) |
| Lenovo Yoga 3 Pro 1370             | [链接](https://github.com/gdllzkusi/hackintosh--lenovo-Yoga-3-Pro-1370) | [链接](https://github.com/gdllzkusi/hackintosh--lenovo-Yoga-3-Pro-1370/blob/master/README.md) | 联想 yaga3/pro                                               |
| ThinkPad Yoga 12                   | [链接](https://github.com/gartempe/MacOS-Thinkpad-Yoga-12) [链接](https://github.com/kymodoke/MacOS-Thinkpad-Yoga-12) | [链接](https://github.com/gartempe/MacOS-Thinkpad-Yoga-12/blob/master/README.md) [链接](https://github.com/kymodoke/MacOS-Thinkpad-Yoga-12/blob/master/README.md) |                                                              |
| Thinkpad S1 Yoga 12 | [链接](https://github.com/thebinh-lg051/Thinkpad-S1-Yoga-12-Hackintosh) |  | |
| Lenovo Yoga3 14                    | [链接](https://github.com/gdllzkusi/Lenovo-yoga3-14-hackntiosh) |                                                              |                                                              |
| Lenovo Yoga3 11                    | [链接](https://github.com/gdllzkusi/Lenovo-yoga3-11-hackntiosh) |                                                              |                                                              |
| Lenovo Yoga 13IKB | [链接](https://github.com/dragonflylee/Yoga13-Hackintosh) | | |
| Lenovo Yoga 370 | [链接](https://github.com/ouxuebo/YOGA370-clover) | |     |
| Lenovo Yoga 520 14IKB | [链接](https://github.com/gasperTheGhost/Yoga-520-Hackintosh) | | |
| Lenovo Yoga 710                    | [链接](https://github.com/xiaoxx970/Hackintosh-Mojave-for-Lenovo-Yoga710) |                                                              |                                                              |
| Lenovo Yoga 720 | [链接](https://github.com/bugprogrammer/hackintosh/tree/Lenovo-yoga-720-13ikb-7200u) | | Lenovo Yoga 720-13IKB |
| Lenovo Yoga 720 | [链接](https://github.com/williambj1/Hackintosh-EFI-Lenovo-Yoga-720-12IKB) | [链接](https://github.com/williambj1/Hackintosh-EFI-Lenovo-Yoga-720-12IKB/tree/master/Resources) | Lenovo Yoga 720-12IKB                                        |
| Lenovo Yoga 730 | [链接](https://github.com/dragonflylee/Yoga-730-hackintosh) | | Lenovo Yoga 730-13IKB |
| Lenovo Yoga 910 13IKB | [链接](https://github.com/wjz304/Hackintosh-EFI-Lenovo-Yoga-910-13IKB) | |  |
| Lenovo Z50(40)/70 系列             | [链接](https://github.com/the-braveknight/Lenovo-X50-macOS)  | [链接](https://www.tonymacx86.com/threads/guide-lenovo-z50-70-z40-70-g50-70-g40-70-using-clover-uefi.261787/) | Lenovo Z50-70/Z40-70   Lenovo G50-70/G40-70                  |
| Lenovo Miix510         | [链接](https://github.com/Aexus/hackintosh-ideapad-miix510)   [链接](https://github.com/liuwaei/Lenovo-Miix510-EFI-Clover-for-MacOS-10.14.X) |    | Lenovo-Miix510          |
| Lenovo Miix-520            | [链接](https://github.com/acai66/lenovo-miix-520-hackintosh-10.14-CLOVER) | [链接](https://github.com/acai66/lenovo-miix-520-hackintosh-10.14-CLOVER) | Lenovo-Miix-520          |
| Lenovo Miix4           | [链接](https://github.com/Zero-zer0/Miix700-OSX-Hackintosh-Clover) |   | Lenovo-Miix4（700）          |
| Lenovo Miix720 | [链接](https://github.com/jennie26/Lenovo-Miix-720-Hackintosh) | |  |
| Thinkstation P910 | [链接](https://github.com/crazyi/Hackintosh_Thinkstation_P910) |  |  |


#### LG

| 机型名称               | 发布地址                                           | 教程地址 | 备注 |
| ---------------------- | -------------------------------------------------- | -------- | ---- |
| LG Gram 14z980         | [链接](https://github.com/ShiningXu/LG-Gram-macOS) |          |      |
| LG Gram 15Z980-G.AA52C | [链接](https://github.com/ice-black-tea/LG-15Z980) |          |      |
| LG Gram Z980           | [链接](https://github.com/ShiningXu/LG-Gram-macOS) |          |       |

#### Mechrevo 机械革命

| 机型名称           | 发布地址                                                     | 教程地址                                                     | 备注                                |
| ------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ----------------------------------- |
| Mechrevo Z2 G      | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh/tree/master/Mechrevo%20Z2%20G%20X9TI/EFI) |                                                              | i7-9750H/GTX1660Ti                  |
| Mechrevo X9Ti R    | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh/tree/master/Mechrevo%20Z2%20G%20X9TI/EFI) |                                                              | i7-9750H/RTX2060/RTX2070            |
| Mechrevo Z2        | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh)      |                                                              | i7-8750H/i5-8300H GTX1050ti/GTX1060 |
| Mechrevo Z2 Air    | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh)      |                                                              | i7-8750H/i5-8300H GTX1050ti/GTX1060 |
| Mechrevo X8ti      | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh)      |                                                              | i7-8750H/i5-8300H GTX1050ti/GTX1060 |
| Mechrevo X8ti Plus | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh)      |                                                              | i7-8750H/i5-8300H GTX1050ti/GTX1060 |
| Mechrevo S1        | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh) [链接](https://github.com/lgs3137/MR_S1-macOS) | [链接](https://github.com/lgs3137/MR_S1-macOS/tree/master/Install) | I5-8250U/I7-8550u Mx150             |
| Mechrevo S1        | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh)      |                                                              | I5-8265U/I7-8565u Mx250             |
| Mechrevo X2        | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh)      |                                                              | i7-8750H/i5-8300H GTX1050ti/GTX1060 |
| Mechrevo S1 PLUS   | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh)      |                                                              | i7-8750H/i5-8300H GTX1050ti/GTX1060 |
| Mechrevo X7TI      | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh)      |                                                              | I7-6700HQ/I7 7700HQ                 |
| Mechrevo X7TI-S    | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh)      |                                                              | I7-7700HQ GTX1070/GTX1060           |
| Mechrevo X6TI      | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh)      |                                                              | i7-8750H/i5-8300H GTX1050ti/GTX1060 |
| Mechrevo X6TIS     | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh)      |                                                              |                                     |
| Mechrevo X1        | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh) [链接](https://github.com/tsmswifty/MECHREVO-X1-hackintosh) |                                                              | i7-7700HQ/GTX1060                   |
| Mechrevo Z2 Air <br> Mechrevo Z2 Air-G <br> Mechreco X3 | [链接](https://github.com/kirainmoe/hasee-tongfang-macos) | [链接](https://www.bilibili.com/video/av81263778) | 适用于同方GK5CN6X, GK5CP6X, GK7CP6R准系统模具 |

#### MSI 微星

| 机型名称                  | 发布地址                                                     | 教程地址                                                     | 备注      |
| ------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | --------- |
| MSI GE60 2PL-403XCN       | [链接](https://github.com/ice-black-tea/MSI-GE60) [链接](https://github.com/cs950809/MSI-GE60-2PL-403XCN-Hackintosh) |                                                              |           |
| MSI GE63 Raider RGB 8RE   | [链接](https://github.com/skyline75489/Hackintosh-MSI-GE63-Raider-RGB-8RE) |                                                            |           |
| MSI GE70 2PC              | [链接](https://github.com/alxzoomer/msi-ge70-2pc-hackintosh) |                                                              |           |
| MSI GF63                  | [链接](https://github.com/oscarrock/hackintosh-msi-gf63-thin-9SC) |                                                              |           |
| MSI GL62M-7REX            | [链接](https://github.com/rlindsberg/Hackintosh-On-MSI-GL62m-7REX) |                                                              |           |
| MSI GL63-8RE              | [链接](https://github.com/iAmineOHN/Hackintosh-MSI-GL63-8RE) |                                                              |           |
| MSI GL72M-7RDX            | [链接](https://github.com/jbwharris/hackintosh-msi-GL72M-7RDX) | [链接](https://github.com/jbwharris/hackintosh-msi-GL72M-7RDX/blob/master/README.md) |           |
| MSI GP62 6QG-1071XCN      | [链接](https://github.com/chuxubank/MSI-GP62-Hackintosh)     | [链接](https://github.com/chuxubank/MSI-GP62-Hackintosh/blob/master/README.md) | 微星 GP62 |
| MSI GS65 Stealth Thin 8RF | [链接](https://github.com/vladichimescu/msi-gs65-hackintosh) |                                                              |           |
| MSI GS65 8SE | [链接](https://github.com/ErrorErrorError/msi-gs65-8SE-hackintosh) | | |
| MSI GS73VR 7RF            | [链接](https://github.com/dogukanoksuz/msi-gs73vr-7rf-macOS) |                                                              |           |
| MSI-Z77A-G45           | [链接](https://github.com/ac1ra/MSI-Z77A-G45-Hackintosh) |                                                              |           |
| clover-z390-aorus-pro-wifi-9700k-rx580 |[链接](https://github.com/cheneyveron/hackintosh-clover-z390-aorus-pro-wifi-9700k-rx580) | [链接](https://github.com/cheneyveron/hackintosh-clover-z390-aorus-pro-wifi-9700k-rx580/blob/master/README.md)    ||
|MSI Z390   |[链接](https://github.com/MonkeySdkCom/EFI-MSI-Z390-Tomahawk)    |     |     |

#### Shinelon 炫龙

| 机型名称               | 发布地址                                                     | 教程地址                                                     | 备注              |
| ---------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ----------------- |
| 炫龙 A40L-i7 | [链接](https://github.com/i0Ek3/Hackintosh_4_Hasee_Shinelon_A40L) | [链接](https://github.com/i0Ek3/Hackintosh_4_Hasee_Shinelon_A40L/blob/master/README.md) |           |
| 炫龙 耀7000                  |  [链接](https://github.com/jinmu333/Shinelon_YAO_7000_efi) | [链接](https://github.com/jinmu333/Shinalon_YAO_7000_efi/blob/efi/README.md) |                   |
| 炫龙 耀7000 <br> 炫龙 耀9000-II | [链接](https://github.com/kirainmoe/hasee-tongfang-macos) | [链接](https://www.bilibili.com/video/av81263778) | 同方 GK5CN6X/GK5CN5X 通用模具 |
| 炫龙毒刺x6 | [链接](https://github.com/JS1993/Shinelon-X6-EFI) |  | |
| 炫龙 T3TI | [链接](https://github.com/283330601/shinelon-t3ti-Hackintosh) |  | 9750H+1660TI |
| 炫龙 DC2/DD2      | [链接](https://github.com/bavelee/DC2_Hackintosh)  [链接DC2_DD](https://github.com/yuedashen88/DC2_EFI)          | [链接](https://bavelee.cn/index.php/archives/60/)            |  yuedashen88基于大佬BaveLee之前的EFI的修改版本,修复了HDMI热插拔问题                 |


#### XiaoMi 小米

| 机型名称           | 发布地址                                                     | 教程地址                                                     | 备注                                           |
| ------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ---------------------------------------------- |
| XiaoMi Air 2019    | [链接](https://github.com/szpinc/Hacintosh_MiBookAir13.3_i5-8250U_with_10.13.5)|
| XiaoMi Air         | [链接](https://github.com/billhhh/MiAir-Hackintosh)          | [链接](https://github.com/billhhh/MiAir-Hackintosh/blob/master/README.md) | XiaoMiAir_i7 7500u                             |
| XiaoMi Air         | [链接](https://github.com/johnnync13/Xiaomi-Mi-Air)          | [链接](https://github.com/johnnync13/Xiaomi-Mi-Air/blob/master/README.md) | 小米 Air                                       |
| XiaoMi Air         | [链接](https://github.com/ourfor/Mibook-air)                 | [链接](https://github.com/ourfor/Mibook-air/blob/master/README.md) | 小米 Air                                       |
| XiaoMi Air         | [链接](https://github.com/whtiehack/XiaoMi-Air)              |                                                              |                                                |
| XiaoMi Air         | [链接](https://github.com/johnnync13/Xiaomi-Notebook-Air-6200u) | [链接](https://github.com/johnnync13/Xiaomi-Notebook-Air-6200u/blob/master/README.md) | 小米 Notebook Air                              |
| XiaoMi Air         | [链接](https://github.com/whtiehack/XiaoMi-Air)              | [链接](https://github.com/whtiehack/XiaoMi-Air/blob/master/README.md) | XiaoMi NoteBook Air                            |
| XiaoMi Air 1gen    | [链接](https://github.com/johnnync13/Xiaomi-Notebook-Air-1Gen) |                                                              | 这哥们应该是忠实的米粉，<br />有兴趣的多多关注 |
| XiaoMi Air Skylake | [链接](https://github.com/johnnync13/EFI_XIAOMI_NOTEBOOK_AIR_SKYLAKE) | [链接](https://github.com/johnnync13/EFI_XIAOMI_NOTEBOOK_AIR_SKYLAKE/blob/master/README.md) |                                                |
| XiaoMi Air Kabylake | [链接](https://github.com/jasper-wan/Xiaomi-Air-i5-7200U) |                                                    | Xiaomi Notebook Air 13.3 i5-7200U 指纹版 |
| XiaoMi Gaming      | [链接](https://github.com/johnnync13/XiaomiGaming)           |                                                              | 额，小米游戏本                                 |
| XiaoMi Pro 系列    | [链接](https://github.com/daliansky/XiaoMi-Pro/releases)              | [链接](https://blog.daliansky.net/MacOS-installation-tutorial-XiaoMi-Pro-installation-process-records.html)         | 小米 Pro 系列                                  |
| XiaoMi Ruby 15.6   | [链接](https://github.com/Jxh98/XiaoMi-Ruby-15.6-2019) [小米ruby2019集显版](https://github.com/XenOriginal/XiaoMi-Ruby-15.6-UMA-only)      |                                                              | 目前ALC256声卡外放无法驱动<br />网卡推荐：[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html) |
| XiaoMi 游戏本 8 代 | [链接](https://github.com/daliansky/XiaoMi-GLP)              |                                                              | 小米游戏本，猜的                               |
| XiaoMi Air    |[链接](https://github.com/hevervie/Hackintosh_XIAOMI_AIR-13.3)   |     |喜欢买小米的，自己区分去吧，我是分不清楚了     |
| XiaoMi Air      |[链接](https://github.com/wilsonnkwan/Hackintosh-Xiaomi-Air-13.3-2018-Catalina)      |     |     |
| 红米redmibook mx250    |[链接](https://github.com/dbv/redmibook_hackintsh_EFI)      |     |     |


#### Intel 英特尔

| 机型名称                                            | 发布地址                                                     | 教程地址                                                     | 备注                                                |
| --------------------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | --------------------------------------------------- |
| Intel DH67GD, DH67BL, <br />DH67CF, DH67CL 系列主板 | [链接](https://github.com/RehabMan/Intel-DH67XX-DSDT-Patch)  | [链接](https://www.tonymacx86.com/threads/guide-intel-dh67xx-with-hd3000-using-clover-uefi-hotpatch.233257/) | Intel DH67GD, DH67BL, <br />DH67CF, DH67CL 系列主板 |
| Intel NUC 5、6、7、8 系列                           | [链接](https://github.com/RehabMan/Intel-NUC-DSDT-Patch)     | [链接](https://www.tonymacx86.com/threads/guide-intel-kaby-lake-nuc7-using-clover-uefi-nuc7i7bnh-nuc7i5bnk-nuc7i3bnh-etc.261711/) | mini 主机                                           |
| NUC8I5BEH                                           | [链接](https://github.com/dongyubin/nuc8i5beh)               | [链接](https://chengxuxiaohei.cn/mac-anzhuang.html) [链接](https://osy.gitbook.io/hac-mini-guide/) |                                                     |
| NUC8i7BEH                                           | [链接](https://github.com/sarkrui/NUC8i7BEH-Hackintosh-Build)[链接](https://github.com/wilsonnkwan/Hackintosh-NUC8i7BEH-Catalina) | [链接](https://osy.gitbook.io/hac-mini-guide/)               |                                                     |
| NUC7i7BNH                                           | [链接](https://github.com/calebchow9/Intel-NUC7i7BNH-Hackintosh) |                                                              |                                                     |
| NUC7i5BEK                                           | [链接](https://github.com/331296441/NUC7i5BEK)               |                                                              |                                                     |
| Surface Pro 3                                       | [链接](https://github.com/hacker1024/Hackintosh-Clover-SurfacePro3) |                                                              |                                                     |
| Surface Pro 4                                       | [链接](https://github.com/Neil-Steven/SurfacePro4-Hackintosh) [链接](https://github.com/bigsadan/surface-pro-4-hackintosh-10.14.3) | [链接](https://github.com/Neil-Steven/SurfacePro4-Hackintosh/blob/master/README.md) | surfacePro 4                                        |
| Surface Pro 6                                       | [链接](https://github.com/molie34/Surface-Pro-6-macOS)       | [教程](https://github.com/molie34/Surface-Pro-6-macOS)       |                                                     |
| 技嘉 GB-BXi5H-4200 系列主板                         | [链接](https://github.com/RehabMan/Gigabyte-BRIX-s-DSDT-Patch) | [链接](https://www.tonymacx86.com/threads/guide-gigabyte-brix-using-clover-uefi-gb-bxi5h-4200-gb-bxi5-4570r-gb-bxi7-4770r.261710/) | 技嘉 GB-BXi5H-4200 系列主板                         |

#### Other 其它

| 机型名称                           | 发布地址                                                     | 教程地址                                                     | 备注              |
| ---------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ----------------- |
| Clevo P950HR                       | [链接](https://github.com/MegaCookie/Clevo-P950HR-Hackintosh) |                                                              | 蓝天 P950HR，猜的 |
| 火影地狱火X6                       | [链接](https://github.com/gaofeicm/DiYuHuo-X6-MacOS-Mojave-10.14.3-Hackintosh) |                                                              |                   |
| 炫龙毒刺x6 | [链接](https://github.com/JS1993/Shinelon-X6-EFI) | | |
| Thunderobot 911 Air | [链接](https://github.com/athlonreg/Thunderobot-911-Air-i7-9750h) | | |
| Thunderobot 911 Air2      |[链接](https://github.com/athlonreg/Thunderobot-911-Air-i7-9750h)        |       |      |
| 雷神笔记本黑苹果套件 | [链接](https://github.com/athlonreg/Thunderobot-Hackintosh) | | |
| Airbook | [链接](https://github.com/nabaonan/airbook-6200u-efi) | | |
| 同方 GI5CN5E | [链接](https://github.com/rodgomesc/AVELL-G1513-FOX-7-TONG-FANG-GI5CN5E-HACKINTOSH) | | |
| Razer Blade Stealth 雷蛇灵刃潜行版 | [链接](https://github.com/widmonstertony/razer-blade-stealth-hackintosh) |                                                              |                   |
| Razer Blade 15 Base Model | [链接](https://github.com/DocSystem/razerbladehackintosh) | | |
| 三星Samsung NP300E4C               | [链接](https://github.com/installgento0/NP300E4C-hackintosh) |                                                              |                   |
| 三星Samsung NP300E5L | [链接](https://github.com/bearkfear/SAMSUNG-NP300E5L-HACKINTOSH) | | |
| 三星Samsung NP300E5M | [链接](https://github.com/zb2947244682/Samsung_300E5M_Mac_Hackintosh_EFI) | | |
| GPD P2 MAX | [链接](https://github.com/Azkali/GPD-P2-MAX-Hackintosh) | | |
| 微星准系统ProBox23  | [链接]( https://github.com/Twilightlee/MSI_ProBox23_hackintosh) |                    |                |
| Razer_Blade_Advanced_early_2019  | [链接]( https://github.com/stonevil/Razer_Blade_Advanced_early_2019_Hackintosh) |                    | [链接](https://github.com/stonevil/Razer_Blade_Advanced_early_2019_Hackintosh)               |
| MaiBenBen_Damai5 | [链接](https://github.com/jasminebd/MaiBenBen-Damai5) | | 麦本本-大麦5 |
| Sony VAIO pro13 | [链接](https://github.com/raydoom/hackintosh-sony-vaio-pro13) | |  |
| toshiba-B654L |[链接](https://github.com/yxb2018/toshiba-B654L-clover-efi) | |  |
| Terrans Force/Devil Rays  DR7 |[链接](https://github.com/Jie2GG/Hackintosh-Devil-Rays-DR7) | | 未来人类 |
| toshiba-C805 |[链接](https://github.com/nan1jueze/TOSHIBA-C805-HM76-CLOVER-Hackintosh)| |  |



#### 笔记本更多的机型

| 机型名称     | 发布地址                                 | 教程地址 | 备注                                                         |
| ------------ | ---------------------------------------- | -------- | ------------------------------------------------------------ |
| **更多机型** | [链接](https://github.com/sqlsec/clover) |          | 引用自：国光之前维护的仓库                                   |
|              | [链接](https://zhih.me/hackintosh/#/)    |          | 底噪出品：**[one-key-hidpi](https://github.com/xzhih/one-key-hidpi)** |

#### 笔记本相关资源

| **笔记本相关资源**   |                                                            |                                                              |                                                              |
| -------------------- | ---------------------------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
|                      | **hotpatch**                                               |                                                              |                                                              |
| P-little             | [链接](https://github.com/daliansky/P-little)              | `Clover` 部件热修复(hotpatch)                                | 宪武做的一套 ThinkPad 补丁，刚开始上传，请期待               |
| OC-little            | [链接](https://github.com/daliansky/OC-little)             | `OpenCore` 部件热修复(hotpatch)                              | 感谢：@宪武                                                  |
|                      | **触摸板**                                                 |                                                              |                                                              |
| VoodooI2C-PreRelease | [链接](https://github.com/williambj1/VoodooI2C-PreRelease) | [触摸设备 DSDT 修补补充](https://github.com/williambj1/VoodooI2C-PreRelease/blob/master/%E8%A7%A6%E6%91%B8%E6%9D%BF%E8%A1%A5%E5%85%85.md) | [Bat.bat](https://github.com/williambj1)搞的                 |
| GenI2C               | [link](https://github.com/williambj1/GenI2C)               | 生成SSDT触摸板的热修复补丁(hotpatch)，以便支持`VoodooI2C`    |                                                              |
|                      | **无线网卡**                                               |                                                              |                                                              |
| 推荐无线网卡         | **MiniPCIe** 接口(推荐 BCM4352HMB、DW1510)                 | **博通**：BCM94322HM8L、Asus BCM94352、AzureWave AW-CE123H、AzureWave AW-NB290H、DW1510、DW1520、DW1550、 | **高通**：DW1515、DW1705、AR5BHB92、AR5BHB112 AR9285 芯片在 10.14 将不再被支持 |
|                      | **PCIe** 接口                                              | **博通**：BCM94331CD、BCM94322MC、BCM94360CD                 | **高通**：AR5BXB72、AR5BXB92、AR5BXB112                      |
|                      | **M.2** 接口                                               | **博通**：BCM94352Z(AE)、DW1560，DW1830<br />BCM94350Z(AE)/[DW1820A](https://blog.daliansky.net/DW1820A_BCM94350ZAE-driver-inserts-the-correct-posture.html) |                                                              |
|                      | **USB** 无线网卡                                           | RealTek系列                                                  | [链接](https://github.com/chris1111/Wireless-USB-Adapter-Clover) |

### 台式机

| **台式（部分）**               | 发布地址                                                     | 教程地址                                                     | 备注                                            |
| ------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ----------------------------------------------- |
| **AMD Ryzen CPU**              |                                                              |                                                              |                                                 |
| AMD Ryzen 7 1700x or 3700x<br />MSI X370 Krait Gaming or ASROCK X570 Taichi<br />RX Vega64 | [链接](https://github.com/yhl452493373/ryzen-hackintosh-efi) |  | 10.14.6 |
| R7 3700x/MSI B450/5700XT | [链接](https://github.com/harpsword/hackintosh-ryzen) | |  |
| AMD Ryzen安装教程              | [链接](https://github.com/MrNegativeTW/Ryzen-Hackintosh-Tutorial) [链接](https://github.com/doesprintfwork/Intel-AMD-Hackintosh-Guide) | [链接](https://kb.hackintoshisfun.ml/vanilla/v/traditional-chinese/) [链接](https://mtwstudio.gitbook.io/ryzentosh/) | 适用于`10.12` `10.13` `10.14` |
| AMD FX 6300/NVIDIA GTX 650     | [链接](https://github.com/pexcn/hackintosh-amd)              |                                                              | 主板：Asus M5A97 LE R2.0                        |
| MSI B350M Gaming Pro           | [链接](https://github.com/nghuunghiaa111/Hackintosh-IMac)    |                                                              | AMD Ryzen 5 1400<br />MSI RX580 8GB Armor       |
| MSI MEG X570 ACE | [链接](https://github.com/vaasheim1995/AMD-MSI-MEG-X570-ACE-Hackintosh) | |  |
| AMD Ryzen 1700/Asus B350 Plus  | [链接](https://github.com/mikigal/ryzen-hackintosh)          |                                                              | MSI GTX 1080 Gaming X                           |
| AMD Vanilla Clover Patches | [链接](https://github.com/AMD-OSX/AMD_Vanilla) | [链接](https://github.com/cheneyveron/hackintosh-clover-tachi-x370-1700x-rx570) | AMD Clover补丁，以后可以<br />直接刻盘安装，10.14.5我会同步<br />更新针对AMD平台的配置文件<br />敬请期待 |
| Clover-Ryzen-MSI-B450I | [链接](https://github.com/portrayer/Clover-Ryzen-MSI-B450I) |  |  |
|  |  |  |  |
| **INTEL CPU**                  |                                                              |                                                              |                                                 |
| INTEL安装教程 | [链接](https://github.com/doesprintfwork/Intel-AMD-Hackintosh-Guide) | | |
| ASRock  deskmini 110           | [链接](https://github.com/suxiaogang/asrock-deskmini-110-hackintosh) |                                                              |                                                 |
| Asrock deskmini 310            | [链接](https://github.com/liminghuang/asrock_deskmini310_hackintosh) |                                                              |                                                 |
| ASRock B360M-HDV | [链接](https://github.com/RealKiro/Hackintosh) | | |
| ASRock Z370 Pro4 | [链接](https://github.com/athlonreg/ASRock-Z370-Pro4-Hackintosh) | | [套路](https://github.com/athlonreg) 自用机型 |
| ASRock Z370M ITX-AC | [链接](https://github.com/youngle316/ASRock-Z370M-ITX-AC) | |  |
| ASRock Z370M Pro4              | [链接](https://github.com/HouCoder/asrock-z370m-pro4-hackintosh) [链接](https://github.com/ljllili23/Hackintosh) | [链接](https://github.com/HouCoder/asrock-z370m-pro4-hackintosh/blob/master/README.md) |                                                 |
| ASRock Z370 Gaming             | [链接](https://github.com/fangf2018/ASRock-Z370-Gaming-ITX-ac-hackintosh) | [链接](https://github.com/fangf2018/ASRock-Z370-Gaming-ITX-ac-hackintosh/blob/master/README.md) | I7-8700k/RX570                                  |
| ASRock Z370 Gaming ITX-ac | [链接](https://github.com/fangf2018/ASRock-Z370-Gaming-ITX-ac-hackintosh) |  |  |
| ASRock Z390M Pro4 mATX | [link](https://github.com/sarkrui/Z390MPro4-i7-9700K-Hackintosh) | | i7-9700K + Sapphire RX580 Nitro+ 8G |
| ASRock Z390 Phantom Gaming itx | [链接](https://github.com/zanderzhng/EFI_Asrock_Z390_Phantom_ITX_OC)  [链接](https://github.com/icyleaf/EFI-ASRock-Z390-Phantom-Gaming-ITX) [链接](https://github.com/bydavy/EFI-ASRock-Z390-Phantom-Gaming) <br />[链接](https://github.com/kcunanan/Jared-PC/) [链接](https://github.com/befuture/EFI-ASRock-Z390-Phantom-Gaming) |                                                              | 华擎 Z390 Phantom Gaming itx/ac                 |
| ASRock Z390 Phantom Gaming itx | [链接](https://github.com/icyleaf/EFI-ASRock-Z390-Phantom-Gaming-ITX) [链接](https://github.com/bydavy/EFI-ASRock-Z390-Phantom-Gaming) <br />[链接](https://github.com/kcunanan/Jared-PC/) [链接](https://github.com/befuture/EFI-ASRock-Z390-Phantom-Gaming) |                                                              | 华擎 Z390 Phantom Gaming itx/ac                 |
| Asrock Z390 Phantom ITX | [链接](https://github.com/zanderzhng/EFI_Asrock_Z390_Phantom_ITX) | |  |
| Asus TUF B360M-PLUS-S | [链接](https://github.com/Zerah64/hackintosh_9400f_b360_vega56) | |  |
| ASUS Z97K 4980HQ               | [链接](https://github.com/efsg/ASUS-Z97K-4980HQ-Hackintosh)  |                                                              | I7-4980HQ                                       |
| Asus Z170-P                    | [链接](https://github.com/Sharlion/z170_6700k_hackintosh)    |                                                              | 华硕Z170-P+6700K+RX470                          |
| Asus ROG STRIX H370-I GAMING   | [链接](https://github.com/Autocrit/Asus-ROG-STRIX-H370-I-GAMING-Hackintosh-Guide) |                                                              | mini-ITX H370 motherboard                       |
| Asus STRIX Z270-E              | [链接](https://github.com/BradenM/Hackintosh-7700k-R9_390-iGPU) |                                                              | Asus STRIX Z270-E                               |
| Asus ROG Strix Z390-E          | [链接](https://github.com/xiedonghang/hackintosh)            |                                                              | Intel i9-9900k+UHD630核显                       |
| Asus Prime Z390m plus | [链接](https://github.com/Asphyxia-m/Asus-Z390m-plus-efi) | | OC |
| ASUS X299 PRIME DELUXE II | [链接](https://github.com/yifan-gu/hackintosh) | | i9 7980XE + Radeon VII |
| Asus X299 | [链接](https://github.com/shinoki7/Asus-X299-Hackintosh) | |  |
| Asus ROG STRIX X299-E GAMING | [链接](https://github.com/Fansaly/X299-STRIX-macOS) | | INTEL® CORE™ i7-7800X |
| CM238 i7-8950H UHD630 ALC269   | [链接](https://github.com/kkzzhizhou/S200H_I7-8750H_Hackintosh) |                                                              | S200H_I7-8750H 小主机                           |
| Dell OptiPlex 3050             | [链接](https://github.com/Leif160519/Dell-OptiPlex-3050-EFI) |                                                              |                                                 |
| Dell OptiPlex 9020M            | [链接](https://github.com/mingcheng/dell-optiplex-9020m-hackintosh) [链接](https://github.com/JimLee1996/Hackintosh_OptiPlex_9020)<br /> [链接](https://github.com/W-MS/OptiPlex-9020-Catalina) |                                                              | Disable MSR 0xE2 (i.e. cfg lock) `setup_var 0xDA2 0x00`<br /> Increase DVMT to 96M `setup_var 0x263 0x03`<br /> 链接3支持Catalina |
| Dell OptiPlex 7060<br />Dell OptiPlex 7070    |[链接](https://github.com/W-MS/OptiPlex-7060and7070-Catalina)        |       |       Increase DVMT to 64M `setup_var 0x8DC 0x2` ，不支持96M模式，<br />切勿使用0x3或在其他型号使用此命令。支持Catalina。 |
| Dell Precision Tower 3620 | [链接](https://github.com/fivestrong/Hackintosh-Dell-Precision-T-3620) | |  |
| Lenovo M93P           | [链接](https://github.com/mingcheng/lenovo-thinkcentre-m93p-hackintosh) |      | 联想 M93P 系列主机 |
| Lenovo ThinkCentre M4500q | [链接](https://github.com/samawong/hackintosh-clover-configure-for-lenovo-m4500q-n000-model) | |  |
| Lenovo ThinkCentre M720Q | [链接](https://github.com/fronttang/Lenovo-ThinkCentre-M720Q-Hackintosh) | |  |
| B360 AORUS Gaming 3 | [链接](https://github.com/littlegtplr/Hackintosh-Clover-folder-for-Coffee-Lake-builds) | |  |
| Gigabyte X370N                 | [链接](https://github.com/cwr31/z370n-hackintosh) [链接](https://github.com/qinkangdeid/z370n-wifi-hackintosh) |                                                              | Gigabyte Z370N                                  |
| DQ77KB                         | [链接](https://github.com/siwilizhao/DQ77KB-I7-3770S-Hackintosh) |                                                              |                                                 |
| Gigabyte Z270X-UG              | [链接](https://github.com/icedterminal/ga-z270x-ug)          | [链接](https://github.com/icedterminal/ga-z270x-ug/blob/master/README.md) |                                                 |
| Gigabyte Z370N WIFI            | [链接](https://github.com/b166ar/Mac-Mini-Killer) [链接](https://github.com/yangbe/z370n-wifi-vega64) |                                                              | Mac-Mini-Killer<br />Z370N WIFI VEGA64          |
| Gigabyte Z390 AORUS            | [链接](https://github.com/cmer/gigabyte-z390-aorus-master-hackintosh) |                                                              | **备注：**<br />如果不是9900k/9700k/8500/8700k CPU，<br />需要打`Device RTC`补丁 |
| Gigabytes Z390 AORUS ELITE     | [链接](https://github.com/liusming/hackintosh)               |                                                              | I9-9900K/Intel (Z380) HD 630 2G                 |
| Gigabytes Z390 Aorus Pro | [链接](https://github.com/sarkrui/Hackintosh-Z390-Aorus-Pro-9700K-RX580) | | OpenCore/i7-9700K/蓝宝石 RX580 8G |
| Gigabyte Z390 AORUS PRO | [链接](https://pcpartpicker.com/product/L9YLrH/gigabyte-z390-i-aorus-pro-wifi-mini-itx-lga1151-motherboard-z390-i-aorus-pro-wifi) | | WIFI Mini ITX |
| Gigabyte Z390 AORUS PRO WIFI | [链接](https://github.com/shiruken/hackintosh) | | i7-9700K + Radeon RX 5700 XT |
| Gigabyte Z390 Master | [链接](https://github.com/felixyin/clover-z390master-i99900k-rx580-970pro) | |  |
| Gigabyte Z390 M Gaming | [链接](https://github.com/tspng/gigabyte-z390-m-gaming-hackintosh) | | 技嘉 Z390m |
| Gigabyte Z390 Ultra           | [链接](https://github.com/mrpaulphan/gigabyte-z390-ultra-master-hackintosh) |                                                              |                                                 |
| Gigabyte Z390-UD | [链接](https://github.com/kong-git/Z390-OC-UHD630) [链接](https://github.com/kong-git/Z390-UD-RX580) | | OpenCore 核显/RX580独显 |
| Gigabyte B365M Aorus Elite | [链接](https://github.com/ChuanfengZhang/Gigabyte-B365M-UHD630-Clover) | | Gigabyte B365M i5-9400 UHD630 Clover config |
| Lenovo ThinkCentre e 73 | [链接](https://github.com/riku2015/Efi-files-for-lenovo-e73) | | |
| Lenovo M73 Tiny                | [链接](https://github.com/rehandalal/m73-tiny-hackintosh)    |                                                              |                                                 |
| Huanan X79 E5-2670, GTX650     | [链接](https://github.com/cheneyveron/clover-x79-e5-2670-gtx650) | [链接](https://github.com/cheneyveron/clover-x79-e5-2670-gtx650/blob/master/README.md) | 华南 x79 V2                                     |
| HP Elitedesk G3 | [链接](https://github.com/lavjamanxd/hp-elitedesk-g3-hackintosh) |  |  |
| HP Z420 | [链接](https://github.com/yansheng1003/Hackintosh) | | E5 1650v2 |
| HP Z600 Workstation            | [链接](https://github.com/lutzmor/hp_z600_hackintosh)        |                                                              | Mac-Mini-Killer                                 |
| MSI B360                       | [链接](https://github.com/SuperNG6/MSI-b360-10.14.4-EFI)     |                                                              | 也适用于<br />MAG Z390 TOMAHAWK <br />(MS-7B18) |
| msi-b360m-i3-8100-rx570 | [链接](https://github.com/shm007g/hackintosh-msi-b360m-i3-8100-rx570) | |  |
| MSI Z370-A                     | [链接](https://github.com/daliansky/Z370-Hackintosh)         | [链接](https://github.com/daliansky/Z370-Hackintosh)         | 黑果小兵MSI Z370-A自用EFI                       |
| MSI-MPG-Z390-Gaming-EDGE-AC  | [链接](https://github.com/fnoopv/MSI-Z390-Gaming-Edge-AC_OC) |   |  微星MPG-Z390-Gaming-Edge-ac OpenCore EFI |
| ASRock-Z370-Gaming-ITX-ac-hackintosh  | [链接](https://github.com/fangf2018/ASRock-Z370-Gaming-ITX-ac-hackintosh) |   |   |
| Gigabyte-Z390M  |[链接](https://github.com/xxiaofeng132/Gigabyte-Z390M-Gaming-Hackintosh)  |  |技嘉Z390m-gaming |
| ASUS-PRIME-Z390 |[链接](https://github.com/dhckdgjs/ASUS-PRIME-Z390-A-HACKINTOSH-Clover-iGPU-with-dGPU-UHD630-RX580)  |  |ASUS-PRIME-Z390 |
| GA-Z77P-D3 |[链接](https://github.com/cloverkits/GA-Z77P-D3-EFI)  |  |GA-Z77P-D3 |
| Deskmini-310 |[链接](https://github.com/yuqi/Deskmini-310-Hackintosh)  |  |Deskmini-310 |
| GA-B360M-D3H |[链接](https://github.com/laelsirus/GA-B360M-D3H-with-UHD630-iGPU-AMD-dGPU-CLOVER)  |  |GA-B360M-D3H |
| 技嘉B360M DS3H |[链接](https://github.com/sqlsec/B360M-DS3H-I5-9600KF-RX580-CLOVER) | |国光自用：i5-9600KF RX580 |
| 技嘉z390 gaming|[链接](https://github.com/dbv/hackintosh_9600k_Z390_RX580) | 小辉自用: i5-9600k RX580 2304sp矿 |
| GA B360m d2v |[链接](https://github.com/Matchas-xiaobin/EFI-B360m_d2v_dvi_uhd630) | |技嘉B360m，支持DVI输出 |
| Soarsea mini PC |[链接](https://github.com/EngLearnsh/Soarsea-i9-8950HK-Hackintosh) | | S200H |
| MSI-B360M-MORTAR-IMACPRO |[链接](https://github.com/andot/MSI-B360M-MORTAR-IMACPRO-EFI) | | |
| ASRock B360M Pro4 |[链接](https://github.com/Joehaivo/hackintosh) | | |
| Lenovo Thinkpad P1 <br />MobileWorkStation |[链接](https://github.com/p455555555/Thinkpad-P1-EFI) | | |
| z370m mortar i7-9700k|[链接](https://github.com/JackyCZJ/Z370M-MORTAR-I7-9700K-M9PEG-CLOVER) | | |
| Gigabyte Z370-HD3P|[链接](https://github.com/kinoute/Hack-Z370-HD3P-i5-8400) | | |
| I7-8850H迷你主机 |[链接](https://github.com/n0jack/i78850h-minipc-hackintosh) | | |
| MSI-B360M-MORTAR OpenCore |[链接](https://github.com/GeQ1an/MSI-B360M-MORTAR-HACKINTOSH-OPENCORE-EFI) | [链接](https://github.com/GeQ1an/MSI-B360M-MORTAR-HACKINTOSH-OPENCORE-EFI/blob/master/README.md) | 使用 iMac19,1 机型，默认启用全部 USB，适合使用微星 b360m 迫击炮（钛金版）主板的用户，详见使用说明 |

#### 台式机其它机型

| 机型名称     | 发布地址                                 | 教程地址 | 备注                                                         |
| ------------ | ---------------------------------------- | -------- | ------------------------------------------------------------ |
| **更多机型** | [链接](https://github.com/sqlsec/clover) |          | 引用自：国光之前维护的仓库                                   |
|              | [链接](https://zhih.me/hackintosh/#/)    |          | 底噪出品：**[one-key-hidpi](https://github.com/xzhih/one-key-hidpi)** |
| 耕田男孩维护的几个机型 | [华硕H81-PLUS](https://pan.baidu.com/s/1iWXxUDWBUUlnsuc4COusJQ) [ASUS-Z97](https://pan.baidu.com/s/1QNax08N7BNI1X_Myuaa-XA) [ASUS X299 deluxe](https://pan.baidu.com/s/1JA0UrABdhu4HmM-WuJDWdw) | |

#### 硬件兼容列表

| 机型名称         | 发布地址                                                     | 教程地址 | 备注                                                  |
| ---------------- | ------------------------------------------------------------ | -------- | ----------------------------------------------------- |
| **硬件兼容列表** | [链接](https://github.com/CrazyPegAsus/macOS-Mojave-Compatibility-hardware-list) |          | 感谢: [CrazyPegAsus](https://github.com/CrazyPegAsus) |
| 黑苹果购买指南   | [链接](https://github.com/khronokernel/Anti-Hackintosh-Buyers-Guide) |          | Hackintosh Buyers Guide                               |
| 黑苹果安装学院   | [链接](https://github.com/huangyz0918/Hackintosh-Installer-University) | [链接](https://github.com/huangyz0918/Hackintosh-Installer-University/blob/master/README-CN.md)         | 这个和本repo功能类似，既然作者开放了，我们也可以收录补充                               |
| 黑苹果互助项目    |[链接](https://github.com/bessyjl/HackintoshClover)  |  |和本repo类似  |

### 其它机型请提交到[这里](https://github.com/daliansky/Hackintosh) 

## QQ群列表：

688324116 [一起黑苹果](http://shang.qq.com/wpa/qunwpa?idkey=6bf69a6f4b983dce94ab42e439f02195dfd19a1601522c10ad41f4df97e0da82) 2000人群 已满

331686786 [一起吃苹果](http://shang.qq.com/wpa/qunwpa?idkey=db511a29e856f37cbb871108ffa77a6e79dde47e491b8f2c8d8fe4d3c310de91) 2000人群 尚有空位

257995340 [一起啃苹果](http://shang.qq.com/wpa/qunwpa?idkey=8a63c51acb2bb80184d788b9f419ffcc33aa1ed2080132c82173a3d881625be8) 2000人群 远景报备群

891434070 [Mojave黑苹果交流群](http://shang.qq.com/wpa/qunwpa?idkey=be06e4c13e796e06a5cd3151d7fcc8f2feee8f9b68b1620ce8771111e2822084) 2000人群 远景报备群

939122730 [Mojave黑苹果交流II群](http://shang.qq.com/wpa/qunwpa?idkey=e7fb8ea793aee10f9e86c70cd134867bde4183cc3eb87424e61e50b3e9cabf72) 2000人群

891677227 [黑果小兵高级群](http://shang.qq.com/wpa/qunwpa?idkey=9a1eaa552c45d736bb6b19d82ad80e76bf82729f1c1a975b437aa3858473231d) 2000人群 尚有空位

943307869 [黑果小兵高级群II](http://shang.qq.com/wpa/qunwpa?idkey=7080e6ff936fd2e207439ea18c0a34b4651db81ff45d0edf27b34a21a037871e) 2000人群 新开群，欢迎踊跃加入

943181023 [联想小新Air黑苹果交流群](http://shang.qq.com/wpa/qunwpa?idkey=fb772a7e01436d43e1d856a099549551952bb08161ced4a8fc08b4e75e7ab438) 500人群 非专用机型请勿加入

43518833  [Mac for HP](https://shang.qq.com/wpa/qunwpa?idkey=739faedadd025d72310a48effa168a797bd7407520f5264560f45fc611e601d0) 1000人群 惠普商务机EFI交流共享（推荐）

612655811 [elitebook_probook_zbook系列黑苹果交流](https://shang.qq.com/wpa/qunwpa?idkey=5f91e85dc300cc5da20324401b23236cdeb9a0e5ebee5944fa8811ff0d5e4e36) 此群已散，勿加，有需要可以加上一个群。

308469644 [外星人Alienware黑苹果交流群](https://shang.qq.com/wpa/qunwpa?idkey=9f579e157ffed2a47be3861601080953453be323e50844005e9f2466dd2b12c5) 500人群 非专用机型请勿加入

## 微信公众号：【`黑果小兵的部落阁`】

![WeChat](http://7.daliansky.net/WeChat/WeChat.png)

## 关于打赏

如果您认可我的工作，请通过打赏支持我后续的更新

| paypal                                                       | 微信                                                       | 支付宝                                               |
| ------------------------------------------------------------ | ---------------------------------------------------------- | ---------------------------------------------------- |
| [![paypal_daliansky](http://7.daliansky.net/paypal_daliansky.png)](https://www.paypal.me/daliansky) | ![wechatpay_160](http://7.daliansky.net/wechatpay_160.jpg) | ![alipay_160](http://7.daliansky.net/alipay_160.jpg) |

[![img](https://img.shields.io/github/stars/daliansky/Hackintosh.svg?color=ff69b4&label=%E7%82%B9%E8%B5%9E&logoColor=ff69b4&style=social)](https://github.com/daliansky/Hackintosh) [![img](https://img.shields.io/github/followers/daliansky.svg?label=%E7%B2%89%E4%B8%9D&logoColor=success&style=social)](https://github.com/daliansky/Hackintosh) ![img](https://img.shields.io/github/contributors/daliansky/Hackintosh.svg?color=red&label=%E8%B4%A1%E7%8C%AE%E4%BA%BA%E6%95%B0) [![img](https://img.shields.io/github/last-commit/daliansky/Hackintosh.svg?color=orange&label=%E6%9C%80%E8%BF%91%E6%8F%90%E4%BA%A4)](https://github.com/daliansky/Hackintosh) [![img](https://img.shields.io/badge/link-996.icu-red.svg)](https://996.icu/)

 
