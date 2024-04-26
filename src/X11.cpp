#include "global.h"
#include "forDrawing.h"
#include "X11.h"


Picasso::Picasso(int fldW, int nffldW, int fldH){
        d = XOpenDisplay(NULL);
    if (d == NULL) {
        std::cout << "Error opening display." << std::endl;
        exit(1);
    }

    s = DefaultScreen(d);
    w = XCreateSimpleWindow(d, RootWindow(d, s),
                            0, 0,
                            fldW+nffldW, fldH,
                            1,
                            WhitePixel(d, s), BlackPixel(d, s));
}
Picasso::Picasso(Display *dis, Window wd, int ss)
    : d(dis), w(wd), s(ss){}

void Picasso::basicConfig(){
    XSelectInput(d, w, KeyPressMask | KeyReleaseMask | ExposureMask);
}
void Picasso::renew(){
    XMapWindow(d, w);
    XFlush(d);
}
void Picasso::view(){
    XEvent event;
    XNextEvent(d, &event);
    XClearWindow(d,w);
    Redraw();
    XFlush(d);
    switch(event.type){
        case Expose:
            Redraw();
            XFlush(d);
            break;
        case KeyPress:
            if (event.xkey.keycode == 111) // ^
            {
                Move(111);

            }
            if (event.xkey.keycode == 113) // <-
            {
                Move(113);

            }
            if (event.xkey.keycode == 114) // ->
            {
                Move(114);

            }
            if (event.xkey.keycode == 116) // v
            {
                Move(116);

            }
            if (event.xkey.keycode == 65) // space
            {
                //!
            }
            XFlush(d);
            break;   

    }
    XFlush(d);
    
}

void Picasso::kill(){
    XCloseDisplay(d);
}
void Picasso::GetColorPixel(){}
void Picasso::brush(int clr){
    XSetForeground(d, DefaultGC(d, 0), clr);
}

void Picasso::line(int x1, int y1, int x2, int y2){
    XDrawLine(d, w, DefaultGC(d, 0), x1, y1, x2, y2);
}

void Picasso::DrawLine(int x1, int y1, int x2, int y2, int LineClr){
    brush(LineClr);
    line(x1, y1, x2, y2);
}
void Picasso::DrawRectangle(int x, int y, int h, int wd,  int LineClr){
    brush(LineClr);
    XDrawRectangle(d, w, DefaultGC(d, 0), x, y, wd, h);

}
void Picasso::FillRectangle(int x, int y, int h, int wd, int clr){
    brush(clr);
    XFillRectangle(d, w, DefaultGC(d, 0), x, y, wd, h);
}

void Picasso::SubscribeToDraw(forDrawing *mem){
    SubscribersToDraw.push_back(mem);
}
void Picasso::UnsubscribeToDraw(forDrawing *mem){}

void Picasso::SubscribeToMove  (iKeyInstructor  *mem){
    SubscribersToMove.push_back(mem);
};
void Picasso::UnsubscribeToMove(iKeyInstructor  *mem){};



