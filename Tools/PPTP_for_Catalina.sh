#!/bin/sh
# 版本判断
base_ver=15
ver=$(sw_vers | grep ProductVersion | awk '{print $2}' | cut -d'.' -f2)
if [ $ver == "$base_ver" ]
then 
   echo "可以安装，请输入用户密码以挂载系统分区"
   sudo mount -o rw /   # 挂载系统分区
   cd /System/Library/Extensions
   sudo mv PPP.kext PPP.kext.orig   # 备份PPP.kext
   

else 
   echo "不满足条件"
fi
