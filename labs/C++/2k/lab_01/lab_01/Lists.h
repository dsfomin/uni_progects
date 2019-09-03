#pragma once

const int MAX = 100;

template <typename T>
class LinkedList {
public:
	T GetData() { return this->data; }
	LinkedList GetNext() { return this->next; }
private:
	T data;
	LinkedList* next;
};

template <typename T>
class MassList {
public:
	*T GetMass() { return list; }
private:
	T *list = new T[MAX];
};