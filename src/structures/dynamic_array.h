#pragma once

#include <iostream>

//The special delete and new operator usage is meant to avoid calling destructor and constructor on inner objects so that we can take complete 
//Responsibility for the lifetime of these objects
template <typename T>
class darray
{
private:
	T* buffer;
	int capacity;
	int size;

	void enlarge(unsigned int slotCount) {
		T* oldBoi = buffer;

		//Increased Capacity
		capacity += slotCount;
		//Allocate new Block
		//Don't call the Destructor on inner objects
		buffer = (T*) ::operator new(capacity * sizeof(T));

		for (int i = 0; i < size; i++) {
			buffer[i] = std::move(oldBoi[i]);
		}

		//Call the destructor on each element
		for (int i = 0; i < size; i++)
			buffer[i].~T();

		//Don't call the Destructor on inner objects
		::operator delete[](oldBoi, capacity * sizeof(T));
	}

public:
	darray() {
		buffer = nullptr;
		capacity = 0;
		size = 0;
	}

	darray(unsigned int initialSize) {
		capacity = initialSize;
		buffer = new T[initialSize];
		size = 0;
	}

	darray(unsigned int initialSize, T defaulto) {
		capacity = initialSize;
		buffer = new T[initialSize];
		size = initialSize;
		for (int i = 0; i < capacity; i++) {
			buffer[i] = defaulto;
		}
	}

	darray(darray<T>& wector) {
		this->size = wector.size;
		this->capacity = wector.capacity;
		for (int i = 0; i < size; i++) {
			buffer[i] = wector.buffer[i];
		}
	}

	~darray() {
		clear();
		//Don't call the Destructor on inner objects
		::operator delete[](buffer, capacity * sizeof(T));
	}

	void add(T element) {
		if (size >= capacity)
			enlarge(capacity / 2);
		
		buffer[size] = element;
		size++;
	}

	void add(T&& element) {
		if (size >= capacity)
			enlarge(capacity / 2);
		
		buffer[size] = std::move(element);
		size++;
	}

	template <typename... ARGS>
	T& emplace(ARGS&&... args) {
		if (size >= capacity)
			enlarge(capacity / 2);

		//THE FUCK?
		//new(&buffer[size]) T(std::forward<ARGS>(args)...)
		buffer[size] = T(std::forward<ARGS>(args)...);
		return buffer[size++];
	}

	void remove_last() {
		if (size > 0) {
			size--;
			//Explicitly calling the destructor on T so that when we remove it from the array we also deallocate its memory
			buffer[size].~T();
		}
	}

	void clear() {
		for (int i = 0; i < size; i++)
			buffer[i].~T();

		size = 0;
	}

	void reserve_slots(int count) {
		int freeSlots = capacity - size;
		int toReserve = freeSlots - count;

		if (toReserve > 0)
			enlarge(static_cast<unsigned int>(toReserve));
	}

	size_t size() const {
		return size;
	}

	T& operator[](unsigned int index) {
		if (index >= size)
			throw std::out_of_range("Index is out of bounds (max index should be " + (size - 1) + ')');
		return buffer[index];
	}
	const T& operator[](unsigned int index) const {
		if (index >= size)
			throw std::out_of_range("Index is out of bounds (max index should be " + (size - 1) + ')');
		return buffer[index];
	}

};

