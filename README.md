# dwm - dynamic window manager

dwm is and extremely fast, small, and dynamic window manager for X.

This is my own custom build of [dwm](https://dwm.suckless.org/).
For dwm-polybar build, click [here](https://github.com/wongweilok/dwm/tree/dwm-polybar-build).
Below are patches that I added into my dwm build.

## Patches

* [actualfullscreen](https://dwm.suckless.org/patches/actualfullscreen/): Toggle fullscreen on selected window
* [bar height](https://dwm.suckless.org/patches/bar_height/): Allow to configure statusbar height
* [scratchpad](https://dwm.suckless.org/patches/scratchpad/): Spawn a floating window that can be hidden instead of occuping a window space
* [status2d](https://dwm.suckless.org/patches/status2d/): Allow color output for statusbar
* [statusallmons](https://dwm.suckless.org/patches/statusallmons/): Draws and updates all statusbar for multi-monitor setup
* [sticky](https://dwm.suckless.org/patches/sticky/): Toggle a selected window to be sticky
* [systray](https://dwm.suckless.org/patches/systray/): Show systray on statusbar
* [titlecolor](https://dwm.suckless.org/patches/titlecolor/): Change title background and foreground color
* [vanitygaps](https://dwm.suckless.org/patches/vanitygaps/): Add gaps between windows for every available layouts
* Additional window layouts
  - [centeredmaster](https://dwm.suckless.org/patches/centeredmaster/)
  - [bottomstack](https://dwm.suckless.org/patches/bottomstack/)

## Installation

```
$ git clone https://github.com/wongweilok/dwm.git
$ cd dwm
$ sudo make clean install
```
