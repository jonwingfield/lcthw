#/bin/sh

gcc -std=c99 -masm=intel -c -g -Wa,-a,-ad $1.c > $1.lst