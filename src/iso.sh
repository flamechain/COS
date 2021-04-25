#!/bin/sh
set -e
. ./build.sh

mkdir -p isodir
mkdir -p isodir/boot
mkdir -p isodir/boot/grub

cp sysroot/boot/cos.kernel isodir/boot/cos.kernel
cat > isodir/boot/grub/grub.cfg << EOF
menuentry "cos" {
	multiboot /boot/cos.kernel
}
EOF
grub-mkrescue -o cos.iso isodir
