#ifndef LIST_H
#define LIST_H

using namespace std;

// ��������� ����� ������������ ������
template<typename T>
class List
{
public:
	// ��������� �� ���������
	List();

	// �������� ������� �������� � ������
	void pop_front();

	// ���������� �������� � ����� ������
	void push_back(T data);

	// �������� ������
	void clear();

	// �������� ���������� ��������� � ������
	int GetSize() { return Size; }

	// ������������� �������� [] 
	T& operator[](const int index);

	// ���������� �������� � ������ ������
	void push_front(T data);

	// ���������� �������� � ������ �� ���������� �������
	void insert(T data, int index);

	// �������� �������� � ������ �� ���������� �������
	void removeAt(int index);

	// �������� ���������� �������� � ������
	void pop_back();

	// ���������� 1)
	void insertionSort();

private:

	// ��������� ����� ����
	template<typename T>
	class Node
	{
	public:
		Node * pNext; // ��������� �� ��������� ������� ������
		T data; // ��������, ������� ��������� � ����� ���� ������

		// ����������� 
		Node(T data = T(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size; // ������ ������
	Node<T> *head; // ��������� �� ������ ������
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