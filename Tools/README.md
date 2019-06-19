# 常用工具

## Nvidia Web Driver下载/更新

提供以下几种方式，总有一款适合你

- Webdriver All Versions.app![WebdriverDownload](WebdriverDownload.png)

- [WebDD v1.7](WebDD.command)

- webdriver.sh 项目仓库：https://github.com/vulgo/webdriver.sh 

  Nvidia webdriver驱动下载：https://vulgo.github.io/nvidia-drivers/

  ```bash
  brew tap vulgo/repo
  brew install webdriver.sh
  webdriver -a list
  ```

  ![webdriver.png](webdriver.png)

- 一条命令17G66 Nvidia Web Driver驱动：

```bash
bash < (curl -s https://vulgo.github.io/webdriver) 387.10.10.10.40.113
```

## 一条命令显示机型和主板

打开终端，输入命令：

```bash
curl -fsSL https://raw.githubusercontent.com/daliansky/Hackintosh/master/Tools/bdmesg -o /tmp/bdmesg && chmod +x /tmp/bdmesg && sh -c /tmp/bdmesg | grep Running
```

输出如下：

```bash
0:100  0:000  Running on: 'Inspiron 7560' with board '07T996'
```

或者：显示更多的信息：

```bash
sh -c "$(curl -fsSL https://raw.githubusercontent.com/daliansky/Hackintosh/master/Tools/archey)"
```

输出效果见上图

## 微信小助手

```bash
curl -o- -L https://raw.githubusercontent.com/lmk123/oh-my-wechat/master/install.sh | bash -s
```



## 一条命令显示USB数量

打开终端，输入命令：<br />

```bash
sh -c "$(curl -fsSL https://raw.githubusercontent.com/daliansky/Hackintosh/master/Tools/usb_Ports)"
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

```bash
curl -fsSL -o /tmp/msss https://raw.githubusercontent.com/daliansky/Hackintosh/master/Tools/msss && chmod a+x /tmp/msss && open $(/tmp/msss -v)
```

也可以下载到本地执行：

```bash
$ msss -h		帮助信息
$ msss -v		回显存储的截屏文件名，配合使用`open`直接显：`open $(msss -v)` 
$ msss -d 0 就是截取所有显示器并自动拼接
$ msss -d 1 就是截取1号主显示器
$ msss -d 2 就是截取第二台显示器
$ msss -f 	手动指定截图文件名和保存路径，比如：`msss -f ~/Desktop/111.png` 将截屏保存到桌面上
```



## 一键变频脚本自动生成`CPUFriend.kext`

- 在终端输入以下命令并回车：

```
bash -c "$(curl -fsSL https://raw.githubusercontent.com/daliansky/XiaoMi-Pro/master/one-key-cpufriend/one-key-cpufriend_cn.sh)"
```

- 把桌面上的 `CPUFriend.kext` 和 `CPUFriendDataProvider.kext` 复制进 `/CLOVER/kexts/Other/` 并重启。

详细说明请[移步](https://github.com/daliansky/XiaoMi-Pro/blob/master/one-key-cpufriend/README_CN.md)



## 提高github/gitalk访问速度

```bash
cat /etc/hosts
# github.com
192.30.253.113	github.com
192.30.253.112	github.com
192.30.255.117	api.github.com
192.30.255.116	api.github.com
```

