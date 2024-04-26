#include "figure_J.h"


Figure_J::Figure_J(){
    state = 0;
    clr = J;
    rotation_coords[0].push_back(std::make_pair(-1,  0));//  _ _ _
    rotation_coords[0].push_back(std::make_pair( 0,  0));// |_|0|_|
    rotation_coords[0].push_back(std::make_pair( 1,  0));//     |_|
    rotation_coords[0].push_back(std::make_pair( 1,  1));//
                                                        
    rotation_coords[1].push_back(std::make_pair( 1, -1));//  _ _
    rotation_coords[1].push_back(std::make_pair( 0, -1));// |_|_|
    rotation_coords[1].push_back(std::make_pair( 0,  0));// |0|
    rotation_coords[1].push_back(std::make_pair( 0,  1));// |_|

    rotation_coords[2].push_back(std::make_pair(-1, -1));//  _    
    rotation_coords[2].push_back(std::make_pair(-1,  0));// |_|_ _
    rotation_coords[2].push_back(std::make_pair( 0,  0));// |_|0|_|
    rotation_coords[2].push_back(std::make_pair( 1,  0));//

    rotation_coords[3].push_back(std::make_pair( 0, -1));//    _
    rotation_coords[3].push_back(std::make_pair( 0,  0));//   |_|
    rotation_coords[3].push_back(std::make_pair( 0,  1));//  _|0|
    rotation_coords[3].push_back(std::make_pair(-1,  1));// |_|_|
}


