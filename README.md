# Hackintosh黑苹果长期维护机型EFI及安装教程整理

[![img](https://img.shields.io/github/stars/daliansky/Hackintosh.svg?color=ff69b4&label=%E7%82%B9%E8%B5%9E&logoColor=ff69b4&style=social)](https://github.com/daliansky/Hackintosh) [![img](https://img.shields.io/github/followers/daliansky.svg?label=%E7%B2%89%E4%B8%9D&logoColor=success&style=social)](https://github.com/daliansky/Hackintosh) ![img](https://img.shields.io/github/contributors/daliansky/Hackintosh.svg?color=red&label=%E8%B4%A1%E7%8C%AE%E4%BA%BA%E6%95%B0) [![img](https://img.shields.io/github/last-commit/daliansky/Hackintosh.svg?color=orange&label=%E6%9C%80%E8%BF%91%E6%8F%90%E4%BA%A4)](https://github.com/daliansky/Hackintosh) [![img](https://img.shields.io/badge/link-996.icu-red.svg)](https://996.icu/) 

## 黑苹果长期维护机型整理 by @[我意](https://github.com/y010204025)

> 整理这份清单的目的：在于给想体验黑苹果的人一个方向，也想减少大家重复造轮子，节约大家的时间。      
> 所有文件均归属于原作者，本清单只列出链接。如果您不希望你的链接被这份清单收录，请发送邮件到 [y010204025@126.com](mailto:y010204025@126.com),我将移除链接      
> 清单收录了 4 个月以内的有人长期维护并更新过 EFI 的机型链接，如果有新的链接希望收录到这份清单，请发送邮件到 [y010204025@126.com](mailto:y010204025@126.com)       
> 致谢：感谢一直为黑苹果进行开发的各位开发者和愿意共享出 EFI 文件的开发者，谢谢！     
> 最近有好几个人发邮件，请求适配机型。

  * 建议大家使用[yandex搜索引擎](https://yandex.ru)、[github](https://github.com)先搜索下有没有自己的机型，型号一样，机型配置有差异可以忽略，使用你的机器型号+clover、型号+EFI、型号+mac、型号+Hackintosh等进行搜索。例如我最近更新了 elitebook840g3、840g4等几个机型的 EFI，就可以使用840g3+clover 840g3+EFI 等关键词进行搜索。

  * 黑苹果论坛：

       * **国内** [远景论坛](http://bbs.pcbeta.com)、[威锋论坛](http://bbs.feng.com)
     * **国外** [insanelymac 论坛](https://www.insanelymac.com/forum/)、[tonymacx86论坛](https://www.tonymacx86.com/)、[德国黑苹果论坛](https://www.hackintosh-forum.de/)、[俄罗斯黑苹果论坛](https://www.applelife.ru)、[法国黑苹果论坛](https://www.hackintosh-montreal.com)、 [osxlatitude论坛](https://osxlatitude.com/forums/)

* 一些黑苹果常用的软件或者驱动开发者的主页，希望大家能及时更新驱动和软件，驱动需要自己去对应驱动开发者的主页去更新。
  
  * *[RehabMan](https://bitbucket.org/RehabMan/)* 维护了很多黑苹果驱动和相关补丁
  * *[Vit9696](https://github.com/acidanthera)* lilu和相关插件、applealc的主要开发或维护者
  * *[Clover更新地址](https://sourceforge.net/projects/cloverefiboot/)* Clover团队更新 clover的主要发佈渠道
* *[常用软件和驱动清单](./LinkList.md)* 整理了常用软件和驱动的主要发佈地址，持续修改……
  
   

 *关于黑苹果，希望大家能摆正心态，容忍小问题的存在，某些功能无法实现或者是体验不好「触摸板、指点杆、触摸屏、雷电端口等等」，系统运行不稳定，容易卡机或者死机或者是开机不认引导、升级系统失败等都属于正常现象。 **每次升级前请先从各种驱动了解本次升级有没有大的改动，在升级前首先升级 Clover 和相关的 kext 驱动，需要添加补丁或者是更新补丁的请做好相关工作，不要等著出了问题再去寻找解决方案。** 在自己遇到问题的时候，请先通过网络寻找解决办法，无法解决再询问别人，请别人帮忙解决问题的时候，首先端正自己的态度，把问题描述清楚，能提供 log 日志或者是相关文件的先提供文件，提供不了文件的拍照拍清楚。*

**解决问题，需要努力的是自己，不是让别人帮你努力；帮你解答是情分，不是义务**

   

### 同步更新：[黑果小兵的部落阁](<https://blog.daliansky.net/Hackintosh-long-term-maintenance-model-checklist.html>)

### 机型讨论：[远景pcbeta.com](<http://bbs.pcbeta.com/viewthread-1795904-1-1.html>)



更新日期：

- 2018 年 10 月 06 日
- 2018 年 12 月 25 日
- 2019 年 01 月 15 日
- 2019 年 3 月 1 日 by 黑果小兵
  - 按机型重新排版
  - 将该文档上传到仓库，方便其它人提交合并，共同维护
- 2019年4月2日
  - 添加部分新机型
  - 将多于2个机型的品牌独立出来，方便检索
- 2019年5月9日
  - 新增机型：`Mechrevo X9Ti R` / `Mechrevo Z2 G` 等
- 2019年5月10日 by [明城](https://github.com/mingcheng)
  - 新增机型：`Lenovo M93P` / `Dell 9020m` 等机型


### 笔记本部分机型

#### Acer 宏碁

| 机型名称                | 发布地址                                                     | 教程地址                                                     | 备注                |
| ----------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------- |
| Acer Aspire 3 A315-51   | [链接](https://github.com/ZeroInfinityXDA/Acer-A315-51-Hackintosh) |                                                              |                     |
| Acer Aspire A515-51G    | [链接](https://github.com/h-okon/Acer-Aspire-A515-Hackintosh) |                                                              |                     |
| Acer Aspire A515-51G    | [链接](https://github.com/Siddhesh1197/Acer-A515-51G-Hackintosh) | [链接](https://github.com/Siddhesh1197/Acer-A515-51G-Hackintosh/blob/master/README.md) |                     |
| Acer A515-51G-58VH      | [链接](https://github.com/Rodrigmatrix/Acer-A515-51G-58VH)   |                                                              |                     |
| Acer Aspire E1-471G     | [链接](https://github.com/matthew728960/Clover-ACER-E1-471G) | [链接](https://github.com/matthew728960/Clover-ACER-E1-471G/blob/master/README.md) | ACER Aspire E1-471g |
| Acer Aspire E5 475G     | [链接](https://github.com/hilmanshini/Acer-Aspire-E5-475G-Clover-Hackintosh) |                                                              |                     |
| Acer Aspire E5-476G     | [链接](https://github.com/DijaminGila/Hackintosh-Mojave-Acer-E5-476G) [链接](https://github.com/budhilaw/Acer-E5-476G-Hackintosh) |                                                              | i3-6006U            |
| Acer Aspire E5-571-5552 | [链接](https://github.com/GaryDoooo/acer_e51_osx)            |                                                              |                     |
| Acer Aspire E1-571G     | [链接](https://github.com/DiogoSilva48/Acer-E1-571G-Hackintosh) |                                                              |                     |
| Acer Aspire E1-572G     | [链接](https://github.com/TonyStark10006/Acer_E1-572G_Hackintosh_EFI) |                                                              |                     |
| Acer ES1-572-37pz       | [链接](https://github.com/joodrew/hackintosh-acer-es1-572-37pz) |                                                              |                     |
| Acer F5-573G            | [链接](https://github.com/johnnywolinger/ACER-F5-573G-Hackintosh) |                                                              |                     |
| Acer F5-573G-55PJ       | [链接](https://github.com/zoothz/Hackintosh-acer-f5-573g-55pj) |                                                              |                     |
| Acer F5-573g-75A3       | [链接](https://github.com/vinicioslc/HACKINTOSH-ACER-F5-573G-75A3) |                                                              |                     |
| Acer V3-471G            | [链接](https://github.com/oneveb/Acer-V3-471G)               |                                                              |                     |
| Acer-V3-572G-51MR       | [链接](https://github.com/AnoldmanLiSir/Acer-V3-572G-51MR)   | [链接](https://github.com/AnoldmanLiSir/Acer-V3-572G-51MR/blob/master/README.md) |                     |
| Acer V5-572             | [链接](https://github.com/7ack/Acer-V5-572-Hackintosh)       | [链接](https://github.com/7ack/Acer-V5-572-Hackintosh/blob/master/readme.md) |                     |
| Acer Vn7-793g           | [链接](https://github.com/cedric-bour/793g-hackintosh-efi)   |                                                              |                     |

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
| Asus FX504GE                      | [链接](https://github.com/PoomSmart/Asus-FX504GE-Hackintosh) |                                                              |                                                            |
| Asus FX504GE-ES72                 | [链接](https://github.com/MegaStood/Hackintosh-FX504GE-ES72) |                                                              |                                                            |
| Asus FX505GD                      | [链接](https://github.com/kreactnative/hackintosh-mojave-fx505gd) |                                                              | ASUS TUF GAMING FX505GD-BQ071T                             |
| Asus F556U (X556UQK)              | [链接](https://github.com/systemfaliure/Asus-X556UQK-hackintosh#Asus-f556u-x556uqk---high-sierra-hackintosh) | [链接](https://github.com/systemfaliure/Asus-X556UQK-hackintosh/blob/master/README.md) | Asus F556U (X556UQK)                                       |
| Asus FX50J                        | [链接](https://github.com/Xc2333/Hackintosh-Asus-FX50J)      |                                                              |                                                            |
| Asus FX50V                        | [链接](https://github.com/Cyberhan123/Hackintosh-ASUS--FX50V) |                                                              |                                                            |
| Asus FX533VD                      | [链接](https://github.com/kue-kid/Asus-FX533VD-HACKINTOSH)   |                                                              |                                                            |
| Asus GL551JW                      | [链接](https://github.com/zacharyrs/GL551JW-Hackintosh)      |                                                              |                                                            |
| Asus G60VW                        | [链接](https://github.com/PtNan/G60VW-Hackintosh)            |                                                              |                                                            |
| Asus K501LB                       | [链接](https://github.com/ApolloRisky/EFI_Clover-Asus-K501LB-Mojave) |                                                              |                                                            |
| Asus K55VD                        | [链接](https://github.com/southernvevo/Asus-K55VD-HACKINTOSH) | [链接](https://github.com/southernvevo/Asus-K55VD-HACKINTOSH/blob/master/README.md) | Asus K55VD                                                 |
| Asus Laptop N56VZ                 | [链接](https://github.com/signxer/N56VZ-Hackintosh)          |                                                              |                                                            |
| Asus P8P67 PRO                    | [链接](https://github.com/rafaelmaeuer/Asus-P8P67Pro-Hackintosh) | [链接](https://github.com/rafaelmaeuer/Asus-P8P67Pro-Hackintosh/blob/master/readme.md) |                                                            |
| Asus ROG GL552JX                  | [链接](https://github.com/javanesse/Asus-ROG-GL552JX-High-Sierra-10.13-Hackintosh) | [链接](https://github.com/javanesse/Asus-ROG-GL552JX-High-Sierra-10.13-Hackintosh/blob/master/README.md) | Asus ROG GL552JX                                           |
| Asus ROG GL552VX                  | [链接](https://github.com/xuanquydsr/Gl552VX-Mojave)         |                                                              |                                                            |
| Asus ROG GL553VD                  | [链接](https://github.com/MohammadtaghiFarkhondekar/macOS-Mojave-For-Asus-ROG-GL553VD) |                                                              |                                                            |
| Asus ROG Zephyrus S GX531GS       | [链接](https://github.com/williambj1/Hackintosh-EFI-Asus-Zephyrus-S-GX531) |                                                              | 华硕玩家国度冰刃 3                                         |
| ASUS S4000VA                      | [链接](https://github.com/stonexing/Asus-S4000VA8550-Hackintosh) |                                                              | 华硕灵耀 i7-8550U                                          |
| Asus S4100V                       | [链接](https://github.com/loong1992/Asus_S4100VN8250U_Hackintosh) |                                                              |                                                            |
| Asus S530UN                       | [链接](https://github.com/tunglamvghy/AsusS530UN-hackintosh) |                                                              |                                                            |
| Asus TUF Gaming FX504             | [链接](https://github.com/PoomSmart/Asus-FX504GE-Hackintosh) [链接](https://github.com/angeljavan/AUSU-FX80GE-FX504Ge-efi) | [链接](https://github.com/PoomSmart/Asus-FX504GE-Hackintosh/blob/master/README.md) | 华硕 FX80GE FX504GE                                        |
| Asus UX501JW                      | [链接](https://github.com/firefly917/Hackintosh_Asus-UX501JW_Mojave) |                                                              |                                                            |
| Asus VivoBook 15 X510UQ / S5100UQ | [链接](https://github.com/wishayne/hackintosh-Asus-S5100UQ-X510UQ) |                                                              |                                                            |
| Asus X441U                        | [链接](https://github.com/jundanaalbasyir/Hackintosh-Asus-X441U) |                                                              |                                                            |
| Asus X441UB                       | [链接](https://github.com/alfinauzikri/Asus-X441UB-Hackintosh) |                                                              |                                                            |
| Asus X441UV                       | [链接](https://github.com/MinorityCode/asus-x441uv-hackintosh-files) |                                                              |                                                            |
| Asus VivoBook Max X441UVK         | [链接](https://github.com/alfinauzikri/Asus-X441UVK-Hackintosh) |                                                              |                                                            |
| Asus VivoBook S15 S510UA          | [链接](https://github.com/tctien342/Asus-Vivobook-S510UA-High-Sierra-10.13-Hackintosh) | [链接](https://github.com/tctien342/Asus-Vivobook-S510UA-High-Sierra-10.13-Hackintosh/blob/master/README.md) | Vivobook S510UA                                            |
| Asus Vivobook S530UA BQ100T       | [链接](https://github.com/superzeldalink/Asus-Vivobook-S530-hackintosh) |                                                              |                                                            |
| Asus VivoBook X510UQR             | [链接](https://github.com/nguyentrucxinh/Asus-VivoBook-X510UQR-Hackintosh) | [链接](https://github.com/nguyentrucxinh/Asus-VivoBook-X510UQR-Hackintosh/blob/master/README.md) |                                                            |
| Asus X450JB                       | [链接](https://github.com/xiaoMGitHub/Asus_X450JB_Hackintosh) |                                                              |                                                            |
| Asus X550JX                       | [链接](https://github.com/gaoliang/Asus-X550JX-Hackintosh)   |                                                              |                                                            |
| Asus X555LB                       | [链接](https://github.com/emre1393/Asus-x555lb-mojave-efi)   |                                                              |                                                            |
| Asus X75VC-TY056D                 | [链接](https://github.com/Jesterjke/ASUS-X75VC-Hackintosh)   |                                                              |                                                            |
| Asus ZenBook 系列                 | [链接](https://github.com/hieplpvip/Asus-ZENBOOK-HACKINTOSH) | [链接](https://www.tonymacx86.com/threads/guide-Asus-zenbook-using-clover-uefi-hotpatch.257448/) | 支持型号: UX310 - UX330 - UX330<br />UX410 - UX430 - UX430 |
| Asus ZenBook Flip UX360UAK        | [链接](https://github.com/Frizz925/UX360UAK-Hackintosh)      | [链接](https://github.com/Frizz925/UX360UAK-Hackintosh/blob/master/README.md) |                                                            |
| Asus ZenBook UX32VD               | [链接](https://github.com/rafaelmaeuer/Asus-UX32VD-Hackintosh) | [链接](https://github.com/rafaelmaeuer/Asus-UX32VD-Hackintosh/blob/master/readme.md) | Asus UX32VD                                                |
| Asus ZenBook UX330UAK             | [链接](https://github.com/Rybo713/UX330UA-macOS)             | [链接](https://github.com/Rybo713/UX330UA-macOS/blob/master/README.md) | Asus UX330UAK (Kabylake）                                  |
| Asus Zephyrus M (GM501GS)         | [链接](https://github.com/kylergib/Asus-Zephyrus-M-gm501gs-Mojave) |                                                              |                                                            |
| 华硕zx50jx4200                    | [链接](https://github.com/sxz799/zx50jx4200_hackintosh)      |                                                              |                                                            |

#### DELL 戴尔

| 机型名称                                   | 发布地址                                                     | 教程地址                                                     | 备注                                                  |
| ------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ----------------------------------------------------- |
| Alienware 17 R4 i7-7700HQ                  | [链接](https://github.com/RockJesus/Alienware-17-R4-I7-7700HQ-MacOS-High-Sierra) | [链接](https://github.com/RockJesus/Alienware-17-R4-I7-7700HQ-MacOS-High-Sierra/blob/master/README.md) | 外星人 17 R4                                          |
| Alienware Aurora-R7                        | [链接](https://github.com/jianghaizhi/DELL-Alienware-Aurora-R7-macOS) |                                                              |                                                       |
| Alienware-Aurora-R6/R7/R8                  | [链接](https://github.com/jianghaizhi/DELL-Alienware-Aurora-R7-macOS) |                                                              |                                                       |
| DELL Latitude E7440                        | [链接](https://github.com/ameeno/Dell-E7440-Hackintosh)      |                                                              |                                                       |
| **Alienware外星人更多机型**                | [链接](https://github.com/RockJesus/Alienware-Hackintosh)    |                                                              | 引用自：RockJesus维护的仓库                           |
|                                            |                                                              |                                                              |                                                       |
| Dell G3 3579                               | [链接](https://github.com/JiangHoumin/Dell_G3_3579_Hackintosh) [链接](https://github.com/JiangHoumin/Dell_G3_3579_Hackintosh) |                                                              |                                                       |
| Dell G7 7588                               | [链接](https://github.com/geraldoandradee/Hackintosh-Dell-G7-7588) |                                                              |                                                       |
| Dell Inspiron 14 5447                      | [链接](https://github.com/SinhLv/Dell-Ins-14-5447-hackintosh) | [链接](https://github.com/SinhLv/Dell-Ins-14-5447-hackintosh/blob/master/README.md) | Dell-Ins-14-5447                                      |
| Dell Inspiron 14 7447                      | [链接](https://github.com/Am1nCmd/Dell-Inspiron-14-7447-Pandora-Hackintosh) | [链接](https://github.com/Am1nCmd/Dell-Inspiron-14-7447-Pandora-Hackintosh/blob/master/README.md) | Dell-Inspiron-14-7447                                 |
| Dell Inspiron 15 7000 (i7-8550U)           | [链接](https://github.com/athlonreg/Dell-Inspiron-15-7000-i7-8550u) |                                                              |                                                       |
| Dell Inspiron 3442                         | [链接](https://github.com/kkzzhizhou/Dell-3443-Hackintosh)   | [链接](https://github.com/kkzzhizhou/Dell-3443-Hackintosh/blob/master/README.md) | Dell 3443                                             |
| Dell Inspiron 3443                         | [链接](https://github.com/kkzzhizhou/Dell-3443-Hackintosh)   |                                                              |                                                       |
| Dell Inspiron 3543                         | [链接](https://github.com/arisskz6/Dell-3543-Hackintosh) [链接](https://github.com/meikeeit/Hackintosh_Dell3543) |                                                              |                                                       |
| Dell Inspiron 3568                         | [链接](https://github.com/YGQ8988/dell-3568)                 | [链接](https://github.com/YGQ8988/dell-3568)                 | Dell Inspiron 3568                                    |
| Dell Inspiron 3670                         | [链接](https://github.com/inyan600/Dell-Inspiron-3670-Hackintosh) |                                                              |                                                       |
| Dell Inspiron 5447                         | [链接](https://github.com/SinhLv/Dell-Ins-14-5447-hackintosh) |                                                              |                                                       |
| Dell Inspiron 5488                         | [链接](https://github.com/daggeryu/DELL-inspiron-5488)       |                                                              |                                                       |
| Dell Inspiron 5559                         | [链接](https://github.com/cbabb/dell-5559)                   |                                                              | Dell 5559                                             |
| Dell Inspiron 5567                         | [链接](https://github.com/MuntashirAkon/HackintoshDellInspiron5567) |                                                              | i3-7100u, Intel HD620                                 |
| Dell inspiron 5570                         | [链接](https://github.com/Mateo1234454545/Dell-5570-hackintosh) |                                                              |                                                       |
| Dell Inspiron 5577                         | [链接](https://github.com/imAmouse/Clover-EFI-For-Dell-5577) |                                                              |                                                       |
| Dell Inspiron 7000 系列                    | [链接](https://github.com/daliansky/dell7000)                | [链接](https://github.com/daliansky/dell7000/blob/master/README.md) | Dell Inspiron 7000 I/II (7x60/7x72)                   |
| Dell Inspiron 14 7447 Pandora              | [链接](https://github.com/Am1nCmd/Dell-Inspiron-14-7447-Pandora-Hackintosh) |                                                              |                                                       |
| Dell Inspiron 7460 和 7560                 | [链接](https://github.com/xzhih/dell-7460-7560-hackintosh)   | [链接](https://github.com/xzhih/dell-7460-7560-hackintosh/blob/master/README.md) | 戴尔 7460 和 7560                                     |
| Dell Inspiron 7559                         | [链接](https://github.com/crackself/Dell-7559-Hackintosh) [链接](https://github.com/JiangHoumin/Dell_G3_3579_Hackintosh) | [链接](https://github.com/crackself/Dell-7559-Hackintosh/blob/Hotpatch/README.md) | Dell 7559                                             |
| Dell Inspiron 7567                         | [链接](https://github.com/Doapeat/Dell7567)                  |                                                              |                                                       |
| Dell Latitude E5440                        | [链接](https://github.com/soejin/hackintosh-dell-e5440)      |                                                              | Dell E5440                                            |
| Dell Latitude E7440                        | [链接](https://github.com/ameeno/Dell-E7440-Hackintosh)      |                                                              |                                                       |
| Dell OptiPlex 3050                         | [链接](https://github.com/Leif160519/Dell-OptiPlex-3050-EFI) | [链接](https://github.com/Leif160519/Dell-OptiPlex-3050-EFI/blob/master/README.md) |                                                       |
| Dell Precision 5510                        | [链接](https://github.com/soulomoon/Dell-Precision-5510-OSX) [链接](https://github.com/PLChinDev/Dell-Precision-5510-Mojave) |                                                              | Dell-Precision-5510                                   |
| Dell Precision M3800<br />Dell XPS 15-9530 | [链接](https://github.com/syscl/M3800)                       | [链接](https://github.com/syscl/M3800/blob/M3800/README.md)  | Dell M3800 和 XPS 9530                                |
| XPS13  9343                                | [链接](https://github.com/SiGae/macOS-Mojave-on-xps-13-9343) | [链接](https://github.com/haos001/XPS13-9343-Clover)         |                                                       |
|                                            |                                                              |                                                              |                                                       |
| Dell XPS 9350                              | [链接](https://github.com/syscl/XPS9350-macOS)               | [链接](https://github.com/syscl/XPS9350-macOS/blob/master/README.md) | Dell XPS 9350                                         |
| Dell XPS 9360                              | [链接](https://github.com/hoanX/xps13-9360-i7-7560u)         | [链接](https://github.com/hoanX/xps13-9360-i7-7560u/blob/master/README.md) | Dell XPS 9360                                         |
| Dell XPS 9360                              | [链接](https://github.com/ymmshi/XPS-9360) [链接](https://github.com/MasonGao/XPS-9360-Hackintosh) <br />[链接](https://github.com/the-marcus/XPS-9360-hackintosh) [链接](https://github.com/the-darkvoid/XPS9360-macOS) <br />[链接](https://github.com/0xHJK/XPS13-9360-i5-8250U-macOS) [链接](https://github.com/samuelshi/XPS13-9360) | [链接](https://github.com/ymmshi/XPS-9360/blob/master/README.md) | Dell XPS 9360                                         |
| Dell XPS 9530                              | [链接](https://github.com/the-darkvoid/XPS9530-OSX/tree/10.13) | [链接](https://www.tonymacx86.com/threads/guide-dell-xps-9530-clover-uefi-hotpatch.235558/) | XPS 9530                                              |
| Dell XPS 9550                              | [链接](https://github.com/wmchris/DellXPS15-9550-OSX) [链接](https://github.com/corenel/XPS9550-macOS) | [链接](https://github.com/wmchris/DellXPS15-9550-OSX/blob/10.14/README.md) [链接](https://github.com/corenel/XPS9550-macOS/blob/master/README.md) | Dell XPS 9550                                         |
| Dell XPS 9560                              | [链接](https://github.com/gunslinger23/XPS15-9560-High-Sierra) | [链接](https://github.com/gunslinger23/XPS15-9560-High-Sierra/blob/master/README.md) | Dell XPS 9560                                         |
| Dell XPS 9570                              | [链接](https://github.com/Xigtun/xps-9570-mojave) [链接](https://github.com/bavariancake/XPS9570-macOS) <br />[链接](https://github.com/LuletterSoul/Dell-XPS-15-9570-macOS-Mojave) |                                                              | 感谢：[LuletterSoul](https://github.com/LuletterSoul) |

#### Gigabyte 技嘉

| 机型名称          | 发布地址                                                 | 教程地址                                                     | 备注 |
| ----------------- | -------------------------------------------------------- | ------------------------------------------------------------ | ---- |
| Gigabyte Aero 15X | [链接](https://github.com/zacmks/Hackintosh-Aero-15X)    | [链接](https://github.com/zacmks/Hackintosh-Aero-15X/blob/master/README.md) |      |
| Gigabyte Aero 15W | [链接](https://github.com/Errrneist/Hackintosh-Aero-15W) |                                                              |      |

#### Hasse 神舟

| 机型名称               | 发布地址                                                     | 教程地址                                                     | 备注              |
| ---------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ----------------- |
| Hasse Shinelon A40L-i7 | [链接](https://github.com/i0Ek3/Hackintosh_4_Hasee_Shinelon_A40L) | [链接](https://github.com/i0Ek3/Hackintosh_4_Hasee_Shinelon_A40L/blob/master/README.md) | 这是神舟          |
| 神舟K650D              | [链接](https://github.com/wklesss/k650D-Hackintosh)          |                                                              | 神舟 K 650D       |
| Hasee Z6-SL5 D1        | [链接](https://github.com/Measureless/Hackintosh_Hasee_Z6-SL5D1) |                                                              |                   |
| 神舟战神 Z7-KP7GZ        | [链接](https://github.com/kirainmoe/hasee-z7-kp7gz-macos)    | [链接](https://note.youdao.com/ynoteshare1/index.html?id=0ebe9470eeaee01e137b9504ceca78db&type=note) | Z7(m)-KP7/5(G)Z |
| Hasee Z7M KP5GC        | [链接](https://github.com/CharlesZhou959/Hasee-Z7M-KP5GC-Hackintosh) |                                                              |                   |
| 神舟炫龙笔记本DC2      | [链接](https://github.com/bavelee/DC2_Hackintosh)            | [链接](https://bavelee.cn/index.php/archives/60/)            |                   |
| 神舟精盾系列T96E       | [链接](https://github.com/L0ngxhn/Hackintosh-Hasee-T96E)     |                                                              |                   |
|                        |                                                              |                                                              |                   |

#### HP 惠普

| 机型名称                                | 发布地址                                                     | 教程地址                                                     | 备注                                                         |
| --------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
|                                         |                                                              |                                                              |                                                              |
| HP ProBook/EliteBook<br />ZBook 系列    | [链接](https://github.com/RehabMan/HP-ProBook-4x30s-DSDT-Patch) | [链接](https://www.tonymacx86.com/threads/guide-hp-probook-elitebook-zbook-using-clover-uefi-hotpatch.261719/) | 除 8x60W,8x70W 系列之外的机型，<br />二代 CPU 及之前的机型仅支持到 10.13.x |
| HP Envy Haswell J/K/Q/N<br />系列笔记本 | [链接](https://github.com/RehabMan/HP-Envy-DSDT-Patch)       | [链接](https://www.tonymacx86.com/threads/guide-hp-envy-haswell-series-j-k-q-n-using-clover-uefi.261724/) | 仅 4 代 envy 机型                                            |
| HP 15 D062TU                            | [链接](https://github.com/trqukhanh0104/hp-15-d062tu-hackintosh) [链接](https://github.com/khanhtran-cse/hp-15-d062tu-hackintosh) |                                                              |                                                              |
| HP Laptop 15-da0233ur                   | [链接](https://github.com/DmitriyyyyS/Hackintosh-HP-Laptop-15-da0233ur) |                                                              | i3-7020U                                                     |
| HP 17 BY0062ST                          | [链接](https://github.com/emilevirus/HP-BY00000-HACKINTOSH)  |                                                              |                                                              |
| HP Envy13 ad1xxx                        | [链接](https://github.com/ArisHub/Hackintosh_Envy13_10.13.6-10.14.4) | [链接](https://github.com/ArisHub/Hackintosh_Envy13_10.13.6/blob/master/README.md) | 惠普 envy13                                                  |
| HP Envy15 as109tu                       | [链接](https://github.com/TianNes/Hackintosh-Clover)         |                                                              |                                                              |
| HP ENVY 15 as110tu                      | [链接](https://github.com/wing-ho/HP-AS110TU-Hackintosh)     |                                                              |                                                              |
| HP Envy DV6 7303ef                      | [链接](https://github.com/TehOrange/hackintosh_configs/tree/master/HP-Envy-DV6-7303ef) |                                                              |                                                              |
| HP 840-G1                               | [链接](https://github.com/blint01/hackintosh-mojave-HP-840-G1) | [链接](https://github.com/blint01/hackintosh-mojave-HP-840-G1/blob/master/README.md) |                                                              |
| HP Pavillion ck069tx                    | [链接](https://github.com/Blizzard57/Hackintosh)             |                                                              |                                                              |
| Hp spectre X360                         | [链接](https://github.com/Just-maple/Hp-spectre-X360-hackintosh) |                                                              |                                                              |
| EliteDesk 800-G3-Mini                   | [链接](https://github.com/francoisminh/Hackintosh-EliteDesk-800-G3-Mini-65W) | [链接](https://github.com/francoisminh/Hackintosh-EliteDesk-800-G3-Mini-65W/blob/master/README.md) |                                                              |
| HP Zhan 66 Pro G1                       | [链接1](https://github.com/A-Linz/Hackintosh-HP-Zhan-66-Pro-G1) [链接2](https://github.com/RenAmamiya/HP-Zhan-66-Pro-G1) |                                                              |                                                              |
| HP ZHAN 66 PRO 14 G2 | [链接](https://github.com/peihexian/HP-ZHAN-66-Pro-14-G2) | | |
| HP ZHAN99 WorkStation G1                | [链接](https://github.com/MacsedProtoss/hackintosh)          |                                                              | 惠普 战99                                                    |
| 暗影精灵4 i5-8300H GTX1050Ti            | [链接](https://github.com/canwdev/omen15dc-hackintosh)       |                                                              |                                                              |
| 暗影精灵2                            |[链接](https://github.com/Arecall/-Mac-os) |            |          |


#### Huawei 华为

| 机型名称            | 发布地址                                                     | 教程地址                                                     | 备注                               |
| ------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ---------------------------------- |
| 华为 Matebook X Pro | [链接](https://github.com/gnodipac886/MatebookXPro-hackintosh) | [链接](https://github.com/gnodipac886/MatebookXPro-hackintosh/blob/master/README-CN.md) | 华为 Matebook X Pro                |
| 华为 Matebook 13    | [链接](https://github.com/FIU001/huawei-matebook-13-)        |                                                              |                                    |
| 华为 Matebook 14    | [链接](https://github.com/frezs/MateBook14-Hackintosh)       |                                                              |                                    |
| 华为 Matebook D     | [链接](https://github.com/MOJUNSHOU/MateBooK-D)              |                                                              | 华为MateBook D2018 i5-8250U 15.6寸 |
| 荣耀 Magicbook      | [链接](https://github.com/hjmmc/Honor-Magicbook)             | [链接](https://github.com/hjmmc/Honor-Magicbook/blob/master/README_CN.md) |                                    |

#### Lenovo 联想

| 机型名称                           | 发布地址                                                     | 教程地址                                                     | 备注                                                         |
| ---------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Lenovo Flex 15                     | [链接](https://github.com/aytic/Lenovo-Flex-15-Hackintosh)   | [链接](https://github.com/aytic/Lenovo-Flex-15-Hackintosh/blob/master/README.md) | Lenovo Flex 15                                               |
| Lenovo Ideapad 310-14IKB           | [链接](https://github.com/29satnam/LenovoHackintosh)         | [链接](https://github.com/29satnam/LenovoHackintosh/blob/master/README.md) |                                                              |
| Lenovo Ideapad 320-15ISK           | [链接](https://github.com/gajjartejas/Lenovo-Ideapad-320-15ISK-Laptop-Hackintosh) |                                                              |                                                              |
| Lenovo Ideapad 700-15ISK           | [链接](https://github.com/athlonreg/Lenovo-XiaoXin700-15ISK) | [链接](https://github.com/athlonreg/Lenovo-XiaoXin700-15ISK/blob/master/README.md) | Lenovo-XiaoXin700-15ISK                                      |
| Lenovo Flex 3-1580                 | [链接](https://github.com/gdllzkusi/Lenovo-Fex3-1580-hackintosh) |                                                              |                                                              |
| Lenovo G40-70M | [链接](https://github.com/jinmu333/Lenovo_G40_70M_EFI) | | |
| Lenovo G50-80                      | [链接](https://github.com/upupming/Lenovo-G50-80-Clover)     |                                                              |                                                              |
| Lenovo G510                        | [链接](https://github.com/Z39/G510-OS-X-Clover-Hotpatch)     | [链接](https://github.com/Z39/G510-OS-X-Clover-Hotpatch/blob/master/README-CN.md) | 感谢：[39军小兵张](http://i.pcbeta.com/space-uid-4472739.html) |
| ThinkPad E450C                     | [链接](https://github.com/zhangxuan1340/Hackintosh_E450C)    |                                                              |                                                              |
| ThinkPad E480                      | [链接](https://github.com/aliyoge/Hackintosh-ThinkPad-E480)  | [链接](https://github.com/aliyoge/Hackintosh-ThinkPad-E480/blob/master/README.md) |                                                              |
| ThinkPad E540                      | [链接](https://github.com/wwbhl/E540)                        |                                                              |                                                              |
| ThinkPad E550                      | [链接](https://github.com/the-braveknight/Lenovo-ThinkPad-E550-DSDT-Patch) | [链接](https://www.tonymacx86.com/threads/guide-lenovo-thinkpad-e550-haswell-using-clover-uefi-10-11.214675/) | E550 四代 CPU                                                |
| ThinkPad E560                      | [链接](https://github.com/rsdev69/Lenovo-E560-Clover)        | [链接](https://www.tonymacx86.com/threads/stable-lenovo-e560-full-work.248842/) |                                                              |
| ThinkPad L440                      | [链接](https://github.com/BesnikRrustemi/Lenovo-ThinkPad-L440) |                                                              |                                                              |
| Lenovo miix 520                    | [链接](https://github.com/acai66/lenovo-miix-520-hackintosh-10.14-CLOVER) |                                                              |                                                              |
| ThinkPad P51                       | [链接](https://github.com/MirkoCovizzi/thinkpad-p51-hackintosh) | [链接](https://github.com/MirkoCovizzi/thinkpad-p51-hackintosh/blob/master/README.md) | Thinkpad P51                                                 |
| ThinkPad P52                       | [链接](https://github.com/liuyishengalan/ThinkPad-P52-Hackintosh-10.14.X-) |                                                              |                                                              |
| 锐 7000                            | [链接](https://github.com/839891627/Lenovo_RUI7000_Hackintosh) |                                                              | 联想 80WB 笔记本电脑                                         |
| ThinkPad S1 2017 | [链接](https://github.com/bugprogrammer/hackintosh/tree/ThinkPad-S1-2017) | | ThinkPad S1 2017 |
| ThinkPad S1 2018 | [链接](https://github.com/bugprogrammer/hackintosh/tree/ThinkPad-S1-2018) | | ThinkPad S1 2018 |
| ThinkPad T420 系列                 | [链接](https://github.com/tluck/Lenovo-T420-Clover)          | [链接](https://www.insanelymac.com/forum/topic/285678-lenovo-thinkpad-t420-with-uefi-only/?page=20&tab=comments#comment-1952283) | 包含 T420、T420s、T520、X220X220，<br />可通过修改支持到 10.14.x |
| ThinkPad T430 | [链接](https://github.com/hai666l/T430-EFI) |  |  |
| ThinkPad T440p                     | [链接](https://github.com/evy0311/t440p) [链接](https://github.com/jloisel/t440p) | [链接](https://github.com/evy0311/t440p/blob/master/README.md) |                                                              |
| ThinkPad T450 | [链接](https://github.com/jsassu20/ThinkPad-T450-Mojave) |  | |
| ThinkPad T460 系列                 | [链接](https://github.com/tluck/Lenovo-T460-Clover)          | [链接](http://www.insanelymac.com/forum/topic/315451-guide-lenovo-t460-macos-with-clover/) | 可支持 T460、T560、T470<br /> 和 T470p4 款机型               |
| ThinkPad T460p                     | [链接](https://github.com/totemofwolf/Thinkpad-T460p-OSX-EFI) |                                                              |                                                              |
| Thinkpad T470                      | [链接](https://github.com/nguyenduy98/Hackintosh)            |                                                              | I7-7500u                                                     |
| ThinkPad T470p                     | [链接](https://github.com/lohcve/EFI_T470P)                  | [链接](https://github.com/lohcve/EFI_T470P/blob/master/README.md) | ThinkPad T470p                                               |
| ThinkPad T480                      | [链接](https://github.com/rhkjyn/T480-Hackintosh-FULL)       |                                                              |                                                              |
| ThinkPad T480s                     | [链接](https://github.com/kk1987/T480s-hackintosh)           | [链接](https://github.com/kk1987/T480s-hackintosh/blob/master/README.md) |                                                              |
| ThinkPad T480s                     | [链接](https://github.com/kk1987/T480s-hackintosh) [链接](https://github.com/linusyang92/macOS-ThinkPad-T480s) <br />[链接](https://github.com/samuelshi/Thinkpad-T480S) | [链接](https://github.com/linusyang92/macOS-ThinkPad-T480s/blob/master/README.md) [链接](https://github.com/kk1987/T480s-hackintosh/blob/master/README.md) | ThinkPad T480s                                               |
| ThinkPad T580                      | [链接](https://github.com/CrazyPegAsus/ThinkPad-T580-Hackintosh) |                                                              | 鸣谢：[CrazyPegasus](https://github.com/CrazyPegasus)        |
| Lenovo U330/U430/U530 系列         | [链接](https://github.com/RehabMan/Lenovo-U430-Touch-DSDT-Patch) | [链接](https://www.tonymacx86.com/threads/guide-lenovo-ideapad-u330-u430-u530-using-clover-uefi.261722/) |                                                              |
| Lenovo V1000                       | [链接](https://github.com/LiuJiangshan/Lenovo-V1000-FHD)     |                                                              | 联想小新笔记本V1000 FHD                                      |
| Lenovo V3000                       | [链接](https://github.com/Xc2333/Hackintosh-Lenovo-v3000-ISE) | [链接](https://github.com/Xc2333/Hackintosh-Lenovo-v3000-ISE/blob/master/README.md) | Lenovo V3000                                                 |
| Lenovo V310 15iKB | [链接](https://github.com/jacobmesier/V310-Hackintosh) |  |  |
| Lenovo V330 15IKB                  | [链接](https://github.com/BesnikRrustemi/Lenovo-V330-15IKB)  | [链接](https://www.tonymacx86.com/threads/guide-lenovo-v330-15ikb-using-clover-uefi-hotpatch.265841/) |                                                              |
| Lenovo xiaoxin air13 6th           | [链接](https://github.com/gdllzkusi/Lenovo-xiaoxin-air13-6th-Hackintosh) |                                                              | Intel 酷睿i5 6200U                                           |
| Lenovo XiaoXin Air 13 IWL          | [链接](https://github.com/daliansky/Lenovo-Air13-IWL)        | [链接](https://blog.daliansky.net/Lenovo-Xiaoxin-Air-13-macOS-Mojave-installation-tutorial.html) | 联想小新 Air 13 2018 IWL                                     |
| Lenovo XiaoXin Chao 5000           | [链接](https://github.com/Xc2333/Hackintosh-Lenovo-chao5000) |                                                              | 联想潮 5000                                                  |
| Lenovo XiaoXin Rui 7000            | [链接](https://github.com/Erf172/Lenovo_XiaoXin_Rui7000_Hackintosh) | [链接](https://github.com/Erf172/Lenovo_XiaoXin_Rui7000_Hackintosh/blob/10.12/README.md) |                                                              |
| Lenovo XiaoXin Chao 7000           | [链接](https://github.com/penghubingzhou/Lenovo-Xiaoxin-Chao-7000--EFI) | [链接](https://github.com/penghubingzhou/Lenovo-Xiaoxin-Chao-7000--EFI/blob/master/Readme.md) | 联想小新潮 7000，已支持 14 寸、<br />12.5 寸、13.3 寸，15 寸以及 <br />13.3 寸的完美支持后续会添加，<br />请期待…… |
| ThinkPad X1 3rd                    | [链接](https://github.com/shockingpants/ThinkpadX1Y3)        | [链接](https://www.tonymacx86.com/threads/guide-thinkpad-x1-yoga-3rd-gen-20ld-with-mojave.261823/) | ThinkPad X1 3 代                                             |
| ThinkPad X1 Carbon 2015 | [链接](https://github.com/transtone/hackintosh/tree/master/x1c-2015) |  |  |
| ThinkPad X1 Carbon 5th gen         | [链接](https://github.com/B0hrer/Thinkpad-x1c-5th-gen-Hackintosh) |                                                              | (5th gen, released 2017)                                     |
| ThinkPad X1 Carbon 6th Gen         | [链接](https://github.com/tylernguyen/x1c6-hackintosh)       | [链接](https://github.com/tylernguyen/x1c6-hackintosh/blob/master/README.md) | Thinkpad X1 Carbon 6th Gen                                   |
| ThinkPad X1 Yoga / Carbon          | [链接](https://github.com/LukaJankovic/Thinkpad-X1-20FQ-Hackintosh) | [链接](https://github.com/LukaJankovic/Thinkpad-X1-20FQ-Hackintosh/blob/master/README.md) | Thinkpad X1 Yoga / Carbon                                    |
| ThinkPad X1 Extreme                | [链接](https://github.com/Errrneist/Hackintosh-Thinkpad-X1-Extreme) [链接](https://github.com/zysuper/Thinkpad-X1-extreme-EFI) | [链接](https://www.tonymacx86.com/threads/macos-10-14-0-thinkpad-x1-extreme-igpu-issue.263916/) | 如果没猜错，这货就是 x1 隐士，<br />好几个人问过，这下省事了 |
| ThinkPad X1C 6th                   | [链接](https://github.com/tylernguyen/x1c6-hackintosh)       | [链接](https://github.com/tylernguyen/x1c6-hackintosh/blob/master/README.md) | ThinkPad X1c 6th                                             |
| ThinkPad X220                      | [链接](https://github.com/b-ggs/x220-hackintosh)             | [链接](https://github.com/b-ggs/x220-hackintosh/blob/master/README.md) | 支持 10.14+                                                  |
| ThinkPad X220                      | [链接](https://github.com/laris/Hackintosh-ThinkPad-X220-MacOS) |                                                              | ThinkPad-X220                                                |
| ThinkPad X230                      | [链接](https://github.com/littlegtplr/Hackintosh-X230-macOS) | [链接](https://github.com/littlegtplr/Hackintosh-X230-macOS/blob/master/README.md) | ThinkPad X230                                                |
| ThinkPad X230                      | [链接](https://github.com/SynneK1337/ThinkPad_X230_Hackintosh) | [链接](https://github.com/SynneK1337/ThinkPad_X230_Hackintosh/blob/master/README.md) | ThinkPad X230                                                |
| ThinkPad X250                      | [链接](https://github.com/Janolan/x250-hackintosh) [链接](https://github.com/qwerty12/X250-Hackintosh) |                                                              |                                                              |
| ThinkPad X260 系列                 | [链接](https://github.com/daliansky/ThinkPad-X260-hackintosh) | [链接](https://github.com/daliansky/ThinkPad-X260-hackintosh/blob/master/README.md) | ThinkPad X260                                                |
| Lenovo Y50(70) 系列                | [链接](https://github.com/RehabMan/Lenovo-Y50-DSDT-Patch)    | [链接](https://www.tonymacx86.com/threads/guide-lenovo-y50-uhd-or-1080p-using-clover-uefi.261723/) | Y50(70)1080P 和 4K 版本                                      |
| Lenovo IdeaPad Y410P               | [链接](https://github.com/Z39/Y410p-OS-X-Clover-Hotpatch)    |                                                              | 感谢：[39军小兵张](http://i.pcbeta.com/space-uid-4472739.html) |
| Lenovo IdeaPad Y430P               | [链接](https://github.com/Z39/Y430p-OS-X-Clover-Hotpatch)    |                                                              | 感谢：[39军小兵张](http://i.pcbeta.com/space-uid-4472739.html) |
| Lenovo IdeaPad Y510P               | [链接](https://github.com/Z39/Y510p-OS-X-Clover-Hotpatch)    |                                                              | 感谢：[39军小兵张](http://i.pcbeta.com/space-uid-4472739.html) |
| Lenovo Y520/Y720                   | [链接](https://github.com/the-braveknight/Lenovo-Y520-macOS) | [链接](https://www.tonymacx86.com/threads/guide-lenovo-legion-y520-y720-using-clover-uefi.261009/) | 联想 Y520 及 Y720                                            |
| Lenovo Legion Y7000                | [链接](https://github.com/hnie-xwz/EFI)                      | [链接](https://github.com/hnie-xwz/EFI/blob/macOs10.14/readme.md) |                                                              |
| Lenovo Legion Y7000-1060           | [链接](https://github.com/TioaTyan/Lenovo_Legion_Y7000-1060_Hackintosh) | [链接](https://github.com/TioaTyan/Lenovo_Legion_Y7000-1060_Hackintosh/blob/master/README.md) | Lenovo_Legion_Y7000-1060                                     |
| Lenovo Legion Y7000<br />Y530 系列 | [链接](https://github.com/xiaoMGitHub/Lenovo_Y7000-Y530_Hackintosh/) [链接](https://github.com/ahossny/Legion-Y530-Hackintosh) | | 全新完美 EFI，舍弃了小键盘                                   |
| Lenovo Yoga 3 Pro 1370             | [链接](https://github.com/gdllzkusi/hackintosh--lenovo-Yoga-3-Pro-1370) | [链接](https://github.com/gdllzkusi/hackintosh--lenovo-Yoga-3-Pro-1370/blob/master/README.md) | 联想 yaga3/pro                                               |
| ThinkPad Yoga 12                   | [链接](https://github.com/gartempe/MacOS-Thinkpad-Yoga-12) [链接](https://github.com/kymodoke/MacOS-Thinkpad-Yoga-12) | [链接](https://github.com/gartempe/MacOS-Thinkpad-Yoga-12/blob/master/README.md) [链接](https://github.com/kymodoke/MacOS-Thinkpad-Yoga-12/blob/master/README.md) |                                                              |
| Lenovo Yoga3 14                    | [链接](https://github.com/gdllzkusi/Lenovo-yoga3-14-hackntiosh) |                                                              |                                                              |
| Lenovo Yoga3 11                    | [链接](https://github.com/gdllzkusi/Lenovo-yoga3-11-hackntiosh) |                                                              |                                                              |
| Lenovo Yoga 710                    | [链接](https://github.com/xiaoxx970/Hackintosh-Mojave-for-Lenovo-Yoga710) |                                                              |                                                              |
| Lenovo Yoga 720 | [链接](https://github.com/bugprogrammer/hackintosh/tree/Lenovo-yoga-720-13ikb-7200u) | | Lenovo Yoga 720-13IKB |
| Lenovo Yoga 730 | [链接](https://github.com/dragonflylee/Yoga-730-hackintosh) | | Lenovo Yoga 730-13IKB |
| Lenovo Z50(40)/70 系列             | [链接](https://github.com/the-braveknight/Lenovo-X50-macOS)  | [链接](https://www.tonymacx86.com/threads/guide-lenovo-z50-70-z40-70-g50-70-g40-70-using-clover-uefi.261787/) | Lenovo Z50-70/Z40-70   Lenovo G50-70/G40-70                  |
| Lenovo-Miix-520             | [链接](https://github.com/acai66/lenovo-miix-520-hackintosh-10.14-CLOVER) | [链接](https://github.com/acai66/lenovo-miix-520-hackintosh-10.14-CLOVER) | Lenovo-Miix-520          |
| ThinkPad P52 | [链接](https://github.com/liuyishengalan/ThinkPad-P52-Hackintosh-10.14.X-)   | [链接](https://github.com/liuyishengalan/ThinkPad-P52-Hackintosh-10.14.X-/blob/master/README.md)        ||

#### LG

| 机型名称               | 发布地址                                           | 教程地址 | 备注 |
| ---------------------- | -------------------------------------------------- | -------- | ---- |
| LG Gram 14z980         | [链接](https://github.com/ShiningXu/LG-Gram-macOS) |          |      |
| LG Gram 15Z980-G.AA52C | [链接](https://github.com/ice-black-tea/LG-15Z980) |          |      |
| LG Gram Z980           | [链接](https://github.com/ShiningXu/LG-Gram-macOS) |          |       |




#### Mechrevo 机械革命

| 机型名称           | 发布地址                                                     | 教程地址 | 备注                                |
| ------------------ | ------------------------------------------------------------ | -------- | ----------------------------------- |
| Mechrevo Z2 G      | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh/tree/master/Mechrevo%20Z2%20G%20X9TI/EFI) |          | i7-9750H/GTX1660Ti                  |
| Mechrevo X9Ti R    | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh/tree/master/Mechrevo%20Z2%20G%20X9TI/EFI) |          | i7-9750H/RTX2060/RTX2070            |
| Mechrevo Z2        | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh)      |          | i7-8750H/i5-8300H GTX1050ti/GTX1060 |
| Mechrevo Z2 Air    | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh)      |          | i7-8750H/i5-8300H GTX1050ti/GTX1060 |
| Mechrevo X8ti      | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh)      |          | i7-8750H/i5-8300H GTX1050ti/GTX1060 |
| Mechrevo X8ti Plus | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh)      |          | i7-8750H/i5-8300H GTX1050ti/GTX1060 |
| Mechrevo S1        | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh)      |          | I5-8250U/I7-8550u Mx150             |
| Mechrevo S1        | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh)      |          | I5-8265U/I7-8565u Mx250             |
| Mechrevo X2        | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh)      |          | i7-8750H/i5-8300H GTX1050ti/GTX1060 |
| Mechrevo S1 PLUS   | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh)      |          | i7-8750H/i5-8300H GTX1050ti/GTX1060 |
| Mechrevo X7TI      | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh)      |          | I7-6700HQ/I7 7700HQ                 |
| Mechrevo X7TI-S    | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh)      |          | I7-7700HQ GTX1070/GTX1060           |
| Mechrevo X6TI      | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh)      |          | i7-8750H/i5-8300H GTX1050ti/GTX1060 |
| Mechrevo X6TIS     | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh)      |          |                                     |
| Mechrevo X1        | [链接](https://github.com/cmbs2019/Mechrevo-Hackintosh) [链接](https://github.com/tsmswifty/MECHREVO-X1-hackintosh) |          | i7-7700HQ/GTX1060                   |



#### MSI 微星

| 机型名称                  | 发布地址                                                     | 教程地址                                                     | 备注      |
| ------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | --------- |
| MSI GE70 2PC              | [链接](https://github.com/alxzoomer/msi-ge70-2pc-hackintosh) |                                                              |           |
| MSI GL62M-7REX            | [链接](https://github.com/rlindsberg/Hackintosh-On-MSI-GL62m-7REX) |                                                              |           |
| MSI GL63-8RE              | [链接](https://github.com/iAmineOHN/Hackintosh-MSI-GL63-8RE) |                                                              |           |
| MSI GL72M-7RDX            | [链接](https://github.com/jbwharris/hackintosh-msi-GL72M-7RDX) | [链接](https://github.com/jbwharris/hackintosh-msi-GL72M-7RDX/blob/master/README.md) |           |
| MSI GP62 6QG-1071XCN      | [链接](https://github.com/chuxubank/MSI-GP62-Hackintosh)     | [链接](https://github.com/chuxubank/MSI-GP62-Hackintosh/blob/master/README.md) | 微星 GP62 |
| MSI GS65 Stealth Thin 8RF | [链接](https://github.com/vladichimescu/msi-gs65-hackintosh) |                                                              |           |
| MSI GS73VR 7RF            | [链接](https://github.com/dogukanoksuz/msi-gs73vr-7rf-macOS) |                                                              |           |


#### XiaoMi 小米

| 机型名称           | 发布地址                                                     | 教程地址                                                     | 备注                                           |
| ------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ---------------------------------------------- |
| XiaoMi Air         | [链接](https://github.com/billhhh/MiAir-Hackintosh)          | [链接](https://github.com/billhhh/MiAir-Hackintosh/blob/master/README.md) | XiaoMiAir_i7 7500u                             |
| XiaoMi Air         | [链接](https://github.com/johnnync13/Xiaomi-Mi-Air)          | [链接](https://github.com/johnnync13/Xiaomi-Mi-Air/blob/master/README.md) | 小米 Air                                       |
| XiaoMi Air         | [链接](https://github.com/ourfor/Mibook-air)                 | [链接](https://github.com/ourfor/Mibook-air/blob/master/README.md) | 小米 Air                                       |
| XiaoMi Air         | [链接](https://github.com/whtiehack/XiaoMi-Air)              |                                                              |                                                |
| XiaoMi Air         | [链接](https://github.com/johnnync13/Xiaomi-Notebook-Air-6200u) | [链接](https://github.com/johnnync13/Xiaomi-Notebook-Air-6200u/blob/master/README.md) | 小米 Notebook Air                              |
| XiaoMi Air         | [链接](https://github.com/whtiehack/XiaoMi-Air)              | [链接](https://github.com/whtiehack/XiaoMi-Air/blob/master/README.md) | XiaoMi NoteBook Air                            |
| XiaoMi Air 1gen    | [链接](https://github.com/johnnync13/Xiaomi-Notebook-Air-1Gen) |                                                              | 这哥们应该是忠实的米粉，<br />有兴趣的多多关注 |
| XiaoMi Air Skylake | [链接](https://github.com/johnnync13/EFI_XIAOMI_NOTEBOOK_AIR_SKYLAKE) | [链接](https://github.com/johnnync13/EFI_XIAOMI_NOTEBOOK_AIR_SKYLAKE/blob/master/README.md) |                                                |
| XiaoMi Gaming      | [链接](https://github.com/johnnync13/XiaomiGaming)           |                                                              | 额，小米游戏本                                 |
| XiaoMi Pro 系列    | [链接](https://github.com/daliansky/XiaoMi-Pro/releases)              | [链接](https://blog.daliansky.net/MacOS-installation-tutorial-XiaoMi-Pro-installation-process-records.html)         | 小米 Pro 系列                                  |
| XiaoMi Ruby 15.6   | [链接](https://github.com/Jxh98/XiaoMi-Ruby-15.6-2019)       |                                                              | 目前ALC256声卡外放无法驱动                     |
| XiaoMi 游戏本 8 代 | [链接](https://github.com/daliansky/XiaoMi-GLP)              |                                                              | 小米游戏本，猜的                               |

#### Intel 英特尔

| 机型名称                                            | 发布地址                                                     | 教程地址                                                     | 备注                                                |
| --------------------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | --------------------------------------------------- |
| Intel DH67GD, DH67BL, <br />DH67CF, DH67CL 系列主板 | [链接](https://github.com/RehabMan/Intel-DH67XX-DSDT-Patch)  | [链接](https://www.tonymacx86.com/threads/guide-intel-dh67xx-with-hd3000-using-clover-uefi-hotpatch.233257/) | Intel DH67GD, DH67BL, <br />DH67CF, DH67CL 系列主板 |
| Intel NUC 5、6、7、8 系列                           | [链接](https://github.com/RehabMan/Intel-NUC-DSDT-Patch)     | [链接](https://www.tonymacx86.com/threads/guide-intel-kaby-lake-nuc7-using-clover-uefi-nuc7i7bnh-nuc7i5bnk-nuc7i3bnh-etc.261711/) | mini 主机                                           |
| NUC8i7BEH                                           | [链接](https://github.com/sarkrui/NUC8i7BEH-Hackintosh-Build) |                                                              |                                                     |
| Surface Pro 3 | [链接](https://github.com/hacker1024/Hackintosh-Clover-SurfacePro3) | | |
| Surface Pro 4                                       | [链接](https://github.com/Neil-Steven/SurfacePro4-Hackintosh) [链接](https://github.com/bigsadan/surface-pro-4-hackintosh-10.14.3) | [链接](https://github.com/Neil-Steven/SurfacePro4-Hackintosh/blob/master/README.md) | surfacePro 4                                        |
| Surface Pro 6     | [链接](https://github.com/molie34/Surface-Pro-6-macOS)   | [教程](https://github.com/molie34/Surface-Pro-6-macOS)   |   |
| 技嘉 GB-BXi5H-4200 系列主板                         | [链接](https://github.com/RehabMan/Gigabyte-BRIX-s-DSDT-Patch) | [链接](https://www.tonymacx86.com/threads/guide-gigabyte-brix-using-clover-uefi-gb-bxi5h-4200-gb-bxi5-4570r-gb-bxi7-4770r.261710/) | 技嘉 GB-BXi5H-4200 系列主板                         |

#### Other 其它

| 机型名称                           | 发布地址                                                     | 教程地址                                                     | 备注              |
| ---------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ----------------- |
| Clevo P950HR                       | [链接](https://github.com/MegaCookie/Clevo-P950HR-Hackintosh) |                                                              | 蓝天 P950HR，猜的 |
| 火影地狱火X6                       | [链接](https://github.com/gaofeicm/DiYuHuo-X6-MacOS-Mojave-10.14.3-Hackintosh) |                                                              |                   |
| Shinalon_Yao_7000                  | [链接](https://github.com/jinmu333/Shinalon_YAO_7000_efi)    | [链接](https://github.com/jinmu333/Shinalon_YAO_7000_efi/blob/efi/README.md) |                   |
| Razer Blade Stealth 雷蛇灵刃潜行版 | [链接](https://github.com/widmonstertony/razer-blade-stealth-hackintosh) |                                                              |                   |
| 三星Samsung NP300E4C               | [链接](https://github.com/installgento0/NP300E4C-hackintosh) |                                                              |                   |
| ASRock-Z370M-ITX-AC | [链接](https://github.com/youngle316/ASRock-Z370M-ITX-AC) |                    |                |


#### 笔记本更多的机型

| 机型名称     | 发布地址                                 | 教程地址 | 备注                                                         |
| ------------ | ---------------------------------------- | -------- | ------------------------------------------------------------ |
| **更多机型** | [链接](https://github.com/sqlsec/clover) |          | 引用自：国光之前维护的仓库                                   |
|              | [链接](https://zhih.me/hackintosh/#/)    |          | 底噪出品：**[one-key-hidpi](https://github.com/xzhih/one-key-hidpi)** |

#### 笔记本相关资源

| **笔记本相关资源**                 |                                                            |                                                              |                                                              |
| ---------------------------------- | ---------------------------------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
|                                    | **hotpatch**                                               |                                                              |                                                              |
| P-little                           | [链接](https://github.com/daliansky/P-little)              | 见 ThinkPad 交流群                                           | 宪武做的一套 ThinkPad 补丁，刚开始上传，请期待               |
|                                    | **触摸板**                                                 |                                                              |                                                              |
| VoodooI2C-PreRelease               | [链接](https://github.com/williambj1/VoodooI2C-PreRelease) | [触摸设备 DSDT 修补补充](https://github.com/williambj1/VoodooI2C-PreRelease/blob/master/%E8%A7%A6%E6%91%B8%E6%9D%BF%E8%A1%A5%E5%85%85.md) | [Bat.bat](https://github.com/williambj1)搞的                 |
|                                    | **无线网卡**                                               |                                                              |                                                              |
| 推荐无线网卡                       | MiniPCIe 接口(推荐 BCM4352HMB、DW1510)                     | 博通：BCM94322HM8L、Asus BCM94352、AzureWave AW-CE123H、AzureWave AW-NB290H、DW1510、DW1520、DW1550、 | 高通：DW1515、DW1705、AR5BHB92、AR5BHB112 AR9285 芯片在 10.14 将不再被支持 |
| PCIe 接口                          | 博通：BCM94331CD、BCM94322MC、BCM94360CD                   | 高通：AR5BXB72、AR5BXB92、AR5BXB112                          |                                                              |
| M.2 接口(推荐 BCM94352ZAE、DW1560) | 博通：BCM94352Z(AE)、DW1560，DW1830                        |                                                              |                                                              |
| Wireless USB Adapter               | RealTek系列                                                | [链接](https://github.com/chris1111/Wireless-USB-Adapter-Clover) |                                                              |

### 台式机

| **台式（部分）**               | 发布地址                                                     | 教程地址                                                     | 备注                                            |
| ------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ----------------------------------------------- |
| **AMD Ryzen CPU**              |                                                              |                                                              |                                                 |
| AMD Ryzen安装教程              | [链接](https://github.com/MrNegativeTW/Ryzen-Hackintosh-Tutorial) | [链接](https://mtwstudio.gitbook.io/ryzentosh/)              | 适用于`Sierra` `10.12.6`                        |
| AMD FX 6300/NVIDIA GTX 650     | [链接](https://github.com/pexcn/hackintosh-amd)              |                                                              | 主板：Asus M5A97 LE R2.0                        |
| MSI B350M Gaming Pro           | [链接](https://github.com/nghuunghiaa111/Hackintosh-IMac)    |                                                              | AMD Ryzen 5 1400<br />MSI RX580 8GB Armor       |
| AMD Ryzen 1700/Asus B350 Plus  | [链接](https://github.com/mikigal/ryzen-hackintosh)          |                                                              | MSI GTX 1080 Gaming X                           |
| AMD Vanilla Clover Patches | [链接](https://github.com/AMD-OSX/AMD_Vanilla) | [链接](https://github.com/cheneyveron/hackintosh-clover-tachi-x370-1700x-rx570) | AMD Clover补丁，以后可以<br />直接刻盘安装，10.14.5我会同步<br />更新针对AMD平台的配置文件<br />敬请期待 |
|  |  |  |  |
| **INTEL CPU**                  |                                                              |                                                              |                                                 |
| ASRock  deskmini 110           | [链接](https://github.com/suxiaogang/asrock-deskmini-110-hackintosh) |                                                              |                                                 |
| Asrock deskmini 310            | [链接](https://github.com/liminghuang/asrock_deskmini310_hackintosh) |                                                              |                                                 |
| ASRock Z370M Pro4              | [链接](https://github.com/HouCoder/asrock-z370m-pro4-hackintosh) [链接](https://github.com/ljllili23/Hackintosh) | [链接](https://github.com/HouCoder/asrock-z370m-pro4-hackintosh/blob/master/README.md) |                                                 |
| ASRock Z370-Gaming             | [链接](https://github.com/fangf2018/ASRock-Z370-Gaming-ITX-ac-hackintosh) | [链接](https://github.com/fangf2018/ASRock-Z370-Gaming-ITX-ac-hackintosh/blob/master/README.md) | I7-8700k/RX570                                  |
| ASRock Z390 Phantom Gaming itx | [链接](https://github.com/icyleaf/EFI-ASRock-Z390-Phantom-Gaming-ITX) [链接](https://github.com/bydavy/EFI-ASRock-Z390-Phantom-Gaming) <br />[链接](https://github.com/kcunanan/Jared-PC/) [链接](https://github.com/befuture/EFI-ASRock-Z390-Phantom-Gaming) |                                                              | 华擎 Z390 Phantom Gaming itx/ac                 |
| ASUS Z97K 4980HQ               | [链接](https://github.com/efsg/ASUS-Z97K-4980HQ-Hackintosh)  |                                                              | I7-4980HQ                                       |
| Asus Z170-P                    | [链接](https://github.com/Sharlion/z170_6700k_hackintosh)    |                                                              | 华硕Z170-P+6700K+RX470                          |
| Asus ROG STRIX H370-I GAMING   | [链接](https://github.com/Autocrit/Asus-ROG-STRIX-H370-I-GAMING-Hackintosh-Guide) |                                                              | mini-ITX H370 motherboard                       |
| Asus STRIX Z270-E              | [链接](https://github.com/BradenM/Hackintosh-7700k-R9_390-iGPU) |                                                              | Asus STRIX Z270-E                               |
| Asus ROG Strix Z390-E          | [链接](https://github.com/xiedonghang/hackintosh)            |                                                              | Intel i9-9900k+UHD630核显                       |
| CM238 i7-8950H UHD630 ALC269   | [链接](https://github.com/kkzzhizhou/S200H_I7-8750H_Hackintosh) |                                                              | S200H_I7-8750H 小主机                           |
| Dell OptiPlex 3050             | [链接](https://github.com/Leif160519/Dell-OptiPlex-3050-EFI) |                                                              |                                                 |
| Dell OptiPlex 9020M            | [链接](https://github.com/mingcheng/dell-optiplex-9020m-hackintosh) |                                                              |                                                 |
| Lenovo M93P           | [链接](https://github.com/mingcheng/lenovo-thinkcentre-m93p-hackintosh) |      | 联想 M93P 系列主机 |
| B360 AORUS Gaming 3 | [链接](https://github.com/littlegtplr/Hackintosh-Clover-folder-for-Coffee-Lake-builds) | |  |
| Gigabyte X370N                 | [链接](https://github.com/cwr31/z370n-hackintosh) [链接](https://github.com/qinkangdeid/z370n-wifi-hackintosh) |                                                              | Gigabyte Z370N                                  |
| DQ77KB                         | [链接](https://github.com/siwilizhao/DQ77KB-I7-3770S-Hackintosh) |                                                              |                                                 |
| Gigabyte Z270X-UG              | [链接](https://github.com/icedterminal/ga-z270x-ug)          | [链接](https://github.com/icedterminal/ga-z270x-ug/blob/master/README.md) |                                                 |
| Gigabyte Z370N WIFI            | [链接](https://github.com/b166ar/Mac-Mini-Killer) [链接](https://github.com/yangbe/z370n-wifi-vega64) |                                                              | Mac-Mini-Killer<br />Z370N WIFI VEGA64          |
| Gigabyte Z390 AORUS            | [链接](https://github.com/cmer/gigabyte-z390-aorus-master-hackintosh) |                                                              | **备注：**<br />如果不是9900k/9700k/8500/8700k CPU，<br />需要打`Device RTC`补丁 |
| Gigabytes Z390 AORUS ELITE     | [链接](https://github.com/liusming/hackintosh)               |                                                              | I9-9900K/Intel (Z380) HD 630 2G                 |
| Gigabytes Z390 Ultra           | [链接](https://github.com/mrpaulphan/gigabyte-z390-ultra-master-hackintosh) |                                                              |                                                 |
| Lenovo M73 Tiny                | [链接](https://github.com/rehandalal/m73-tiny-hackintosh)    |                                                              |                                                 |
| Huanan X79 E5-2670, GTX650     | [链接](https://github.com/cheneyveron/clover-x79-e5-2670-gtx650) | [链接](https://github.com/cheneyveron/clover-x79-e5-2670-gtx650/blob/master/README.md) | 华南 x79 V2                                     |
| HP Z600 Workstation            | [链接](https://github.com/lutzmor/hp_z600_hackintosh)        |                                                              | Mac-Mini-Killer                                 |
| MSI B360                       | [链接](https://github.com/SuperNG6/MSI-b360-10.14.4-EFI)     |                                                              | 也适用于<br />MAG Z390 TOMAHAWK <br />(MS-7B18) |
| MSI Z370-A                     | [链接](https://github.com/daliansky/Z370-Hackintosh)         | [链接](https://github.com/daliansky/Z370-Hackintosh)         | 黑果小兵MSI Z370-A自用EFI                       |
| ASRock-Z370-Gaming-ITX-ac-hackintosh  | [链接](https://github.com/fangf2018/ASRock-Z370-Gaming-ITX-ac-hackintosh) |   |   |



#### 台式机其它机型

| 机型名称     | 发布地址                                 | 教程地址 | 备注                                                         |
| ------------ | ---------------------------------------- | -------- | ------------------------------------------------------------ |
| **更多机型** | [链接](https://github.com/sqlsec/clover) |          | 引用自：国光之前维护的仓库                                   |
|              | [链接](https://zhih.me/hackintosh/#/)    |          | 底噪出品：**[one-key-hidpi](https://github.com/xzhih/one-key-hidpi)** |
| 耕田男孩维护的几个机型 | [华硕H81-PLUS](https://pan.baidu.com/s/1iWXxUDWBUUlnsuc4COusJQ) [ASUS-Z97](https://pan.baidu.com/s/1QNax08N7BNI1X_Myuaa-XA) [ASUS X299 deluxe](https://pan.baidu.com/s/1JA0UrABdhu4HmM-WuJDWdw)

#### 硬件兼容列表

| 机型名称         | 发布地址                                                     | 教程地址 | 备注                                                  |
| ---------------- | ------------------------------------------------------------ | -------- | ----------------------------------------------------- |
| **硬件兼容列表** | [链接](https://github.com/CrazyPegAsus/macOS-Mojave-Compatibility-hardware-list) |          | 感谢: [CrazyPegAsus](https://github.com/CrazyPegAsus) |
|                  |                                                              |          |                                                       |



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

436905405 [机械革命MECHREVO【MR学院】黑苹果](http://shang.qq.com/wpa/qunwpa?idkey=fedfd951c92b6493a1b02940ec673657d3d0c8316d1abfa738f92214ed66d365) 500人群 非专用机型请勿加入

43518833  [Mac for HP](https://shang.qq.com/wpa/qunwpa?idkey=739faedadd025d72310a48effa168a797bd7407520f5264560f45fc611e601d0) 1000人群 惠普商务机EFI交流共享（推荐）

612655811 [elitebook_probook_zbook系列黑苹果交流](https://shang.qq.com/wpa/qunwpa?idkey=5f91e85dc300cc5da20324401b23236cdeb9a0e5ebee5944fa8811ff0d5e4e36) 500人群 hotpatch方案(备选)

308469644 [外星人Alienware黑苹果交流群](https://shang.qq.com/wpa/qunwpa?idkey=9f579e157ffed2a47be3861601080953453be323e50844005e9f2466dd2b12c5) 500人群 非专用机型请勿加入

## 关于打赏

如果您认可我的工作，请通过打赏支持我后续的更新

| paypal                                                       | 微信                                                       | 支付宝                                               |
| ------------------------------------------------------------ | ---------------------------------------------------------- | ---------------------------------------------------- |
| [![paypal_daliansky](https://7.daliansky.net/paypal_daliansky.png)](https://www.paypal.me/daliansky) | ![wechatpay_160](http://7.daliansky.net/wechatpay_160.jpg) | ![alipay_160](http://7.daliansky.net/alipay_160.jpg) |

[![img](https://img.shields.io/github/stars/daliansky/Hackintosh.svg?color=ff69b4&label=%E7%82%B9%E8%B5%9E&logoColor=ff69b4&style=social)](https://github.com/daliansky/Hackintosh) [![img](https://img.shields.io/github/followers/daliansky.svg?label=%E7%B2%89%E4%B8%9D&logoColor=success&style=social)](https://github.com/daliansky/Hackintosh) ![img](https://img.shields.io/github/contributors/daliansky/Hackintosh.svg?color=red&label=%E8%B4%A1%E7%8C%AE%E4%BA%BA%E6%95%B0) [![img](https://img.shields.io/github/last-commit/daliansky/Hackintosh.svg?color=orange&label=%E6%9C%80%E8%BF%91%E6%8F%90%E4%BA%A4)](https://github.com/daliansky/Hackintosh) [![img](https://img.shields.io/badge/link-996.icu-red.svg)](https://996.icu/) 
