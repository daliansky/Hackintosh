#!/bin/bash

if [ "$(id -u)" != "0" ]; then
    if [ "$(sudo -n echo 'sudo' 2> /dev/null)" != "sudo" ]; then
        echo "This script must be run as root!"
    fi
    sudo $0 $@
    exit 0
fi

# Note: Based on CloverPackage MountESP script.

if [[ "$1" == "" ]]; then
    DestVolume=/
else
    DestVolume="$1"
fi

# find whole disk for the destination volume
DiskDevice=$(LC_ALL=C diskutil info "$DestVolume" 2>/dev/null | sed -n 's/.*Part [oO]f Whole: *//p')
if [[ -z "$DiskDevice" ]]; then
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
if [[ "$PartitionScheme" == "FDisk_partition_scheme" ]]; then
    echo "Error: Volume \"$DestVolume\" is part of an MBR disk"
    exit 1
fi
# Check if not GPT
if [[ "$PartitionScheme" != "GUID_partition_scheme" ]]; then
    echo "Error: Volume \"$DestVolume\" is not on GPT disk or APFS container"
    exit 1
fi

# Find the associated EFI partition on DiskDevice
diskutil list -plist "/dev/$DiskDevice" 2>/dev/null >/tmp/org_rehabman_diskutil.plist
for ((part=0; 1; part++)); do
    content=`/usr/libexec/PlistBuddy -c "Print :AllDisksAndPartitions:0:Partitions:$part:Content" /tmp/org_rehabman_diskutil.plist 2>&1`
    if [[ "$content" == *"Does Not Exist"* ]]; then
        echo "Error: cannot locate EFI partition for $DestVolume"
        exit 1
    fi
    if [[ "$content" == "EFI" ]]; then
        EFIDevice=`/usr/libexec/PlistBuddy -c "Print :AllDisksAndPartitions:0:Partitions:$part:DeviceIdentifier" /tmp/org_rehabman_diskutil.plist 2>&1`
        break
    fi
done
rm /tmp/org_rehabman_diskutil.plist

# should not happen
if [[ -z "$EFIDevice" ]]; then
    echo "Error: unable to determine EFIDevice from $DiskDevice"
    exit 1
fi

# Get the EFI mount point if the partition is currently mounted
code=0
EFIMountPoint=$(LC_ALL=C diskutil info "$EFIDevice" 2>/dev/null | sed -n 's/.*Mount Point: *//p')
if [[ -z "$EFIMountPoint" ]]; then
    # try to mount the EFI partition
    EFIMountPoint="/Volumes/EFI"
    [ ! -d "$EFIMountPoint" ] && mkdir -p "$EFIMountPoint"
    diskutil mount -mountPoint "$EFIMountPoint" /dev/$EFIDevice >/dev/null 2>&1
    code=$?
fi
efidir="${EFIMountPoint// /\\ }"
echo "${EFIMountPoint// /\\ }"
#exit $code
