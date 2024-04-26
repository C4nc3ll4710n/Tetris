#include "figure_L.h"


Figure_L::Figure_L()
{
    state = 0;
    clr = L;
    std::cout << "\033[31m"<< rotation_coords.size() << "from figure_L.cpp" << "\033[0m\n";
    rotation_coords[0].push_back(std::make_pair(-1,  1));//  _ _ _
    rotation_coords[0].push_back(std::make_pair(-1,  0));// |_|0|_|
    rotation_coords[0].push_back(std::make_pair( 0,  0));// |_|
    rotation_coords[0].push_back(std::make_pair( 1,  0));//
                                                        
    rotation_coords[1].push_back(std::make_pair( 0, -1));//  _
    rotation_coords[1].push_back(std::make_pair( 0,  0));// |_|
    rotation_coords[1].push_back(std::make_pair( 0,  1));// |0|_
    rotation_coords[1].push_back(std::make_pair( 1,  1));// |_|_|

    rotation_coords[2].push_back(std::make_pair(-1,  0));//      _
    rotation_coords[2].push_back(std::make_pair( 0,  0));//  _ _|_|
    rotation_coords[2].push_back(std::make_pair( 1,  0));// |_|0|_|
    rotation_coords[2].push_back(std::make_pair( 1, -1));//

    rotation_coords[3].push_back(std::make_pair(-1, -1));//  _ _
    rotation_coords[3].push_back(std::make_pair( 0, -1));// |_|_|
    rotation_coords[3].push_back(std::make_pair( 0,  0));//   |0|
    rotation_coords[3].push_back(std::make_pair( 0,  1));//   |_|
}


