#pragma once
#include <iostream>
#include <Vector2.h>

struct House // made it into a struct instead
{
	std::string name;
	Vector2 position;

	House() {}

	House(const std::string& nameInput, const Vector2& pos)
		: name(nameInput), position(pos)
	{
	}

};