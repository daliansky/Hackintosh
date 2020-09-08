#!/bin/sh
#This shell script is modified by Mison base on the script of headkaze,Gengik84.

# function checkTools() {
#   checkNasm
#   checkMtoc
# }

# Check Nasm and Mtoc by vit9696 ( macbuild.tool )
# function checkNasm(){
#   local NASMVER="2.13.03"
# 
#   if [ "$(nasm -v)" = "" ] || [ "$(nasm -v | grep Apple)" != "" ]; then
#     echo "Missing or incompatible nasm!"
#     echo "Download the latest nasm from http://www.nasm.us/pub/nasm/releasebuilds/"
#     read -p "Last tested with nasm ${NASMVER}. Install it automatically? (Y/N) " confirmInstallNasm 
#     case "${confirmInstallNasm}" in
#       y | Y | "" ) 
#         pushd /tmp >/dev/null
#         rm -rf "nasm-${NASMVER}-macosx.zip" "nasm-${NASMVER}"
#         echo "Download nasm..."
#         curl -OL "http://www.nasm.us/pub/nasm/releasebuilds/${NASMVER}/macosx/nasm-${NASMVER}-macosx.zip" || exit 1
#         unzip -q "nasm-${NASMVER}-macosx.zip" "nasm-${NASMVER}/nasm" "nasm-${NASMVER}/ndisasm" || exit 1
#         sudo mkdir -p /usr/local/bin || exit 1
#         sudo mv "nasm-${NASMVER}/nasm" /usr/local/bin/ || exit 1
#         sudo mv "nasm-${NASMVER}/ndisasm" /usr/local/bin/ || exit 1
#         rm -rf "nasm-${NASMVER}-macosx.zip" "nasm-${NASMVER}"
#         popd >/dev/null
#       ;;
# 
#       * )
#         echo -e "\nnasm installation Aborted.\n"
#         exit
#       ;;
#     esac
#   fi    
# }

# function checkMtoc(){
#   if [ "$(which mtoc.NEW)" = "" ] || [ "$(which mtoc)" = "" ]; then
#     echo  "Missing mtoc or mtoc.NEW!"
#     echo "To build mtoc follow: https://github.com/tianocore/tianocore.github.io/wiki/Xcode#mac-os-x-xcode"
#     read -p "Install prebuilt mtoc and mtoc.NEW automatically? (Y/N) " confirmInstallMtoc
#     case "${confirmInstallMtoc}" in
#       y | Y | "" )
#         pushd /tmp >/dev/null
#         rm -f mtoc mtoc.NEW
#         echo "Download the latest Mtoc and install..."
#         curl -O "https://github.com/acidanthera/ocbuild/raw/master/external/mtoc-mac64.zip" || exit 1
#         unzip -q ./mtoc-mac64.zip mtoc.NEW || exit 1
#         sudo mkdir -p /usr/local/bin || exit 1
#         sudo cp mtoc.NEW /usr/local/bin/mtoc || exit 1
#         sudo mv mtoc.NEW /usr/local/bin/ || exit 1
#         popd >/dev/null
#       ;;
# 
#       * )
#         echo -e "\nmtoc installation Aborted.\n"
#         exit
#       ;;
#     esac
#   fi    
# }
# checkTools
echo "源码更新中..."
cd ~/git/buildlilu
cd Lilu && git pull && cd ..
cd WhateverGreen && git pull && cd ..
cd AppleALC && git pull && cd ..
cd VirtualSMC && git pull && cd ..
cd AirportBrcmFixup && git pull && cd ..
cd RTCMemoryFixup && git pull && cd ..
cd NVMeFix && git pull && cd ..
cd BrcmPatchRAM && git pull && cd ..
cd LucyRTL8125Ethernet && git pull && cd ..
cd IntelMausi && git pull && cd ..
cd SystemProfilerMemoryFixup && git pull && cd ..
cd VoodooPS2 && git pull && cd ..
cd HibernationFixup && git pull && cd ..
#cd OS-X-USB-Inject-All && git pull && cd ..


# git clone https://github.com/acidanthera/NVMeFix --depth=1
# git clone https://github.com/acidanthera/Lilu --depth=1
# git clone https://github.com/acidanthera/WhateverGreen --depth=1
# git clone https://github.com/acidanthera/AppleALC --depth=1
# git clone https://github.com/acidanthera/AirportBrcmFixup --depth=1
# git clone https://github.com/acidanthera/HibernationFixup --depth=1
# git clone https://github.com/acidanthera/RTCMemoryFixup --depth=1
# git clone https://github.com/athlonreg/ATH9KFixup --depth=1
# git clone https://github.com/acidanthera/BT4LEContiunityFixup --depth=1
# git clone https://github.com/acidanthera/CPUFriend --depth=1
# git clone https://github.com/al3xtjames/NoTouchID --depth=1
# git clone https://github.com/acidanthera/VirtualSMC --depth=1
# git clone https://github.com/vulgo/NoVPAJpeg --depth=1
# git clone https://github.com/Goldfish64/DiskArbitrationFixup --depth=1
# git clone https://github.com/Goldfish64/SystemProfilerMemoryFixup --depth=1
# git clone https://github.com/lvs1974/VoodooSDHCMod --depth=1
# git clone https://github.com/sinetek/Sinetek-rtsx --depth=1
# git clone https://github.com/Mieze/AtherosE2200Ethernet --depth=1
# git clone https://github.com/Mieze/RealtekRTL8100 --depth=1
# git clone https://github.com/Mieze/RTL8111_driver_for_OS_X --depth=1
# git clone https://github.com/acidanthera/IntelMausi --depth=1
# git clone https://github.com/al3xtjames/AtherosL1cEthernet --depth=1
# git clone https://github.com/acidanthera/VoodooPS2 --depth=1
# git clone https://github.com/RehabMan/OS-X-Voodoo-PS2-Controller --depth=1
# git clone https://github.com/RehabMan/OS-X-USB-Inject-All --depth=1
# git clone https://github.com/RehabMan/OS-X-ACPI-Battery-Driver --depth=1
# git clone https://github.com/RehabMan/OS-X-Null-Ethernet --depth=1
# git clone https://github.com/RehabMan/VoodooTSCSync --depth=1

# 编译Lilu Debug版本
xcodebuild -project ./Lilu/Lilu.xcodeproj -configuration Debug clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Debug

# 软链接Lilu Debug
ln -s ./Debug/Lilu.kext ./WhateverGreen
ln -s ./Debug/Lilu.kext ./AppleALC
ln -s ./Debug/Lilu.kext ./AirportBrcmFixup
ln -s ./Debug/Lilu.kext ./HibernationFixup
ln -s ./Debug/Lilu.kext ./RTCMemoryFixup
ln -s ./Debug/Lilu.kext ./ATH9KFixup
ln -s ./Debug/Lilu.kext ./BT4LEContiunityFixup
ln -s ./Debug/Lilu.kext ./CPUFriend
ln -s ./Debug/Lilu.kext ./NoTouchID
ln -s ./Debug/Lilu.kext ./VirtualSMC
ln -s ./Debug/Lilu.kext ./NoVPAJpeg
ln -s ./Debug/Lilu.kext ./DiskArbitrationFixup
ln -s ./Debug/Lilu.kext ./SystemProfilerMemoryFixup

echo "开始编译常用驱动..."
xcodebuild -project ./Lilu/Lilu.xcodeproj -configuration Release clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Release
xcodebuild -project ./WhateverGreen/WhateverGreen.xcodeproj -configuration Release clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Release
xcodebuild -project ./AppleALC/AppleALC.xcodeproj -configuration Release clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Release
xcodebuild -project ./AirportBrcmFixup/AirportBrcmFixup.xcodeproj -configuration Release clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Release
xcodebuild -project ./HibernationFixup/HibernationFixup.xcodeproj -configuration Release clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Release
xcodebuild -project ./RTCMemoryFixup/RTCMemoryFixup.xcodeproj -configuration Release clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Release
# xcodebuild -project ./ATH9KFixup/ATH9KFixup.xcodeproj -configuration Release clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Release/ATH9KFixup
# xcodebuild -project ./BT4LEContiunityFixup/BT4LEContiunityFixup.xcodeproj -configuration Release clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Release
# xcodebuild -project ./CPUFriend/CPUFriend.xcodeproj -configuration Release clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Release
# xcodebuild -project ./NoTouchID/NoTouchID.xcodeproj -configuration Release clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Release
xcodebuild -project ./VirtualSMC/VirtualSMC.xcodeproj -configuration Release clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Release
# xcodebuild -project ./NoVPAJpeg/NoVPAJpeg.xcodeproj -configuration Release clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Release
# xcodebuild -project ./DiskArbitrationFixup/DiskArbitrationFixup.xcodeproj -configuration Release clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Release
xcodebuild -project ./SystemProfilerMemoryFixup/SystemProfilerMemoryFixup.xcodeproj -configuration Release clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Release
# xcodebuild -project ./VoodooSDHCMod/VoodooSDHC.xcodeproj -configuration Release clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Release
# xcodebuild -project ./Sinetek-rtsx/Sinetek-rtsx.xcodeproj -configuration Release clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Release
# xcodebuild -project ./AtherosE2200Ethernet/AtherosE2200Ethernet.xcodeproj -configuration Release clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Release
# xcodebuild -project ./RealtekRTL8100/RealtekRTL8100.xcodeproj -configuration Release clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Release
# xcodebuild -project ./RTL8111_driver_for_OS_X/RealtekRTL8111.xcodeproj -configuration Release clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Release
xcodebuild -project ./IntelMausi/IntelMausiEthernet.xcodeproj -configuration Release clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Release
# xcodebuild -project ./AtherosL1cEthernet/AtherosL1cEthernet.xcodeproj -configuration Release clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Release
xcodebuild -project ./NVMeFix/NVMeFix.xcodeproj  -configuration Release clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Release
xcodebuild -project ./VoodooPS2/VoodooPS2Controller.xcodeproj -configuration Release clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Release
xcodebuild -project ./OS-X-USB-Inject-All/USBInjectAll.xcodeproj -scheme USBInjectAll -configuration Release clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Release
xcodebuild -project ./LucyRTL8125Ethernet/LucyRTL8125Ethernet.xcodeproj -configuration Release clean build ARCHS=x86_64 ONLY_ACTIVE_ARCH=YES CONFIGURATION_BUILD_DIR=../Release
echo  "编译完成！"
find ./ -name "*.dSYM" -depth -exec rm -rf {} \;  # 删除无用的.dSYM文件
find ./ -name "dSYM" -depth -exec rm -rf {} \;  # 删除无用的.dSYM文件
echo "合并VoodooPS2Controller驱动..."
cd Release
cp -r VoodooPS2Trackpad.kext VoodooPS2Controller.kext/Contents/PlugIns/
cp -r VoodooPS2Mouse.kext VoodooPS2Controller.kext/Contents/PlugIns/
cp -r VoodooPS2Keyboard.kext VoodooPS2Controller.kext/Contents/PlugIns/
cd ../
echo "合并VoodooPS2Controller驱动完成！"
open Release
