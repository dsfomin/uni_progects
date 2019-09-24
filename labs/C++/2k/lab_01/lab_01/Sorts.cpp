#include "Sorts.h"
#include "Date.h"
#include <vector>

// InsertionSort

void insertionSort(vector<Date>& arr, int n)
{
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

// QuickSort

template <class T>
void swap(T* a, T* b)
{
	T t = *a;
	*a = *b;
	*b = t;
}

int partition(vector<Date>& arr, int low, int high)
{
	Date pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(vector<Date>& arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

// MergeSort

void merge(vector<Date>& arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	Date *L = new Date[n1];
	Date *R = new Date[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] < R[j] || L[i] == R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(vector<Date>& arr, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void linkedListInsertionSort(List<Date> l, int n)
{
	int i, j;
	Date key;
	for (i = 1; i < n; i++)
	{
		key = l[i];
		j = i - 1;


		while (j >= 0 && l[j] > key)
		{
			l.removeAt(j + 1);
			l.insert(l[j], j + 1);
			j = j - 1;
		}
		l.removeAt(j + 1);
		l.insert(key, j + 1);
	}
}


void linkedListMerge(List<Date> list, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	Date *L = new Date[n1];
	Date *R = new Date[n2];

	for (i = 0; i < n1; i++)
		L[i] = list[l + i];
	for (j = 0; j < n2; j++)
		R[j] = list[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] < R[j] || L[i] == R[j])
		{
			list.removeAt(k);
			list.insert(L[i],k);
			i++;
		}
		else
		{
			list.removeAt(k);
			list.insert(R[j], k);
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		list.removeAt(k);
		list.insert(L[i], k);
		i++;
		k++;
	}

	while (j < n2)
	{
		list.removeAt(k);
		list.insert(R[j], k);
		j++;
		k++;
	}
}

void linkedListMergeSort(List<Date> list, int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		linkedListMergeSort(list, l, m);
		linkedListMergeSort(list, m + 1, r);

		linkedListMerge(list, l, m, r);
	}
}


int linkedListPartition(vector<Date>& arr, int low, int high)
{
	Date pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void linkedListQuickSort(vector<Date>& arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}