#include <iostream>
#include <Global.h>
#include <UnorderedMap.h>

void Exercise1_SortCheck()
{
	Vector<int> numbersBubble;
	Vector<int> numbersSelection;
	for (int i = 0; i < 10; i++)
	{
		int value = rand() % 200 + 1;
		numbersBubble.PushBack(value);
		numbersSelection.PushBack(value);
		std::cout << value << " ";
	}
	std::cout << "\n";
	auto oddEvenSort = [](const int& a, const int& b)->bool
		{
			bool aIsOdd = a % 2 == 1;
			bool bIsOdd = b % 2 == 1;
			if (aIsOdd == bIsOdd) { return a < b; }
			if (aIsOdd) { return true; }
			return false;
		};


	Global::BubbleSort(numbersBubble, oddEvenSort);
	Global::SelectionSort(numbersSelection, oddEvenSort);

	std::cout << "Bubble Sort:\n";
	for (int i = 0; i < numbersBubble.Size(); i++)
	{
		std::cout << numbersBubble[i] << " ";
	}

	std::cout << "\nSelection Sort:\n";
	for (int i = 0; i < numbersSelection.Size(); i++)
	{
		std::cout << numbersSelection[i] << " ";
	}
	std::cout << "\n";

}

void Exercise2_CheckUnorderedMap()
{
	UnorderedMap<std::size_t, int> mapTest;
	for (std::size_t i = 1; i <= 20; i++)
	{
		mapTest.Insert(i, rand() % 1000);
	}

	std::cout << "Unordered Map:\n";
	for (std::size_t i = 1; i <= 20; i++)
	{
		std::cout << mapTest[i] << " ";
	}

	std::cout << "Map Has Key 30: " << mapTest.Has(30) << "\n";
	int outValue = 0;
	if (mapTest.Find(15, outValue))
	{
		std::cout << "Map Has Key 15: " << outValue << "\n";
	}
	else
	{
		std::cout << "Map does not have Key 15!!\n";
	}

	if (mapTest.Remove(10))
	{
		std::cout << "Map removed Key 10\n";
	}

	mapTest[35] = 2;
	std::cout << "Map value 35: " << mapTest[35] << "\n";
	std::cout << "Map value 40: " << mapTest[40] << "\n";
	mapTest.Clear();

}

void Exercise3_CheckUnorderedString()
{
	std::cout << "Unordered Map with String Keys:\n";
	
	UnorderedMap<std::string, int> myCarPrices;
	myCarPrices.Insert("Ford", 50);
	myCarPrices.Insert("Honda", 10000);
	myCarPrices.Insert("Dodge", 350000);
	myCarPrices.Insert("BMW", INT_MAX);
	myCarPrices["Kia"] = 14000;

	std::cout << "Price of a Ford: " << myCarPrices["Ford"] << "\n";
	std::cout << "Has Audi: " << myCarPrices.Has("Audio") << "\n";
	std::cout << "Price of a Audi: " << myCarPrices["Audi"] << "\n";
	std::cout << "Has Audi: " << myCarPrices.Has("Audio") << "\n";
	std::cout << "Price of Kia: " << myCarPrices["Kia"] << "\n";

	std::cout << "Number of Cars: " << myCarPrices.Count() << "\n";
	myCarPrices.Remove("Ford");
	std::cout << "Number of Cars: " << myCarPrices.Count() << "\n";

	int outValue = 0;
	if (myCarPrices.Find("Honda", outValue))
	{

	}
}


int main()
{
	//Exercise1_SortCheck();
	//Exercise2_CheckUnorderedMap();
	Exercise3_CheckUnorderedString();

	return 0;
}