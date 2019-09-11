#ifndef MASSLIST_H
#define MASSLIST_H

#pragma once

template <typename T>
class MassList {
public:
	MassList() {};
	T* GetMass() { return this->list; }
	int GetSize() { return this->size; }
	void push_back(T data);
	void pop_back();
	void insertionSort();
private:
	T *list = new T[MAX];
	int size = 0;
};

#endif