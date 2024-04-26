#ifndef RANDFIGFACT_H
#define RANDFIGFACT_H

#include "figure_L.h"
#include "figure_J.h"
#include "figure_T.h"
#include "FigureFactory.hpp"
#include "iPassFigure.h"
#include <cassert>
#include <random>

class RandomFigureFactory{


    std::vector<iPassFigure *> SubscribersToGiveFig;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<> distrib;

    void GiveFig(std::shared_ptr<FigureBase> someFigure)
    {
        for (size_t i=0; i<SubscribersToGiveFig.size(); i++)
            SubscribersToGiveFig[i]->givemefigure(someFigure);
    }

public:
    std::vector<std::unique_ptr<iFigureFactory>> factories;
    int type = 0;
   
    RandomFigureFactory();

    void changeType();
    void giveFig();
    void giveFigPred();

    void SubscribeToGiveFig (iPassFigure  *mem);
    void UnsubscribeGiveFig (iPassFigure  *mem);
    
};

#endif // RANDFIGFACT_H