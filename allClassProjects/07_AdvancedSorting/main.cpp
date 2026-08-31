#include <iostream>
#include <Global.h>

void PrintIntVector(Vector<int>& numbers)
{
    for (int i = 0; i < numbers.Size(); ++i)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n";
}

void Exercise1InsertionSort()
{
    std::cout << "Insertion Sort:\n";
    Vector<int> numbers;
    for (int i = 0; i < 20; ++i)
    {
        int value = 1 + (rand() % 100);
        numbers.PushBack(value);
        std::cout << value << " ";
    }
    std::cout << "\n";
    std::cout << "Sorted:\n";
    Global::InsertionSort(numbers.Begin(), numbers.End(), std::greater<int>());
}
void Exercise2MergeSort()
{
    std::cout << "Merge Sort:\n";
    Vector<int> numbers;
    for (int i = 0; i < 20; ++i)
    {
        int value = 1 + (rand() % 100);
        numbers.PushBack(value);
        std::cout << value << " ";
    }
    std::cout << "\n";
    std::cout << "Sorted:\n";
    Global::MergeSort(numbers.Begin(), numbers.End());
    PrintIntVector(numbers);
}
void Exercise3QuickSort()
{
    std::cout << "Quick Sort:\n";
    Vector<int> numbers;
    for (int i = 0; i < 20; ++i)
    {
        int value = 1 + (rand() % 100);
        numbers.PushBack(value);
        std::cout << value << " ";
    }
    std::cout << "\n";
    std::cout << "Sorted:\n";
    Global::QuickSort(numbers.Begin(), numbers.End());
    PrintIntVector(numbers);
}
void Exercise4BucketSort()
{
    std::cout << "Bucket Sort:\n";
    Vector<float> numbers;
    for (int i = 0; i < 20; ++i)
    {
        float value = 20.0f * ((float)rand() / (float)RAND_MAX);
        numbers.PushBack(value);
        std::cout << value << " ";
    }
    std::cout << "\n";
    std::cout << "Sorted:\n";
    Global::BucketSort(numbers.Begin(), numbers.End());
    //PrintIntVector(numbers);
    for (int i = 0; i < numbers.Size(); ++i)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n";
}
void Exercise5HeapSort()
{
    std::cout << "Heap Sort:\n";
    Vector<int> numbers;
    for (int i = 0; i < 20; ++i)
    {
        int value = 1 + (rand() % 100);
        numbers.PushBack(value);
        std::cout << value << " ";
    }
    std::cout << "\n";
    std::cout << "Sorted:\n";
    Global::HeapSort(numbers.Begin(), numbers.End());
    PrintIntVector(numbers);
}
void Exercise6IntroSort()
{
    std::cout << "Intro Sort:\n";
    Vector<int> numbers;
    for (int i = 0; i < 20; ++i)
    {
        int value = 1 + (rand() % 100);
        numbers.PushBack(value);
        std::cout << value << " ";
    }
    std::cout << "\n";
    std::cout << "Sorted:\n";
    Global::IntroSort(numbers.Begin(), numbers.End());
    PrintIntVector(numbers);
}

int main()
{
    srand(time(0));

    //Exercise1InsertionSort();
    //Exercise2MergeSort();
    //Exercise3QuickSort();
    //Exercise4BucketSort();
    //Exercise5HeapSort();
    Exercise6IntroSort();

    return 0;
}