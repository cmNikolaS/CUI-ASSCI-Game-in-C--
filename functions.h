#pragma once

#include "programDefaulths.h"

#include <iostream>
#include <conio.h>
#include <fstream>
#include <cstdlib>


void showCommands()
{
    std::cout << "\
    EXIT = 'q'\n\
	MOVE_UP = 'w'\n\
	MOVE_LEFT = 'a'\n\
	MOVE_DOWN = 's'\n\
	MOVE_RIGHT = 'd'\n\
    SHOW_CORDINATES = 'c'\n\
    OPEN_CLOSE_INVENTORY = 'e'\n\
    PICK_UP_ITEM = 'f'\n\
    SHOW_COMMANDS = 'h'" << std::endl;
}