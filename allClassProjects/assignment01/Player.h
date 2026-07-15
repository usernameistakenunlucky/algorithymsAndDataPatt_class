#pragma once
#include <iostream>
#include "Array.h"
#include "Vector.h"

/*
1) Create an enum called Stats
    a. Stats should be Health, Attack, Defense, Stamina, Speed
*/
enum class Stats
{
    Health = 0,
    Attack, 
    Defense, 
    Stamina, 
    Speed
};

/*
2) Create a class Player
    a. Player should have a name (std::string is fine)
    b. Player should have an int Array that contains all of the stats in the enum
    c. There should be a function to Initialize the player with default values
        i. Health = 100
        ii. The rest of the stats are random from 1-5
    d. There should be a function to get the stat value for a specific stat using the
       enum as the index value
*/
class Player
{
private:
    std::string _name;
    Array<int, 5> _stats;

public:

    Player()
    {
    }

    Player(const std::string& name)
        : _name(name)
    {
        InitializeRandom();
    }

    void InitializeRandom()
    {
        _stats[(int)Stats::Health] = 100;

        auto RandNum = []() { return rand() % 5 + 1; };
        for (int i = (int)Stats::Health + 1; i < _stats.Size(); i++)
        {
            _stats[i] = RandNum();
        }
    }

    int GetStat(const Stats& stat) const { return _stats[(int)stat]; }

    std::string GetName() const { return _name; }

    void Display() const
    {
        int buffer = 15 - _name.size();
        std::cout << _name << " ";
        for (int i = 0; i <= buffer; i++)
        {
            std::cout << "~";
        }
        std::cout << "> " <<
            "HP = " << _stats[(int)Stats::Health] << "| " <<
            "ATK = " << _stats[(int)Stats::Attack] << "| " <<
            "DEF = " << _stats[(int)Stats::Defense] << "| " <<
            "STAM = " << _stats[(int)Stats::Stamina] << "| " <<
            "SPEED = " << _stats[(int)Stats::Speed] << "\n";
    }

};