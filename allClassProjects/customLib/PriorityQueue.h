#pragma once

#include <iostream>
#include "Vector.h"

template<typename T, typename Compare = std::less<typename T>>
class PriorityQueue
{
public:
	PriorityQueue() {}

	bool Empty() const
	{
		return mValues.Size() == 0;
	}
	const std::size_t Size()
	{
		return mValues.Size();
	}

	void Push(const T& value)
	{
		mValues.PushBack(value);
		HeapifyUp(Size() - 1);
	}

	const T& Top() const
	{
		return mValues[0];
	}

	void Pop()
	{
		if (Empty())
		{
			assert(false, "Tried to pop an empty PriorityQueue!");
			return;
		}

		mValues[0] = mValues[Size() - 1];
		mValues.Resize(Size() - 1);
		HeapifyDown(0);
	}

private:
	void Swap(T& a, T& b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	void HeapifyUp(int index)
	{
		int parent = (index - 1) / 2;
		while (index > 0 && mCompare(mValues[index], mValues[parent]))
		{
			Swap(mValues[index], mValues[parent]);
			index = parent;
			parent = (index - 1) / 2;
		}
	}

	void HeapifyDown(int index)
	{
		int largest = index;
		int leftChild = 2 * index + 1;
		int rightChild = 2 * index + 2;
		if (leftChild < Size() && mCompare(mValues[leftChild], mValues[largest]))
		{
			largest = leftChild;
		}
		if (rightChild < Size() && mCompare(mValues[rightChild], mValues[largest]))
		{
			largest = rightChild;
		}
		if (largest != index)
		{
			Swap(mValues[index], mValues[largest]);
			HeapifyDown(largest);
		}
	}

	Compare mCompare;
	Vector<T> mValues;

};