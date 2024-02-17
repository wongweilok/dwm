/* See LICENSE file for copyright and license details. */ /* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     	/* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            = 24;       /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const char *fonts[]          = {
	"monospace:pixelsize=12:antialias=true:autohint=true",
	"Inconsolata for Powerline:size=18:antialias=true:autohint=true",
	"Font Awesome 6 Free:size=10:antialias=true:autohint=true",
	"Font Awesome 6 Free Solid:size=10:antialias=true:autohint=true",
	"Font Awesome 6 Brands:size=10:antialias=true:autohint=true",
	"NotoColorEmoji:pixelsize=10:antialias=true:autohint=true"
};
static const char col_black[]       = "#282828";
static const char col_black2[]	    = "#1d2021";
static const char col_orange[]	    = "#fe8019";
static const char col_white[]       = "#ebdbb2";
static const char col_green[]       = "#b8bb26";
static const char col_gray[]        = "#555555";
static const char *colors[][3]      = {
	/*                fg          bg         border   */
	[SchemeNorm]  = { col_white,  col_black, col_gray },
	[SchemeSel]   = { col_black2, col_green, col_green },
	[SchemeTitle] = { col_orange, col_black, col_gray },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
	{ "float",    NULL,	  NULL,	      0,	    1,		 -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    		/* first entry is default */
	{ "TTT",      bstack },			/* Master on top, slaves on bottom */
	{ "|M|",      centeredmaster },		/* Master in middle, slaves on sides */
	{ "[M]",      monocle },
	{ "><>",      NULL },    		/* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", NULL };
static const char *termcmd[]  = { "st", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };

#include <X11/XF86keysym.h>

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,             		XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_n,  	   togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_o,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_o,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_space,  zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,             		XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_y,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_u,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_i,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,             		XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_s,      togglesticky,   {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_Left,   focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_Right,  focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Left,   tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Right,  tagmon,         {.i = +1 } },
	{ MODKEY,			XK_a,	   togglegaps,	   {0} },
	{ MODKEY|ShiftMask,		XK_d,	   defaultgaps,	   {0} },
	{ MODKEY,			XK_z,	   incrgaps,	   {.i = +5 } },
	{ MODKEY|ShiftMask,		XK_z,	   incrgaps,	   {.i = -5 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },

	{ MODKEY,			XK_w,	   spawn,	   SHCMD("$BROWSER") },
	{ MODKEY,			XK_r,	   spawn,	   SHCMD("st -e $FILE") },
	{ MODKEY,			XK_m,	   spawn,	   SHCMD("st -c float -g 100x22+350+200 ncmpcpp-ueberzug") },
	{ MODKEY,			XK_c,	   spawn,	   SHCMD("st -e calcurse") },
	{ MODKEY,			XK_g,	   spawn,	   SHCMD("st -e gotop") },
	{ MODKEY|ShiftMask,		XK_g,	   spawn,	   SHCMD("st -e htop") },
	{ MODKEY,			XK_x,	   spawn,	   SHCMD("slock & xset dpms force off; mpc pause") },

	{ MODKEY|ShiftMask,		XK_x,	   spawn,	   SHCMD("powerOption") },
	{ MODKEY|ShiftMask,		XK_k,	   spawn,	   SHCMD("fcitx5") },
	{ MODKEY|ShiftMask,		XK_p,	   spawn,	   SHCMD("passmenu") },
	{ MODKEY,			XK_grave,  spawn,	   SHCMD("dmenuunicode") },
	{ MODKEY,			XK_Print,  spawn,	   SHCMD("screenshotSel") },
	{ 0,				XK_Print,  spawn,	   SHCMD("screenshot") },

	{ MODKEY,			XK_F8,	   spawn,	   SHCMD("st -e nmtui") },
	{ MODKEY,			XK_F10,	   spawn,	   SHCMD("dmenumount") },
	{ MODKEY,			XK_F11,	   spawn,	   SHCMD("dmenuumount") },

	{ MODKEY,			XK_comma,  spawn,	   SHCMD("mpc prev") },
	{ MODKEY,			XK_period, spawn,	   SHCMD("mpc next") },
	{ MODKEY|ShiftMask,		XK_comma,  spawn,	   SHCMD("mpc seek -10") },
	{ MODKEY|ShiftMask,		XK_period, spawn,	   SHCMD("mpc seek +10") },

	{ MODKEY,			XK_Cancel, spawn,	   SHCMD("mpc stop") },
	{ MODKEY,			XF86XK_Go, spawn,	   SHCMD("mpc toggle") },
	{ MODKEY,		 XF86XK_Favorites, spawn,	   SHCMD("mpc seek 0") },

	{ 0, 	XF86XK_AudioMute,		   spawn,	   SHCMD("wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle; pkill -RTMIN+10 dwmblocks") },
	{ 0, 	XF86XK_AudioRaiseVolume,	   spawn,	   SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%+; pkill -RTMIN+10 dwmblocks") },
	{ 0, 	XF86XK_AudioLowerVolume,	   spawn,	   SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%-; pkill -RTMIN+10 dwmblocks") },
	{ 0,	XF86XK_AudioMicMute,		   spawn,	   SHCMD("wpctl set-mute @DEFAULT_AUDIO_SOURCE@ toggle") },
	{ 0,	XF86XK_MonBrightnessUp,		   spawn,	   SHCMD("xbacklight -inc 10") },
	{ 0,	XF86XK_MonBrightnessDown,	   spawn,	   SHCMD("xbacklight -dec 10") },
	{ 0,	XF86XK_Display,			   spawn,	   SHCMD("displayselect") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

