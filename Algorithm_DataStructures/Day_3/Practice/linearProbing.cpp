#include<iostream>
using namespace std;
class linearProbing {
public:
	linearProbing(int size) {
		n = size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
			arr[i] = 0;
	}

	int hashFunction(int value) {
		return (value % n);
	}
	void insert(int value)
	{
		int i = hashFunction(value);
		if(arr[i]==0)
			arr[i] = value;
		else {
			while (arr[i] != 0)
			{
				i++;
				if (i > n) {
					i = 0;
				}

			}
			arr[i] = value;
		}

	}
	void print() {
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
private:
	int* arr;
	int n;
};

int main() {
	linearProbing lr(11);
	lr.insert(21);
	lr.insert(42);
	lr.print();
	lr.insert(31);
	lr.print();
	lr.insert(12);
	lr.insert(54);
	lr.insert(20);
	lr.print();

}