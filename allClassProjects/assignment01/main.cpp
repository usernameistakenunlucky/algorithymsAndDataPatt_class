#include "Player.h"


std::string RandName()
{
	int randNum = rand() % 20 + 1;
	std::string first;
	switch (randNum)
	{
	case 1: first = "Aria"; break;
	case 2: first = "Marcus"; break;
	case 3: first = "Elena"; break;
	case 4: first = "Jackson"; break;
	case 5: first = "Priya"; break;
	case 6: first = "Diego"; break;
	case 7: first = "Sophie"; break;
	case 8: first = "Kwame"; break;
	case 9: first = "Lena"; break;
	case 10: first = "Owen"; break;
	case 11: first = "Nadia"; break;
	case 12: first = "Theo"; break;
	case 13: first = "Amara"; break;
	case 14: first = "Felix"; break;
	case 15: first = "Ingrid"; break;
	case 16: first = "Malik"; break;
	case 17: first = "Yuki"; break;
	case 18: first = "Ruby"; break;
	case 19: first = "Hassan"; break;
	case 20: first = "Clara"; break;
	default: first = "Unknown"; break;
	}

	randNum = rand() % 20 + 1;
	std::string last;
	switch (randNum)
	{
	case 1: last = "Thompson"; break;
	case 2: last = "Chen"; break;
	case 3: last = "Rodriguez"; break;
	case 4: last = "Wright"; break;
	case 5: last = "Patel"; break;
	case 6: last = "Morales"; break;
	case 7: last = "Bennett"; break;
	case 8: last = "Osei"; break;
	case 9: last = "Fischer"; break;
	case 10: last = "Bradley"; break;
	case 11: last = "Volkov"; break;
	case 12: last = "Anderson"; break;
	case 13: last = "Johnson"; break;
	case 14: last = "Novak"; break;
	case 15: last = "Larsen"; break;
	case 16: last = "Carter"; break;
	case 17: last = "Tanaka"; break;
	case 18: last = "Sullivan"; break;
	case 19: last = "Ali"; break;
	case 20: last = "Dubois"; break;
	default: last = "Unknown"; break;
	}

	return first + " " + last;
}

int CalculateScore(const Player& playerA, const Player& playerB)
{
	return playerA.GetStat(Stats::Health) - ((playerB.GetStat(Stats::Attack) * playerB.GetStat(Stats::Stamina)) -
		(playerA.GetStat(Stats::Defense) * playerA.GetStat(Stats::Speed)));
}

void Fight(const Player& playerA, const Player& playerB)
{
	/*
		i. Int playerAScore = PlayerA(health) - ((PlayerB(attack) *
		   PlayerB(stamina)) - (PlayerA(defense) * PlayerA(speed))

		ii. Reverse the Players to calculate PlayerB's score
		iii. Whoever has the best score wins
		iv. If there is a tie, flip a coin
		v. Print the winner and final scores
	*/

	int scoreA = CalculateScore(playerA, playerB);
	int scoreB = CalculateScore(playerB, playerA);

	std::cout << playerA.GetName() << "'s score = " << scoreA << ",\n" <<
		playerB.GetName() << "'s score = " << scoreB << ",\n";

	std::string winner;
	if (scoreA == scoreB) { winner = rand() % 2 > 0 ? playerA.GetName() : playerB.GetName(); }
	/**/             else { winner = scoreA > scoreB ? playerA.GetName() : playerB.GetName(); }

	std::cout << winner << " wins!\n\n";
}

void DisplayPlayers(const Vector<Player>& players)
{
	for (int i = 0; i < players.Size(); i++)
	{
		players[i].Display();
	}
	std::cout << "\n";
}

int main()
{
	srand(time(0));

	/*    a. Create a Vector of players*/
	Vector<Player> players;

	/*    b. Add 10 players with random names*/
	for (int i = 0; i < 10; i++)
	{
		players.PushBack(Player(RandName()));
	}

	/*    c. Display the names of all the players and all of their stats*/
	DisplayPlayers(players);

	/*    d. Remove 6 players*/
	for (int i = 0; i < 6; i++)
	{
		players.PopBack();
	}

	/*    e. Add up to a total of 20 players (max out at 20) and display all the new names also with random stats*/
	for (int i = players.Size(); i < 20; i++)
	{
		players.PushBack(Player(RandName()));
	}
	DisplayPlayers(players);

	int randNum1 = rand() % players.Size();
	int randNum2;
	do
	{
		randNum2 = rand() % players.Size();
		if (randNum1 != randNum2) { break; }

	} while (true);

	/*    f. Pick a random 2 Players, compare their stats to see who would win a fight*/
	Fight(players[randNum1], players[randNum2]);




	return 0;
}