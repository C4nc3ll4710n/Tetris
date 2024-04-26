#ifndef Field_h
#define Field_h

#include "X11.h"
#include "forDrawing.h"
#include "figureBase.h"
#include "FieldBase.hpp"

class Field : public FieldBase<20, 10>{
    
public:
    // Constructors
    Field (Picasso& P, RandomFigureFactory& Fact);

    //Draw
    void draw() override
    {
        FieldBase::draw();
    }; 
    void DrawDynamicFigure(int x, int y) override;

    //Destructor
    ~Field();
};

#endif