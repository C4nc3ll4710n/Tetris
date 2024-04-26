#ifndef FIGURE_FACT_HPP
#define FIGURE_FACT_HPP

#include <memory>
#include "iFigureFactory.h"



template <typename FigureT>
class FigureFactory : public iFigureFactory{

public:

std::shared_ptr<FigureBase> createFigure() override 
{
    return std::shared_ptr<FigureBase>(new FigureT());
}

};

#endif //FIGURE_FACT_HPP