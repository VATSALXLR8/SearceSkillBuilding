#include<iostream>
#include"stack.cpp"
using namespace std;
void operations() {
	int n;
	cin >> n;
	CustomStack c(n);
	for (int i = 0; i < n; i++)
	{
		int opr;
		cin >> opr;
		if (opr == 1)
		{
			int value;
			cin >> value;
			c.push(value);
		}
		else if (opr == 2)
		{
			c.pop();
		}
		else if (opr == 3)
		{
			c.maximum();
		}
		else
		{
			cout << "invalid operation";
		}
	}
	c.print();
}
int main() {
	operations();
}