#ifndef _LIB_OF_SORTS_H
#define _LIB_OF_SORTS_H

#include <iostream>
#include "Graph.h"
#include "List.h"

using namespace std;

int CountOfNeighbours(Graph g, int _a) {
	List<int> n = g.FindNeighbours(_a);
	return n.GetSize();
}

int SumOfNeighbours(Graph g, int _a) {
	int r = 0;
	List<int> n = g.FindNeighbours(_a);
	for (int i = 0; i < n.GetSize(); i++) {
		r += g.GetLenghtOfEdge(n[i], _a);
	}
	return r;
}

List<int> insertionSort(Graph g)
{
	List<int> v = g.ListOfVertices();
	List<int> nb;
	for (int i = 0; i < v.GetSize(); i++) {
		nb.push_back(CountOfNeighbours(g, v[i]));
	}
	int i, key, keyv, j;
	for (i = 1; i < nb.GetSize(); i++) {
		key = nb[i];
		keyv = v[i];
		j = i - 1;

		while (j >= 0 && nb[j] > key) {
			nb.removeAt(j + 1);
			nb.insert(nb[j], j + 1);
			v.removeAt(j + 1);
			v.insert(v[j], j + 1);
			j = j - 1;
		}
		nb.removeAt(j + 1);
		nb.insert(key, j + 1);
		v.removeAt(j + 1);
		v.insert(keyv, j + 1);
	}
	return v;
}

void swap_edge(Edge* a, Edge* b)
{
	Edge t = *a;
	*a = *b;
	*b = t;
}

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

List<int> bubbleSort(Graph g)
{
	List<int> v = g.ListOfVertices();
	List<int> nb;
	for (int i = 0; i < v.GetSize(); i++) {
		nb.push_back(SumOfNeighbours(g, v[i]));
	}
	for (int i = 0; i < v.GetSize() - 1; i++) {
		for (int j = 0; j < v.GetSize() - i - 1; j++) {
			if (nb[j] > nb[j + 1]) {
				swap(&nb[j], &nb[j + 1]);
				swap(&v[j], &v[j + 1]);
			}
		}
	}
	return v;
}

int partition(List<Edge>& arr, int low, int high)
{
	int pivot = arr[high].len;
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j].len <= pivot)
		{
			i++;
			swap_edge(&arr[i], &arr[j]);
		}
	}
	swap_edge(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(List<Edge>& arr, int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
#endif