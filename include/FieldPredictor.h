#ifndef FieldPred_h
#define FieldPred_h

#include "X11.h"
#include "forDrawing.h"
#include "figureBase.h"
#include "FieldBase.hpp"

class FieldPredictor : public FieldBase<4, 4>{
    
public:
    // Constructors
    FieldPredictor (Picasso& P, RandomFigureFactory& Fact);

    //Draw
    void draw() override
    {
        FieldBase::draw();
    }; 

    
    void DrawDynamicFigure(int x, int y) override;

    //Destructor
    ~FieldPredictor();
};

#endif //FieldPred_h