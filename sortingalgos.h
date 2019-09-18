#pragma once
#include<iostream>
#include <ctime>
#include<chrono>
using namespace std;
unsigned long int BubbleSort(int arr[], int MAX, unsigned long int counter)//bubble sort
{

	int i, j;
	for (i = 0; i < MAX - 1; i++)
	{
		counter++;
		for (j = 0; j < MAX - i - 1; j++)
		{
			//compare one element to the next, and swap if the next element is less than the current.
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				counter++;
			}
			counter++;
		}
	}
	return counter; //returns step counter
}
int InsertionSort(int arr[], int MAX, int counter) //insertion sort
{
	int i, key, j;
	for (i = 1; i < MAX; i++)
	{
		counter++;
		key = arr[i];
		j = i - 1;
		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key)
		{
			counter++;
			arr[j + 1] = arr[j];
			j = j - 1;

		}
		arr[j + 1] = key;
		counter++;
	}
	return counter; //returns step counter
}
unsigned long int SelectionSort(int arr[], int MAX, unsigned long int counter) //selection sort
{
	int i, j, min;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < MAX - 1; i++)
	{
		counter++;
		// Find the minimum element in unsorted array
		min = i;
		for (j = i + 1; j < MAX; j++)
		{
			counter++;
			if (arr[j] < arr[min])
			{
				min = j;
				counter++;
			}
		}
		// Swap the found minimum element with the first element
		swap(arr[min], arr[i]);
	}
	return counter; //returns step counter value
}
int partition(int arr[], int left, int right, int& count)//partition for quicksort
{
	int mid = left + (right - left) / 2;
	int pivot = arr[mid];
	// move the mid point value to the front.
	swap(arr[mid], arr[left]);
	count++;
	int i = left + 1;
	int j = right;
	while (i <= j)
	{
		count++;
		while (i <= j && arr[i] <= pivot)
		{
			count++;
			i++;
		}

		while (i <= j && arr[j] > pivot)
		{
			count++;
			j--;
		}

		if (i < j)
		{
			count++;
			swap(arr[i], arr[j]);
		}

	}
	swap(arr[i - 1], arr[left]);
	return i - 1; // returns partition point

}
int QuickSort(int arr[], int low, int high, int counter) //quick sort 
{
	if (low >= high)
	{
		return 0;
	}
	counter++;
	int partitionpt = partition(arr, low, high, counter);
	QuickSort(arr, low, partitionpt - 1, counter++);
	QuickSort(arr, partitionpt + 1, high, counter++);
	return counter;//return step counter
}
int merge(int A[], int low, int mid, int high, int count)//array merger for mergesort
{
	int i, j, k;
	int* c = new int[high + 1];
	i = low;
	k = low;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		count++;
		if (A[i] < A[j])
		{
			c[k] = A[i];
			count++;
			k++;
			i++;
		}
		else
		{
			c[k] = A[j];
			count++;
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		count++;
		c[k] = A[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		count++;
		c[k] = A[j];
		k++;
		j++;
	}
	for (i = low; i < k; i++) // Throw the sorted array into the original array
	{
		count++;
		A[i] = c[i];
	}
	delete[]c;
	return count;
}


int MergeSort(int arr[], int low, int high, int counter) //merge sort
{

	if (low >= high)                  //Base case: 1 value to sort->sorted
		return 0;  //(0 possible only on initial call)
	else
	{
		counter++;
		int mid = (low + high) / 2;       //Approximate midpoint
		MergeSort(arr, low, mid, counter++);        //Sort low to mid part of array
		MergeSort(arr, mid + 1, high, counter++);     //Sort mid+1 to high part of array
		counter += merge(arr, low, mid, high, counter); //Merge sorted subparts of array
	}
	return counter;//returns step counter
}
void randomize(int arr[], int n)
{

	// Start from the last element and swap one by one. We don't
	// need to run for the first element that's why i > 0
	for (int i = n - 1; i > 0; i--)
	{
		// Pick a random index from 0 to i
		int j = rand() % (i + 1);
		// Swap arr[i] with the element at random index
		swap(arr[i], arr[j]);
	}
}



