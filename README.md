# dwm - dynamic window manager

dwm is and extremely fast, small, and dynamic window manager for X.

This is my own custom build of [dwm](https://dwm.suckless.org/).
Below are patches that I added into my dwm build.

## Patches

* [actualfullscreen](https://dwm.suckless.org/patches/actualfullscreen/): Toggle fullscreen on selected window
* [bar height](https://dwm.suckless.org/patches/bar_height/): Allow to configure statusbar height
* [scratchpad](https://dwm.suckless.org/patches/scratchpad/): Spawn a floating window that can be hidden instead of occuping a window space
* [status2d](https://dwm.suckless.org/patches/status2d/): Allow color output for statusbar
* [sticky](https://dwm.suckless.org/patches/sticky/): Toggle a selected window to be sticky
* [systray](https://dwm.suckless.org/patches/systray/): Show systray on statusbar
* [titlecolor](https://dwm.suckless.org/patches/titlecolor/): Change title background and foreground color
* [vanitygaps](https://dwm.suckless.org/patches/vanitygaps/): Add gaps between windows for every available layouts
* Additional window layouts
  - [centeredmaster](https://dwm.suckless.org/patches/centeredmaster/)
  - [bottomstack](https://dwm.suckless.org/patches/bottomstack/)

## Requirements

Install [libxft-bgra](https://aur.archlinux.org/packages/libxft-bgra/) to prevent color emoji / font rendering issues.

## Installation

```
$ git clone https://github.com/Wayloque/dwm.git
$ cd dwm
$ sudo make clean install
```
