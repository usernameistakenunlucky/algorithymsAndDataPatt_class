#include <iostream>
#include <random>
#include "Array.h"
#include "Vector.h"

// Build an array of 10 ints
// initialize them to 0
// iterate through them all and set the values to random numbers (print the numbers)
// create a new array of 10 ints
// make it equal to the initial array
// iterate through all the elements and add 5 (print the numbers)

int main()
{
	// ARRAY ----------------------------------------------------------------------

	Array<int, 10> array1;
	for (int i = 0; i < 10; i++)
	{
		array1[i] = 0;
	}

	int randNum;
	for (int i = 0; i < 10; i++)
	{
		randNum = rand() % 10 + 1;
		std::cout << "Random number #" << i + 1 << ": " << randNum << "\n";
		array1[i] = randNum;
	}
	std::cout << "\n\n";

	Array<int, 10> array2 = array1;
	for (int i = 0; i < 10; i++)
	{
		array2[i] += 5;
		std::cout << "New array number #" << i + 1 << ": " << array2[i] << "\n";
	}

	// VECTOR ----------------------------------------------------------------------

	Vector<int> vector1;
	vector1.PushBack(10);
	vector1.Resize(10);
	

}