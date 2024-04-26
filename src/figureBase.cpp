#include "figureBase.h"

int FigureBase::getColor(){
    return clr;
}

void FigureBase::rotate (int steps){
    //!unfinished?
    state=(state+steps)%4;
}

//std::vector<std::pair<int, int>>
void FigureBase::getCoords(int cx, int cy, std::vector<std::pair<int, int>> &field_relat_coords){
    if (rotation_coords.size()==4)
    {
        if (rotation_coords[state].size()==4)
        {
            for (int i = 0; i<4; i++)
                field_relat_coords.push_back(std::make_pair(
                                            rotation_coords[state][i].first+cx,
                                            rotation_coords[state][i].second+cy));

        }
    }

}

void FigureBase::getrotateCoords(int cx, int cy, std::vector<std::pair<int, int>> &field_relat_coords){
    std::cout << "\033[31m from get Coords3 "<< rotation_coords.size()<<" \033[0m\n";
    if (rotation_coords.size()==4)
    {
        std::cout << "\033[31m from get Coords4 "<< rotation_coords[0].size() << " " << state <<" \033[0m\n";
        int rotate_state = (state+1)%4;
        if (rotation_coords[rotate_state].size()==4)
        {
            for (int i = 0; i<4; i++)
                field_relat_coords.push_back(std::make_pair(
                                            rotation_coords[rotate_state][i].first+cx,
                                            rotation_coords[rotate_state][i].second+cy));

        }
    }

}


FigureBase::~FigureBase(){}








