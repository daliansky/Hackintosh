## 更新日志：
- 2026年 11月 18日
   - 新增驱动：
     - AMD: RedNavi (RX 7800 XT / RDNA3)、RX 9060 XT (Navi 44)、Tahiti VCE H.264 编码
     - NVIDIA: RTXDarwin (RTX 3060 研究)、NVDAAL Driver (RTX 40 系计算)
     - WiFi: RTL8814Native (RTL8814AU + AWDL)、ForbiddenItlwm、AX200 蓝牙修复
   - 新增 AMD Radeon 机型：
     - MSI Bravo 15 B7ED (Ryzen 5 7535HS + 660M)
     - MSI Bravo 15 C7VFKP (Ryzen 7 7735HS)
     - WOOKING X15 (8745HS + 780M)、MECHREVO 无界14XA (H255 + 780M)
     - Beelink SER 5800H、AMD Athlon PRO 300U 迷你主机
   - 新增 Intel 核显机型：
     - Samsung Galaxy Book3 Ultra (OLED 120Hz)、X-STATION V2
     - Monster Abra A5 V19.2、dynabook G83/HS、ASUS VivoBook X415JA
     - ASUS ROG Strix SCAR 18 G835LXG、ASUS TUF F16 FX607JVB
     - ThinkBook 14+ 2024 (Meteor Lake)
   - 新增 NVIDIA 机型：
     - ASUS ROG Strix FX607VJ (RTX 3050)、Legion Y7000P IRX10 详版 + 触控板方案
     - Ryzen + RTX 通用 EFI、Dell G15 风扇控制工具
   - 新增笔记本机型：
     - ThinkPad T490 (OC 版)、T14 G2、X1 Carbon 6th Gen (OC 1.0.2)
     - HUAWEI MateBook D15 2020 / D16、Lenovo Legion R7000 2020
     - Lenovo IdeaPad Flex 5 14ITL05、Yoga 920 (80Y7)
     - Acer Nitro 5 AN515-46、HP 15s-dy0xxx
     - Dell Latitude 5300 / 7400 2-in-1 / Inspiron 15 3511 / PowerEdge T40
   - 新增台式机/迷你机型：
     - Gigabyte Z390 Designare (i9-9900K + RX 580)
     - MSI B760M BOMBER DDR4 (i5-13400F + RX 6650 XT)
     - Intel NUC8 Bean Canyon、Lenovo ThinkCentre M720q Tiny / ThinkStation P320 Tiny
     - Alienware x14 R1、GPD P2 Max 2019

- 2026年 11月 17日
   - 新增机型（NVIDIA 笔记本）：
     - ASUS TUF FA607PI (Ryzen 9 7940HX + RTX 4070)
     - Legion Pro5 16IRX9 (RTX 5060)
     - GTX 1650 + AMD Renoir (Turing TU117)
     - RTX 2070 Super (NullMoth 驱动适配)
   - 新增机型（Intel 核显）：
     - ASUS Vivobook X513EP (i7-1165G7)
     - Dell XPS 13 Plus 9320 (i7-1360P Raptor Lake)
     - Dell XPS 17 9720 (i9-12900HK Alder Lake)
     - Dell OptiPlex Micro (i7-12700T UHD 770)
     - ThinkPad T15 Gen2 (Tiger Lake)
     - Dynabook G83 (PORTEGE X30L-J)
     - HP EliteBook 830 G8 (11th Gen)
     - Alder Lake-H MoDT (i7-13500H)
     - ThinkBook 14 G5+ IRH (i5-13500H)
   - 新增 AMD Radeon 参考机型：
     - Lenovo m75q Gen3 (Ryzen 7 5700G + Pro WX4100)
     - B850M + Ryzen 5 9600X + RX 570 / 5500 XT
     - MECHREVO 无界15XA / 无界14X Pro / 同方 7840HS (Ryzen 780M)
   - 新增驱动 & 工具：
     - NVIDIA optC CI (NullMoth v3.0)
     - NullMoth Audio
- 2026年 11月 16日
   - 新增机型：
     - Lenovo Yoga 9 15IMH5
     - ASUS Pro WS C621-64L SAGE
     - Clevo NH50RA
   - 新增 NVIDIA（NullMoth 驱动）机型汇总：
     - 台式机：B550M/5600X + RTX 5070、H610M/14400F + RTX 5060、14600KF + RTX 3060、B550/5600G + RTX 2070、B760M/12400F + RTX 4060、i7-6700K + RTX 2080 Super、RTX 5060 Ti、Arrow Lake 245K + RTX 3070、RTX 4090、RTX A5000、ROG G16 QEMU/KVM + RTX 4060
     - 笔记本：Legion Y7000P IRX10 + RTX 5060、Lenovo R7000P 2025 + RTX 5060、Y9000P IRX9 + RTX 4060、Y540-17IRH + GTX 1660 Ti、Legion Y7000P 2020H + RTX 2060、Razer Blade 18 + RTX 4080、ROG GU603ZM + RTX 3060、OMEN 8f06 + RTX 5060、MECHREVO GM5AR5E + RTX 4050、Dell G15 5530 + RTX 4050、HP Victus 15 fa2xxx + RTX 4050、HP Victus 15 fa0xxx + RTX 3050 Ti、ASUS TUF A14 + RTX 4050、Gigabyte Gaming A16 + RTX 5050、Acer AN515 + RTX、MECHREVO 极光X + RTX 5060、MECHREVO 蛟龙 + RTX 5070、MSI GF63 Thin 9SCX + GTX、OEMN15 1082TX + RTX 2070、ROG Strix SCAR17 + RTX 3060
   - 新增无线网卡（WiFi）支持列表：
     - 博通 BCM94360Z4（隔空接力完整支持）
     - Intel AX200/AX201/AX210/AX211、BE200/BE201（AirportItlwm）
     - MediaTek MT7921/MT7922（AirportMtkWlan）
     - Realtek RTL8188E/RTW88/RTW89
     - Atheros AR946x/AR5Bxx
   - archey 修复：多 NVMe 盘显示、磁盘空间统计、扩展显示器隐藏
   - BCM94360Z4/BCM94360Z4_Web 修复：移除 SMBIOS 三码信息显示
   - 移除 Apple Silicon 引导参数显示
- 2026年 6月 18日
   - 新增机型：
     - Asus X550VQ
     - Dell Latitude 7410
     - Dell OptiPlex 7070 MFF
     - ThinkPad E14 Gen2 AMD
- 2026年 4月 9日
   - 新增机型：
     - ASRock Z890I Nova WiFi
     - ASUS Z890 MAX GAMING WIFI7 
     - Asus PRIME Z890M-PLUS WIFI
     - ASUS PRIME Z890-P
     - Asus ROG Strix Z890-A Gaming WiFi S
     - Gigabyte B860M AORUS ELITE WIFI6E ICE
     - Z890M AORUS ELITE WIFI7 ICE
     - MSI MPG Z890I EDGE WIFI 
     - MSI Z890-P Wifi 7
     - MSI Z890 EDGE TI
- 2024年3月4日
   - 新增机型：
     - FEVM FN60G
     - minisforum UM480XT
     - minisforum UM560XT
     - minisforum UM580D/UM590
     - minisforum NAG6
- 2023年10月10日
   - 新增机型：
      - HP OMEN 15 2017 15-ax218TX
      - 华南X99TF
      - NUC8-BEH/BEK
      - NUC9QNX
      - morefine M600s
- 2023年1月19日
   - 新增机型：
      - ASUS PRIME Z790 P WIFI D4
      - Gigabyte Z790 Aorus Elite
      - Gigabyte Z790 Aorus Master
      - MSI Z790i EDGE
      - 铭瑄z790m
- 2022年11月21日
   - 新增机型：
     - Gigabyte B360M AORUS PRO 
     - Lenovo IdeaPad 300-15ISK  
     - MSI Z490-A PRO
     - MSI H81M P33   
     - Airbook 颜值版 i5 6200u（Ventura）
     - Infinix INBook X1
     - MSI X470 gaming PRO MAX 
     - MAG B660M MORTAR WIFI DDR4
     - DELL VOSTRO 14 3401
     - Alienware M15R2
     - Asus Vivobook X515JA
     - Asus VivoBook A412F
     - Acer Nitro 5 AN515-52-593F
     - ThinkPad L470 
     - Dell G5 5500 
     - ASUS ROG Z590-A-Gaming-WIFI-II
     - Gigabyte Z590 Vision G
- 2022年4月22日
   - 新增机型：
     - Acer Nitro 5 an517-51-55NT 
     - HP ENVY x360 - 15-bp103tx 
     - HP Elitebook 820 G3 
     - HP Pavilion Laptop 14-ce3xxx 
     - MSI GT60 16F4
     - Asus ROG Strix X570-E Gaming
     - HP Prodesk 600 G3
- 2022年1月12日
   - 新增机型：
      - Dell OptiPlex 7080 MT
      - Gigabyte Z690 Aorus Elite AX 
      - HP Pavilion 15 cb008nt
      - Asus ROG STRIX B350-I GAMING
      - Dell Latitude 5300
      - MSI B450M MORTAR
      - MSI B350M Gaming Pro
      - MSI X370 Krait Gaming
      - X99 K9 v2 Machinist
      - Gigabyte Z690 Aorus Pro
      - 华为 Matebook X Pro 2020
      - Asus PRIME X570-P 
      - Dell Inspiron 7501
- 2021年12月16日
   - 新增机型：
      - Acer Aspire 3 A315-56
      - Asus TP412FA
      - LG Gram 14Z90N
      - Samsung NT350XCR-AD5AS
- 2021年12月3日
   - 新增机型：
      - Asus UX32VD
      - ASRock H510M-HDV
      - Asus ROG STRIX Z490-F GAMING
      - Lenovo B50-80 80EW
- 2021年11月29日
   - 新增机型：
      - Acer Nitro 5 AN515-54-51NJ
      - HP Pavilion 16 a000x
      - HP Pavilion 550
      - Dell OptiPlex 7080 MT
      - Asus PN62
      - HP ProDesk 680 G3 MT
- 2021年11月23日
   - 新增机型：
      - Toshiba Satelite Pro L850-1UJ
      - Lenovo ThinkCentre M920X
      - Dell Vostro 5590
      - Dell Inspiron 5593
      - Dell OptiPlex 3080
      - Asus ROG STRIX B560-I GAMING WIFI
      - Acer Aspire A515-53G-5269
      - HP Elitebook 9480m
      - Asus ROG STRIX B550-A GAMING  
      - Gigabyte Z490M
- 2021年11月15日

   - 新增机型：
      - ASUS Vivobook Pro 15 N580GD
      - Dell XPS 15 9500
      - Lenovo ThinkPad L14 Gen1
      - Lenovo Thinkpad P1 Gen1
      - Asus Prime Z690M Plus
- 2021年11月11日

   - 新增机型：

      - Asus ROG Strix G17 G712LW
      - HP Probook 440 G6
      - Gigabyte X399 Aorus Extreme
      - MSI B550 A-Pro
- 2021年11月8日

  - 新增机型：
    - Dell Inspiron 5493/5593
    - Lenovo Ideapad S540 14IWL
    - Lenovo Ideapad Flex 5 14IIL05
    - Lenovo Yoga Duet 2020
    - Chuwi CoreBookX 14
- 2021年10月21日

  - 新增机型：
    - Asus FX505GT
    - Dell Inspiron 3647
    - HP ProBook 440 G3
    - MSI GF63 9SCSR 846VN
    - Gigabytes B560M AORUS Pro AX
    - morefine S500
- 2021年9月7日

  - 新增机型：

    - Acer Aspire A515-55
  - Asus FX55VD DM001D
    - Dell Latitude 3400
  - MSI GF63 8RD
- 2021年6月22日

  - 新增机型：
    - Acer Aspire V3-371
    - Asus X411UF
    - Dell Latitude E6230
    - HP Zbook G1
    - HP Zbook 15 G2
    - HP Pavilion 15-cs0093ca
    - avita liver v-14
    - Dell ChengMing 3991
    - HP 288 Pro G5
    - Lenovo Ideacenter A340
- 2021年5月28日

  - 新增机型：
    - HP Probook 430 G3
    - ThinkPad e490s
    - Lenovo Yoga X390
    - 三星 Samsung NP350XAA-KF3BR
    - ASRock B560M-HDV
    - ASRock B560M-ITX
    - ASRock B560 Steel Legend
    - Asus TUF Gaming B560M PLUS
    - Asus Z590 ROG MAXIMUS XIII HERO
    - HP Omen 30L
- 2021年5月12日

  - 新增机型：

    - Dell Latitude 5310
    - Asrock deskmini H470m
    - ONDA B460 SD4
- 2021年4月12日

  - 新增机型：
    - Dell Inspirion 15 3576
    - HP Elite X2 G4 平板
    - Lenovo IdeaPad Gaming 3i
    - minisforum U820
    - ASUS PRIME B250M-K
    - ASROCK B560 STEEL LEGEND
    - 51nb T70 ThinkPad 副厂主板
- 2021年4月2日

  - 新增机型：
    - Asus VivoBook FL8000u
    - Dell Inspiron 3568
    - Dell Latitude E7370
    - Dell Vostro 3468
    - Dell Vostro 5581
    - HP Pavilion 15 au624tx
    - Lenovo Ideapad S540 14IWL
    - Gigabyte H410M S2H
- 2021年3月22日
  - 新增机型：
    - Asus X540LJ
    - HP 15 da0004tu
    - HP 15G BR011TX
    - Asus Z490 AORUS PRO AX
    - Huananzhi x99 f8
- 2021年3月17日
  - 新增机型：
    - Asus X542u
    - Asus ZenBook UX305UA
    - Dell Inspriron 14 3467
    - Dell Inspiron 7391
    - Dell Inspiron 7560
    - Dell Latitude E5270
    - 战神K670C-g6a1
    - HP Probook 450 G5
    - HP Pavilion ce3034nl
    - Lenovo IdeaPad 320S 14IKB
    - 三星Samsung NP350U-2B
    - 海尔Haier Y11C
    - Asrock B365M Pro4
    - ASRock Z170 Gaming K4
    - Asus H170M-PLUS
    - Asus Z170 Deluxe
    - Asus TUF Z390-PLUS GAMING
    - Dell Optiplex 5040
    - Dell Optiplex 5060MFF
    - Dell Optiplex 5070mff
    - Dell Optiplex 7020 SFF/MT
    - Dell XPS 8940 
    - Gigabyte H370m D3h
    - Lenovo v410z
    - MSI B250 GAMING PRO CARBON
    - MSI H61-P31/W8
    - MSI Z490 Gaming Plus
    - Onda P75U
- 2021年3月8日
  - 新增机型
    - Acer Aspire E5-575G
    - Acer Predator G3-571
    - Asus N550JK
    - Asus N550JV
    - 战神 G8-CU7NA
    - HP Elitebook 830 G7
    - HP Elitebook 840 G7
    - HP Elitebook 850 G7
    - Thinkpad X1 Carbon Gen 7
    - Lenovo Z410
    - LG 14U530
    - MSI GF63-10
    - 火影金刚GTX
    - MSI MAG B550M MORTAR WIFI
    - Asus H110M-C2 MoBo
    - Asus ROG STRIX H370-I GAMING
    - Asus Z170-Pro
    - ASUS ROG Z390-F Gaming
    - Dell Optiplex 5070mff
    - Gigabyte mdh11ki
    - MSI B250M MORTAR
- 2021年3月7日

  - 重新排版
- 2021年2月24日

   - 删除已失效的repo
- 2021年2月15日

  - 新增机型：

    - Asus FL5900U
    - Asus ROG Strix G15 - G512LV
    - Asus TUF 505GE
    - Asus VivoBook X509FB
    - Dell Latitude E5280
    - HP EliteBook 840 G4
    - HP EliteBook 840 G6
    - HP ZHAN99 zbook 15v g5
    - HP ZHAN 99 Pro G1 MT
    - Lenovo 昭阳 E49
    - Lenovo V730-15IKB
    - Lenovo XiaoXin V4000
    - Thinkpad X1 Carbon Gen 8
    - Lenovo Legion 5i
    - LG Gram 14Z990
    - LG Gram17 Z90n
    - Redmibook14增强版
    - Xiaomi Redmibook 16
    - 未来人类T5
    - CHUWI Minibook
    - Asus X470 Pro
    - ASRock H61M-S1 Plus
    - Gigabyte H170 HD3
    - HP Compaq Pro 4300
    - MSI B460I GAMING EDGE WIFI
    - MSI H270 GAMING M3
    - MSI H410M-PRO-VH
    - ONDA H410 SD4
- 2021年1月25日

  - 新增机型：
    - Asus ROG GL703ge
    - 战神Z7-SP7S2
    - HP Pavilion 15an051dx
    - Lenovo G40-80
    - Lenovo V110-15ISK
    - Shinelon T50TI
    - Asus P8P67 EVO
    - ASRock B85 Pro4
    - Gigabyte B150M-VP
    - Gigabyte Z490 UD
- 2021年1月20日

  - 新增机型：
    - HP 15 BS661TX
    - MSI GL62M 7RDX
    - FUJITSU 富士通 S762
    - ASUS ROG Strix X570-F Gaming
    - ASUS-Z490M-PLUS
    - Gigabyte Z490I AORUS ULTRA
    - Lenovo 天逸510S
    - Lenovo B360
- 2021年1月19日

  - 新增机型：
    - Acer Aspire V 15 V5-591G
    - Dell Latitude 5411
    - Dell Latitude 5511
    - 暗影精灵5 dc1010nr
    - Lenovo Ideapad S145-15IWL
    - 拯救者R720
    - MSI GE70 2OE
    - MSI GE72 2QE
    - ASUS B250M
    - Asus Prime H410M
    - ASRock Z390M-ITX/ac
    - Gigabyte B365M Aorus Elite
    - Gigabyte H87M-D3H
    - Gigabyte GA-Z170XP-SLI
    - MSI Z390-A PRO
- 2021年1月15日

  - 新增机型：
    - Asus ROG Strix G15 G512LU
    - Mi Notebook 14 2020
    - Gigabyte H110M H
    - Gigabyte Z390 DESIGNARE
- 2020年12月23日

  - 新增机型：
    - Acer Swift 3 SF314-54
    - Asus N551JK
    - ASUS ZenBook UX305FA
    - Lenovo Legion Y520
    - Gigabyte X570 UD
    - ASRock B460m HDV
    - Gigabyte Z370 HD3
    - MSI B360M Bazooka
    - MSI H410M BOMBER
    - 七彩虹CVN B460i
    - ......
- 2020年12月14日

  - 新增机型：
    - `NUC5I5RYH`
    - `NUC6I5SYH`
    - `Asus UX433FN`
    - `Dell Inspiron 5680`
    - `ThinkPad L430`
    - `Lenovo Legion Y545`
    - `Dell  Optiplex 7010`
    - `ASRock deskmini H470`
    - `Gigabyte H110M S2HP`
- 2020年12月2日

  - 新增机型：
    - `Lenovo Yoga C740-14IML`
    - `HP Notebook 15ac001tx`
    - `Dell Optiplex 5040`
    - `Acer TravelMate TX520-G2-MG`
    - `HP ProDesk 600 G2 DM`
    - ……
- 2020年11月26日

  - 新增机型：
    - `Acer Nitro 5 AN515-54`
    - `Asus H370i`
    - `Gigabyte Z390 I Aorus Pro WiFi`
- 2020年11月24日

  - 新增机型：`Ice Lake`等部分机型
- 2020年11月23日

  - 新增机型：Acer Aspire A514-52-37H1/ Gygabyte B550i Aorus Pro AX 等新机型
  - 新增机型：HP EliteDesk 800 G1/G2/G3/G4/G5
- 2020年10月29日

  - 新增N多机型：包括 `AMD`  /  `INTEL`等部分台式机型
- 2020年9月15日

  - 新增机型：Lenovo 天逸 510S Mini
- 2020年8月31日

  - 新增机型：新增战神Z7、G8系列部分机型，具体请看commit
- 2020年8月17日

  - 新增机型：新增B450等部分机型
- 2020年8月6日

  - 新增机型：新增B460/Z490等新机型
- 2020年7月31日

  - 新增机型：新增对`Big Sur`等机型的支持，新增部分新机型
- 2020年7月5日

  - 新增机型：新增ThinkPad T470p、ASUS-Prime-Z390M-PLUS、神舟战神z7-kp7sc、ASRock-B365M-ITX-AC等部分新机型
- 2020年6月30日

  - 新增机型：B460 / Z490 以及其它笔记本机型
- 2020年6月23日

  - 新增机型：新增Dell Latitude E7390等部分新机型
- 2020年6月19日

  - 新增机型：新增部分台式机型，基于OpenCore
- 2020年6月12日

  - 新增机型：新增DELL 9020 MT/SFF/USFF/Micro机型，基于OpenCore
- 2020年6月10日

  - 新增机型：新增Lenovo Thinkcentre M910x等部分新机型
- 2020年6月8日

  - 新增机型：新增Z490等部分台式机型
- 2020年5月5日

  - 新增机型：联想M710Q等
  - 将台式机品牌重新分类、整理，便于查看相关信息
- 2020年4月22日

  - 新增机型：光影精靈4代/MSI-MPG-Z390-Gaming-EDGE-AC
- 2020年4月8日

  - 新增机型：联想Miix 720/YOGA 910等机型
- 2020年3月14日

  - 新增机型：Lenovo G400
- 2020年3月8日

  - 新增机型：华为Matebook 14 2020款
- 2020年2月15日

  - 新增机型：ASUS VivoBook FL8000UQ
- 2020年1月18日

  - 新增机型：DELL系列/Lenovo系列等机型
- 2019年11月21日

  - 新增机型：Dell XPS 15 7590
- 2019年11月14日

  - 新增机型：Lenovo Y9000X
- 2019年11月4日 by [YGQ8988](https://github.com/YGQ8988)

  - 新增机型：HP ProBook 430 G6
- 2019年10月28日 by [W-MS](https://github.com/W-MS)

  - 新增机型：Dell OptiPlex 7060 and 7070
  - 增加新版本支持： Dell OptiPlex 9020
- 2019年10月19日 by [kongbg](https://github.com/kongbg)

  - 新增机型：ASUS K555LD
- 2019年10月5日 by [sarkrui](https://github.com/sarkrui)

  - 新增机型：ASRock Z390M Pro4 + i7-9700K + Sapphire RX580 Nitro+ 8G
- 2019年10月5日 by [我意](https://github.com/y010204025)

  - 新增机型：lenovo miix4(700)、miix510、E470
- 2019年9月17日 by [skyline75489](https://github.com/skyline75489)

  - 新增机型：`MSI GE63 Raider RGB 8RE`
- 2019年9月7日 by [lgs3137](https://github.com/lgs3137)

  - 新增机型：`Acer P258-MG`
- 2019年9月1日 by [lgs3137](https://github.com/lgs3137)

  - 新增机型：`ASUS Y5000U`(X507UBR)
- 2019年8月16日

  - 新增机型：MSI X370 KRAIT GAMING + 1700X + RADEON VEGA64
  - 新增机型：ASROCK X570 TAICHI + 3700X + RADEON VEGA64，兼容ASROCK X570 TAICHI(BIOS<=1.21) + 1700X + RADEON VEGA64
- 2019年8月15日

  - 新增机型：ASUS X299 PRIME DELUXE II + i9 7980XE + Radeon VII
- 2019年7月19日 by [lgs3137](https://github.com/lgs3137)

  - 新增机型：`暗影精灵I`(惠普PAVILION Gaming NB 15-ak039TX)
- 2019年7月3日 by [Cruii](https://github.com/Cruii)

  - 新增机型：`暗影精灵2Pro`(HP OMEN 15-ax225TX)
- 2019年5月10日 by [明城](https://github.com/mingcheng)

  - 新增机型：`Lenovo M93P` / `Dell 9020m` 等机型
- 2019年5月9日

  - 新增机型：`Mechrevo X9Ti R` / `Mechrevo Z2 G` 等
- 2019年4月2日

  - 添加部分新机型
  - 将多于2个机型的品牌独立出来，方便检索
- 2018 年 10 月 06 日
- 2018 年 12 月 25 日
- 2019 年 01 月 15 日
- 2019 年 3 月 1 日 by 黑果小兵

  - 按机型重新排版
  - 将该文档上传到仓库，方便其它人提交合并，共同维护
