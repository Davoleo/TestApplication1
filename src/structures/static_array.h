#pragma once

#include <iostream>

template<typename T, size_t S>
class sarray
{
private:
	T buffer[S];

public:
	//constexpr because it can be evauluated at compile time
	constexpr unsigned int size() const {
		return S;
	}

	T& operator[](unsigned int index) {
		if (index >= S)
			throw std::exception("Index out of bounds!")
		return buffer[index];
	}

	//Overload for const arrays
	const T& operator[](unsigned int index) const {
		if (index >= S)
			throw std::exception("Index out of bounds!")
		return buffer[index];
	}

	//Returns the raw CArray Pointer
	T* raw() {
		return buffer;
	}
	const T* raw() const {
		return buffer;
	}
};

