#ifndef LISTS_H
#define LISTS_H

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
	LinkedList* GetNext() { return this->next; }
	int GetSize() { return this->size; }
private:
	T data;
	LinkedList* next;
	LinkedList* head = nullptr;
	int size = 0;
};

template<typename T>
void LinkedList<T>::insert(T data, int index)
{
	if (index == 0) {
		this->head = new LinkedList(data, head);
		this->size++;
	}
	else {
		LinkedList *previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->GetNext();
		}

		LinkedList *newNode = new LinkedList(data, previous->GetNext);

		previous->GetNext() = newNode;

		size++;
	}
}

template<typename T>
void LinkedList<T>::removeAt(int index)
{
	if (index == 0)
	{
		removeAt(0);
	}
	else
	{
		LinkedList *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->next;
		}


		LinkedList *toDelete = previous->GetNext();

		previous->next = toDelete->next;

		delete toDelete;

		size--;
	}
}

template<typename T>
void LinkedList<T>::pop_back()
{
	removeAt(size - 1);
}

template <class T>
T& LinkedList<T>::operator[](const int index) {
	int counter = 0;

	LinkedList *current = this->head;

	while (current != nullptr) {
		if (counter == index) return current->data;
		current = current->next;
		counter++;
	}
}

template <class T>
void LinkedList<T>::push_back(T data) {
	if (head == nullptr)
	{
		head = new LinkedList(data);
	}
	else
	{
		LinkedList *current = this->head;

		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = new LinkedList(data);

	}
	size++;
}
#endif
