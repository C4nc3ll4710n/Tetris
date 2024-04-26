#ifndef FigureBase_h
#define FigureBase_h

#include "X11.h"
#include "forDrawing.h"
#include <utility>
#include <vector>

constexpr unsigned int I = 0x00ffff; //
constexpr unsigned int O = 0xffff00;
constexpr unsigned int T = 0x800080;
constexpr unsigned int S = 0x00ff00;
constexpr unsigned int Z = 0xff0000;
constexpr unsigned int J = 0x0000ff;
constexpr unsigned int L = 0xff7f00;


class FigureBase{
protected:
    std::vector<std::vector<std::pair<int, int>>> rotation_coords{4};
    int clr;
    int state; 
    
public:

    //Methods
    int getColor();
    void rotate (int steps);

    //virtual std::vector<std::pair<int, int>> 
    void getCoords(int cx, int cy, std::vector<std::pair<int, int>> &coords);
    void getrotateCoords(int cx, int cy, std::vector<std::pair<int, int>> &coords);
    

    //Destructor
    ~FigureBase();
};

#endif //FigureBase_h