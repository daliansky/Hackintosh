# 常用工具

## Nvidia Web Driver下载/更新

提供以下几种方式，总有一款适合你

- [Webdriver All Versions.app](Webdriver All Versions.app)

![WebdriverDownload](WebdriverDownload.png)

- [WebDD v1.7](WebDD.command)

- webdriver.sh 项目仓库：https://github.com/vulgo/webdriver.sh 

  Nvidia webdriver驱动下载：https://vulgo.github.io/nvidia-drivers/

  ```bash
  brew tap vulgo/repo
  brew install webdriver.sh
  webdriver -a list
  ```

  ![webdriver.png](webdriver.png)

一条命令17G66 Nvidia Web Driver驱动：

```bash
bash <(curl -s https://vulgo.github.io/webdriver) 387.10.10.10.40.113
```



