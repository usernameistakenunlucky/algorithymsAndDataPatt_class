#pragma once
#include "KeyItem.h"
#include <Map.h>

class Inventory
{
private:
	Map<std::string, KeyItem> _keys;

	Inventory() {}

public:
	// Singleton setup functions
	static Inventory* Get()
	{
		static Inventory sInstance;
		return &sInstance;
	}
	Inventory(const Inventory&) = delete;
	Inventory& operator=(const Inventory&) = delete;

	void PickupKey(const std::string& keyName, int amount)
	{
		if (_keys.Has(keyName))
		{
			_keys[keyName].Add(amount);
		}
		else
		{
			_keys.Insert(keyName, KeyItem(keyName, amount));
		}
	}

	void UseKey(const std::string& keyName, int amount)
	{
		if (!_keys.Has(keyName))
		{
			std::cout << "Error, key not found\n";
			return;
		}
		_keys[keyName].Use(amount);
		if (_keys[keyName].GetCount() <= 0)
		{
			_keys.Remove(keyName);
		}
	}

	bool HasKey(const std::string& keyName) const
	{
		return _keys.Has(keyName) && _keys[keyName].GetCount() > 0;
	}

	void ObtainKeys(Vector<std::string>& outVector)
	{
		_keys.ObtainKeys(outVector);
	}

	void PrintKey(std::string keyName) const
	{
		if (!_keys.Has(keyName))
		{
			std::cout << "Error, key not found\n";
			return;
		}

		_keys[keyName].Print();
	}

};