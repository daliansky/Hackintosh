#!/bin/sh
# 版本判断
base_ver=15
ver=$(sw_vers | grep ProductVersion | awk '{print $2}' | cut -d'.' -f2)
if [ $ver == "$base_ver" ]
then 
   echo "可以安装，请确保禁用System Intregrity Protection，请输入用户密码以挂载系统分区"
   say "可以安装，请确保禁用System Intregrity Protection，请输入用户密码以挂载系统分区"
   sudo mount -o rw /   # 挂载系统分区
   sudo rm -rf /tmp/__MACOSX && sudo rm -rf /tmp/PPTP*
   cd /System/Library/Extensions
   sudo mv PPP.kext PPP.kext.orig   # 备份PPP.kext
   echo "正在安装PPTP驱动及相关服务" && say "正在安装PPTP驱动及相关服务"
   curl -fsSL https://raw.githubusercontent.com/daliansky/Hackintosh/master/Tools/PPTP/PPTP.zip -o /tmp/PPTP.zip && cd /tmp && unzip -oq PPTP.zip
   sudo cp -R /tmp/PPTP/PPP.kext /System/Library/Extensions
   sudo cp -R /tmp/PPTP/PPTP.ppp /System/Library/Extensions
    [ -d /usr/local/bin ] && echo "/usr/local/bin目录已存在" && say "目录已存在" || sudo mkdir /usr/local/bin && sudo chown $(whoami) /usr/local/bin
   sudo cp /tmp/PPTP/pptp /usr/local/bin
   sudo chown -R $(whoami) /usr/local/bin/pptp
   chmod 755 /usr/local/bin/pptp
   echo "正在重建缓存..." && say "正在重建缓存"
   sudo kextcache -i /
   cd ~
   echo "安装完成，请重启系统，并请安装Shimo Version 4.1.5.1 (8837)以启用PPTP客户端" && say "安装完成，请重启系统，并请安装Shimo Version 4.1.5.1 (8837)以启用PPTP客户端"

else 
   echo "别闹，你的系统不满足安装条件" && say "别闹，你的系统不满足安装条件"
fi
