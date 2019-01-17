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



{% note primary %}
小课堂：<br />

- 一条命令显示USB数量

{% endnote %}
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