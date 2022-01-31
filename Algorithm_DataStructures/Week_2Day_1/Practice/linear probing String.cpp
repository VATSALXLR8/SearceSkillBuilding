#include<iostream>
using namespace std;
struct stringcount {
	int count;
	char value;
};
class linearProbing {
public:
	linearProbing(int size) {
		n = size;
		arr = new stringcount[size];
		for (int i = 0; i < size; i++)
		{
			arr[i].count = 0;
			arr[i].value = NULL;
		}
	}

	int hashFunction(int value) {
		return (value % n);
	}
	void insert(char value)
	{
		int i = hashFunction(value);
			arr[i].count = arr[i].count+1;
			arr[i].value = value;
	}
	void print() {
		for (int i = 0; i < n; i++)
		{
			cout << "value = " << arr[i].value << " count = " << arr[i].count <<"\n";
		}
		cout << "\n";
	}
	void max() {
		int i = 0;
		int max = 0;
		int j = 0;
		for (; i < n; i++)
		{
			if (arr[i].value != NULL)
			{
				if (arr[i].count > max)
				{
					max = arr[i].count;
					j = i;
				}
			}
			
		}
		cout << "Maximum Ocurrence of value = " << arr[j].value << " count = " << arr[j].count << "\n";
	}
private:
	stringcount* arr;
	int n;
};

int main() {
	linearProbing lr(32);
	char arr[] = "vatsal";
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i=0;i<n;i++)
		lr.insert(arr[i]);
	lr.print();
	lr.max();

}