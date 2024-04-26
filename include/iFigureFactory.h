#ifndef iFigureFactory_h
#define iFigureFactory_h

#include <memory>

#include "figureBase.h"

class iFigureFactory {

public:
    virtual std::shared_ptr<FigureBase> createFigure() = 0;

    virtual ~iFigureFactory() = default;
};

#endif //iFigureFactory_h

