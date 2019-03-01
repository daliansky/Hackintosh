# Hackintosh
## 黑苹果长期维护机型整理 by @我意

> 整理这份清单的目的：在于给想体验黑苹果的人一个方向，也想减少大家重复造轮子，节约大家的时间。
> 所有文件均归属于原作者，本清单只列出链接。如果您不希望你的链接被这份清单收录，请发送邮件到 [y010204025@126.com](mailto:y010204025@126.com),我将移除链接
> 清单收录了4个月以内的有人长期维护并更新过 EFI 的机型链接，如果有新的链接希望收录到这份清单，请发送邮件到 [y010204025@126.com](mailto:y010204025@126.com)
> 致谢：感谢一直为黑苹果进行开发的各位开发者和愿意共享出 EFI 文件的开发者，谢谢！

更新日期：

- 2018年10月06日

- 2018年12月25日

- 2019年01月15日

- 2019年3月1日 by 黑果小兵

  - 按机型重新排版
  - 将该文档上传到仓库，方便其它人提交合并，共同维护

  

### 笔记本部分机型

| 机型名称 | 发布地址  | 教程地址  | 备注 |
| --- | --- | --- | --- |
| ASUS F455LD| [链接](https://github.com/athlonreg/ASUS-F455LD-i5-4210u)|||
| ASUS ZenBook   | [链接](https://github.com/hieplpvip/ASUS-ZENBOOK-HACKINTOSH) | [链接](https://www.tonymacx86.com/threads/guide-asus-zenbook-using-clover-uefi-hotpatch.257448/) | 支持型号: - UX310 (KabyLake) - UX330 (KabyLake) (not tested) - UX330 (KabyLake-R) - UX410 (KabyLake) - UX430 (KabyLake) - UX430 (KabyLake-R) |
| 惠普 probook/elitebook/zbook 系列| [链接](https://github.com/RehabMan/HP-ProBook-4x30s-DSDT-Patch) | [链接](https://www.tonymacx86.com/threads/guide-hp-probook-elitebook-zbook-using-clover-uefi-hotpatch.261719/) | 除8x60W,8x70W系列之外的机型，二代 CPU 及之前的机型仅支持到10.13.x |
| 惠普Envy Haswell  J/K/Q/N系列笔记本| [链接](https://github.com/RehabMan/HP-Envy-DSDT-Patch)   | [链接](https://www.tonymacx86.com/threads/guide-hp-envy-haswell-series-j-k-q-n-using-clover-uefi.261724/) | 仅4代envy 机型   |
| 联想 Y50(70)系列 | [链接](https://github.com/RehabMan/Lenovo-Y50-DSDT-Patch)| [链接](https://www.tonymacx86.com/threads/guide-lenovo-y50-uhd-or-1080p-using-clover-uefi.261723/) | Y50(70)1080P和4K 版本|
| 联想 U330/U430/U530系列  | [链接](https://github.com/RehabMan/Lenovo-U430-Touch-DSDT-Patch) | [链接](https://www.tonymacx86.com/threads/guide-lenovo-ideapad-u330-u430-u530-using-clover-uefi.261722/) ||
| Lenovo Z50(40)-70系列| [链接](https://github.com/the-braveknight/Lenovo-X50-macOS)  | [链接](https://www.tonymacx86.com/threads/guide-lenovo-z50-70-z40-70-g50-70-g40-70-using-clover-uefi.261787/) | Lenovo Z50-70/Z40-70 (use make install_z50) Lenovo G50-70/G40-70 (use make install_g50) |
| Lenovo Y520/Y720 | [链接](https://github.com/the-braveknight/Lenovo-Y520-macOS) | [链接](https://www.tonymacx86.com/threads/guide-lenovo-legion-y520-y720-using-clover-uefi.261009/) | 联想Y520及Y720   |
| ThinkPad E550  | [链接](https://github.com/the-braveknight/Lenovo-ThinkPad-E550-DSDT-Patch) | [链接](https://www.tonymacx86.com/threads/guide-lenovo-thinkpad-e550-haswell-using-clover-uefi-10-11.214675/) | E550四代 CPU |
| ThinkPad X1 3rd| [链接](https://github.com/shockingpants/ThinkpadX1Y3)| [链接](https://www.tonymacx86.com/threads/guide-thinkpad-x1-yoga-3rd-gen-20ld-with-mojave.261823/) | ThinkPad X1 3代  |
| ThinkPad T420系列| [链接](https://github.com/tluck/Lenovo-T420-Clover)  | [链接](https://www.insanelymac.com/forum/topic/285678-lenovo-thinkpad-t420-with-uefi-only/?page=20&tab=comments#comment-1952283) | 包含T420、T420s、T520、X220X220，可通过修改支持到10.14.x |
| ThinkPad T460系列| [链接](https://github.com/tluck/Lenovo-T460-Clover)  | [链接](http://www.insanelymac.com/forum/topic/315451-guide-lenovo-t460-macos-with-clover/) | 可支持 T460、T560、T470和 T470p4款机型 |
| ThinkPad T470P | [链接](https://github.com/lohcve/EFI_T470P)| [链接](https://github.com/lohcve/EFI_T470P/blob/master/README.md) | ThinkPad T470p   |
| ThinkPad T480s | [链接](https://github.com/kk1987/T480s-hackintosh) [链接](https://github.com/linusyang92/macOS-ThinkPad-T480s) [链接](https://github.com/samuelshi/Thinkpad-T480S) | [链接](https://github.com/linusyang92/macOS-ThinkPad-T480s/blob/master/README.md) [链接](https://github.com/kk1987/T480s-hackintosh/blob/master/README.md) | ThinkPad T480s   |
| ThinkPad X260系列| [链接](https://github.com/daliansky/ThinkPad-X260-hackintosh) | [链接](https://github.com/daliansky/ThinkPad-X260-hackintosh/blob/master/README.md) | ThinkPad X260|
| 英特尔Intel DH67GD, DH67BL, DH67CF, DH67CL系列主板 | [链接](https://github.com/RehabMan/Intel-DH67XX-DSDT-Patch)  | [链接](https://www.tonymacx86.com/threads/guide-intel-dh67xx-with-hd3000-using-clover-uefi-hotpatch.233257/) | Intel DH67GD, DH67BL, DH67CF, DH67CL系列主板 |
| 技嘉GB-BXi5H-4200 系列主板   | [链接](https://github.com/RehabMan/Gigabyte-BRIX-s-DSDT-Patch) | [链接](https://www.tonymacx86.com/threads/guide-gigabyte-brix-using-clover-uefi-gb-bxi5h-4200-gb-bxi5-4570r-gb-bxi7-4770r.261710/) | 技嘉GB-BXi5H-4200 系列主板 |
| 英特尔 NUC 5、6、7、8系列| [链接](https://github.com/RehabMan/Intel-NUC-DSDT-Patch) | [链接](https://www.tonymacx86.com/threads/guide-intel-kaby-lake-nuc7-using-clover-uefi-nuc7i7bnh-nuc7i5bnk-nuc7i3bnh-etc.261711/) | mini 主机|
| MibookAir  | [链接](https://github.com/ourfor/Mibook-air) | [链接](https://github.com/ourfor/Mibook-air/blob/master/README.md) | 小米 Air |
| XiaoMi Pro 系列| [链接](https://github.com/daliansky/XiaoMi-Pro)  | [链接](https://github.com/daliansky/XiaoMi-Pro/blob/master/README-CN.md) | 小米 Pro系列 |
| XiaoMi 游戏本8代 | [链接](https://github.com/daliansky/XiaoMi-GLP)  || 小米游戏本，猜的 |
| Dell-Inspiron-7000-i5-7559   | [链接](https://github.com/athlonreg/Dell-Inspiron-7000-i5-7559) |||
| Dell 7000系列  | [链接](https://github.com/daliansky/dell7000)| [链接](https://github.com/daliansky/dell7000/blob/master/README.md) | Dell Inspiron 7000 I/II (7x60/7x72)|
| Dell 7460和7560| [链接](https://github.com/xzhih/dell-7460-7560-hackintosh)   | [链接](https://github.com/xzhih/dell-7460-7560-hackintosh/blob/master/README.md) | 戴尔7460和7560   |
| Dell-Inspiron-15-7000-i7-8550u   | [链接](https://github.com/athlonreg/Dell-Inspiron-15-7000-i7-8550u) |||
| Dell XPS 9560  | [链接](https://github.com/gunslinger23/XPS15-9560-High-Sierra) | [链接](https://github.com/gunslinger23/XPS15-9560-High-Sierra/blob/master/README.md) | Dell XPS 9560|
| Dell-7559-Hackintosh | [链接](https://github.com/crackself/Dell-7559-Hackintosh)| [链接](https://github.com/crackself/Dell-7559-Hackintosh/blob/Hotpatch/README.md) | Dell 7559|
| Dell M3800/XPS9530   | [链接](https://github.com/syscl/M3800) | [链接](https://github.com/syscl/M3800/blob/M3800/README.md)  | Dell M3800和 XPS 9530|
| Dell XPS 9530  | [链接](https://github.com/the-darkvoid/XPS9530-OSX/tree/10.13) | [链接](https://www.tonymacx86.com/threads/guide-dell-xps-9530-clover-uefi-hotpatch.235558/) | XPS 9530 |
| Dell XPS 9350  | [链接](https://github.com/syscl/XPS9350-macOS)   | [链接](https://github.com/syscl/XPS9350-macOS/blob/master/README.md) | Dell XPS 9350|
| Dell 3543  | [链接](https://github.com/arisskz6/Dell-3543-Hackintosh) |||
| Dell 3442  | [链接](https://github.com/kkzzhizhou/Dell-3443-Hackintosh)   | [链接](https://github.com/kkzzhizhou/Dell-3443-Hackintosh/blob/master/README.md ) | Dell 3443|

### 台式机部分机型

引用自：国光之前维护的仓库地址：[链接](https://github.com/sqlsec/clover/tree/master/%E5%8F%B0%E5%BC%8F%E6%9C%BA)

### Github 上一些贡献者的配置

- [Acer Aspire E1-471G](https://github.com/matthew728960/Clover-ACER-E1-471G)
- [Acer V5-573G](https://github.com/Kaijun/Acer-V5-573G-Hackintosh)
- [Acer Aspire E5-571-376T](https://github.com/GalaticStryder/Acer-E5-571-Hackintosh)
- [Acer Aspire V3-371-52FF](https://github.com/Ty3uK/52ff-elcapitan-toolbox)
- [Acer Aspire E5-473-30N5](https://github.com/b-ggs/aspire-e5-hackintosh)
- [Acer Aspire V3-572G](https://github.com/FREDwiz/Hackintosh)
- [Alienware 17 R4 KBL-1060 Dual Graphics](https://github.com/RockJesus/Alienware-17-R4-I7-7700HQ-MacOS-High-Sierra)
- [Asus FX50J/X550JX](https://github.com/Xc2333/Hackintosh-ASUS-FX50J)
- [Asus H81M-K](https://github.com/Slbomber/AsusH81MK-macos)
- [Asus Zenbook](https://github.com/hieplpvip/ASUS-ZENBOOK-HACKINTOSH)
- [Asus Vivobook S510UA](https://github.com/tctien342/Asus-Vivobook-S510UA-High-Sierra-10.13-Hackintosh)
- [Asus ROG Zephyrus S GX531](https://github.com/williambj1/Hackintosh-EFI-Asus-Zephyrus-S-GX531)
- [Dell 7559 4K SKL](https://github.com/RockJesus/Dell-7559-I7-6700HQ-4K-touch-MacOS-High-Sierra)
- [Dell XPS13-9350-Skylake](https://github.com/syscl/XPS9350-macOS)
- [Dell XPS15-9550](https://github.com/corenel/XPS9550-macOS)
- [Dell XPS15-9550](https://github.com/PromiseYo/XPS15-9550-macOS)
- [Dell XPS13-9360](https://github.com/the-darkvoid/XPS9360-macOS)
- [Dell XPS15-9530-Haswell](https://github.com/the-darkvoid/XPS9530-OSX)
- [Gigabyte GA-Z77-DS3H](https://github.com/tkrotoff/Gigabyte-GA-Z77-DS3H-rev1.1-Hackintosh)
- [Gigabyte GA-H97-D3H](https://github.com/korzhyk/Clover_GA-H97-D3H)
- [Gigabyte GA-Z270M-D3H](https://github.com/LER0ever/Hackintosh)
- [Gigabyte X99P-SLI](https://github.com/koush/EFI-X99)
- [Gigabyte Aero15-W](https://github.com/Errrneist/Hackintosh-Aero-15W)
- [Gigabyte z170x ud3 ultra](https://github.com/RoJoHub/Hackintosh)
- [Gigabyte Sabre15K](https://github.com/gnehs/Sabre15KClover)
- [Lenovo chao 5000](https://github.com/Xc2333/Hackintosh-Lenovo-chao5000)
- [Lenovo G50-70M](https://github.com/LEXUGE/macOS-Lenovo_G50-70M)
- [Lenovo Thinkpad P50](https://github.com/Errrneist/Hackintosh-Thinkpad-P50)
- [Lenove Thinkpad T450](https://github.com/shmilee/T450-Hackintosh)
- [Lenovo Thinkpad T460P](https://github.com/LER0ever/Hackintosh)
- [Lenovo T430s](https://github.com/dmitriypavlov/T430s-macOS)
- [Lenovo T430-NVS5400M](https://github.com/david-cako/T430-Hackintosh)
- [Lenovo T450s](https://github.com/stevenmirabito/T450s-Hackintosh)
- [Lenovo U330/U430/U530](https://github.com/RehabMan/Lenovo-U430-Touch-DSDT-Patch)
- [Lenovo Y470](https://github.com/Dwarven/Hackintosh/tree/master/Lenovo%20Y470)
- [Lenovo Y50-70](https://github.com/RehabMan/Lenovo-Y50-DSDT-Patch)
- [Lenovo Z50-70](https://github.com/Maxvien/hackintosh-lenovo-z5070)
- [Lenovo B470](https://github.com/0xE8551CCB/hackintosh)
- [Lenovo G470](https://github.com/hunterMG/DSDT-Lenovo-G470)
- [Lenovo T470 (i5-6300U)](https://github.com/okay/t470)
- [Lenovo x230](https://github.com/edu-rinaldi/Lenovo-x230-High-Sierra)
- [Lenovo Yoga 3 Pro](https://github.com/zohaad/hackintosh-Yoga-3-Pro)
- [Lenovo-v3000-ISE](https://github.com/Xc2333/Hackintosh-Lenovo-v3000-ISE)
- [Lenovo-rescuer-15-isk](https://github.com/oneplusdash/lenovo-rescuer-15-isk-hackintosh)
- [Lenovo Ideapad 310-14IKB](https://github.com/29satnam/LenovoHackintoshEFI)
- [Lenovo-XiaoXin700-15ISK](https://github.com/athlonreg/Lenovo-XiaoXin700-15ISK)
- [HUANAN X79](https://github.com/cheneyveron/clover-x79-e5-2670-gtx650)
- [HP ProBook/EliteBook/ZBook](https://github.com/RehabMan/HP-ProBook-4x30s-DSDT-Patch)
- [HP Elitebook 8470p](https://github.com/minhphuc429/hackintosh-hp-elitebook-8470p)
- [HP Elitebook 8470p](https://github.com/dreadkopp/8470p_10.13.x)
- [HP Elitebook 840 G1/G2](https://github.com/loicpirez/HackintoshConfig)
- [HP Elitebook Folio 9480m](https://github.com/obviouslyerratic/clover_9480m)
- [HP EliteDesk 800 G2 TWR](https://github.com/sakoula/HP-EliteDesk-800-G2-6700)
- [HP Envy J-series](https://github.com/RehabMan/HP-Envy-DSDT-Patch)
- [HP Envy K-series](https://github.com/RehabMan/HP-Envy-K-DSDT-Patch)
- [HP Envy Q-series](https://github.com/RehabMan/HP-Envy-Q-DSDT-Patch)
- [HP Envy N-series](https://github.com/RehabMan/HP-Envy-N-DSDT-Patch)
- [HP Z420 Workstation](https://github.com/NTT123/Hackintosh-HP-Z420-MacOS-High-Sierra-10.13)
- [Samsung 450r5j](https://github.com/LER0ever/Hackintosh)
- [Samsung nt550p7c-IVY](https://github.com/RockJesus/samsung-nt550p7c-sierra)
- [XiaoMi NoteBook Pro](https://github.com/daliansky/XiaoMi-Pro)
- [Xiaomi Mi Air 13.3 Skylake-U 2016 (1rst Gen)](https://github.com/sakoula/XiaoMi-Air-6200U)



