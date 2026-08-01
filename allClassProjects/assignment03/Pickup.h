#pragma once
#include <string>
#include "Vector3.h"

enum PickupType
{
	Invalid = 0,
	Health,
	Ammo,
	Coins,
	Upgrade,
	ScecialItem
};

std::string TypeToString(const PickupType& type)
{
	switch (type)
	{
	case PickupType::Invalid: return "Invalid";
	case PickupType::Health: return "Health";
	case PickupType::Ammo: return "Ammo";
	case PickupType::Coins: return "Coins";
	case PickupType::Upgrade: return "Upgrade";
	case PickupType::ScecialItem: return "ScecialItem";
	default: return "Error!";
	}
}

class Pickup
{
private:
	PickupType _type;
	std::string _name;
	Vector3 _pos;



public:
	Pickup() {}

	Pickup(const PickupType& pickupType, const Vector3& pos)
		: _type(pickupType), _pos(pos)
	{
		_name = TypeToString(_type);
	}

	Vector3& GetPos() { return _pos; }
	const Vector3& GetPos() const { return _pos; }
	std::string GetName() const { return _name; }
	bool IsType(PickupType type) const { return _type == type; }

};