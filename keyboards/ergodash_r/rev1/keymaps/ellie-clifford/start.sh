#!/bin/sh
python3 pregen_overrides.py
qmk flash -kb ergodash_r/rev1 -km eleanor-clifford
qmk flash -kb ergodash_r/rev1 -km eleanor-clifford
sleep 2
#~/.config/scripts/setup-keyboards.sh
setxkbmap gb
