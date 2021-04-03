#!/bin/sh
curl -fsSL https://cdn.jsdelivr.net/gh/daliansky/Hackintosh/Tools/macserial -o /tmp/macserial && chmod +x /tmp/macserial && sh -c /tmp/macserial | grep -w 'Model:\|Valid:\|Hardware UUID:\|ROM:\|MLB:\|Serial Number:' | sed '/ \- /d' | tr -d ' ' | sed $'s/Model:/SystemProductName:/g' | sed $'s/HardwareUUID:/SystemUUID:/g' | sed $'s/SerialNumber:/SystemSerialNumber:/g' | sed $'s/\:/\: /g'  ## 一键提取三码，自己试试就行了，别帖出来哈

