#include "Date.h"
#include "MassList.h"

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
