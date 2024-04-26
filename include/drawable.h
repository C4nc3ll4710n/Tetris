#ifndef Drawable_h
#define Drawable_h


#include "global.h"

struct drawable{
    /*int x, y, h, wd;
    int backClrCode = 0x000000, bordClrCode = 0xFFFF00;
    drawable(int posX, int posY)
        : x(posX), y(posY), h(0), wd(0) {}
    drawable(int posX, int posY, int height, int width)
        : x(posX), y(posY), h(height), wd(width) {}
    drawable(int posX, int posY, int height, int width, int clrcd)
        : x(posX), y(posY), h(height), wd(width), backClrCode(clrcd) {}
    drawable(int posX, int posY, int height, int width, int clrcd, int brclr)
        : x(posX), y(posY), h(height), wd(width), backClrCode(clrcd), bordClrCode(brclr) {}*/
    virtual void draw() = 0;
};



#endif //Drawable_h