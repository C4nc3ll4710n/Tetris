#ifndef Figure_T_h
#define Figure_T_h


#include "figureBase.h"
#include "FigureFactory.hpp"



class Figure_T : public FigureBase {

    Figure_T();
public:
    friend class FigureFactory<Figure_T>;

    ~Figure_T() = default;

};

#endif //Figure_T_h