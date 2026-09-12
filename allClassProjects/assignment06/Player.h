#pragma once
#include <iostream>
#include <array>

enum class Stats
{
    Health = 0,
    Attack,
    Speed,
    AttackCount,
};

class Player
{
private:
    std::string _name;
    std::array<int, 4> _stats = { 0,0,0,0 };


public:
    Player() {}

    Player(const std::string& name)
        : _name(name)
    {
    }

    void Initialize()
    {
        _stats[(int)Stats::Health] = 100;
        _stats[(int)Stats::Speed] = rand() % 81 + 20;
        _stats[(int)Stats::Attack] = rand() % 16 + 5;
        _stats[(int)Stats::AttackCount] = 1;
    }

    std::string GetName() const { return _name; }

    int GetStat(Stats stat) const
    {
        return _stats[(int)stat];
    }

    void SetStat(Stats stat, int value)
    {
        _stats[(int)stat] = value;
    }

    bool IsAlive() const
    {
        return _stats[(int)Stats::Health] > 0;
    }
};
