#pragma once
#include <iostream>


enum class ItemType
{
	healthPotion = 1,
	throwingKnife,
	javelin,
	fireballSpell,
	soothingSunlightSpell,
	phoenixFeather,
	bandageWrap,
	poisonVial,
	canOfCola,
	venomDart,
};

class Item
{
private:
	ItemType _type;
	std::string _name;
	int _power; // instead of "value"
	int _count;

	void InitializeFromType()
	{
		switch (_type)
		{
		case ItemType::healthPotion:			_name = "Healing Potion"; _power = 15; break;
		case ItemType::throwingKnife:			_name = "Throwing Knife"; _power = -6; break;
		case ItemType::javelin:					_name = "Javelin"; _power = -10; break;
		case ItemType::fireballSpell:			_name = "Fireball"; _power = -25; break;
		case ItemType::soothingSunlightSpell:   _name = "Soothing Sunlight"; _power = 40; break;
		case ItemType::phoenixFeather:			_name = "Phoenix Feather"; _power = 20; break;
		case ItemType::bandageWrap:				_name = "Bandage Wrap"; _power = 5; break;
		case ItemType::poisonVial:				_name = "Poison Vial"; _power = -9; break;
		case ItemType::canOfCola:				_name = "Can of Cola"; _power = -2; break;
		case ItemType::venomDart:				_name = "Venom Dart"; _power = -4; break;
		}
	}

public:
	Item() {}

	Item(const ItemType& type, const int& count)
		: _type(type), _count(count)
	{
		InitializeFromType();
	}

	ItemType GetType() const { return _type; }
	int GetCount() const { return _count; }

	void UseItem() // instead of "ConsumeItem"
	{
		if (_count > 0)
		{
			std::cout << "used the " << _name << ", ";
			if (_power > 0) { std::cout << "it heals " << _power << " hp!\n"; }
			else { std::cout << "it deals " << _power << " damage!\n"; }

			_count--;
		}
		else
		{
			std::cout << "There are no " << _name << " left in the inventory!\n";
		}
	}

	void AddItem(const int& count)
	{
		_count += count;
		std::cout << "Added " << count << " " << _name << "(s) to your inventory (currently: " << _count << ")\n";
	}

	void Display() const
	{
		std::cout << _name << " | power: " << _power
			<< " | count: " << _count << "\n";
	}

};