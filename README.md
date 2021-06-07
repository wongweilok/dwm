# dwm - dynamic window manager

dwm is and extremely fast, small, and dynamic window manager for X.

This is my own custom build of [dwm](https://dwm.suckless.org/).
Below are patches that I added into my dwm build.

## Patches

* [actualfullscreen](https://dwm.suckless.org/patches/actualfullscreen/): Toggle fullscreen on selected window
* [anybar](https://dwm.suckless.org/patches/anybar/): Enable dwm to use external status bar
* [ipc](https://dwm.suckless.org/patches/ipc/): Allow communication between window manager and external status bar through UNIX socket
* [scratchpad](https://dwm.suckless.org/patches/scratchpad/): Spawn a floating window that can be hidden instead of occuping a window space
* [sticky](https://dwm.suckless.org/patches/sticky/): Toggle a selected window to be sticky
* [vanitygaps](https://dwm.suckless.org/patches/vanitygaps/): Add gaps between windows for every available layouts
* Additional window layouts
  - [centeredmaster](https://dwm.suckless.org/patches/centeredmaster/)
  - [bottomstack](https://dwm.suckless.org/patches/bottomstack/)

## Installation

```
$ git clone https://github.com/wongweilok/dwm.git
$ cd dwm
$ git checkout dwm-polybar-build
$ sudo make clean install
```

## Resources

For more information, refer [polybar-dwm-module](https://github.com/mihirlad55/polybar-dwm-module) repo.
