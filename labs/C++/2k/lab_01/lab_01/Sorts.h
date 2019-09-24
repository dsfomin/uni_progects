#ifndef SORTS_H
#define SORST_H

#pragma once
#include "Date.h"
#include "Lists.h"
#include <vector>

// Standart Vector

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

// 

// Linked List

// InsertionSort

void linkedListInsertionSort(List<Date> l, int n);

// MergeSort

void linkedListMerge(List<Date> list, int l, int m, int r);
void linkedListMergeSort(List<Date> list, int l, int r);

// QuickSort

int linkedListPartition(vector<Date>& arr, int low, int high);
void linkedListQuickSort(vector<Date>& arr, int low, int high);

#endif