#include "RandomFigureFactory.h"


RandomFigureFactory::RandomFigureFactory()
    {
        std::random_device rd;  
        std::mt19937 gen(rd()); 
        std::uniform_int_distribution<> distrib(1, 6);
        factories.push_back(std::unique_ptr<iFigureFactory> (new FigureFactory<Figure_L>()));
        factories.push_back(std::unique_ptr<iFigureFactory> (new FigureFactory<Figure_T>()));
        factories.push_back(std::unique_ptr<iFigureFactory> (new FigureFactory<Figure_J>()));
    }

void RandomFigureFactory::changeType()
{
    type = distrib(gen)%3;
}


void RandomFigureFactory::giveFig()
{
    GiveFig(factories[type]->createFigure());
    changeType();
}

void RandomFigureFactory::giveFigPred()
{
    GiveFig(factories[(type+2)%3]->createFigure());
}


void RandomFigureFactory::SubscribeToGiveFig (iPassFigure  *mem)
{
    SubscribersToGiveFig.push_back(mem);
    std::cout << "\033[31m PUSHED BACK" << mem  <<" \033[0m\n";
}

void RandomFigureFactory::UnsubscribeGiveFig (iPassFigure  *mem)
{
}


