#include <Vector.h>
#include "Inventory.h"

enum class Options
{
	OpenDoor = 1,
	ObtainKey,
	Exit,
};

std::string GetRandKey(const Vector<std::string>& keyNames)
{
	return keyNames[rand() % keyNames.Size()];
}

void PrintMyKeys()
{
	Inventory* inv = Inventory::Get();
	// d.Obtain all the keys you own and print their names and the count
	Vector<std::string> myKeys;
	inv->ObtainKeys(myKeys);

	for (int i = 0; i < myKeys.Size(); i++)
	{
		inv->PrintKey(myKeys[i]);
	}
}

void OpenDoor(const Vector<std::string>& keyNames, int& unlockedDoors, int& failedUnlocks)
{
	Inventory* inv = Inventory::Get();
	std::string randKey = GetRandKey(keyNames);
	std::cout << "You arrive at a door and need a " << randKey << ",\n";

	if (inv->HasKey(randKey))
	{
		std::cout << "You have the " << randKey << " and have unlocked the door!\n";
		inv->UseKey(randKey, 1);
		unlockedDoors++;
	}
	else
	{
		std::cout << "You do not have the " << randKey << ", the door will remain locked!\n";
		failedUnlocks++;
	}
	system("pause");
}

void ObtainKey(const Vector<std::string>& keyNames)
{
	Inventory* inv = Inventory::Get();
	std::string randKey = GetRandKey(keyNames);

	inv->PickupKey(randKey, 1);
	std::cout << "You obtained a " << randKey << "!\n";
	inv->PrintKey(randKey);
	system("pause");
}

void GameLoop(const Vector<std::string>& keyNames)
{
	Inventory* inv = Inventory::Get();
	int unlockedDoors = 0;
	int failedUnlocks = 0;

	while (true)
	{
		system("cls");
		std::cout << "Options:\n[1] Open Door \n[2] Obtain a Key \n[3] Exit\n\n->";
		int input;
		std::cin >> input;

		switch (input)
		{
		case (int)Options::OpenDoor: OpenDoor(keyNames, unlockedDoors, failedUnlocks);
			break;
		case (int)Options::ObtainKey: ObtainKey(keyNames);
			break;
		case (int)Options::Exit:
		{
			PrintMyKeys();
			std::cout << "Successfully unlocked " << unlockedDoors << " doors.\n";
			std::cout << "Failed to unlock " << failedUnlocks << " doors.\n";
			return;
		}
		default: std::cout << "Invalid input\n";
		}
	}
}

int main()
{
	Inventory* inv = Inventory::Get();
	Vector<std::string> keyNames;
	{
		keyNames.PushBack("Excalibur");
		keyNames.PushBack("Aegis");
		keyNames.PushBack("Phoenixfeather");
		keyNames.PushBack("Bloodstone");
		keyNames.PushBack("Wraithblade");
		keyNames.PushBack("Ironhide");
		keyNames.PushBack("Moonshard");
		keyNames.PushBack("Venomfang");
		keyNames.PushBack("Stormcaller");
		keyNames.PushBack("Netherblade");
		keyNames.PushBack("Runestone");
		keyNames.PushBack("Frostbite");
		keyNames.PushBack("Shadowcloak");
		keyNames.PushBack("Thornmail");
		keyNames.PushBack("Voidwalker");
		keyNames.PushBack("Emberheart");
		keyNames.PushBack("Skullcrusher");
		keyNames.PushBack("Starforge");
		keyNames.PushBack("Dragonscale");
		keyNames.PushBack("Soulreaper");
	}

	for (int i = 0; i < 100; i++)
	{
		inv->PickupKey(keyNames[rand() % keyNames.Size()], 1);
	}
	PrintMyKeys();
	

	//e.Do a loop as if you are playing a text based adventure(“Game Loop”)
	system("pause");
	GameLoop(keyNames);


	return 0;
}