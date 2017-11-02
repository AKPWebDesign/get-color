# get-color
This just gets the color under your cursor and spits it out. Cobbled together from various sample code I found.

Usage: `get-color | xclip -selection clipboard`

Compile: `gcc -o get-color get-color.c -lxdo $(pkg-config --cflags --libs x11)`
That's how I compile this. If you know a better way, feel free to PR.
