#include "Lists.h"

template<typename T>
void LinkedList<T>::insert(T data, int index)
{
	if (index == 0)	push_front(data);
	else {
		LinkedList *previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->GetNext;
		}

		LinkedList *newNode = new LinkedList(data, previous->GetNext);

		previous->GetNext = newNode;

		size++;
	}
}

template<typename T>
void LinkedList<T>::pop_back()
{
	removeAt(size - 1);
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
			previous = previous->GetNext;
		}


		LinkedList *toDelete = previous->GetNext;

		previous->GetNext = toDelete->GetNext;

		delete toDelete;

		size--;
	}

}

template<typename T>
T & LinkedList<T>::operator[](const int index)
{
	int counter = 0;

	LinkedList *current = this->head;

	while (current != nullptr) {
		if (counter == index) return current->data;
		current = current->GetNext;
		counter++;
	}
}

template<typename T>
void LinkedList<T>::push_back(T data) {
	if (head == nullptr)
	{
		head = new LinkedList(data);
	}
	else
	{
		LinkedList *current = this->head;

		while (current->GetNext != nullptr)
		{
			current = current->GetNext;
		}
		current->GetNext = new LinkedList(data);

	}
	size++;
}