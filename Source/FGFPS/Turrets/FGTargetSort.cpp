#pragma once
#include "FGTargetSort.h"


TargetSorting::TargetSorting()
{
}

TargetSorting::~TargetSorting()
{
}

void TargetSorting::TargetQuickSort(int *arr, int low, int high)
{
	if (low < high)
	{
		int partidx = Partition(arr, low, high);
		TargetQuickSort(arr, low, partidx - 1);
		TargetQuickSort(arr, partidx + 1, high);
	}
}

int TargetSorting::Partition(int *arr, int low, int high)
{
	int pivot = arr[high]; // pivot point
	int i = (low - 1); // index for smaller elements

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			Swapping(&arr[i], &arr[j]);
		}
	}
	Swapping(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void TargetSorting::Swapping(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp; 
	*yp = temp;
}

