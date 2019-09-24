#ifndef MASSLIST_H
#define MASSLIST_H

#pragma once

template <typename T>
class MassList
{
public:
	// Конструктор по умолчанию
	MassList() {};

	// Получить массив
	T* GetMass() { return this->list; }

	// Получить количество елементов
	int GetSize() { return this->size; }

	// Добавление в конец списка
	void push_back(T data);

	// Удаление вконце списка
	void pop_back();

	// Сортировка 1)
	void insertionSort();

private:
	// Список ввиде массива
	T *list = new T[MAX];

	// Размер массива
	int size = 0;
};

template<typename T>
void MassList<T>::push_back(T data)
{
	this->GetMass()[this->GetSize()] = T;
	this->size++;
}

template<typename T>
void MassList<T>::pop_back()
{
	this->size--;
}

template <class T>
void swap(T* a, T* b)
{
	T t = *a;
	*a = *b;
	*b = t;
}

template<typename T>
void MassList<T>::insertionSort()
{
	int *arr = this->GetMass();
	int n = this->GetSize() - 1;
	int i, j;
	Date key;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}


#endif