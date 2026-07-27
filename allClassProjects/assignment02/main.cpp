#include <Array.h>

#include "Inventory.h"

int main()
{
	srand(time(0));

	Inventory inventory;
	inventory.Initialize();

	for (int i = 0; i < 100; i++) // adding 100 random items
	{
		int randNum = rand() % 10 + 1;
		ItemType type = static_cast<ItemType>(randNum);
		inventory.AddItem(type);
	}

	inventory.Display();

	while (inventory[0].GetCount() > 0)
	{
		inventory[0].UseItem();
	}
	inventory[0].UseItem();

	int main();
}