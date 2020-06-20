# OpenCore0.5.9引导安装Hackintosh
## 维护公告
* 20200619维护内容：
> 内核扩展更新
* 20200618维护内容：
> 测试支持使用Boot Camp程序引导Windows  
> Misc：ShowPicker由Fales修改为True  
> Misc：Timeout引导等待时间5秒修改至3秒  
> Misc：ExposeSensitiveData由62修改为2（Z370原声支持NVRAM，一直以来填错）  
> NVRAM：WriteFlash由Fales修改为True（支持macOS系统内切换至Windows）  
> DeviceProperties：注入Intel UHD630核心显卡参数支持仅核显用户安装（仅支持DP接口，独立显卡用户请安装后删除此数据）
* 解决Boot Camp程序安装后隐藏D盘的问题：
1. 打开运行（Win+R），输入CMD，再输入diskpart；
2. 输入list volume，会看到D盘已隐藏；
3. 输入select volume x（x为D盘卷号）；
4. 输入attributes volume clear hidden，清除隐藏属性。
* 20200616维护内容：
> ACPI：加载原生电源管理修改为关闭  
> DeviceProperties：删除核心显卡UHD630注入  
> Kernel：开启解除15个USB端口限制XhciPortLimit  
> Misc：showpicker开启  
> NVRAM：UI初始化模式大小修改为01  
> PlatformInfo：机型信息更新为iMac19,1  
* 20200603维护内容：
> 更新OpenCore引导版本至0.5.9  
> 更新Kexts至最新Release  
> 更新macOS10.15.5  
## 前言
1. 本EFI原则上仅供华硕 TUF Z370-Plus Gaming使用，其他华硕Z370系列主板是否通用未做测试，请谨慎使用；
2. 本EFI经测试能够在macOS High Sierra、macOS Mojave、macOS Catalina上安装；
3. 本EFI已注入核显参数，支持核显安装（仅DP接口）；
4. 本EFI配置文件「config」中添加了三码，但安装后最好更换；
5. BIOS设置请百度。
## 主机配置
* 处理器：英特尔i7-8700 CPU @ 3.20GHz
* 主板：华硕 TUF Z370-Plus Gaming
* 内存：海盗船 DDR4 3200Mhz 16GB*2
* 显卡：迪兰 Radeon RX 590 Series
* 显示器： Dell UltraSharp U2718Q
* 板载声卡：Realtek ALC887
* 有线网卡：Intel Ethernet Connection I219-V
* 无线网卡：Broadcom BCM94360CD
* 固态硬盘：Samsung SSD 960 EVO 500GB
## 功能测试结果
### 解决的问题
- [x]   声卡
- [x] 核显硬解（H.264、HEVC硬解加速）
- [x] 有线网卡
- [x] 无线网卡（Apple拆机卡，免驱）
- [x] 随航（iPad可做副屏）
- [x] 隔空投送（Mac to iPhone、iPhone to Mac、Mac to iPad、iPad to Mac）
- [x] 接力
- [x] CPU处理器原生变频睿频（机型iMac19,1）
- [x] 睡眠（自动睡眠、手动睡眠、长时间睡眠「整晚」）
- [x] USB2.0、USB3.0、USB3.1
- [x] 固态硬盘、机械硬盘（内建）
- [x] 解决Boot Camp程序安装后隐藏D盘的问题
###  未解决的问题
- [ ] 核显UHD630 HDMI紫屏（不打算解决，板载HDMI接口不支持4K）
- [ ] 核显UHD630在macOS10.15.5下黑屏（不打算解决，本人有独显）
- [ ] ACPI Error有八处（不打算解决，没发现影响使用，也不会修改SSDT）
## 截图（仅供参考）
![Image text](https://github.com/hackintosh-OC/Asus-Z370_8700_RX590-EFI/blob/master/uPic/86C56891-0ED6-46EC-ADCB-8C65019DB47A.png)
![Image text](https://raw.githubusercontent.com/hackintosh-OC/Asus-Z370_8700_RX590-EFI/master/uPic/11F467A6-913B-496A-8CB7-D26D1F15DAD2.png)
![Image text](https://raw.githubusercontent.com/hackintosh-OC/Asus-Z370_8700_RX590-EFI/master/uPic/4690EC6F-CA0E-4118-B2AE-BB2AA7A02807.png)
![Image text](https://raw.githubusercontent.com/hackintosh-OC/Asus-Z370_8700_RX590-EFI/master/uPic/8EF3650B-2461-4E5F-96E9-24909F3D20A9.png)
![Image text](https://raw.githubusercontent.com/hackintosh-OC/Asus-Z370_8700_RX590-EFI/master/uPic/0955B6A3-5894-47C9-9423-108E22CF7C06.png)
![Image text](https://raw.githubusercontent.com/hackintosh-OC/Asus-Z370_8700_RX590-EFI/master/uPic/4FC647D3-1872-4F1B-B662-11F6F1183865.png)
![Image text](https://raw.githubusercontent.com/hackintosh-OC/Asus-Z370_8700_RX590-EFI/master/uPic/F87B875C-0122-49E3-8FE1-1F42316D5D02.png)
![Image text](https://raw.githubusercontent.com/hackintosh-OC/Asus-Z370_8700_RX590-EFI/master/uPic/EA82D4D8-44CB-4E42-A0AA-2350ACCBBF76.png)
![Image text](https://raw.githubusercontent.com/hackintosh-OC/Asus-Z370_8700_RX590-EFI/master/uPic/55077B0C-9794-4E12-84F9-5595A5E24AD7.png)
![Image text](https://raw.githubusercontent.com/hackintosh-OC/Asus-Z370_8700_RX590-EFI/master/uPic/364AAEEB-21C2-4554-90B2-A177F1618B6E.png)
![Image text](https://raw.githubusercontent.com/hackintosh-OC/Asus-Z370_8700_RX590-EFI/master/uPic/8A422547-A0E5-4AA2-B060-E2E788D7DF7F.png)
![Image text](https://raw.githubusercontent.com/hackintosh-OC/Asus-Z370_8700_RX590-EFI/master/uPic/7005394C-4165-4CBC-A1B8-E566AE3399A2.png)
![Image text](https://raw.githubusercontent.com/hackintosh-OC/Asus-Z370_8700_RX590-EFI/master/uPic/31B29C8B-B5B7-4FB6-8B0A-85A129EADD7C.png)
![Image text](https://github.com/hackintosh-OC/Asus-Z370_8700_RX590-EFI/blob/master/uPic/%E5%90%AF%E5%8A%A8%E7%A3%81%E7%9B%98.png)
