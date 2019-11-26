**如果有比较实用的软件或者是 kext 驱动，都可以加到清单里面哟^^**

## 1.软件类

| 软件名称             | 链接地址                                     | 主要用途                                     |
| ---------------- | ---------------------------------------- | ---------------------------------------- |
| Clover  | [链接](https://sourceforge.net/projects/cloverefiboot)  |  EFI引导工具，ACPI 代码加载和相关驱动的实现基础  |
| Clover Configurator  | [链接](https://mackie100projects.altervista.org/download-clover-configurator)  |  Clover配置工具，记得时常更新哦  |
| DarwinDumper  | [链接](https://bitbucket.org/blackosx/darwindumper/downloads)  | 类似于 AIDA64的工具，很实用，用的人不多，蛮可惜的  |
| Hackintool  | [链接](https://www.insanelymac.com/forum/topic/335018-hackintool-v224)  | 修补Framebuffer、实现 USB 端口定制以及 AppleALC layout-id 节点选择  |
| IORegistryExplorer  | [链接](https://www.tonymacx86.com/attachments/ioregistryexplorer-slrid_v10-6-3-zip.24086)  | 查看系统 I/O 信息以及驱动和设备的附属关系  |
| MaciASL  | [链接](https://github.com/acidanthera/MaciASL/releases)  | AML的编译器和IDE，用于修改DSDT和制作热补丁  |
| OSX-Debug  | [链接](https://github.com/black-dragon74/OSX-Debug)  | 收集原始ACPI表，驱动，崩溃日志等相关信息的脚本，用于给大神反馈问题  |
| ProperTree | [链接](https://github.com/corpnewt/ProperTree)  | OpenCore 官方推荐的配置工具 | 

## 2.驱动类

### Lilu和它的插件

| 驱动名称             | 链接地址                                     | 主要用途                                     |
| ---------------- | ---------------------------------------- | ---------------------------------------- |
| Lilu  | [链接](https://github.com/acidanthera/Lilu)  | 驱动注入框架，AppleALC, WhateverGreen, VirtualSMC等驱动的依赖  |
| AirportBrcmFixup  | [链接](https://github.com/acidanthera/AirportBrcmFixup)  | 博通无线网卡驱动  |
| AppleALC  | [链接](https://github.com/acidanthera/AppleALC)  | 声卡注入框架  |
| ATH9KFixup  | [链接](https://github.com/chunnann/ATH9KFixup)  | Atheros网卡驱动  |
| BT4LEContiunityFixup  | [链接](https://github.com/acidanthera/BT4LEContiunityFixup)  | 开启接力，隔空投送等功能  |
| CPUFriend  | [链接](https://github.com/acidanthera/CPUFriend)  | 注入CPU动态电源数据的驱动  |
| DiskArbitrationFixup | [链接](https://github.com/Goldfish64/DiskArbitrationFixup)  | 禁止“此电脑不能读取您插入的磁盘”提示  |
| HibernationFixup  | [链接](https://github.com/acidanthera/HibernationFixup)  | 修复休眠问题  |
| NightShiftUnlocker | [链接](https://github.com/0xFireWolf/NightShiftUnlocker)  | 开启夜览功能  |
| NoTouchID  | [链接](https://github.com/al3xtjames/NoTouchID)  | 禁用触控 ID支持  |
| SystemProfilerMemoryFixup  | [链接](https://github.com/Goldfish64/SystemProfilerMemoryFixup)  | 显示关于本机的内存标签  |
| VirtualSMC  | [链接](https://github.com/acidanthera/VirtualSMC)  | SMC仿冒驱动，和FakeSMC二选一 |
| WhateverGreen  | [链接](https://github.com/acidanthera/WhateverGreen)  | 显卡注入框架，集成了很多补丁 |

### 其它

| 驱动名称             | 链接地址                                     | 主要用途                                     |
| ---------------- | ---------------------------------------- | ---------------------------------------- |
| AppleBacklightFixup  | [链接](https://bitbucket.org/RehabMan/applebacklightfixup)  | 亮度调节驱动，已集成进WhateverGreen v1.2.5  |
| EFICheckDisabler  | [链接](https://github.com/RehabMan/hack-tools/tree/master/kexts/EFICheckDisabler.kext)  | 禁止macOS EFI开机检查  |
| OS-X-ACPI-Battery-Driver  | [链接](https://bitbucket.org/RehabMan/os-x-acpi-battery-driver) | 电池驱动  |
| OS-X-BrcmPatchRAM  | [链接](https://bitbucket.org/RehabMan/os-x-brcmpatchram)  | 博通蓝牙驱动  |
| OS-X-EAPD-Codec-Commander  | [链接](https://bitbucket.org/RehabMan/os-x-eapd-codec-commander)  | 修复声卡休眠无声的驱动  |
| OS-X-Fake-PCI-ID  | [链接](https://bitbucket.org/RehabMan/os-x-fake-pci-id)  | 硬件 ID 仿冒驱动  |
| OS-X-FakeSMC-kozlek  | [链接](https://bitbucket.org/RehabMan/os-x-fakesmc-kozlek)  | SMC仿冒驱动，和VirtualSMC二选一  |
| OS-X-Intel-Network  | [链接](https://bitbucket.org/RehabMan/os-x-intel-network)  | Intel有线网卡驱动(部分)  |
| OS-X-Null-Ethernet  | [链接](https://bitbucket.org/RehabMan/os-x-null-ethernet)  | 仿冒有线网卡到en0端口，帮助连接AppleStore等  |
| OS-X-Realtek-Network  |  [链接](https://bitbucket.org/RehabMan/os-x-realtek-network) | Realtek有线网卡驱动  |
| OS-X-USB-Inject-All  | [链接](https://bitbucket.org/RehabMan/os-x-usb-inject-all)  | USB端口注入框架  |
| RTL8111_driver_for_OS_X  | [链接](https://github.com/Mieze/RTL8111_driver_for_OS_X)  | Realtek RTL8111/8168有线网卡驱动  |
| SATA-unsupported  | [链接](https://github.com/RehabMan/hack-tools/tree/master/kexts/SATA-unsupported.kext)  | SATA硬盘驱动  |
| VoodooI2C  | [链接](https://github.com/alexandred/VoodooI2C)  | I2C触控板驱动  |
| VoodooPS2Controller  | [链接](https://github.com/acidanthera/VoodooPS2)  | PS2键盘和触控板驱动，ALPS 触控板请用 SmartTouchPad 驱动  |
| XHCI-unsupported  | [链接](https://github.com/RehabMan/OS-X-USB-Inject-All/tree/master/XHCI-unsupported.kext)  |  USB驱动  |

## 3.待续……
