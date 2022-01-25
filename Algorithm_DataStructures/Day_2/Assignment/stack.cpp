#include<iostream>
using namespace std;
class CustomStack {
public:
	CustomStack(int size) {
		arr = new int[size];
		this->n = size;
		top=-1;
	}
	bool push(int value) {
		if (top == n)
			return false;
		top++;
		arr[top] = value;
		return true;
	}
	bool pop()
	{
		if (top == -1)
			return false;
		top--;
		return true;
	}
	int peek()
	{
		if (top == -1)
			return 0;
		return arr[top];
	}
	void print()
	{
		for (int i = 0; i <= top; i++)
			cout << arr[i] << " ";
	}
	int maximum() {
		int max = arr[0];
		for (int i = 0; i <= top; i++)
		{
			if (arr[i] > max)
				max = arr[i];
		}
		return max;
	}
private:
	int *arr;
	int n;
	int top;
};
//int main() {
//	CustomStack c(5);
//	c.push(2);
//	c.push(3);
//	c.push(4);
//	c.push(5);
//	c.print();
//	c.pop();
//	c.print();
//	cout<<c.peek();
//
//
//
//}