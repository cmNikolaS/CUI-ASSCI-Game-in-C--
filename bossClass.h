#pragma once

#include "programDefaulths.h"
#include <algorithm>
#include <cmath>

class Boss//odustao od ovoga
{
    private:
    dT MAPSIZEX, MAPSIZEY;
    dT HP;
    dT new_X, new_Y, X, Y;
    // protected:
    public:
    //char bossMap[][VELICINAMAPE], dT mapSizeX, dT mapSizeY, dT Bossx, dT Bossy
    Boss()
    {
        X = 2;
        Y = 4;
        new_X = X;
        new_Y = Y;
    }

    void makeBoss(dT mSX, dT mSY)
    {
        MAPSIZEX = mSX; MAPSIZEY = mSY;
    }

    void findClosestRouteToPlayer(MapSkelet *map, dT & playerX, dT & playerY)
    {
        dT nX = X, nY = Y;
        if (X < playerX)
        {
            nX = X++;
        }
        else if (X > playerX)
        {
            nX = X--;
        }
        else{ 
        if (Y < playerY)
        {
            nY = Y++;
            return;
        }
        else if (Y > playerY)
        {
            nY = Y--;
            return;
        } }

        if (map->getSpecificBlockOfTheMap(nX, nY) == WALL)
        {
            playerX = X;
            playerY = Y;
            return;
            // if (nY == Y)
            // {
            //     nY++;
            // }
            // if (nX == X)
            // {
            //     nX++;
            // }
        }
        playerX = nX; playerY = nY;
                map->changeSpecificBlockOfTheMap(BOSSChar, X, Y);    

    }

    void locatePlayer(MapSkelet * map, dT &x, dT &y)
    {
        for (dT i = 0; i < MAPSIZEX; i++)
        {
            for (dT j = 0; j < MAPSIZEY; j++)
            {
                if (map->getSpecificBlockOfTheMap(i, j) == PLR) { x = i; y = j; return; }
                // std::cout << map->getSpecificBlockOfTheMap(i, j);
            }
            // std::cout << std::endl;
        }
        // std::cout << "NEMA";
    }



    void updateBoss(MapSkelet*map)
    {
        map->changeSpecificBlockOfTheMap(ABL, X, Y);    
        locatePlayer(map, new_X, new_Y);
        findClosestRouteToPlayer(map, new_X, new_Y);

    }




};