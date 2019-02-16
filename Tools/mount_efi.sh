#!/bin/bash

#set -x

# Note: Based on CloverPackage MountESP script.

if [ "$(id -u)" != "0" ]; then
    echo "Error: This script requires superuser access, use: 'sudo $0 $@'"
    exit 1
fi

if [ "$1" == "" ]; then
    DestVolume=/
else
    DestVolume="$1"
fi

# find whole disk for the destination volume
DiskDevice=$(LC_ALL=C diskutil info "$DestVolume" 2>/dev/null | sed -n 's/.*Part [oO]f Whole: *//p')
if [ -z "$DiskDevice" ]; then
    echo "Error: Not able to find volume with the name \"$DestVolume\""
    exit 1
fi

# check if target volume is a logical Volume instead of physical
if [[ "$(echo $(LC_ALL=C diskutil list | grep -i 'Logical Volume' | awk '{print tolower($0)}'))" == *"logical volume"* ]]; then
    # ok, we have a logical volume somewhere.. so that can assume that we can use "diskutil cs"
    LC_ALL=C diskutil cs info $DiskDevice > /dev/null 2>&1
    if [[ $? -eq 0 ]] ; then
        # logical volumes does not have an EFI partition (or not suitable for us?)
        # find the partition uuid
        UUID=$(LC_ALL=C diskutil info "${DiskDevice}" 2>/dev/null | sed -n 's/.*artition UUID: *//p')
        # with the partition uuid we can find the real disk in in diskutil list output
        if [[ -n "$UUID" ]]; then
            realDisk=$(LC_ALL=C diskutil list | grep -B 1 "$UUID" | grep -i 'logical volume' | awk '{print $4}' | sed -e 's/,//g' | sed -e 's/ //g')
            if [[ -n "$realDisk" ]]; then
                DiskDevice=$(LC_ALL=C diskutil info "${realDisk}" 2>/dev/null | sed -n 's/.*Part [oO]f Whole: *//p')
            fi
        fi
    fi
fi

# check if target volume is APFS, and therefore part of an APFS container
if [[ "$(echo $(LC_ALL=C diskutil list "$DiskDevice" | grep -i 'APFS Container Scheme' | awk '{print tolower($0)}'))" == *"apfs container scheme"* ]]; then
    # ok, this disk is an APFS partition, extract physical store device
    realDisk=$(LC_ALL=C diskutil list "$DiskDevice" 2>/dev/null | sed -n 's/.*Physical Store *//p')
    DiskDevice=$(LC_ALL=C diskutil info "$realDisk" 2>/dev/null | sed -n 's/.*Part [oO]f Whole: *//p')
fi

PartitionScheme=$(LC_ALL=C diskutil info "$DiskDevice" 2>/dev/null | sed -nE 's/.*(Partition Type|Content \(IOContent\)): *//p')
# Check if the disk is an MBR disk
if [ "$PartitionScheme" == "FDisk_partition_scheme" ]; then
    echo "Error: Volume \"$DestVolume\" is part of an MBR disk"
    exit 1
fi
# Check if not GPT
if [ "$PartitionScheme" != "GUID_partition_scheme" ]; then
    echo "Error: Volume \"$DestVolume\" is not on GPT disk or APFS container"
    exit 1
fi

# Get the index of the EFI partition
EFIIndex=$(LC_ALL=C /usr/sbin/gpt -r show "/dev/$DiskDevice" 2>/dev/null | awk 'toupper($7) == "C12A7328-F81F-11D2-BA4B-00A0C93EC93B" {print $3; exit}')
[ -z "$EFIIndex" ] && EFIIndex=$(LC_ALL=C diskutil list "$DiskDevice" 2>/dev/null | awk '$2 == "EFI" {print $1; exit}' | cut -d : -f 1)
[ -z "$EFIIndex" ] && EFIIndex=$(LC_ALL=C diskutil list "$DiskDevice" 2>/dev/null | grep "EFI"|awk '{print $1}'|cut -d : -f 1)
[ -z "$EFIIndex" ] && EFIIndex=1 # if not found use the index 1

# Define the EFIDevice
EFIDevice="${DiskDevice}s$EFIIndex"

# Get the EFI mount point if the partition is currently mounted
EFIMountPoint=$(LC_ALL=C diskutil info "$EFIDevice" 2>/dev/null | sed -n 's/.*Mount Point: *//p')

code=0
if [ ! "$EFIMountPoint" ]; then
    # try to mount the EFI partition
    EFIMountPoint="/Volumes/EFI"
    [ ! -d "$EFIMountPoint" ] && mkdir -p "$EFIMountPoint"
    diskutil mount -mountPoint "$EFIMountPoint" /dev/$EFIDevice >/dev/null 2>&1
    code=$?
fi
echo $EFIMountPoint
exit $code
