#!/bin/sh
bindir=$(pwd)
cd /Users/jon/Library/CloudStorage/Dropbox/Work/2023_2024/Graphics/Git repos/Lab10_Quaternions/source/
export 

if test "x$1" = "x--debugger"; then
	shift
	if test "x" = "xYES"; then
		echo "r  " > $bindir/gdbscript
		echo "bt" >> $bindir/gdbscript
		GDB_COMMAND-NOTFOUND -batch -command=$bindir/gdbscript  /Users/jon/Library/CloudStorage/Dropbox/Work/2023_2024/Graphics/Git\ repos/Lab10_Quaternions/build_work/MinSizeRel/Lab10_Quaternions 
	else
		"/Users/jon/Library/CloudStorage/Dropbox/Work/2023_2024/Graphics/Git\ repos/Lab10_Quaternions/build_work/MinSizeRel/Lab10_Quaternions"  
	fi
else
	"/Users/jon/Library/CloudStorage/Dropbox/Work/2023_2024/Graphics/Git\ repos/Lab10_Quaternions/build_work/MinSizeRel/Lab10_Quaternions"  
fi
