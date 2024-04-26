#ifndef Figure_J_h
#define Figure_J_h


#include "figureBase.h"
#include "FigureFactory.hpp"


class Figure_J : public FigureBase {
    Figure_J();

public:
    friend class FigureFactory<Figure_J>;

    ~Figure_J() = default;

};

#endif //Figure_J_h