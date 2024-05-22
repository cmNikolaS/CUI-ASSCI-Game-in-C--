#include <iostream>
#include <cctype>
#include <conio.h>
#include <memory>
#include "Player-GameClass.h"
#include "functions.h"
#include "programDefaulths.h"
#include <string>
#include <chrono>
#include <fstream>

using namespace std::chrono;

void endScreen(char &input, long &najbolje_vrjeme);
void writeBestTimeToFile(const std::string& filename, long bestTime);
long readBestTimeFromFile(const std::string& filename);


int main()
{

    COLOR_DEFAULT;

	std::string saveFile = "bestTime.txt";
    bool showCords, inventory, showComm;
    char input;
	long bestTime = readBestTimeFromFile(saveFile);
	long currentTime = 0;

    do
    {
		showComm = false, showCords = inventory = true;
		currentTime = 0;

        std::unique_ptr < Player_GameClass > Player = std::make_unique < Player_GameClass > ();
        auto start = high_resolution_clock::now();

        while (Player -> isGameOver() == false)
        {
            Player -> drawMap();

            if (Player -> lookForPickableItems()) {std::cout << "Press 'f' to pick up" << std::endl;}
            if (showCords) { Player -> showCordinates(); }
            if (inventory) { Player -> showInventory(); }
            if (showComm) { showCommands(); } 
        
            do { input = getch(); input = tolower(input); } while( isCommand(input) == false );
            
            switch (input) 
            {   
                case EXIT: { return 0; break; }

                case MOVE_UP: { Player -> moveUp(); break; }
                case MOVE_DOWN: { Player -> moveDown(); break; }
                case MOVE_RIGHT: { Player -> moveRight(); break; }
                case MOVE_LEFT: { Player -> moveLeft(); break; }

                case SHOW_COMMANDS: { if (showComm == false) showComm = true; else showComm = false; break; }
                case SHOW_CORDINATES: { if (showCords == false) showCords = true; else showCords = false; break; }
                case OPEN_CLOSE_INVENTORY: { if (inventory == false) inventory = true; else inventory = false; break; }
                case UNLOCK_ALL_DOORS: { Player -> unlockAllDoors(); break; }
                case PICK_UP_ITEM: { Player -> pickUpItem(); break; }
            }
            clearScreenPD();
        }

		auto stop = high_resolution_clock::now();
        auto duration = duration_cast<seconds>(stop - start);
		currentTime = duration.count();

			if (currentTime < bestTime) 
			{ 
            	bestTime = currentTime;
            	writeBestTimeToFile(saveFile, bestTime); 
        	}

        endScreen(input, bestTime);

    } while (input == '1');

    getch();

    return 0;
}

void endScreen(char &input, long &najbolje_vrjeme)
{   
    std::cout << "Najbolje Vrjeme: " << najbolje_vrjeme/60 << ":"<< najbolje_vrjeme%60 << std::endl;
    std::cout << "1-Igraj Ponovo!" << std::endl;
	std::cout << "0-Izadji" << std::endl;
    do
    { 
	    input = getch();
        if (input == '0') { exit(0); } 
    } while(input != '1');
    clearScreenPD();
}

long readBestTimeFromFile(const std::string& filename) {
    std::ifstream file(filename);
    long time = 0;
    if (file.is_open()) {
        file >> time;
        file.close();
    }
    return time;
}

void writeBestTimeToFile(const std::string& filename, long bestTime) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << bestTime;
        file.close();
    }
}