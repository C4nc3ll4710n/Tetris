#include "global.h"
#include "forDrawing.h"
#include "iKeyInstructor.h"
#ifndef X11_H
#define X11_H


class Picasso{
private:
    Display *d;
    Window   w;
    int      s;
    std::vector<forDrawing *> SubscribersToDraw;
    std::vector<iKeyInstructor  *> SubscribersToMove;

    void Redraw()
    {
        for (size_t i=0; i<SubscribersToDraw.size(); i++)
        {
            SubscribersToDraw[i]->draw();
        }
    }
    void Move(int state)
    {
        for (size_t i=0; i<SubscribersToMove.size(); i++)
        {
            SubscribersToMove[i]->move(state);
        }

    }
    
public:
    Picasso(int fldW, int nffldW, int fldH);
    Picasso(Display *dis, Window wd, int ss);

    void basicConfig();
    void renew();
    void view();

    void kill();
    void GetColorPixel();
    void brush(int clr);

    void line(int x1, int y1, int x2, int y2);
    void DrawLine(int x1, int y1, int x2, int y2, int LineClr);
    void DrawRectangle(int x, int y, int h, int wd,  int LineClr);
    void FillRectangle(int x, int y, int h, int wd, int clr);
    
    void SubscribeToDraw  (forDrawing *mem);
    void UnsubscribeToDraw(forDrawing *mem);

    void SubscribeToMove  (iKeyInstructor  *mem);
    void UnsubscribeToMove(iKeyInstructor  *mem);
    
};


#endif //X11_H