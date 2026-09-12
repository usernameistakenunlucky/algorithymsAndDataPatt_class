
#include "Team.h"

int main()
{
    srand(time(0));

    Team teamA("IEEEEE");
    Team teamB("Jeff");
    teamA.Initialize(20);
    teamB.Initialize(20);

    while (teamA.GetRemainingPlayers() > 0 && teamB.GetRemainingPlayers() > 0)
    {
        system("cls");
        teamA.StartTurn();
        teamB.StartTurn();
        std::cout << "Team: " << teamA.GetName() << " has " << teamA.GetRemainingPlayers() << " player remaining.\n";
        std::cout << "Team: " << teamB.GetName() << " has " << teamB.GetRemainingPlayers() << " player remaining.\n\n";

        while (!teamA.TurnOver() || !teamB.TurnOver())
        {
            Player* a = teamA.GetNextBattlingPlayer();
            Player* b = teamB.GetNextBattlingPlayer();

            if (a && b)
            {
                if (a->GetStat(Stats::Speed) > b->GetStat(Stats::Speed))
                {
                    teamB.DamagePlayer(a);
                }
                else
                {
                    teamA.DamagePlayer(b);
                }
            }
            else if (a)
            {
                teamB.DamagePlayer(a);
            }
            else if (b)
            {
                teamA.DamagePlayer(b);
            }

            teamA.OrderPlayers();
            teamB.OrderPlayers();
        }

        std::cout << "\nRound over.\n\n";
        system("pause");
    }

    if (teamA.GetRemainingPlayers() > 0)
    {
        std::cout << "\n\nTeam: " << teamA.GetName() << " wins!\n";
    }
    else
    {
        std::cout << "\n\nTeam: " << teamB.GetName() << " wins!\n";
    }

    return 0;
}