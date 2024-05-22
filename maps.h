#include "programDefaulths.h"
#include <cstdlib>
#include <cstdint>
#include <iostream>
#include <string>
#include <fstream>

std::string map1File = "MAP1.txt";
std::string map2File = "MAP2.txt";
std::string map3File = "MAP3.txt";
std::string map4File = "MAP4.txt";
std::string map5File = "MAP5.txt";
std::string map6File = "MAP6.txt";

void makeMap(std::string mapFile, std::string map[], dT &mapSizeX, dT &mapSizeY, dT &spawnX, dT &spawnY)
{
    std::string t;
    std::string mapSizeXS, mapSizeYS, spawnXS, spawnYS;
    std::fstream MAP1;//78 1011
    MAP1.open(mapFile);

    std::getline(MAP1, t);

    mapSizeYS = t[3];
    mapSizeYS += t[4];
    mapSizeXS = t[0];
    mapSizeXS += t[1];
    spawnXS = t[7];
    spawnXS += t[8];
    spawnYS = t[10];
    spawnYS += t[11];

    mapSizeX = stoi(mapSizeXS);
    mapSizeY = stoi(mapSizeYS);
    spawnX = stoi(spawnXS);
    spawnY = stoi(spawnYS);

    for (int i = 0; i <= mapSizeX; i++)
    {
        std::getline(MAP1, map[i]);
    }
    MAP1.close();
}

class MapSkelet
{

private:

    std::string MAP[maximumXSize];
    dT spawnX, spawnY, sizeX, sizeY;
        
public:

    MapSkelet(std::string map[], std::string mapFile)
    {
        makeMap(mapFile, map, sizeX, sizeY, spawnX, spawnY);
        
        for (dT i = 0; i < sizeX; i++)
        {   
            MAP[i] = map[i];
        }
    }

    void drawMap()
    {
        for (dT i = 0; i < sizeX; i++) {
        std::cout << MAP[i] << std::endl;
        }
    }

    void changeSpecificBlockOfTheMap(char block, dT x, dT y) { MAP[x][y] = block; }

    char getSpecificBlockOfTheMap(dT &x, dT &y) { return MAP[x][y]; }

    void getSpawnXY(dT &xP, dT &yP) { xP = spawnX; yP = spawnY; }

    void deleteSpecificBlockOfTheMap(char &a)
    {
        for (dT i = 0; i <= sizeX; i++)
        {
            for (dT j = 0; j <= sizeY; j++) 
            {
                if(MAP[i][j] == a)
                {
                    MAP[i][j] = ABL;
                    break;
                }
            }
        }
    }

    void setStartingPositionXY(dT & X, dT & Y)
    {
        for (dT i = 0; i <= sizeX; i++)
        {
            for (dT j = 0; j <= sizeY; j++)
            {
                if (MAP[i][j] == PLR) { X = i; Y = j; return;}
            }
        }
    }

    void setSpawnX_and_Y(dT x, dT y) { spawnX = x; spawnY = y; }

};
