#ifndef Figuregivable_h
#define Figuregivable_h

#include "global.h"
#include <memory>
#include "figureBase.h"

struct iPassFigure
{
    virtual void givemefigure(std::shared_ptr<FigureBase> someFig) = 0;  
};
#endif //Figuregivable_h