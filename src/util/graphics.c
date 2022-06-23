#include "graphics.h"
#include <X11/Xlib.h>
#include<X11/Xutil.h>
#include<X11/Xatom.h>
#include "../log/log.h"

struct {
    Display * display;
    int root;
    int defaultscreen;
    XVisualInfo visinfo;
}
    handle;

#define BIT_DEPTH 24

bool graphics_init()
{
    handle.display = XOpenDisplay(0);
    handle.root = DefaultRootWindow(handle.display);
    handle.defaultscreen = DefaultScreen(handle.display);

    if (!XMatchVisualInfo (handle.display, handle.defaultscreen, BIT_DEPTH, TrueColor, &handle.visinfo))
    {
	log_fatal ("Failed XMatchVisualInfo");
	return false;
    }

    
}
