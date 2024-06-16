# dwm - dynamic window manager

dwm is and extremely fast, small, and dynamic window manager for X.

This is my own custom build of [dwm](https://dwm.suckless.org/).
For dwm-polybar build, click [here](https://github.com/wongweilok/dwm/tree/dwm-polybar-build).
Below are patches that I added into my dwm build.

## Patches

* [actualfullscreen](https://dwm.suckless.org/patches/actualfullscreen/): Toggle fullscreen on selected window; (Latest ver: [20211013](https://dwm.suckless.org/patches/actualfullscreen/dwm-actualfullscreen-20211013-cb3f58a.diff))
* [bar height](https://dwm.suckless.org/patches/bar_height/): Allow to configure statusbar height; (Latest ver: [6.2](https://dwm.suckless.org/patches/bar_height/dwm-bar-height-6.2.diff))
* [scratchpad](https://dwm.suckless.org/patches/scratchpad/): Spawn a floating window that can be hidden instead of occuping a window space; (Latest ver: [22021102](https://dwm.suckless.org/patches/scratchpad/dwm-scratchpad-20221102-ba56fe9.diff))
* [status2d](https://dwm.suckless.org/patches/status2d/): Allow color output for statusbar; (Latest ver: [6.4](https://dwm.suckless.org/patches/status2d/dwm-status2d-systray-6.4.diff))
* [statusallmons](https://dwm.suckless.org/patches/statusallmons/): Draws and updates all statusbar for multi-monitor setup; (Latest ver: [6.2](https://dwm.suckless.org/patches/statusallmons/dwm-statusallmons-6.2.diff))
* [sticky](https://dwm.suckless.org/patches/sticky/): Toggle a selected window to be sticky; (Latest ver: [6.4](https://dwm.suckless.org/patches/sticky/dwm-sticky-6.4.diff))
* [systray](https://dwm.suckless.org/patches/systray/): Show systray on statusbar; (Latest ver: [6.4](https://dwm.suckless.org/patches/status2d/dwm-status2d-systray-6.4.diff))
* [titlecolor](https://dwm.suckless.org/patches/titlecolor/): Change title background and foreground color; (Latest ver: [20210815](https://dwm.suckless.org/patches/titlecolor/dwm-titlecolor-20210815-ed3ab6b4.diff))
* [vanitygaps](https://dwm.suckless.org/patches/vanitygaps/): Add gaps between windows for every available layouts, only include [centeredmaster](https://dwm.suckless.org/patches/centeredmaster/) and [bottomstack](https://dwm.suckless.org/patches/bottomstack/) layout; (Latest ver: [6.2](https://dwm.suckless.org/patches/vanitygaps/dwm-vanitygaps-6.2.diff))
* [windowmap](https://dwm.suckless.org/patches/windowmap/): Makes windows get mapped or unmapped in Xorg, to allow fading animation by picom; (Latest ver: [20221026](https://dwm.suckless.org/patches/windowmap/dwm-windowmap-20221026.diff))

## Installation

```
$ git clone https://github.com/wongweilok/dwm.git
$ cd dwm
$ sudo make clean install
```
