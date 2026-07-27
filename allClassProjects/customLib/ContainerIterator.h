#pragma once

// gives accesibility to iterator functions
// can be tied into and used with std::sorting functions (std::sort, priorityqueue...)
// iterate over containers instead of indexing through them

#include <algorithm>
#include <iterator>
#include <cstddef>

template<typename T>
class ContainerIterator
{
public:
	// defines ids/ names for stl use (std::sort, find, etc)
	using iterator_cotegory = std::random_access_iterator_tag;
	using value_type = T;
	using difference_type = std::ptrdiff_t;
	using pointer = T*;
	using reference = T&;

	ContainerIterator(T* ptr)
		: mPtr(ptr)
	{
	}

	T& operator*() { return *mPtr; }
	T* operator->() { return mPtr; }

	ContainerIterator operator++() { ++mPtr; return *this; } // ++itr
	ContainerIterator operator--() { --mPtr; return *this; } // --itr
	ContainerIterator operator++(int) { ContainerIterator tmp = ++(*this); return tmp; } // itr++
	ContainerIterator operator--(int) { ContainerIterator tmp = ++(*this); return tmp; } // itr--

	// (+ and -) does not modify the object
	ContainerIterator operator+(difference_type n) const { return ContainerIterator(mPtr + n); }
	ContainerIterator operator-(difference_type n) const { return ContainerIterator(mPtr - n); }
	// (+= and -=) modifies the object and returns a reference
	ContainerIterator operator+=(difference_type n) { mPtr += n; return *this; }
	ContainerIterator operator-=(difference_type n) { mPtr -= n; return *this; }

	difference_type operator-(const ContainerIterator& rhs) const { return mPtr - rhs.mPtr; }

	// comparisons
	bool operator==(const ContainerIterator& rhs) const { return mPtr == rhs.mPtr; }
	bool operator!=(const ContainerIterator& rhs) const { return mPtr != rhs.mPtr; }
	bool operator<(const ContainerIterator& rhs) const { return mPtr < rhs.mPtr; }
	bool operator>(const ContainerIterator& rhs) const { return mPtr > rhs.mPtr; }
	bool operator<=(const ContainerIterator& rhs) const { return mPtr <= rhs.mPtr; }
	bool operator>=(const ContainerIterator& rhs) const { return mPtr >= rhs.mPtr; }

private:
	T* mPtr = nullptr;


};