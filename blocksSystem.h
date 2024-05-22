#pragma once

#include "programDefaulths.h"
#include <string>

class blocksSystem
{
    private:

    char BLOCK;
    bool IsItPassable = false;
    bool isItPickable = false;    
    
    public:

    blocksSystem(char block, bool isItPass = false, bool isItPick = false)
    {
        BLOCK = block;
        IsItPassable = isItPass;
        isItPickable = isItPick;
    }
    

    //getters..............................
    bool isBlockPassableThrough() { return IsItPassable; }
    bool isBlock(char character) { if (character == BLOCK) { return true; } return false; }
    bool isBlockDoor() { if (IsItPassable == true && isalnum(BLOCK)) { return true; } return false; }
    bool isBlockPickable() {return isItPickable; }
    char getBlock() { return BLOCK; }

    //setters
    void setIsPassableThrough(bool newIsPassTh) { IsItPassable = newIsPassTh; }

};
