#pragma once

#include <string>
#include <cstdint>
#include <cstdlib>

typedef uint16_t dT;

const std::string giveDmdTakeKey = "giveDmdTakeKey";

static const dT maximumXSize = 25;
const dT maximumYSize = 35;
const dT NUMBEROFMAPS = 6;
const dT NUMBEROFBLOCKS = 12;
const dT NUMBEROFNOTES = 2;
const dT bossMAP = 5;

const char EXIT_DOOR = 'E';
const char SWORD = 'S';
const char DMD = 'D';
const char PLR = 'P';
const char note = 'n';
const char KEY = 'k';
const char ABL = ' ';
const char WALL = '#';
const char TRADERS_STAND = '|';
const char BOSSChar = 'B';


enum commands
{
    EXIT = 'q',
    MOVE_UP = 'w',
    MOVE_DOWN = 's',
    MOVE_RIGHT = 'd',
    MOVE_LEFT = 'a',
    SHOW_CORDINATES = 'c',
    OPEN_CLOSE_INVENTORY = 'e',
    PICK_UP_ITEM = 'f',
    SHOW_COMMANDS = 'h',
    UNLOCK_ALL_DOORS = 'u'
};

char COMMANDSARR[10]{EXIT, MOVE_UP, MOVE_DOWN, MOVE_RIGHT, MOVE_LEFT, SHOW_CORDINATES,
OPEN_CLOSE_INVENTORY, PICK_UP_ITEM, SHOW_COMMANDS, UNLOCK_ALL_DOORS};

bool isCommand(char cm)
{
    for (dT i = 0; i < 10; i++)
    {
        if (cm == COMMANDSARR[i]) { return true; }
    }
    return false;
}

void clearScreenPD()
{
    system ("cls");
}

#define COLOR_DEFAULT system("Color 07")
#define COLOR_NOTE system("Color 1E")

