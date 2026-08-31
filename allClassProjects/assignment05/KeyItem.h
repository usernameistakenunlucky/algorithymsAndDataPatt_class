#pragma once
#include <iostream>

class KeyItem
{
private:
	std::string _name;
	int _count;



public:
	KeyItem() {}

	KeyItem(std::string name, int count)
		: _name(name), _count(count)
	{}

	void Add(int amount)
	{
		_count += amount;
	}

	void Use(int amount) // instead of "Consume"
	{
		_count -= amount;
	}

	int GetCount() const
	{
		return _count;
	}

	void Print() const
	{
		std::cout << _name << ": " << _count << "\n";
	}


};