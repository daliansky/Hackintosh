#!/bin/bash
#WebDD v1.7
r="\\033[31;1m"
g="\\033[32;1m"
b="\033[36m"
k="\033[30m"
d="\\033[0m"
rm -rf /tmp/expanded.pkg 2>/dev/null
rm -rf /tmp/WebDriver-"$download_version".pkg 2>/dev/null
rm -rf /tmp/nvtmp 2>/dev/null
echo > /tmp/gputmp
echo > /tmp/gpuvid
mkdir -p /tmp/nvtmp
cd /tmp/nvtmp
webdd()
{
	if [ ! -n "$1" ];then
		bver=$(sw_vers -buildVersion)
		pver=$(sw_vers -productVersion)
		pname=$(sw_vers -productName)
		text="当前"
		else
			bver=$1
			pver=$(cat /tmp/sysver|grep "$1"|grep -Eo '[0-9]+\.[0-9]+\.[0-9+]')
			pname="Mac OS X"
			text="选择"
			fi
index=0
echo -ne "正在查找合适的驱动版本...\r"
curl -s "https://gfe.nvidia.com/mac-update" > /tmp/mac-update.plist
	if [[ $(test -f /tmp/mac-update.plist && echo 1) ]]
	then
		while [[ $(/usr/libexec/PlistBuddy -c "Print :updates:"$index":OS" /tmp/mac-update.plist 2>/dev/null && echo 1) ]];
		do
			if [[ $(/usr/libexec/PlistBuddy -c "Print :updates:"$index":OS" /tmp/mac-update.plist) == "$bver" ]]
			then
				download_url=$(/usr/libexec/PlistBuddy -c "Print :updates:"$index":downloadURL" /tmp/mac-update.plist)
				download_version=$(/usr/libexec/PlistBuddy -c "Print :updates:"$index":version" /tmp/mac-update.plist)
				break
			else
				let index++
			fi
		done
	fi
if [[ "$download_version" == "" ]] || [[ "$download_url" == "" ]]
	then
		index=0
		curl -s "https://raw.githubusercontent.com/lihaoyun6/web/master/mac-update.plist" > /tmp/mac-update.plist
		if [[ $(test -f /tmp/mac-update.plist && echo 1) ]]
		then
			while [[ $(/usr/libexec/PlistBuddy -c "Print :updates:"$index":OS" /tmp/mac-update.plist 2>/dev/null && echo 1) ]];
			do
				if [[ $(/usr/libexec/PlistBuddy -c "Print :updates:"$index":OS" /tmp/mac-update.plist) == "$bver" ]]
				then
					download_url=$(/usr/libexec/PlistBuddy -c "Print :updates:"$index":downloadURL" /tmp/mac-update.plist)
					download_version=$(/usr/libexec/PlistBuddy -c "Print :updates:"$index":version" /tmp/mac-update.plist)
					break
				else
					let index++
				fi
			done
		fi
		if [[ "$download_version" == "" ]] || [[ "$download_url" == "" ]]
		then
		echo "未能从NVIDIA官方服务器中找到适用于 $(echo $pname|tr -d '\n') $(echo $pver|tr -d '\n') $(echo $bver|tr -d '\n') 系统的WebDriver."
		echo -ne '是否手动选择版本 [y/n]'
		read custom
		case $custom in
			[yY])
			read -p "请输入系统版本(例如10.13.6):" ver
			curl "https://raw.githubusercontent.com/lihaoyun6/macOS-Build-Numbers/master/bv2pv" 2>/dev/null|tee /tmp/sysver|grep -i "$ver" > /tmp/webddtmp
			printlist /tmp/webddtmp 'sed s/\.0//g' "chosefromlist \$num \$filepath \"grep -Eo [0-9]{1,2}[A-Z].*\" \"webdd \\\$info\" \"webdd \\\$info\" \"\n请选择您要下载驱动的系统版本: \" \"${r}\a请选择正确的序号:$d\"" "根据您搜索的关键词,共找到 $g" "$d 个系统版本$r"
			;;
			[nN])  exit
			;;
			*)  echo '输入y继续，输入n退出，请输入正确的选项'
			;;
			esac
		exit
		fi
fi
echo -e "您"$text"的系统版本为: "$g"$(echo $pname|tr -d '\n') $(echo $pver|tr -d '\n') $(echo $bver|tr -d '\n')"$d
echo -e "已找到适用于当前系统版本的: "$g"NVIDIA WebDriver-$download_version"$d
echo -ne '是否立即下载此版本 WebDriver [y/n]'
read yn1
case $yn1 in
	[yY])
	echo "正在下载 WebDriver..."
	curl -# -k -o /tmp/WebDriver-"$download_version".pkg $download_url
	clear
	echo -n "下载完成，是否需要去除安装限制 [y/n]"
	read yn2
	case $yn2 in
		[yY])  clear
		echo "正在移除安装限制..."
		pkgutil --expand /tmp/WebDriver-"$download_version".pkg /tmp/expanded.pkg
		sed -i '' -E "s/if \(\!validateHardware\(\)\) return false;/\/\/if \(\!validateHardware\(\)\) return false;/g" /tmp/expanded.pkg/Distribution
		sed -i '' -E "s/if \(\!validateSoftware\(\)\) return false;/\/\/if \(\!validateSoftware\(\)\) return false;/g" /tmp/expanded.pkg/Distribution
		sed -i "" '/installation-check/d' /tmp/expanded.pkg/Distribution
		echo -n "是否需要强制匹配当前系统版本 [y/n]"
		read yn3
		case $yn3 in
			[yY])  clear
			echo "正在修改匹配信息..."
			cat /tmp/expanded.pkg/*NVWebDrivers.pkg/Payload|gunzip -dc|cpio -i --quiet
			/usr/libexec/PlistBuddy -c "Set IOKitPersonalities:NVDAStartup:NVDARequiredOS $(sw_vers -buildVersion)" $(find /tmp/nvtmp -type d -name NVDAStartupWeb.kext)/Contents/Info.plist
			find .|cpio -o --quiet|gzip -c > /tmp/expanded.pkg/*NVWebDrivers.pkg/Payload
			mkbom . /tmp/expanded.pkg/*NVWebDrivers.pkg/Bom
			clear
			echo "已强制匹配此版 WebDriver 版本信息。"
			;;
			[nN])  :
			;;
			*)  echo '输入y继续，输入n退出，请输入正确的选项'
			;;
		esac
		pkgutil --flatten /tmp/expanded.pkg ~/Desktop/WebDriver-"$download_version"-Unoffical.pkg
		rm -rf /tmp/expanded.pkg
		rm -rf /tmp/WebDriver-"$download_version".pkg
		rm -rf /tmp/nvtmp
		clear
		echo "已将修改后的 WebDiver 复制到桌面。"
		;;
		[nN])  cp /tmp/WebDriver-"$download_version".pkg ~/Desktop/WebDriver-"$download_version"-Offical.pkg
		rm -rf /tmp/WebDriver-"$download_version".pkg
		clear
		echo "已将未修改的官方版 WebDriver 复制到桌面。"
		;;
		*)  echo '输入y继续，输入n退出，请输入正确的选项'
		;;
	esac
	;;
	[nN])  exit
	;;
	*)  echo '输入y继续，输入n退出，请输入正确的选项'
	;;
esac
}
gpulist()
{
	echo > /tmp/gputmp
	nngpu="$(ioreg -n GFX0@0|sed -E '/{/,/\| }$/!d'|grep \"device-id\"|sed 's/.*\<\(.*\)\>.*/\1/'|sed -E 's/^(.{2})(.{2}).*$/\2\1/'|wc -l|awk '{print $1}')"
	if [ "$nngpu" -lt 1 ]
	then
		n=0
	else
		n=0
	while [ x"$ngpu" != x0 ]
	do
		eval dgpu_device_id="$(ioreg -n GFX$n@0|sed -E '/{/,/\| }$/!d'|grep \"device-id\"|sed 's/.*\<\(.*\)\>.*/\1/'|sed -E 's/^(.{2})(.{2}).*$/\2\1/')"
		eval dgpu_vendor_id="$(ioreg -n GFX$n@0|sed -E '/{/,/\| }$/!d'|grep \"vendor-id\"|sed 's/.*\<\(.*\)\>.*/\1/'|sed -E 's/^(.{2})(.{2}).*$/\2\1/')"
		echo $dgpu_vendor_id >> /tmp/gpuvid
		dgpu_names=$(curl -s "http://pci-ids.ucw.cz/read/PC/"$dgpu_vendor_id$"/"$dgpu_device_id|grep itemname|sed -E "s/.*Name\: (.*)$/\1/")
		echo "$dgpu_names"|tail -1|sed 's/ /_/g' >> /tmp/gputmp
		let n++
		eval ngpu="$(ioreg -n GFX$n@0|sed -E '/{/,/\| }$/!d'|grep \"device-id\"|sed 's/.*\<\(.*\)\>.*/\1/'|sed -E 's/^(.{2})(.{2}).*$/\2\1/'|wc -l|awk '{print $1}')"
	done
	fi
	if [ $n = 0 ];then
		gpu2n="$(system_profiler SPDisplaysDataType|grep "0x10de" -A 1|grep -Eo "0x[^)]*"|sed 's/0x//g'|grep -v "10de"|wc -l|awk '{print $1}')"
		if [ $gpu2n = 0 ];then
			gpu2a="$(system_profiler SPDisplaysDataType|grep "0x1002" -A 1|grep -Eo "0x[^)]*"|sed 's/0x//g'|grep -v "1002"|wc -l|awk '{print $1}')"
			if [ $gpu2a = 0 ];then
				n2=0
				else
					n2=0
					for i in $(system_profiler SPDisplaysDataType|grep "0x1002" -A 1|grep -Eo "0x[^)]*"|sed 's/0x//g'|grep -v "1002")
					do
						gpu_names2a=$(curl -s "http://pci-ids.ucw.cz/read/PC/1002/"$i|grep itemname|sed -E "s/.*Name\: (.*)$/\1/")
						echo "$gpu_names2a"|tail -1|sed 's/ /_/g' >> /tmp/gputmp
						echo 1002 >> /tmp/gpuvid
						let n2++
						done
						fi
						else
							n2=0
							for i in $(system_profiler SPDisplaysDataType|grep "0x10de" -A 1|grep -Eo "0x[^)]*"|sed 's/0x//g'|grep -v "10de")
							do
								gpu_names2n=$(curl -s "http://pci-ids.ucw.cz/read/PC/10de/"$i|grep itemname|sed -E "s/.*Name\: (.*)$/\1/")
								echo "$gpu_names2n"|tail -1|sed 's/ /_/g' >> /tmp/gputmp
								echo 10de >> /tmp/gpuvid
								let n2++
								done
								n3=0
								for i in $(system_profiler SPDisplaysDataType|grep "0x1002" -A 1|grep -Eo "0x[^)]*"|sed 's/0x//g'|grep -v "1002")
								do
									gpu_names2a=$(curl -s "http://pci-ids.ucw.cz/read/PC/1002/"$i|grep itemname|sed -E "s/.*Name\: (.*)$/\1/")
									echo "$gpu_names2a"|tail -1|sed 's/ /_/g' >> /tmp/gputmp
									echo 1002 >> /tmp/gpuvid
									let n3++
									done
								fi
								fi
	negpu="$(ioreg -n display@0|sed -E '/{/,/\| }$/!d'|grep \"device-id\"|sed 's/.*\<\(.*\)\>.*/\1/'|sed -E 's/^(.{2})(.{2}).*$/\2\1/'|wc -l|awk '{print $1}')"
	if [ "$negpu" -lt 1 ]
	then
		ne=0
	else
		ne=0
	while [ x"$egpu" != x0 ]
	do
		eval egpu_vendor_id="$(ioreg -n display@$ne|sed -E '/{/,/\| }$/!d'|grep \"vendor-id\"|sed 's/.*\<\(.*\)\>.*/\1/'|sed -E 's/^(.{2})(.{2}).*$/\2\1/')"
		eval egpu_device_id="$(ioreg -n display@$ne|sed -E '/{/,/\| }$/!d'|grep \"device-id\"|sed 's/.*\<\(.*\)\>.*/\1/'|sed -E 's/^(.{2})(.{2}).*$/\2\1/')"
		echo $dgpu_vendor_id >> /tmp/gpuvid
		egpu_names=$(curl -s "http://pci-ids.ucw.cz/read/PC/"$egpu_vendor_id$"/"$egpu_device_id|grep itemname|sed -E "s/.*Name\: (.*)$/\1/")
		echo "$egpu_names"|tail -1|sed 's/ /_/g' >> /tmp/gputmp
		let ne++
		eval egpu="$(ioreg -n display@$ne|sed -E '/{/,/\| }$/!d'|grep \"device-id\"|sed 's/.*\<\(.*\)\>.*/\1/'|sed -E 's/^(.{2})(.{2}).*$/\2\1/'|wc -l|awk '{print $1}')"
	done
	fi
	let n=n+ne+n2+n3
}
printlist()
{
filepath=$1
optionsetting=$2
endcommand=$3
text1=$4
text2=$5
num=1
echo -ne "$text1$(cat $filepath|grep -v '^$'|wc -l|awk '{print $1}')$text2\n\n"
	for i in $(cat $filepath)
	do
		echo -ne "["$num"] ";echo -ne "$i\n"|$optionsetting
		let num++
		done
		echo -ne "\\033[0m"
		eval $endcommand
}
chosefromlist()
{
options=$1
filepath=$2
optionsetting=$3
command1gt=$4
command1eq=$5
ntext=$6
wtext=$7

	if [ "$options" -lt 2 ];then
		:
		elif [ "$options" -gt 2 ];then
			if [ x"$8" != x"warn" ];then
				text=$ntext
				else
					text=$wtext
					fi
					echo -ne $text
	read chose
	if [ ! -n "$chose" ];then
		chosefromlist "$options" "$filepath" "$optionsetting" "$command1gt" "$command1eq" "$ntext" "$wtext" warn
		elif [ $(echo $chose|sed 's/[0-9]//g'|wc -c) -ne 1 ];then
			chosefromlist "$options" "$filepath" "$optionsetting" "$command1gt" "$command1eq" "$ntext" "$wtext" warn
			elif [ "$chose" -gt "$options" ];then
				chosefromlist "$options" "$filepath" "$optionsetting" "$command1gt" "$command1eq" "$ntext" "$wtext" warn
				elif [ "$chose" -lt 1 ];then
					chosefromlist "$options" "$filepath" "$optionsetting" "$command1gt" "$command1eq" "$ntext" "$wtext" warn
				else
	line=$(cat $filepath|sed -n "${chose}p")
	info=$(echo $line|$optionsetting)
	echo -ne "\n["$chose"] "$info"\n\n"
	eval $command1gt
	fi
	elif [ "$options" -eq 2 ];then
		line=$(cat $filepath|sed -n 1p)
		info=$(echo $line|$optionsetting)
		eval $command1eq
		else
			echo "未知错误! 可能发生了无法预计的错误."
			fi
}
if [ ! -n "$1" ];then
	clear
	echo -ne "正在进行信息检查...\r"
	gpulist
	printlist /tmp/gputmp 'cat' '' "在此计算机上共找到 $g" "$d 张独立显卡$r"
	echo
	if [ $n -lt 1 ]
	then
		echo "并未找到独立显卡，是否仍要下载WebDriver? [y/n]"
		read yn0
		case $yn0 in
		[yY]) webdd
		;;
		[nN]) exit
		;;
		*)  echo '输入y继续，输入n退出，请输入正确的选项'
		esac
	else
		nvidia=$(cat /tmp/gpuvid|grep 10de|wc -l|awk '{print $1}')
		if [ $nvidia = 0 ];then
			echo "并未找到 Nvidia 独立显卡，是否仍要下载WebDriver? [y/n]"
			read yn1
			case $yn1 in
			[yY]) webdd
			;;
			[nN]) exit
			;;
			*)  echo '输入y继续，输入n退出，请输入正确的选项'
			esac
			else
		webdd
		fi
	fi
	else
		curl "https://raw.githubusercontent.com/lihaoyun6/macOS-Build-Numbers/master/bv2pv" 2>/dev/null|tee /tmp/sysver|grep -i "$1" > /tmp/webddtmp
		printlist /tmp/webddtmp 'sed s/\.0//g' "chosefromlist \$num \$filepath \"grep -Eo [0-9]{1,2}[A-Z].*\" \"webdd \\\$info\" \"webdd \\\$info\" \"\n请选择您要下载驱动的系统版本: \" \"${r}\a请选择正确的序号:$d\"" "根据您搜索的关键词,共找到 $g" "$d 个系统版本$r"
	fi
