#pragma once

#include <iostream>
#include "Stack.h"
#include "Queue.h"

template<typename T>
class Graph
{
private:
	struct Node
	{
		// data stored on a graph node
		const T* data = nullptr;
		// use flag for if it is visited
		bool isVisited = false;
		// for obtaining path
		Node* fromNode = nullptr;
		// connected edges
		Vector<int> edges;
	};

public:

	Graph()
	{

	}
	~Graph()
	{
		Terminate();
	}

	// adds item, returns index of added item
	int AddItem(const T* data)
	{
		Node* newNode = new Node();
		newNode->data = data;
		mNodes.PushBack(newNode);
		return mNodes.Size() - 1;
	}
	// add link between node indices (optional by directional)
	void AddLink(std::size_t a, std::size_t b, bool bothWays = true)
	{
		if (a >= mNodes.Size() || b >= mNodes.Size())
		{
			return;
		}
		mNodes[a]->edges.PushBack(b);
		if (bothWays)
		{
			mNodes[b]->edges.PushBack(a);
		}
	}

	// Get Connection DFS
	void GetAllConnectionsDFS(int srartIndex, Vector<const T*>& connections)
	{
		// LIFO
		Reset();
		Stack<Node*> stack;
		stack.Push(mNodes[srartIndex]);
		while (!stack.Empty())
		{
			Node* node = stack.Top();
			stack.Pop();
			if (!node->isVisited)
			{
				node->isVisited = true;
				connections.PushBack(node->data);
				for (std::size_t i = 0; i < node->edges.Size(); i++)
				{
					int edgeIndex = node->edges[i];
					Node* edgeNode = mNodes[edgeIndex];
					if (!edgeNode->isVisited)
					{
						stack.Push(edgeNode);
					}
				}
			}
		}
	}
	// Get Connection BFS
	void GetAllConnectionsBFS(int srartIndex, Vector<const T*>& connections)
	{
		// FIFO
		Reset();
		Queue<Node*> queue;
		queue.Enqueue(mNodes[srartIndex]);
		while (!queue.Empty())
		{
			Node* node = queue.Front();
			queue.Dequeue();
			if (!node->isVisited)
			{
				node->isVisited = true;
				connections.PushBack(node->data);
				for (std::size_t i = 0; i < node->edges.Size(); i++)
				{
					int edgeIndex = node->edges[i];
					Node* edgeNode = mNodes[edgeIndex];
					if (!edgeNode->isVisited)
					{
						queue.Enqueue(edgeNode);
					}
				}
			}
		}
	}

	// get path DFS
	bool GetPathDFS(int startIndex, int endIndex, Vector<const T*>& path)
	{
		Reset();
		bool pathFound = false;
		Node* startNode = mNodes[startIndex];
		Node* endNode = mNodes[endIndex];
		Stack<Node*> stack;
		stack.Push(startNode);
		while (!stack.Empty())
		{

			Node* node = stack.Top();
			stack.Pop();
			if (!node->isVisited)
			{
				node->isVisited = true;
				if (node == endNode)
				{
					pathFound = true;
					break;
				}
				for (std::size_t i = 0; i < node->edges.Size(); i++)
				{
					int edgeIndex = node->edges[i];
					Node* edgeNode = mNodes[edgeIndex];
					if (!edgeNode->isVisited)
					{
						edgeNode->fromNode = node;
						stack.Push(edgeNode);
					}
				}
			}
		}
		if (pathFound)
		{
			Node* pathNode = endNode;
			while (pathNode != nullptr)
			{
				path.PushBack(pathNode->data);
				pathNode = pathNode->fromNode;
			}
		}
		return pathFound;
	}

	// get path BFS
	bool GetPathBFS(int startIndex, int endIndex, Vector<const T*>& path)
	{
		Reset();
		bool pathFound = false;
		Node* startNode = mNodes[startIndex];
		Node* endNode = mNodes[endIndex];
		Queue<Node*> queue;
		queue.Enqueue(startNode);
		while (!queue.Empty())
		{

			Node* node = queue.Front();
			queue.Dequeue();
			if (!node->isVisited)
			{
				node->isVisited = true;
				if (node == endNode)
				{
					pathFound = true;
					break;
				}
				for (std::size_t i = 0; i < node->edges.Size(); i++)
				{
					int edgeIndex = node->edges[i];
					Node* edgeNode = mNodes[edgeIndex];
					if (!edgeNode->isVisited)
					{
						edgeNode->fromNode = node;
						queue.Enqueue(edgeNode);
					}
				}
			}
		}
		if (pathFound)
		{
			Node* pathNode = endNode;
			while (pathNode != nullptr)
			{
				path.PushBack(pathNode->data);
				pathNode = pathNode->fromNode;
			}
		}
		return pathFound;
	}


	// print all the graph data
	void PrintGraph()
	{
		std::cout << "Printing Graph: \n";
		for (std::size_t i = 0; i < mNodes.Size(); i++)
		{
			// prints the "data" value ( if using a class, may need to override ostream& operator<<(ostream& s))
			std::cout << *mNodes[i]->data << ": ";
			for (std::size_t e = 0; e < mNodes[i]->edges.Size(); e++)
			{
				int edgeNodeIndex = mNodes[i]->edges[e];
				std::cout << *mNodes[edgeNodeIndex]->data << " ";
			}
			std::cout << "\n";
		}
	}
	void Terminate()
	{
		for (std::size_t i = 0; i < mNodes.Size(); i++)
		{
			delete mNodes[i];
			mNodes[i] = nullptr;
		}
		mNodes.Clear();
	}

private:

	void Reset()
	{
		for (size_t i = 0; i < mNodes.Size(); i++)
		{
			mNodes[i]->isVisited = false;
			mNodes[i]->fromNode = nullptr;
		}
	}

	Vector<Node*> mNodes;
};