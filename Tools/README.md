# 常用工具

## 一键提取 BCM94360Z4网卡信息

```bash
sh -c "$(curl -fsSL https://cdn.jsdelivr.net/gh/daliansky/Hackintosh/Tools/BCM94360Z4)"
```

输出结果如下：



## 一键安装`Catalina`下缺失的`PPTP`驱动及相关文件，以使用`PPTP client for Catalina`

```bash
sh -c "$(curl -fsSL https://cdn.jsdelivr.net/gh/daliansky/Hackintosh/Tools/PPTP_for_Catalina.sh)"
```



## 一条命令显示机型和主板

打开终端，输入命令：

```bash
curl -fsSL https://cdn.jsdelivr.net/gh/daliansky/Hackintosh/Tools/bdmesg -o /tmp/bdmesg && chmod +x /tmp/bdmesg && sh -c /tmp/bdmesg | grep Running
```

输出如下：

```bash
0:100  0:000  Running on: 'Inspiron 7560' with board '07T996'
```

或者：显示更多的信息：

```bash
sh -c "$(curl -fsSL https://cdn.jsdelivr.net/gh/daliansky/Hackintosh/Tools/archey)"
```

输出效果见上图

## 一条命令解决时间不同步问题：

> 两种方法，选项其中一个即可。

### Windows下操作：

`Win+x`选择管理员模式进入`CMD`
执行以下命令：

```bash
Reg add HKLM\SYSTEM\CurrentControlSet\Control\TimeZoneInformation /v RealTimeIsUniversal /t REG_DWORD /d 1
```

### macOS下操作：

打开终端，输入命令：

```bash
sudo sh -c "$(curl -kfsSL https://cdn.jsdelivr.net/gh/daliansky/LocalTime-Toggle/fix_time_osx.sh)"
```

备注：不适用于`Big Sur`系统

## 微信小助手

打开终端，输入命令：

```bash
curl -o- -L https://cdn.jsdelivr.net/gh/lmk123/oh-my-wechat/install.sh | bash -s
```

## 微信助手

打开终端，输入命令：

```bash
cd ~/Downloads && rm -rf MacWeChatPlugin && git clone https://github.com/cuiyu8580/MacWeChatPlugin.git --depth=1 && ./MacWeChatPlugin/Other/Install.sh
```


>>>>>>> Stashed changes
## 一条命令显示USB数量

打开终端，输入命令：

```bash
sh -c "$(curl -fsSL https://cdn.jsdelivr.net/gh/daliansky/Hackintosh/Tools/usb_Ports)"
```

输出如下：

```bash
+--XHC@14IOPCIDevice
|+--XHC@14000000
|+--HS01@14100000
|+--HS02@14200000
|+--HS03@14300000
|+--HS04@14400000
|+--HS05@14500000
||+--Integrated_Webcam_HD@14500000
|+--HS06@14600000
||+--USB2.0-CRW@14600000
|+--HS07@14700000
|+--HS08@14800000
||+--BCM20702A0@14800000
|+--HS09@14900000
|+--HS10@14a00000
|+--USR1@14b00000
|+--USR2@14c00000
|+--SS01@14d00000
|+--SS02@14e00000
|+--SS03@14f00000
+--pci80869d31@142IOPCIDevice
+--AppleUSBXHCI@14000000AppleUSBController
+--AppleUSBXHCIHub
+--USB2.0-CRW@14600000AppleUSBDevice
+--Integrated_Webcam_HD@14500000AppleUSBDevice
+--BCM20702A0@14800000AppleUSBDevice
```

## 一键截屏，方法来自[绿帽兄](https://github.com/lihaoyun6)

打开终端，输入命令：

```bash
[[ ! -x "/tmp/msss" ]] && (curl -fsSL -o /tmp/msss https://cdn.jsdelivr.net/gh/daliansky/Hackintosh/Tools/msss && chmod a+x /tmp/msss && open $(/tmp/msss -v)) || open $(/tmp/msss -v)
```

也可以下载到本地执行：

```bash
$ msss -h   帮助信息
$ msss -v   回显存储的截屏文件名，配合使用`open`直接显：`open $(msss -v)`
$ msss -d 0 就是截取所有显示器并自动拼接
$ msss -d 1 就是截取1号主显示器
$ msss -d 2 就是截取第二台显示器
$ msss -f 手动指定截图文件名和保存路径，比如：`msss -f ~/Desktop/111.png` 将截屏保存到桌面上
```

## 一键变频脚本自动生成`CPUFriend.kext`

- 使用前请先阅读[CPUFriend - WARNING](https://github.com/acidanthera/CPUFriend/blob/master/Instructions.md#warning)
- 在终端输入以下命令并回车：

```bash
bash -c "$(curl -fsSL https://cdn.jsdelivr.net/gh/stevezhengshiqi/one-key-cpufriend/one-key-cpufriend.sh)"
```

- 把桌面上的 `CPUFriend.kext` 和 `CPUFriendDataProvider.kext` 复制进 `/CLOVER/kexts/Other/` 并重启。

详细说明请[移步](https://github.com/stevezhengshiqi/one-key-cpufriend/blob/master/README_CN.md)

## 提高github/gitalk访问速度

打开终端，输入命令：

```bash
cat /etc/hosts
# github.com
192.30.253.113	github.com
192.30.253.112	github.com
192.30.255.117	api.github.com
192.30.255.116	api.github.com
#151.101.184.133 raw.githubusercontent.com

192.30.253.119 gist.github.com
151.101.184.133 assets-cdn.github.com
151.101.184.133 raw.githubusercontent.com
151.101.184.133 gist.githubusercontent.com
151.101.184.133 cloud.githubusercontent.com
151.101.184.133 camo.githubusercontent.com
151.101.184.133 avatars0.githubusercontent.com
151.101.184.133 avatars1.githubusercontent.com
151.101.184.133 avatars2.githubusercontent.com
151.101.184.133 avatars3.githubusercontent.com
151.101.184.133 avatars4.githubusercontent.com
151.101.184.133 avatars5.githubusercontent.com
151.101.184.133 avatars6.githubusercontent.com
151.101.184.133 avatars7.githubusercontent.com
151.101.184.133 avatars8.githubusercontent.com
```

## 运用iasl编译dsl文件

### 使用RehabMan的iasl62（ACPI标准6.2）

打开终端，输入命令：

```bash
curl -fsSL https://cdn.jsdelivr.net/gh/daliansky/Hackintosh/Tools/iasl-RM -o /tmp/iasl-RM && chmod +x /tmp/iasl-RM && sh -c /tmp/iasl-RM -l <dsl文件路径>
```

### 使用ACPICA的iasl63（ACPI标准6.3）

打开终端，输入命令：

```bash
curl -fsSL https://cdn.jsdelivr.net/gh/daliansky/Hackintosh/Tools/iasl63 -o /tmp/iasl63 && chmod +x /tmp/iasl63 && sh -c /tmp/iasl63 -l <dsl文件路径>
```

## 一键提取DW1820A所需的信息：

```bash
sh -c "$(curl -fsSL https://cdn.jsdelivr.net/gh/daliansky/Hackintosh/Tools/DW1820A)"
```

输出结果如下：

![DW1820A驱动信息](http://7.daliansky.net/DW1820A/DW1820A_Bug_Report.png)

## 一键提取`macOS 三码`

```bash
sh -c "$(curl -fsSL https://cdn.jsdelivr.net/gh/daliansky/Hackintosh/Tools/sn.sh)"
```

输出结果如下：

```bash
SystemProductName: MacPro7,1
SystemUUID: AF9CB0AC-DE74-4BE8-A59C-8BA4639D0BDD
SystemSerialNumber: F5KGD7Y5P7QM
Valid: Unlikely
ROM: FCFFFF28FCFF
MLB: F5K137404J9K3F7CB
```



## 一条命令提取`EDID`

```bash
ioreg -lw0 | grep -i "IODisplayEDID" | sed -e 's/.*<//' -e 's/>//'

```

显示结果：

```xml
00ffffffffffff000e6f6d0700000000141d0104a51d1278e2ee95a3544c99260f505400000001010101010101010101010101010101ec6800a0a0402e60302036001eb31000001a000000000000000000000000000000000000000000fe0043534f542054330a2020202020000000fe004d4e443330374441312d320a200048
```

将`EDID`值复制进`config.plist`里