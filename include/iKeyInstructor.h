#ifndef Movable_h
#define Movable_h


#include "global.h"

struct iKeyInstructor
{
    virtual void move(int state) = 0;
};

#endif //Movable_h