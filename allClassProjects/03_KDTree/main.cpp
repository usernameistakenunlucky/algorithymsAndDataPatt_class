#include <string>
#include <Vector2.h>
#include <Vector.h>
#include <KDTree.h>
#include <algorithm>

enum ItemType
{
	IT_HEALTH,
	IT_WELLNESS,
	IT_MONEY,
	IT_COUNT
};
struct Item
{
	std::string name;
	ItemType itemType;
	Vector2 position;

	// filter by type
	struct FilterByType
	{
		ItemType itemType;
		bool operator()(const void* data)
		{
			const Item* item = (const Item*)data;
			return item->itemType == itemType;
		}
	};
};

int main()
{
	std::cout << "KDTree Example:\n";

	Vector<Item> items;
	KDTree<float, 2> itemLocations;

	int maxItems = 100;
	items.Resize(maxItems);
	for (int i = 0; i < maxItems; ++i)
	{
		items[i].name = "ItemName" + std::to_string(i);
		items[i].itemType = (ItemType)(rand() % IT_COUNT);
		switch (items[i].itemType)
		{
		case IT_HEALTH:    items[i].name += "HEALTH"; break;
		case IT_WELLNESS:  items[i].name += "WELLNESS"; break;
		case IT_MONEY:     items[i].name += "MONEY"; break;
		default: break;
		}
		items[i].position.x = (float)(rand() % 501);
		items[i].position.y = (float)(rand() % 501);
		itemLocations.AddItem(&items[i].position.x, &items[i]);
	}

	itemLocations.BuildTree();

	Vector2 minRange = { 200.0f, 200.0f };
	Vector2 maxRange = { 400.0f, 400.0f };
	Item::FilterByType filter;
	filter.itemType = IT_MONEY;
	Vector<const void*> itemsInRange;
	itemLocations.FindInRange(itemsInRange, &minRange.x, &maxRange.x, filter);
	for (Vector<const void*>::Iterator iter = itemsInRange.Begin(); iter != itemsInRange.End(); ++iter)
	{
		const Item* item = (const Item*)(*iter);
		std::cout << "Item In Range: " << item->name << " (" << item->position.x << ", " << item->position.y << ")\n";
	}

	itemLocations.Terminate();
}