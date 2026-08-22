#pragma once

#include <string>
#include <functional>
#include "Vector.h"

namespace Global
{
	// hash function
	std::size_t HashFunction(const std::string& str)
	{
		std::size_t hash = 0;
		for (std::size_t i = 0; i < str.size(); i++)
		{
			hash = (~hash << i) + (std::size_t)(str[i]);
		}
		return hash;
	}

	// swap
	template<typename T>
	void Swap(T& a, T& b)
	{
		T temp = a;
		a = b;
		b = temp;
	}

	// bubble sort
	template<typename T, typename Compare = std::less<T>>
	void BubbleSort(Vector<T>& values, Compare sortFunc = Compare{})
	{
		std::size_t size = values.Size();
		for (std::size_t i = 0; i < size - 1; i++)
		{
			for (std::size_t j = 0; j < size - i - 1; j++)
			{
				if (sortFunc(values[j + 1], values[j]))
				{
					Swap(values[j + 1], values[j]);
				}
			}
		}
	}

	// selection sort
	template<typename T, typename Compare = std::less<T>>
	void SelectionSort(Vector<T>& values, Compare sortFunc = Compare{})
	{
		std::size_t size = values.Size();
		for (std::size_t i = 0; i < size - 1; i++)
		{
			size_t minIndex = i;
			for (std::size_t j = i + 1; j < size; j++)
			{
				if (sortFunc(values[j], values[minIndex]))
				{
					minIndex = j;
				}
			}
			if (i != minIndex)
			{
				Swap(values[i], values[minIndex]);
			}
		}
	}



}