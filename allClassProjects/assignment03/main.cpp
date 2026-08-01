#include "PickupManager.h"


float RandNum(int min, int max)
{
	return (float)(rand() % (max - min + 1) + min);
}

Vector3 RandPos()
{
	return Vector3{ RandNum(1,99), RandNum(1,99), RandNum(1,99) };
}

int main()
{
	srand(time(0));

	int size = 100;
	PickupManager pickupMananger(size);

	for (int i = 0; i < size; i++)
	{
		PickupType type = static_cast<PickupType>(rand() % 5 + 1);
		pickupMananger.AddItem(type, RandPos());
	}

	pickupMananger.BuildTree();

	Vector3 player = { 50.f, 50.f, 50.f };

	// pickups within 10
	std::cout << "--- Pickups within attract range (10.0f) ---" << std::endl;
	pickupMananger.ObtainPickupsInRange(player, 10.0f, PickupType::Invalid);

	// health within 50
	std::cout << "--- Health pickups within range (50.0f) ---" << std::endl;
	pickupMananger.ObtainPickupsInRange(player, 50.0f, PickupType::Health);

	// closest pickup
	const Pickup* closest = pickupMananger.GetClosestPickup(player);
	if (closest != nullptr)
	{
		std::cout << "--- Closest pickup ---" << std::endl;
		std::cout << closest->GetName() << " at ("
			<< closest->GetPos().x << ", "
			<< closest->GetPos().y << ", "
			<< closest->GetPos().z << ")";

		// in case you meant the position relative to the player
		Vector3 offset = closest->GetPos() - player; 
		std::cout << " or -> ("
			<< offset.x << ", " << offset.y << ", " << offset.z << ") from the player\n";
	}


	return 0;
}