#pragma once
#include <algorithm>
#include <Vector.h>
#include <PriorityQueue.h>
#include "Item.h"

struct CompareByCount
{
	bool operator()(const Item& a, const Item& b) const
	{
		return a.GetCount() > b.GetCount();
	}
};

class Inventory
{
private:
	Vector<Item> _items;

public:
	Inventory() {}

	void Initialize()
	{
		_items.PushBack(Item {ItemType::healthPotion, 0 });
		_items.PushBack(Item {ItemType::throwingKnife, 0 });
		_items.PushBack(Item {ItemType::javelin, 0 });
		_items.PushBack(Item {ItemType::fireballSpell, 0 });
		_items.PushBack(Item {ItemType::soothingSunlightSpell, 0 });
		_items.PushBack(Item {ItemType::phoenixFeather, 0 });
		_items.PushBack(Item {ItemType::bandageWrap, 0 });
		_items.PushBack(Item {ItemType::poisonVial, 0 });
		_items.PushBack(Item {ItemType::canOfCola, 0 });
		_items.PushBack(Item {ItemType::venomDart, 0 });
	}

	void AddItem(const ItemType& type, const int& count = 1)
	{
		for (Vector<Item>::Iterator it = _items.Begin(); it != _items.End(); it++)
		{
			if (it->GetType() == type)
			{
				it->AddItem(count);
				return;
			}
		}

		Item newItem(type, count);
		_items.PushBack(newItem);
	}

	void Display() // instead of DisplayInventory
	{
		PriorityQueue<Item, CompareByCount> queue;
		for (Vector<Item>::Iterator it = _items.Begin(); it != _items.End(); it++)
		{
			queue.Push(*it);
		}

		while (!queue.Empty())
		{
			queue.Top().Display();
			queue.Pop();
		}
	}

	Item& operator[](const std::size_t& index) { return _items[index]; }
	const Item& operator[](const std::size_t& index) const { return _items[index]; }

};