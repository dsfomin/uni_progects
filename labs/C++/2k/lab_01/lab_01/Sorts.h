#ifndef SORTS_H
#define SORST_H

#pragma once
#include "Date.h"
#include <vector>

// InsertionSort

void insertionSort(vector<class Date>& arr, int n);

// QuickSort

template <class T>
void swap(T* a, T* b);

int partition(vector<class Date>& arr, int low, int high);
void quickSort(vector<class Date>& arr, int low, int high);

// MergeSort

void merge(vector<class Date>& arr, int l, int m, int r);
void mergeSort(vector<class Date>& arr, int l, int r);

#endif