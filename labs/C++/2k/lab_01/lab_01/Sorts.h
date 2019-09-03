#pragma once

// InsertionSort

void insertionSort(int arr[], int n);

// QuickSort

void swap(int* a, int* b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

// MergeSort

void merge(int arr[], int l, int m, int r);
void mergeSort(int arr[], int l, int r);