#!/bin/bash
wget -P /tmp https://github.com/AbduHany/alx-low_level_programming/raw/master/0x18-dynamic_libraries/_printf.so
export LD_PRELOAD=/tmp/_printf.so
