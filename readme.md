# akp's QMK fork

This is my personal fork of the QMK project.

### Keyboards

* [`keyboards/codemicro/macropad`](keyboards/codemicro/macropad)
	* See https://github.com/codemicro/macropad

### Keymaps

* [`keyboards/lets_split/keymaps/codemicro`](keyboards/lets_split/keymaps/codemicro)
	* `reflash.sh` is setup for use with this keymap
* [`keyboards/codemicro/macropad/codemicro`](keyboards/codemicro/macropad/keymaps/codemicro)

#### Building `codemicro/macropad`

To compile QMK for the macropad, run the following command:

```
make codemicro/macropad:codemicro
```

This compiles the `codemicro` keymap for the `codemicro/macropad` keyboard and will output a file called `codemicro_macropad_codemicro.uf2` that be copied onto the Pi Pico.
