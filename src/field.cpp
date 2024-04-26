#include "field.h"

Field::Field (Picasso& P, RandomFigureFactory& Fact)
        : FieldBase(P, Fact)
        {
                manager.SubscribeToMove  (this); 
                anchorx = 5;
                anchory = 1;
                
        };

void Field::DrawDynamicFigure(int x, int y) 
{
        std::vector<std::pair<int, int>> coords;
        figure.first->getCoords(anchorx, anchory, coords);

        for (int i=0; i<4; i++){
            manager.FillRectangle(40*coords[i].first, 40*coords[i].second, 40, 40, figure.first->getColor());
            manager.DrawRectangle(40*coords[i].first, 40*coords[i].second, 40, 40, 0xCACACA);
            manager.DrawLine(40*coords[i].first+24, 40*coords[i].second+4, 40*coords[i].first+36, 40*coords[i].second+4, 0xCACACA);
            manager.DrawLine(40*coords[i].first+36, 40*coords[i].second+4, 40*coords[i].first+36, 40*coords[i].second+24, 0xCACACA);
        }
}


Field::~Field(){}