#include<iostream>
using namespace std;


void print(string s, int arr[], int n)
{
	cout << s << "->  ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void bubblesort(int arr[], int n)
{
	int* temp = arr;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (temp[j] > temp[j+1])
			{
				int carry = temp[j];
				temp[j] = temp[j+1];
				temp[j+1] = carry;
			}
		}
	}
	print("Bubble Sort", temp, n);
}

void selectionSort(int arr[],int n) {
	int* cpy = arr;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (cpy[j] < cpy[i])
			{
				int carry = cpy[j];
				cpy[j] = cpy[i];
				cpy[i] = carry;
			}
		}

	}
	print("Selection Sort", cpy, n);
}

void InsertionSort(int arr[], int n) {
	int* cpy = arr;
	for (int i =1; i < n; i++)
	{
		int insert = i;
		int curritem = cpy[i];
		while (insert > 0 && curritem < cpy[insert-1]) {
			cpy[insert] = cpy[insert - 1];
			insert--;
		}
		cpy[insert] = curritem;
	}
	print("Insertion Sort", cpy, n);
}

void merge(int* cpy, int lower, int mid, int upper)
{
	int n, m, i, j, k;
	n = mid - lower + 1;
	m = upper - mid;
	auto const subArrOne = mid - lower + 1;
	auto const subArrTwo = upper - mid;
	int* a = new int[subArrOne];
	int* b = new int[subArrOne];
	for (i = 0; i < n; i++)
		a[i] = cpy[lower + i];
	for (j = 0; j < m; j++)
		b[j] = cpy[mid + 1 + j];
	i = 0; j = 0; k = lower;
	while (i < n && j < m)
	{
		if (a[i] < b[j])
		{
			cpy[k] = a[i];
			i++;
		}
		else
		{
			cpy[k] = b[j];
			j++;
		}
		k++;
	}
	while (i < n)
	{
		cpy[k] = a[i];
		k++; i++;
	}
	while (j < m)
	{
		cpy[k] = b[j];
		k++; j++;
	}

}

void mergeSort(int arr[],int start, int n)
{
	int* cpy = arr;
	if (start < n)
	{
		int mid = (start + n) / 2;
		mergeSort(cpy, start, mid);
		mergeSort(cpy, mid + 1, n);
		merge(cpy, start, mid, n);
	}

	print("Merge Sort", cpy, n);
}



int partition(int arr[], int start, int n)
{
	int pivot = arr[n]; // pivot
	int i = (start - 1); // Index of smaller element and indicates the right position of pivot found so far

	for (int j = start; j <= n - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			int carry = arr[j];
			arr[j] = arr[i];
			arr[i] = carry;
		}
	}
	int carry = arr[i+1];
	arr[i+1] = arr[n];
	arr[n] = carry;
	return (i + 1);
}

void QuickSort(int arr[], int start, int n)
{
	int* cpy = arr;

	if (start < n)
	{
		
		int pi = partition(arr, start, n);

		QuickSort(arr, start, pi - 1);
		QuickSort(arr, pi + 1, n);
	}
	print("Quick Sort", cpy, n);
}
int main() {
	int arr[] = { 20,40,50,60,70,80,10,5,9,0,15,27,35,42 };
	int n = sizeof(arr) / sizeof(arr[0]);
	bubblesort(arr,n);
	selectionSort(arr, n);
	InsertionSort(arr, n);
	mergeSort(arr, 0, n - 1);
	QuickSort(arr,0, n-1);
}

//count,radix,bucket,