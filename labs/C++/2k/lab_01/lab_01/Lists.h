#pragma once

const int MAX = 100;

template <typename T>
class LinkedList {
public:
	LinkedList() {};
	LinkedList(T data, LinkedList* next = nullptr) {
			this->data = data;
			this->next = next;
	}
	void push_back(T data);
	T& operator[](const int index);
	void insert(T data, int index);
	void removeAt(int index);
	void pop_back();
	T GetData() { return this->data; }
	LinkedList GetNext() { return this->next; }
	int GetSize() { return this->size; }
private:
	T data;
	LinkedList* next;
	LinkedList* head = nullptr;
	int size = 0;
};

template <typename T>
class MassList {
public:
	MassList() {};
	T* GetMass() { return this->list; }
	int GetSize() { return this->size; }
private:
	T *list = new T[MAX];
	int size = 0;
};


