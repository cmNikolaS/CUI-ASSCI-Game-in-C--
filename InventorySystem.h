#pragma once

#include "programDefaulths.h"

#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <string>

class InventorySystem
{
    private:
    bool isAnyKeysPicked;
    bool isAnySpecialItemsPicked;
    dT numberOfKeys;
    dT currentElementNumber;

    static const dT numberOfElements = 5;
    char INVENTORY[numberOfElements];

    public:    

    InventorySystem() : currentElementNumber(0), numberOfKeys(0), 
    isAnyKeysPicked(false), isAnySpecialItemsPicked(false) {}

    protected:
    
    void showInventory()
    {
        if ((!isAnyKeysPicked) && (!isAnySpecialItemsPicked)) { std::cout << "Inventory Is Empty" << std::endl; return; }  

        if (isAnySpecialItemsPicked)
        {
            std::cout << "Special Items: ";
            for (int i = 0; i < currentElementNumber; i++)
            {
                std::cout << INVENTORY[i];
                if (i != currentElementNumber - 1) { std::cout << ", "; }
            }
            std::cout << std::endl;
        }
        if (isAnyKeysPicked)
        {
            std::cout << "Keys for rooms: ";
            for (int i = 0; i < numberOfKeys; i++)
            {
                std::cout << i + 3;
                if (i != numberOfKeys - 1) { std::cout << ", "; }
            }
            std::cout << std::endl;
        }
    }

    dT getNumberOfElements() { return (currentElementNumber + numberOfKeys); }

    void addElement(char elementToAdd)
    {
        if (elementToAdd == KEY) { numberOfKeys++; isAnyKeysPicked = true; return; }
        INVENTORY[currentElementNumber] = elementToAdd;
        currentElementNumber++;
        isAnySpecialItemsPicked = true;
    }

   void deleteElement(char elementToDelete)
{
    bool isFound = false;
    for (dT i = 0; i < currentElementNumber; i++)
    {
        if (INVENTORY[i] == elementToDelete)
        {
            isFound = true;
            for (dT j = i; j < currentElementNumber - 1; j++)
            {
                INVENTORY[j] = INVENTORY[j + 1];
            }
            currentElementNumber--;
            break;
        }
    }

    if (isFound)
    {
        isAnySpecialItemsPicked = (currentElementNumber > 0);
    }
}


};