#include<iostream>
using namespace std;
void printh(string s, int arr[], int n)
{
	cout << s << "->  ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void heapify(int arr[], int n, int i)
{
	int largest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;
	
	if (largest != i) {
		swap(arr[i], arr[largest]);

		heapify(arr, n, largest);
	}
}

void HeapSort(int arr[], int n) {

	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i > 0; i--) {
		swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
	printh("HeapSort Sort", arr, n);
}
//int main() {
//	int arr[] = { 20,40,50,60,70,80,10,5,9,0,15,27,35,42 };
//		int n = sizeof(arr) / sizeof(arr[0]);
//		printh("HeapSort Sort", arr, n);
//		HeapSort(arr, n);
//}