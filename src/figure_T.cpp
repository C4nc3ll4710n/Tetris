#include "figure_T.h"


Figure_T::Figure_T(){
    state = 0;
    clr = T;
    rotation_coords[0].push_back(std::make_pair(-1,  0));//  _ _ _
    rotation_coords[0].push_back(std::make_pair( 0,  0));// |_|0|_|
    rotation_coords[0].push_back(std::make_pair( 1,  0));//   |_|
    rotation_coords[0].push_back(std::make_pair( 0,  1));//
                                                        
    rotation_coords[1].push_back(std::make_pair( 0, -1));//  _
    rotation_coords[1].push_back(std::make_pair( 0,  0));// |_|_
    rotation_coords[1].push_back(std::make_pair( 0,  1));// |0|_|
    rotation_coords[1].push_back(std::make_pair( 1,  0));// |_|

    rotation_coords[2].push_back(std::make_pair(-1,  0));//    _   
    rotation_coords[2].push_back(std::make_pair( 0,  0));//  _|_|_
    rotation_coords[2].push_back(std::make_pair( 1,  0));// |_|0|_|
    rotation_coords[2].push_back(std::make_pair( 0, -1));//

    rotation_coords[3].push_back(std::make_pair(-1,  0));//    _
    rotation_coords[3].push_back(std::make_pair( 0, -1));//  _|_|
    rotation_coords[3].push_back(std::make_pair( 0,  0));// |_|0|
    rotation_coords[3].push_back(std::make_pair( 0,  1));//   |_|
}

