#!/bin/bash
 
####################
# Notes            #                 
####################
#
# Created 20200625 by Nathan Worster
#
# This script assumes that the macOS Beta installer is already staged in the Applications folder, and will convert that .app installer into a bootable .dmg.
# To download the latest macOS beta, go to https://developer.apple.com/download/ or, if applicable, https://appleseed.apple.com/.
# The .dmg file will be placed in ~/Downloads.
# This script must be run with sudo using "sudo bash <filename>" if run outside of an MDM.
# 
####################
# Variables        #
####################
 
dmgName=$"macOS11BigSurBeta"
 
####################
# Script           #
####################
 
cd ~/Downloads
 
# Create and mount sparse volume:
hdiutil create -o install_container -size 15G -layout SPUD -fs HFS+J -type SPARSE
hdiutil attach install_container.sparseimage -noverify -mountpoint /Volumes/install_build
 
# Copy contents of installer .app into mounted volume:
/Applications/Install\ macOS\ Beta.app/Contents/Resources/createinstallmedia --nointeraction --volume /Volumes/install_build
 
# Detach the completed image:
hdiutil detach -force /Volumes/Install\ macOS\ Beta
 
# Convert and rename the image:
hdiutil convert install_container.sparseimage -format UDZO -o $dmgName.dmg
 
# Cleanup
 
rm install_container.sparseimage
 
exit 0