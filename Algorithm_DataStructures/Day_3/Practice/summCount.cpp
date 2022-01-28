#include<iostream>
#include<unordered_map>
using namespace std;
int getPairsCount(int arr[], int sum, int n) {
	unordered_map<int, int> m;
	//marking position for value count eg if 1 repeats 3 times so key 1 will have value 3
	for (int i = 0; i < n; i++)
		m[arr[i]]++;

	int count = 0;

	for (int i = 0; i < n; i++) {
		//counting the value eg if 11 - 10 = 1 so at key value 1 we will add the count of 1 to totalcount which is 3
		count += m[sum - arr[i]];

		//if same value addition then it shouldnt be counted eg if sum == 12 and value in array is 6 so 
		//6 is counted and its against rule of question 
		if (sum - arr[i] == arr[i])
			count--;
		
	}
	//because once it was counted when pointer was at 12 and once again when pointer was at -1 as it is pair we want once
	return count / 2;
}
int main() {
	int arr[] = { 10, 12, 10, 15, -1, 7, 6,
				   5, 4, 2, 1, 1, 1 };
	cout<< getPairsCount(arr, 11, 13);
}