#include<iostream>
#include<list>
using namespace std;

class Hash
{

public:

	Hash(int b)
	{
		this->size = b;
		table = new list<int>[size];
	}

	void insertItem(int key)
	{
		int index = hashFunction(key);
		table[index].push_back(key);
	}

	
	void deleteItem(int value)
	{
		int index = hashFunction(value);

		
		list <int> ::iterator i;
		for (i = table[index].begin();
			i != table[index].end(); i++) {
			if (*i == value)
				break;
		}

		
		if (i != table[index].end())
			table[index].erase(i);
	}


	int hashFunction(int value) {
		return (value % size);
	}

	void displayHash() {
		for (int i = 0; i < size; i++) {
			cout << i;
			for (auto x : table[i])
				cout << " - " << x;
			cout << endl;
		}
	}
private:
	int size;
	list<int>* table;
};

int main()
{
	
	int a[] = { 12,9,12,10, 9 , 4 , 1, 25,  15, 11, 27, 8,  20, 17, 14, 20, };
	int n = sizeof(a) / sizeof(a[0]);

	
	Hash hc(7); 
	for (int i = 0; i < n; i++)
		hc.insertItem(a[i]);

	hc.deleteItem(12);
	hc.displayHash();

}
