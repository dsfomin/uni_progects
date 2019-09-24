#ifndef LIST_H
#define LIST_H

using namespace std;

// Шаблонный класс односвязного списка
template<typename T>
class List
{
public:
	// Контейнер по умолчанию
	List();

	// Удаление первого элемента в списке
	void pop_front();

	// Добавление элемента в конец списка
	void push_back(T data);

	// Очистить список
	void clear();

	// Получить количество елементов в списке
	int GetSize() { return Size; }

	// Перегруженный оператор [] 
	T& operator[](const int index);

	// Добавление элемента в начало списка
	void push_front(T data);

	// Добавление элемента в список по указанному индексу
	void insert(T data, int index);

	// Удаление элемента в списке по указанному индексу
	void removeAt(int index);

	// Удаление последнего элемента в списке
	void pop_back();

	// Сортировка 1)
	void insertionSort();

private:

	// Шаблонный класс Ноды
	template<typename T>
	class Node
	{
	public:
		Node * pNext; // Указатель на следующий елемент списка
		T data; // Значение, которое храниться в даной Ноде списка

		// Конструктор 
		Node(T data = T(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size; // Размер списка
	Node<T> *head; // Указатель на голову списка
};


template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;

	head = head->pNext;

	delete temp;

	Size--;

}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T> *current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}
	Size++;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}


template<typename T>
T & List<T>::operator[](const int index)
{
	int counter = 0;

	Node<T> *current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T> *previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T> *newNode = new Node<T>(data, previous->pNext);

		previous->pNext = newNode;

		Size++;
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}


		Node<T> *toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}

}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

template<typename T>
void List<T>::insertionSort()
{
	int i, j;
	Date key;
	for (i = 1; i < this->Size; i++)
	{
		key = this[0][i];
		j = i - 1;

		while (j >= 0 && this[0][j] > key)
		{
			this->removeAt(j + 1);
			this->insert(this[0][j], j + 1);
			j = j - 1;
		}
		this->removeAt(j + 1);
		this->insert(key, j + 1);
	}
}

#endif