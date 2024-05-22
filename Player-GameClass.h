#pragma once

#include "inventorySystem.h"
#include "MoveSystem.h"
#include "programDefaulths.h"

#include <string>

class Player_GameClass final: private MoveSystem, InventorySystem
{
    private:
    bool is_GameOver = false;
    std::string PlayersName = "You";
    std::string event = "EMPTY";

    public:

    Player_GameClass(std::string pName = "You") : PlayersName(pName), MoveSystem(is_GameOver), InventorySystem()
    {
    }

    void pickUpItem()
    {
        char itemToPick;
        if (MoveSystem::lookForPickableItems(itemToPick))
        {
            MoveSystem::pickUpItem(itemToPick);
            InventorySystem::addElement(itemToPick);
            if(itemToPick == KEY) { MoveSystem::unlockNextDoor(); }
            if (itemToPick == DMD) { MoveSystem::changeNote(1, noteToChange); }
        }
    }

    void checkEvent()
    {
        if (event == giveDmdTakeKey) { deleteElement(DMD); unlockNextDoor(); addElement(KEY); }
        event = "EMPTY";
    }

    void drawMap() { MoveSystem::drawMap(); }
    bool lookForPickableItems() { char temp; return MoveSystem::lookForPickableItems(temp); }
    void showCordinates() { MoveSystem::showCordinates(); }
    void showInventory() { InventorySystem::showInventory(); }

    void moveUp() { MoveSystem::moveUp(event, is_GameOver); checkEvent(); }
    void moveDown() { MoveSystem::moveDown(event, is_GameOver); checkEvent(); }
    void moveLeft() { MoveSystem::moveLeft(event, is_GameOver); checkEvent(); }
    void moveRight() { MoveSystem::moveRight(event, is_GameOver); checkEvent(); }

    void unlockAllDoors() { for (dT i = 0; i < NUMBEROFMAPS - 2; i++) { MoveSystem::unlockNextDoor(); } }

    bool isGameOver() { return is_GameOver; }

};

