#include<iostream>
using namespace std;
void reverse_print(int *arr,int size);
void reverse_inArray(int *arr, int n);
void reverse();

int main()
{
	reverse();

} 

void reverse() {
	int arr[3] = { 6, 5, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	reverse_print(arr,n);
	reverse_inArray(arr,n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ",";
	}

	
}
void reverse_print(int* arr,int size) {
	cout << "Printing array in revrse \n";
	
	for (int i = size-1; i >= 0; i--)
	{
		cout << arr[i] << ",";
	}
	cout << "\n";

}
void reverse_inArray(int* arr, int n) {
	cout << "reversing array using the pointer\n";
	int start = 0,end = n-1;
	while (start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
	
}