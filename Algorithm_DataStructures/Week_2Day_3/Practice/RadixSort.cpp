#include<iostream>
#include<algorithm>
using namespace std;



void printr(string s, int arr[], int n)
{
	cout << s << "->  ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void countSort(int arr[], int n, int exp)
{

	int* output = new int[n];
	int  count[10] = { 0 };


	for (int i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];


	for (int i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (int i = 0; i < n; i++)
		arr[i] = output[i];
}

void RadixSort(int arr[], int n) {
	int* cpy = arr;

	int m = *max_element(arr, arr + n);
	for (int i = 1; m / i > 0; i *= 10)
		countSort(arr, n, i);
	printr("radix Sort", cpy, n);

}


int main() {
	int arr[] = { 20,40,50,60,70,80,10,5,9,0,15,27,35,42 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printr("radix Sort", arr, n);
	RadixSort(arr, n);
}