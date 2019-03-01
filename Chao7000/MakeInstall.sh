#!/bin/sh
makedir="/Users/$USER/Desktop/EFI"
backupdir="/Users/$USER/Desktop/EFIBAK"
origindir="$( dirname "${BASH_SOURCE[0]}" )"
tmpdir="/Users/$USER/Desktop/Temp0"
cloverfile="/Users/$USER/Desktop/Clovernew.pkg"
extractdir="/Users/$USER/Desktop/extractdir"
efitemp="/Users/$USER/Desktop/efitemp"
driverdir="/Users/$USER/Desktop/EFI/CLOVER/drivers64UEFI"


#起始块
function start()
{
    clear

cat << EOF
　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　
　潮潮潮潮潮潮潮潮潮　　　潮潮潮潮　　　　　　潮潮潮潮　　　　　　潮潮潮潮
　潮潮　　　　潮潮　　　潮潮潮潮潮潮　　　　潮潮潮潮潮潮　　　　潮潮潮潮潮潮
　潮潮　　　潮潮　　　潮潮潮　　潮潮潮　　潮潮潮　　潮潮潮　　潮潮潮　　潮潮潮
　　　　　　潮潮　　　潮潮潮　　潮潮潮　　潮潮潮　　潮潮潮　　潮潮潮　　潮潮潮
　　　　　潮潮　　　潮潮潮　　　　潮潮潮潮潮潮　　　　潮潮潮潮潮潮　　　　潮潮潮
　　　　　潮潮　　　潮潮潮　　　　潮潮潮潮潮潮　　　　潮潮潮潮潮潮　　　　潮潮潮
　　　　潮潮潮　　　潮潮潮　　　　潮潮潮潮潮潮　　　　潮潮潮潮潮潮　　　　潮潮潮
　　　　潮潮　　　　潮潮潮　　　　潮潮潮潮潮潮　　　　潮潮潮潮潮潮　　　　潮潮潮
　　　潮潮潮　　　　潮潮潮　　　　潮潮潮潮潮潮　　　　潮潮潮潮潮潮　　　　潮潮潮
　　　潮潮潮　　　　　潮潮潮　　潮潮潮　　潮潮潮　　潮潮潮　　潮潮潮　　潮潮潮
　　　潮潮潮　　　　　潮潮潮　　潮潮潮　　潮潮潮　　潮潮潮　　潮潮潮　　潮潮潮
　　　潮潮潮　　　　　　潮潮潮潮潮潮　　　　潮潮潮潮潮潮　　　　潮潮潮潮潮潮
　　　潮潮潮　　　　　　　潮潮潮潮　　　　　　潮潮潮潮　　　　　　潮潮潮潮




EOF
    echo "联想潮7000 EFI自动生成脚本 by 澎湖冰洲"
    echo "（基于AnywhereEFI定制）"
    choose
}

#第一选择块
function choose()
{

cat << EOF

请选择要执行的操作：
(1) 生成EFI文件
(2) 自动更新四叶草版本
(3) 自动安装
(4) 退出

EOF

    read -p "输入你的选择[1~4]: " input
    case $input in
        1) generate
        ;;
        2) extract
        ;;
        3) instinit
        ;;
        4) end
        ;;
        *)
    echo "输入有误，请重新输入"
    choose
    esac
}



#生成EFI模块
function generate()
{

    clear

cat << EOF
请选择您的触摸板型号：
(1) SYNA2B2C
(2) SYNA2393/06CB0001
(3) 返回
EOF

    read -p "输入你的选择[1~3]: " input
    case $input in
        1) SYNA2B2C
        ;;
        2) SYNA2393
        ;;
        3) start
        ;;
        *)
    echo "输入有误，请重新输入"
    generate
    esac
}

#目录冲突检测块
function dirdetect()
{
    if [[ -d $makedir ]];then
        echo "目标目录已经存在，发生冲突，正在备份冲突目录为EFIBAK……"
        sudo mv -f $makedir $backupdir
        echo "备份生成目录成功"
    fi
}

#2B2C触摸板生成模块
function SYNA2B2C()
{
    dirdetect

    echo "正在生成SYNA2B2C的EFI……"
    cp -r $origindir/Basic $makedir
    cp $origindir/config/SYNA2B2C.plist $makedir/CLOVER/config.plist
    cp -r  $origindir/ACPI/SYNA2B2C $makedir/ClOVER/ACPI
    read -p "生成成功，按任意键返回上层！"
    start
}

#2393触摸板生成模块
function SYNA2393()
{
    dirdetect

    echo "正在生成SYNA2393的EFI……"
    sudo rm -Rf $makedir
    cp -r $origindir/basic $makedir
    cp $origindir/config/SYNA2393.plist $makedir/CLOVER/config.plist
    cp -r  $origindir/ACPI/SYNA2393 $makedir/CLOVER/ACPI
    read -p "生成成功，按任意键返回上层！"
    start
}


#下载模块
function download()
{
    #解析最新Clover下载地址
    if [ ! -d $tmpdir ]; then
        mkdir $tmpdir
    fi
    echo "正在解析最新的Clover下载地址"
    cd $tmpdir
    curl --progress-bar -o $tmpdir/resource https://api.github.com/repos/Dids/clover-builder/releases

    if [ ! -f $tmpdir/resource ]; then

        for ((i=1;i<=2 && ! -f $tmpdir/resource;i++));
        do
            echo "解析失败，正在尝试重新解析"
            curl --progress-bar -o $tmpdir/resource https://api.github.com/repos/Dids/clover-builder/releases
        done

        if [ ! -f $tmpdir/resource ]; then
            read -p "解析失败，按任意键返回上层！"
            start
        fi
    fi


    #获取地址并保存，然后用curl下载
    downlink=`cat $tmpdir/resource |  grep 'browser_download_url' | sed -n 3p | awk -F " " '{print $2}' | tr -d '"'`
    echo "正在下载最新Clover"
    cd /Users/$USER/Desktop
    curl --progress-bar -L -o $cloverfile $downlink
    if [ ! -f $cloverfile ]; then
        for ((i=1;i<=2 && ! -f $cloverfile;i++));
        do
            echo "解析失败，正在尝试重新解析"
            curl --progress-bar -L -o /Users/$USER/Desktop/Clover.pkg $downlink
        done

        if [ ! -f $cloverfile ]; then
            read -p "解析失败，按任意键返回上层！"
            start
        fi
    fi

    rm -f $tmpdir/resource
}

#解压模块
function extract()
{
    clear
    download

    #提取新Clover文件
    xar -xf $cloverfile -C $tmpdir
    rm -rf $tmpdir/Resources

    if [ ! -d $extractdir ]; then
        mkdir $extractdir
    fi

    dirlist=$(ls $tmpdir)
    cd $extractdir

    for name in ${dirlist[*]}
    do
        cat $tmpdir/$name/Payload | cpio -i
    done
    rm -rf $tmpdir

    #将需要更新的文件放入efitemp
    echo "正在生成新文件"
    mkdir $efitemp
    mkdir $efitemp/CLOVER
    mkdir $efitemp/CLOVER/drivers64UEFI
    cp $extractdir/EFI/CLOVER/CLOVERX64.efi $efitemp/CLOVER
    cp -rf $extractdir/EFI/CLOVER/tools $efitemp/CLOVER
    cp -rf $extractdir/EFI/BOOT $efitemp

    dirlist=$(ls $driverdir)

    for name in ${dirlist[*]}
    do
    #由于原有的EFI文件可能存在一些四叶草安装包不存在efi文件（像VirtualSMC.efi),故此处加以判断原有是否存在，只合并需要更新的
    if [ -f $extractdir/$name ]; then
        cp -f $extractdir/$name $efitemp/CLOVER/drivers64UEFI && stty -echo
    fi
    done

    rm -rf $extractdir

    #开始替换
    if [[ ! -d $makedir ]];then
        read -p "待安装的EFI文件夹不存在，请将安装文件夹放在桌面！按任意键返回。"
        start
    fi

    echo "正在更新"
    rm -rf $makedir/CLOVER/drivers64UEFI
    rm -f $makedir/CLOVER/CLOVERX64.efi
    rm -rf $makedir/CLOVER/tools
    rm -rf $makedir/BOOT

    cp -rf $efitemp/CLOVER/drivers64UEFI $makedir/CLOVER
    cp -f $efitemp/CLOVER/CLOVERX64.efi $makedir/CLOVER
    cp -rf $efitemp/CLOVER/tools $makedir/CLOVER
    cp -rf $efitemp/BOOT $makedir/BOOT

    #收尾工作
    rm -rf $efitemp
    rm -f $cloverfile
    read -p "自动升级Clover版本成功，按任意键返回上一层"
    m=1
    start
}

#安装初始化块
function instinit()
{
    clear
cat << EOF
自动安装要求：
1、UEFI模式
2、设置的四叶草引导路径为/EFI/CLOVER/CLOVERX64.efi
3、将待安装的EFI文件夹放置在桌面
4、mount_efi.sh与本安装脚本放置在一块
EOF

    read -p "如您确认以上四点无误，请输入y回车，否则按任意键返回！！！！" input
    if [[ $input == y ]];then
        if [[ ! $m == 1 ]];then
            read -p "为了保证使用的EFI能够支持新的系统版本，强烈建议先更新Clover版本！！！如果想更新Clover版本，请输入y回车返回上一层进行更新Clover的操作，否则请按其他任意键继续。" input
            if [[ $input == y ]];then
                start
            fi
        fi
        install
    else
        start
    fi
}


#安装块
function install()
{

    #检测EFI挂载脚本

    if [[ ! -f $origindir/mount_efi.sh ]];then
        read -p "未检测到EFI挂载脚本（mount_efi.sh)！按任意键返回。"
        start
    fi

    #挂载EFI分区，由hieplpvip写出脚本
    echo "正在挂载EFI……"
    efidir=`$origindir/mount_efi.sh`

    #检测是否存在Windows EFI文件，如果是，将变量haswin设为yes以启动后面的恢复Windows EFI
    if [[ -d $efidir/Microsoft ]];then
        haswin="yes"
    fi

    #备份原有EFI文件
    echo "正在备份原有EFI，原EFI将被备份到桌面下的EFIREC下"
    cp -rf $efidir /Users/$USER/Desktop/EFIREC

    if [[ ! -d /Users/$USER/Desktop/EFIREC ]];then
        read -p "备份原有EFI失败，安装将在无备份的条件下进行！输入y继续安装，否则按任意键返回。" input
        if [[ $input != y ]];then
            start
        fi
    else
        echo "备份完成，正在准备安装新EFI……"
    fi

    #检测是否存在安装文件
    if [[ ! -d $makedir ]];then
        read -p "待安装的EFI文件夹不存在，请将安装文件夹放在桌面！按任意键返回。"
        start
    fi

    #安装
    rm -rf $efidir/EFI
    cp -rf $makedir $efidir

    #恢复删除的Windows EFI
    if [[ $haswin == yes ]];then
        echo "正在将Windows EFI文件恢复到EFI分区"
        cp -rf /Users/$USER/Desktop/EFIREC/EFI/Microsoft $efidir/EFI

        if [[ -d $efidir/EFI/Microsoft ]];then
            echo "恢复Windows EFI成功。"
        else
            read -p "恢复Windows EFI失败。按任意键返回！"
            start
        fi
    fi

#完成安装
    if [[ -d $efidir ]];then
        rm -rf $makedir
        say 从现在起开启全新的黑苹果之旅
        read -p "自动安装成功，重启生效！按任意键返回。"
    else
        read -p "自动安装失败，按任意键返回。"
    fi
    start
}

#结束块
function end()
{
    echo "正在退出,欢迎下次使用!"
    exit 0
}



start
