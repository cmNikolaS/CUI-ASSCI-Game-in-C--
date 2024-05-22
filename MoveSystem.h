#pragma once
#include <iostream>
#include <string>
#include <memory>
#include "blocksSystem.h"
#include "maps.h"
#include "InventorySystem.h"
#include "noteSystem.h"

std::string noteToChange;

class MoveSystem
{

private:

    MapSkelet* maps[NUMBEROFMAPS];
    blocksSystem* blocks[NUMBEROFBLOCKS];
    noteSystem* notes[NUMBEROFNOTES];
    dT nextDoorToUnlock = 3;
    dT X_position;
    dT Y_position;
    dT newX;
    dT newY;
    dT crrMap;
    dT crrBlock;
    dT crrNote;
    bool isKeyGiven = false;


    void MOVE(dT UP, dT DOWN, dT RIGHT, dT LEFT, std::string & event, bool & isGameOver) 
    {
        newX = X_position - UP + DOWN;
        newY = Y_position - LEFT + RIGHT;
        crrBlock = 0;
        if (maps[crrMap] -> getSpecificBlockOfTheMap(newX, newY) == note 
        || maps[crrMap] -> getSpecificBlockOfTheMap(newX, newY) == TRADERS_STAND)
        {
            notes[crrNote] -> showNote();
            if (crrMap == 4) 
            {
                 maps[3]->changeSpecificBlockOfTheMap(ABL, 17, 5);
                 if ((notes[crrNote]->getNote()) == (noteToChange)) 
                {  
                      if(isKeyGiven == false) { event = giveDmdTakeKey; isKeyGiven = true; } 
                    else { notes[crrNote]->setNewNote("Vec Imate Kljuc!"); } 
                }
            }
            return; 
        }
        if (maps[crrMap] -> getSpecificBlockOfTheMap(newX, newY) == EXIT_DOOR)
        {
            isGameOver = true;
            return;
        }
        while (crrBlock < NUMBEROFBLOCKS) 
        {
            if (blocks[crrBlock]->getBlock() == maps[crrMap]->getSpecificBlockOfTheMap(newX, newY))
            {
                if (blocks[crrBlock]->isBlockDoor()) { changeMaps(); }

                else if ((blocks[crrBlock]->isBlockPassableThrough()))
                {
                    maps[crrMap]->changeSpecificBlockOfTheMap(ABL, X_position, Y_position);
                    X_position = newX;
                    Y_position = newY;
                    maps[crrMap]->changeSpecificBlockOfTheMap(PLR, X_position, Y_position);
                }
                break;
            }
            else { crrBlock++; }
        }
    }

public:

    MoveSystem(bool & isGameOver)
    {
        crrBlock = crrMap = 0;

        //MAPEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
        std::string map1[25];
        maps[0] = new MapSkelet(map1, map1File);

        std::string map2[7];
        maps[1] = new MapSkelet(map2, map2File);

        std::string map3[11];
        maps[2] = new MapSkelet(map3, map3File);

        std::string map4[20];
        maps[3] = new MapSkelet(map4, map4File);

        std::string map5[10];
        maps[4] = new MapSkelet(map5, map5File);
            
        std::string map6[24];
        maps[5] = new MapSkelet(map6, map6File);

        //blokoviiiiiiiiiiiiiiiiiiiiiiiiiiiiiii  
             
        blocks[0] = new blocksSystem(' ', true, false);

        blocks[1] = new blocksSystem('1', true, false);
        blocks[2] = new blocksSystem('2', true, false);
        blocks[3] = new blocksSystem('3', false, false);
        blocks[4] = new blocksSystem('4', false, false);
        blocks[5] = new blocksSystem('5', false, false);
        blocks[6] = new blocksSystem('6', false, false);
        blocks[7] = new blocksSystem('7', false, false);

        blocks[8] = new blocksSystem(WALL, false, false);
        blocks[9] = new blocksSystem(KEY, false, true);
        
        blocks[10] = new blocksSystem('|', false, false);
        blocks[11] = new blocksSystem(note, false, false);

        notes[0] = new noteSystem (note1File);
        notes[1] = new noteSystem (note2_1File);

        makeNote(noteToChange, note2_2File);

        maps[0] -> setStartingPositionXY(X_position, Y_position);

    }

    void changeNote(dT n, std::string note_to_set) { notes[n]->setNewNote(note_to_set); }

    ~MoveSystem() 
    {
        for (dT i = 0; i < NUMBEROFMAPS; i++) { delete maps[i]; }
        for (dT i = 0; i < NUMBEROFNOTES; i++) { delete notes[i]; }
        for (dT i = 0; i < NUMBEROFBLOCKS; i++) { delete blocks[i]; }
    }

    void moveUp( std::string &ev, bool &isGameOver) { MOVE(1, 0, 0, 0, ev, isGameOver); }
    void moveDown( std::string &ev, bool &isGameOver) { MOVE(0, 1, 0, 0, ev, isGameOver); }
    void moveRight( std::string &ev, bool &isGameOver) { MOVE(0, 0, 1, 0, ev, isGameOver); }
    void moveLeft( std::string &ev, bool &isGameOver) { MOVE(0, 0, 0, 1, ev, isGameOver); }

    void drawMap() { maps[crrMap]->drawMap(); }

    void changeMaps()
    {
        maps[crrMap]->setSpawnX_and_Y(X_position, Y_position);
        maps[crrMap]->changeSpecificBlockOfTheMap(ABL, X_position, Y_position);
        crrMap = dT(blocks[crrBlock]->getBlock()) - 48 - 1;
        maps[crrMap] -> getSpawnXY(X_position, Y_position);
        maps[crrMap]->changeSpecificBlockOfTheMap(PLR, X_position, Y_position);
        
        setNoteNumber(crrMap, crrNote);
    }

    bool lookForPickableItems(char & itemToPick)
    {
    for (int dx = -1; dx <= 1; ++dx)
    {
        for (int dy = -1; dy <= 1; ++dy)
        {
            if (dx == 0 && dy == 0) 
                continue;
            
            newX = X_position + dx;
            newY = Y_position + dy;

            if (maps[crrMap]->getSpecificBlockOfTheMap(newX, newY) == KEY) { itemToPick = KEY; return true; }
            if (maps[crrMap]->getSpecificBlockOfTheMap(newX, newY) == DMD) { itemToPick = DMD; return true; }
            //tacno da imam jos jedan item stavio bi loop
        }
    }
    
    return false;
}


    void pickUpItem(char & itemToPick) 
    {

    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) 
                continue;
            
            newX = X_position + dx;
            newY = Y_position + dy;

            if (maps[crrMap]->getSpecificBlockOfTheMap(newX, newY) == itemToPick) {
                maps[crrMap]->changeSpecificBlockOfTheMap(ABL, newX, newY);
                break;
            }
        }
    }

    }
    
    void unlockNextDoor()
    {
        blocks[nextDoorToUnlock]->setIsPassableThrough(true);
        nextDoorToUnlock++;
    }

    void showCordinates()
    {
        std::cout << "-Map: " << crrMap + 1 << std::endl;
        std::cout << "-Position: " << X_position << "   " << Y_position << std::endl;
    }

    std::string getNextMapSTR() {return std::to_string(crrMap + 2);}

    void deleteMapItem(char block = KEY) { maps[crrMap] -> deleteSpecificBlockOfTheMap(block); }

};
