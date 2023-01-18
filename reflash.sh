#!/bin/bash

QMK_DIR="$HOME/src/codemicro/qmk_firmware"

function flash {
    make --jobs=1 $KEYBOARD:$KEYMAP:flash
}

set -ex

KEYBOARD="lets_split/rev2"
KEYMAP="codemicro"

(
	cd $QMK_DIR

	(
		cd keyboards/lets_split/keymaps/codemicro
		qmk json2c abi_stock.json > layout.c
	)

    echo "Connect first side now"
    flash
    echo "Connect second side now"
    flash
)
