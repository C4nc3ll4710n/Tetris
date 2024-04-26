#include "global.h"
#include "drawable.h"
#ifndef X11_HPP
#define X11_HPP


class Picasso{
private:
    Display *d;
    Window   w;
    int      s;
    std::vector<drawable *> SubscribersToDraw;
    void Redraw(){
        for (size_t i=0; i<SubscribersToDraw.size(); i++){
            SubscribersToDraw[i]->draw();
        }
    }
    
public:
    Picasso(int fldW, int nffldW, int fldH){
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
    Picasso(Display *dis, Window wd, int ss)
        : d(dis), w(wd), s(ss){}

    void basicConfig(){
        XSelectInput(d, w, KeyPressMask | KeyReleaseMask | ExposureMask);
    }
    void renew(){
        XMapWindow(d, w);
        XFlush(d);
    }
    void view(){
        //XExposeEvent xe = {Expose, 0, 1, d, w, 0, 0, 1000, 1000, 0};
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
                /*if (event.xkey.keycode == 113)
                    f.left();
                if (event.xkey.keycode == 114)
                    f.right();
                if (event.xkey.keycode == 65){
                    std::cout << "spaceAlert" << heapHeight[f.x/40]-40;
                    f.y = heapHeight[f.x/40]-40;
                }*/
                std::cout << "That was keypress.\n";
                XFlush(d);
                break;   

        }
        XFlush(d);
        
    }

    void kill(){
        XCloseDisplay(d);
    }
    void GetColorPixel(){}
    void brush(int clr){
        XSetForeground(d, DefaultGC(d, 0), clr);
    }

    void line(int x1, int y1, int x2, int y2){
        XDrawLine(d, w, DefaultGC(d, 0), x1, y1, x2, y2);
    }

    void DrawLine(int x1, int y1, int x2, int y2, int LineClr){
        brush(LineClr);
        line(x1, y1, x2, y2);
    }
    void DrawRectangle(int x, int y, int h, int wd,  int LineClr){
        /*XSetForeground(d, DefaultGC(d, 0), LineClr);
        XDrawRectangle(d, w, DefaultGC(d, 0), x, y, 40, 40);
        XDrawLine(d, w, DefaultGC(d, 0), x+24, y+4, x+36, y+4);
        XDrawLine(d, w, DefaultGC(d, 0), x+36, y+4, x+36, y+24);    */
        brush(LineClr);
        XDrawRectangle(d, w, DefaultGC(d, 0), x, y, wd, h);

    }
    void FillRectangle(int x, int y, int h, int wd, int clr){
        brush(clr);
        XFillRectangle(d, w, DefaultGC(d, 0), x, y, wd, h);
    }
    
    void SubscribeToDraw(drawable *mem){
        SubscribersToDraw.push_back(mem);
    }
    void UnsubscribeToDraw(drawable *mem){}
    
    
    
};


#endif //X11_HPP