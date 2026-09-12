#pragma once
#include <algorithm>
#include <Vector.h>
#include <Global.h>
#include "Player.h"

class Team
{
private:
	std::string _name;
	Vector<Player> _players;


public:
	Team(std::string name)
		: _name(name)
	{
	}

	void Initialize(int numPlayers)
	{
		for (int i = 0; i < numPlayers; i++)
		{
			Player newPlayer("player" + std::to_string(i) + " of " + _name);
			newPlayer.Initialize();
			_players.PushBack(newPlayer);
		}
	}
	std::string GetName() const { return _name; }

	Player* GetNextBattlingPlayer()
	{
		Player* fastest = nullptr;
		for (int i = 0; i < _players.Size(); i++)
		{
			if (_players[i].IsAlive() && _players[i].GetStat(Stats::AttackCount) > 0)
			{
				if (fastest == nullptr || _players[i].GetStat(Stats::Speed) > fastest->GetStat(Stats::Speed))
				{
					fastest = &_players[i];
				}
			}
		}
		return fastest;
	}
	void DamagePlayer(Player* attacker)
	{
		if (GetRemainingPlayers() <= 0)
		{
			attacker->SetStat(Stats::AttackCount, 0); // nobody left to hit so set to 0 and win da gameee
			return;
		}

		while (true)
		{
			Player* target = &_players[rand() % _players.Size()];
			if (target->IsAlive())
			{
				std::cout << attacker->GetName() << " attacks " << target->GetName() << " for " << (int)attacker->GetStat(Stats::Attack) << " dmg! ";

				int newHp = target->GetStat(Stats::Health) - attacker->GetStat(Stats::Attack);
				target->SetStat(Stats::Health, newHp);
				if (rand() % 4 == 0)
				{
					std::cout << target->GetName() << " had their speed reduced! ";
					target->SetStat(Stats::Speed, std::max((int)target->GetStat(Stats::Speed) - 10, 5));
				}
				if (rand() % 10 == 0)
				{
					std::cout << attacker->GetName() << " had their speed increase! ";
					attacker->SetStat(Stats::Speed, (int)attacker->GetStat(Stats::Speed) + 5);
				}
				attacker->SetStat(Stats::AttackCount, 0);
				std::cout << "\n";
				return;
			}
		}
	}

	int GetRemainingPlayers()
	{
		int remaining = 0;
		for (int i = 0; i < _players.Size(); i++)
		{
			if (_players[i].GetStat(Stats::Health) > 0)
			{
				remaining++;
			}
		}
		return remaining;
	}

	bool TurnOver()
	{
		for (const auto& player : _players)
		{
			if ((int)player.GetStat(Stats::AttackCount) > 0 && player.IsAlive())
			{
				return false;
			}
		}
		return true;
	}

	void OrderPlayers()
	{
		auto speedSort = [](const Player& a, const Player& b)
			{
				int speedA = 0;
				if (a.GetStat(Stats::AttackCount) > 0 && a.GetStat(Stats::Health) > 0)
				{
					speedA = (int)a.GetStat(Stats::Speed);
				}
				int speedB = 0;
				if (b.GetStat(Stats::AttackCount) > 0 && b.GetStat(Stats::Health) > 0)
				{
					speedB = (int)b.GetStat(Stats::Speed);
				}
				return speedA > speedB;
			};
		Global::IntroSort(_players.Begin(), _players.End(), speedSort);
	}

	void StartTurn()
	{
		for (Player& player : _players)
		{
			if (player.IsAlive())
			{
				player.SetStat(Stats::AttackCount, 1);
			}
		}
		OrderPlayers();
	}


};