
#include <iostream>
#include <Graph.h>

void Exercise1Eaxmple()
{
	std::cout << "Graph Example:\n";

	Graph<int> myGraph;
	Vector<int> graphData;
	// create data for graph
	for (int i = 0; i < 10; i++)
	{
		graphData.PushBack(i);
	}
	// add data to the graph
	for (int i = 0; i < graphData.Size(); i++)
	{
		myGraph.AddItem(&graphData[i]);
	}
	// link data together
	myGraph.AddLink(0, 1);
	myGraph.AddLink(0, 2);
	myGraph.AddLink(1, 3);
	myGraph.AddLink(2, 5);
	myGraph.AddLink(2, 6);
	myGraph.AddLink(3, 7);
	myGraph.AddLink(4, 8);
	myGraph.AddLink(4, 7);
	myGraph.AddLink(5, 9);
	myGraph.AddLink(0, 9);
	myGraph.PrintGraph();

	Vector<const int*> dfsConnections;
	Vector<const int*> bfsConnections;
	myGraph.GetAllConnectionsDFS(0, dfsConnections);
	myGraph.GetAllConnectionsBFS(0, bfsConnections);

	std::cout << "Connections (DFS):\n";
	for (int i = 0; i < dfsConnections.Size(); i++)
	{
		std::cout << *dfsConnections[i] << " ";
	}
	std::cout << "\n";

	std::cout << "Connections (BFS):\n";
	for (int i = 0; i < bfsConnections.Size(); i++)
	{
		std::cout << *bfsConnections[i] << " ";
	}
	std::cout << "\n\n";

	int startIndex = 0;
	int endIndex = 0;
	Vector<const int*> pathDFS;
	Vector<const int*> pathBFS;
	std::cout << "Path from " << startIndex << "-" << endIndex << " (DFS):\n";
	if (myGraph.GetPathDFS(startIndex, endIndex, pathDFS))
	{
		for (int i = pathDFS.Size() - 1; i >= 0; --i)
		{
			std::cout << (*pathDFS[i]) << "-";
		}
		std::cout << "\n";
	}
	else
	{
		std::cout << "Path is not found!\n";
	}
	std::cout << "\n";
	std::cout << "Path from " << startIndex << "-" << endIndex << " (BFS):\n";
	if (myGraph.GetPathBFS(startIndex, endIndex, pathBFS))
	{
		for (int i = pathBFS.Size() - 1; i >= 0; --i)
		{
			std::cout << (*pathBFS[i]) << "-";
		}
		std::cout << "\n";
	}
	else
	{
		std::cout << "Path is not found!\n";
	}
}

void Exercise2CitiesOfVancouver()
{
	// Create a City object (string)
	// add all the cities to a vector
	// add the cities to the graph, then link them all where applicable
	// print all the connections
	// find paths between cities

	// Store all the indices
	Vector<std::string> cities;
	cities.PushBack("Vancouver");        // 0
	cities.PushBack("Burnaby");          // 1
	cities.PushBack("North_Vancouver");  // 2
	cities.PushBack("Delta");            // 3
	cities.PushBack("Richmond");         // 4
	cities.PushBack("New_West");         // 5
	cities.PushBack("Coquitlam");        // 6
	cities.PushBack("Victoria");         // 7
	cities.PushBack("Naniamo");          // 8
	cities.PushBack("Quesnel");          // 9
	cities.PushBack("Langley");          // 10
	cities.PushBack("Abbotsford");       // 11
	cities.PushBack("Maple_Ridge");      // 12
	cities.PushBack("Port_Coquitlam");   // 13
	cities.PushBack("Surrey");           // 14

	Graph<std::string> myGraph;
	// create data for graph
	// add data to the graph
	for (int i = 0; i < cities.Size(); i++)
	{
		myGraph.AddItem(&cities[i]);
	}

	myGraph.AddLink(0, 1);   // Vancouver - Burnaby
	myGraph.AddLink(0, 5);   // Vancouver - New West
	myGraph.AddLink(0, 2);   // Vancouver - North_Vancouver (Lions Gate / Ironworkers bridges)
	myGraph.AddLink(0, 4);   // Vancouver - Richmond
	myGraph.AddLink(1, 5);   // Burnaby - New_West
	myGraph.AddLink(1, 6);   // Burnaby - Coquitlam
	myGraph.AddLink(3, 4);   // Delta - Richmond
	myGraph.AddLink(3, 14);  // Delta - Surrey
	myGraph.AddLink(4, 14);  // Richmond - Surrey (Oak St / Alex Fraser bridges)
	myGraph.AddLink(5, 6);   // New_West - Coquitlam
	myGraph.AddLink(5, 14);  // New_West - Surrey (Pattullo Bridge)
	myGraph.AddLink(6, 13);  // Coquitlam - Port_Coquitlam
	myGraph.AddLink(6, 12);  // Coquitlam - Maple_Ridge (Pitt River Bridge)
	myGraph.AddLink(10, 14); // Langley - Surrey
	myGraph.AddLink(10, 11); // Langley - Abbotsford
	myGraph.AddLink(10, 12); // Langley - Maple_Ridge (Golden Ears Bridge)
	myGraph.AddLink(7, 8);   // Victoria - Nanaimo (Island Hwy)
	myGraph.AddLink(0, 8);   // Vancouver - Nanaimo (ferry route)
	myGraph.PrintGraph();



}

struct Tile
{
	int x = 0;
	int y = 0;

	// in path finding
	bool isInPath = false;
	void Draw() const
	{
		if (isInPath)
		{
			std::cout << "[0]";
		}
		else
		{
			std::cout << "[ ]";
		}
	}

	// this is so "std::cout << tile" can be used
	friend std::ostream& operator<<(std::ostream& os, const Tile& t)
	{
		os << t.x << "_" << t.y;
		return os;
	}

};
void ClearMap(Vector<Tile>& map)
{
	for (int i = 0; i < map.Size(); i++)
	{
		map[i].isInPath = false;
	}
}
void DrawMap(int width, int height, const Vector<Tile>& tileMap)
{
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			int index = x + (y * width);
			tileMap[index].Draw();
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}
void Exercise3TileMap()
{
	Vector<Tile> tileMap;
	Graph<Tile> mapGraph;

	int width = 10;
	int height = 10;
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			Tile tile;
			tile.x = x;
			tile.y = y;
			tileMap.PushBack(tile);
		}
	}
	for (int i = 0; i < tileMap.Size(); ++i)
	{
		mapGraph.AddItem(&tileMap[i]);
	}
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			int index = x + (y * width);
			if (x + 1 < width)
			{
				int rightIndex = (x + 1) + (y * width);
				mapGraph.AddLink(index, rightIndex);
			}
			if (y + 1 < height)
			{
				int downIndex = x + ((y + 1) * width);
				mapGraph.AddLink(index, downIndex);
			}
		}
	}

	DrawMap(width, height, tileMap);
	int startX = 0;
	int startY = 0;
	int endX = 0;
	int endY = 0;
	std::cout << "Enter Start X: ";
	std::cin >> startX;
	std::cout << "Enter Start Y: ";
	std::cin >> startY;
	std::cout << "Enter End X: ";
	std::cin >> endX;
	std::cout << "Enter End Y: ";
	std::cin >> endY;

	Vector<const Tile*> pathDFS;
	Vector<const Tile*> pathBFS;
	int startIndex = startX + (startY * width);
	int endIndex = endX + (endY * width);
	mapGraph.GetPathDFS(startIndex, endIndex, pathDFS);
	mapGraph.GetPathBFS(startIndex, endIndex, pathBFS);
	system("cls");
	for (int i = 0; i < pathDFS.Size(); i++)
	{
		int index = pathDFS[i]->x + (pathDFS[i]->y * width);
		tileMap[index].isInPath = true;
	}
	DrawMap(width, height, tileMap);
	ClearMap(tileMap);
	std::cout << "\n";
	std::cout << "BFS Path: \n";
	for (int i = 0; i < pathBFS.Size(); ++i)
	{
		int index = pathBFS[i]->x + (pathBFS[i]->y * width);
		tileMap[index].isInPath = true;
	}
	DrawMap(width, height, tileMap);
	std::cout << "\n";
}

int main()
{
	//Exercise1Eaxmple();
	//Exercise2CitiesOfVancouver();
	Exercise3TileMap();

	return 0;
}