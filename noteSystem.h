#pragma once

#include "programDefaulths.h"

#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>

std::string note1File = "NOTE1.txt";
std::string note2_1File = "NOTE2_1.txt";
std::string note2_2File = "NOTE2_2.txt";

void makeNote(std::string &note, std::string noteFile)
{
    note = "";
    std::string t;
    std::fstream NOTE;
    NOTE.open(noteFile);
    while(!NOTE.eof())
    {
        std::getline(NOTE, t);
        note += t;
    }
    NOTE.close();
}

void setNoteNumber(const dT & map, dT & n)
{
    if (map == 2) { n = 0; }
    if (map == 4) { n = 1; }
}

class noteSystem
{
    private:
    std::string note;
    
    public:

    noteSystem(std::string noteFile) { makeNote(note, noteFile); } 

    std::string getNote() { return note; }

    void showNote()
    {
        clearScreenPD();
        COLOR_NOTE;
        std::cout << "              ";
        for (dT i = 0; i < note.length(); i++)
        {
            if (note[i] == '|') { std::cout << std::endl; std::cout << "              "; continue; }
            if (note[i] == '~') { getch(); continue; }
            std::cout << note[i];
        }
        std::cout << std::endl;
        getch();
        COLOR_DEFAULT;
    }

    void setNewNote(std::string newNote) { note = newNote; }

};