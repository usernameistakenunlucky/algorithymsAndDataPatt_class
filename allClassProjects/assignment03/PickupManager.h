#pragma once
#include <Vector.h>
#include <KDTree.h>
#include "Pickup.h"


class PickupManager
{
private:
	Vector<Pickup> _pickups;
	KDTree<float, 3> _kdTree;


public:
	PickupManager(const int& size)
	{
		_pickups.Reserve(size);
	}

	void AddItem(const PickupType& pickupType, const Vector3& pos)
	{
		
		_pickups.PushBack(Pickup{ pickupType, pos });

		Pickup& pickup = _pickups[_pickups.Size() - 1];
		_kdTree.AddItem(&pickup.GetPos().x, &pickup);
	}

	void BuildTree()
	{
		_kdTree.BuildTree();
	}

	const Pickup* GetClosestPickup(const Vector3& pos)
	{
		const void* result = _kdTree.FindNearest(&pos.x);
		return static_cast<const Pickup*>(result);
	}

	void ObtainPickupsInRange(const Vector3& pos, float range, PickupType pickupType)
	{
		Vector3 minRange = pos - Vector3(range);
		Vector3 maxRange = pos + Vector3(range);

		Vector<const void*> result; // -> const void* instead of Pickup* since _kdTree doesn't know what a pickup is

		if (pickupType != PickupType::Invalid)
		{
			auto filter = [pickupType](const void* userData) -> bool // -> again, using void* since kdTree is oblivious to this file
				{
					return static_cast<const Pickup*>(userData)->IsType(pickupType);
				};

			_kdTree.FindInRange(result, &minRange.x, &maxRange.x, filter);
		}
		else
		{
			_kdTree.FindInRange(result, &minRange.x, &maxRange.x);
		}

		for (std::size_t i = 0; i < result.Size(); ++i)
		{
			const Pickup* pickup = static_cast<const Pickup*>(result[i]);
			std::cout << pickup->GetName() << " at ("
				<< pickup->GetPos().x << ", "
				<< pickup->GetPos().y << ", "
				<< pickup->GetPos().z << ")" << std::endl;
		}
	}
};