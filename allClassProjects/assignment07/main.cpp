/*
   f. What is the cheapest road that can be built to connect all the houses?
   g. Print the MST connections for both
   h. Print the total cost for the road (both methods should be the same)
*/
#include "City.h"

int main()
{
	City city;
	city.AddHouse("A", Vector2(20, 40));
	city.AddHouse("B", Vector2(50, 20));
	city.AddHouse("C", Vector2(90, 40));
	city.AddHouse("D", Vector2(60, 80));
	city.AddHouse("E", Vector2(30, 120));
	city.AddHouse("F", Vector2(100, 110));
	city.AddHouse("G", Vector2(150, 130));
	city.AddHouse("H", Vector2(160, 90));
	city.AddHouse("I", Vector2(140, 60));
	city.AddHouse("J", Vector2(180, 30));
	city.AddHouse("K", Vector2(200, 120));
	city.AddHouse("L", Vector2(220, 70));
	city.AddHouse("M", Vector2(240, 50));

	city.ConnectAllHouses();

	const float kCostPerMeter = 10.0f;

	// print MST
	std::cout << "MST:\n";
	city.PrintMST();

	std::cout << "\nMST (K):\n";
	city.PrintKMST();

	// print total cost
	float primDistance = city.GetTotalRoadDistancePrim();
	float kruskalDistance = city.GetTotalRoadDistanceKruskal();

	std::cout << "\nTotal Road Distance: " << primDistance << "m\n";
	std::cout << "Total Road Cost: $" << (primDistance * kCostPerMeter) << "\n";

	std::cout << "\nTotal Road Distance (K): " << kruskalDistance << "m\n";
	std::cout << "Total Road Cost (K): $" << (kruskalDistance * kCostPerMeter) << "\n";

	return 0;
}