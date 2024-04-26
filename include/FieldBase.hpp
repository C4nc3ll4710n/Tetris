#ifndef FieldBase_h
#define FieldBase_h

#include "X11.h"
#include "forDrawing.h"
#include "iKeyInstructor.h"
#include "iPassFigure.h"
#include "figureBase.h"
#include "RandomFigureFactory.h"



template <size_t H, size_t W>
class FieldBase : public forDrawing, public iKeyInstructor, public iPassFigure
{
protected:
    int fldX, fldY, fldH, fldW;
    int anchorx, anchory;                          // якорные координаты
    int temp = 1;
    std::pair<std::shared_ptr<FigureBase>, std::shared_ptr<FigureBase>> figure;
    std::vector< std::vector<int> > figures;       // массив цветов
    Picasso& manager;
    RandomFigureFactory& RFFact;

public:

    //Constructors
    FieldBase(Picasso& P, RandomFigureFactory& Fact)
        : fldX(0), fldY(0), fldH(40*H), fldW(40*W), anchorx(0), anchory(0), figures(H, std::vector<int>(W, 0)), manager(P), RFFact(Fact)
        { 
            manager.SubscribeToDraw  (this); 
            RFFact.SubscribeToGiveFig(this);
            RFFact.giveFig();
            RFFact.giveFig();
        }

    void givemefigure(std::shared_ptr<FigureBase> someFig) override
    {
        if(temp==1)
        {
            figure.first = someFig;
            figure.second = nullptr;
            temp+=1;
        }
        else if (temp==2)
        {
            figure.second = someFig;
            temp = 0;
        }
        else
        {
            figure.first = figure.second;
            figure.second = someFig;
        }
        
    }
    


    void addFig(int figX, int figY, int clr)
    {
        std::cout << figures.size() << "\n";
        if (figures.size()!=0)
        {
            if (figures[figY].size()!=0)
                figures[figY][figX]=clr;
        }
    }    
    
    //Draw
    void draw() override 
    {
        DrawField();
        DrawStaticFigures();
        DrawDynamicFigure(anchorx, anchory);
    }
    
    void DrawField()
    {
        manager.FillRectangle(fldX, fldY, fldH, fldW, 0x000000);
        manager.DrawRectangle(fldX, fldY, fldH, fldW, O);
        for (int i=40; i<fldW; i+=40)
            manager.DrawLine(i, 0, i, fldH, 0x545454);
        for (int i=40; i<fldH; i+=40)
            manager.DrawLine(0, i, fldW, i, 0x545454);
    }
    void DrawStaticFigures()
    {
        for (size_t i = 0; i<figures.size(); i++)
        {
            for (size_t j=0; j<figures[i].size(); j++)
            {
                std::cout << figures[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";

        for (size_t i = 0; i<figures.size(); i++)
        {
            for (size_t j=0; j<figures[i].size(); j++)
            {
                if (figures[i][j]!=0)
                {
                    std::cout << "Drawing figures...." << j << " " << i << " " << figures.size()<< "\n";
                    manager.FillRectangle(40*j, 40*i, 40, 40, figures[i][j]);
                    manager.DrawRectangle(40*j, 40*i, 40, 40, 0xCACACA);
                    manager.DrawLine(40*j+24, 40*i+4, 40*j+36, 40*i+4, 0xCACACA);
                    manager.DrawLine(40*j+36, 40*i+4, 40*j+36, 40*i+24, 0xCACACA);
                }

            }
        }
    }

    //! больше не ядерная, не делай это virtual будет какой-то треш...
    virtual void DrawDynamicFigure(int x, int y) = 0;

    //Move
    void move(int action_id) override 
    {
        if (action_id ==111) //^ ROTATION!
        {
            if (checkCollision(111))
                figure.first->rotate(1);

        }
        if (action_id ==113) //<
        {
            if (checkCollision(113))
                anchorx-=1;

        }
        if (action_id ==114) //>
        {
            if (checkCollision(114))
                anchorx+=1;

        }
        if (action_id ==116) //v
        {   
            if (checkCollision(116))
            {
                anchory+=1;
            }

        }

    }

    bool checkCollision(int action_id)
    {
        std::vector<std::pair<int, int>> coords;
        figure.first->getCoords(anchorx, anchory, coords);
        if (action_id ==111) //^
        {
            
            for (int i=coords.size(); i>0; i--)
                coords.pop_back();
            figure.first->getrotateCoords(anchorx, anchory, coords);
            for ( auto i : coords)
            {
                if ((i.second>=0 && i.second<20) && (i.first>=0 && i.first<10))
                {
                    if (figures[i.second][i.first]!=0)
                        return 0;
                }
                else
                    return 0;
                
            }
            return 1;
        }
        if (action_id ==113) //<
        {
            for ( auto i : coords)
            {
                if (i.first>=1)
                {
                    if (figures[i.second][i.first-1]!=0)
                        return 0;
                }
                if(i.first==0)
                    return 0;
            }
            return 1;

        }
        if (action_id ==114) //>
        {
            for ( auto i : coords)
            {
                if (i.first<=8)
                {
                    if (figures[i.second][i.first+1]!=0)
                        return 0;
                }
                if(i.first==9)
                    return 0;
            }
            return 1;

        }
        if (action_id ==116) //v
        {
            for ( auto i : coords)
            {
                if (i.second<=18)
                {
                    if (figures[i.second+1][i.first]!=0)
                    {
                        killFigure();
                        return 0;
                    }
                        
                }
                if(i.second==19)
                {
                    killFigure();
                    return 0;
                }
                    
            }
            return 1;

        }
        return 0;

    }


    void killFigure(){
        std::vector<std::pair<int, int>> kcoords;
        figure.first->getCoords(anchorx, anchory, kcoords);
        for (auto i : kcoords)
            figures[i.second][i.first] = figure.first->getColor();
        RFFact.giveFig();
        anchorx = 5;
        anchory = 1;
        int is_row_full = 0;
        for (size_t i=0; i < figures.size(); i++)
        {
            is_row_full = 1;
            for (size_t j=0; j < figures[i].size(); j++)
            {
                if (figures[i][j]==0) is_row_full = 0;
            }
            if (is_row_full == 1)
                massacre(i);
        }
    }


    void massacre(int i)
    {
        if (i>=0 && i<20)
        {
            for (size_t j = i-1; j > 0; j--)
            {
                
                for (size_t k = 0; k < 10; k++)
                {
                    std::cout << "\033[32m coords:" << j << " " << k << "\033[0m\n";
                    figures[j+1][k] = figures[j][k];
                }
                    
            }
                
        }
        else
            exit(1);

    }

    //Destructor
    ~FieldBase(){manager.UnsubscribeToDraw(this); }

};

#endif //FieldBase_h