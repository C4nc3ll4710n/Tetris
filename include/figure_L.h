#ifndef Figure_L_h
#define Figure_L_h


#include "figureBase.h"
#include "FigureFactory.hpp"


class Figure_L : public FigureBase {
    Figure_L();

public:
    friend class FigureFactory<Figure_L>;

    ~Figure_L() = default;

};

#endif //Figure_L_h