#include "forDrawing.h"
#include "field.h"
#include "global.h"
#include "X11.h"
#include "FieldPredictor.h"


int main(){
    int fldH = 800, fldW = 400, nffldH = 160;

    //Field, figures, etc.
    
    Picasso pcs(fldW, nffldH, fldH);
    RandomFigureFactory Factory;
    Field field(pcs, Factory);
    
    FieldPredictor nextFigField(pcs, Factory);

    pcs.basicConfig();

    pcs.renew();

    while (1) {
        pcs.view();
    }
    
    pcs.kill();



    return 0;
}