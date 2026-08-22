#include "Entity.h"

/*
4) Main flow
	a. Create a Vector<Entity> myEntities;

	b. Create 2 different types of “player” entities with different textures
		i. (textures are not real, just a unique string)

	c. Create 20 types of “enemy” entities with the same texture, but different than the players

	d. Call Update on all entities

	e. Sort the entities by closest to the origin (0.0f, 0.0f) using the Globals::BubbleSort algorithm

	f. Call Render on all the entities

	g. Repeat steps d-f three more times
*/

void AddEntity(Vector<Entity>& myEntities, const std::string& filePath)
{
	Entity entity;
	entity.Initialize(filePath);
	myEntities.PushBack(entity);
}

int Square(int num) { return num * num; }

void RenderAll(const Vector<Entity>& myEntities)
{
	std::cout << "Rendering All Entities:\n";
	for (auto& entity : myEntities)
	{
		entity.Render();
	}
	std::cout << "\n\n\n";
}

int main()
{
	Vector<Entity> myEntities;

	AddEntity(myEntities, "player01.path");
	AddEntity(myEntities, "player02.path");

	for (int i = 0; i < 20; i++)
	{
		AddEntity(myEntities, "enemy.path");
	}
	RenderAll(myEntities);

	//Repeat steps d-f three more times
	for (int i = 0; i < 4; i++)
	{
		system("cls");
		std::cout << "Updating all...\n";
		for (auto& entity : myEntities)
		{
			entity.Update();
		}
		RenderAll(myEntities);


		std::cout << "Sorting all...\n";
		auto sortByOrigin = [](const Entity& a, const Entity& b)->bool
			{
				Vector2 aPos = a.GetPosition();
				Vector2 bPos = b.GetPosition();
				return (Square(bPos.x) + Square(bPos.y)) > (Square(aPos.x) + Square(aPos.y));
			};

		Global::BubbleSort(myEntities, sortByOrigin);
		RenderAll(myEntities);

		system("pause");
	}

	return 0;
}