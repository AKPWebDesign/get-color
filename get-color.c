#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <xdo.h>

void get_pixel_color (Display *d, int x, int y, XColor *color) 
{
  XImage *image;
  
  image = XGetImage (d, RootWindow (d, DefaultScreen (d)), x, y, 1, 1, AllPlanes, XYPixmap);
  color->pixel = XGetPixel (image, 0, 0);
  XFree (image);
  XQueryColor (d, DefaultColormap(d, DefaultScreen (d)), color);
}

int main()  {
  int x, y, scrn;
  
  xdo_t *hndl = xdo_new(NULL);
  xdo_get_mouse_location(hndl, &x, &y, &scrn);
  xdo_free(hndl);

  XColor c;
  Display *display = XOpenDisplay(NULL);

  get_pixel_color(display, x, y, &c);
  printf ("#%02x%02x%02x", c.red >> 8, c.green >> 8, c.blue >> 8);
  return 0;
}