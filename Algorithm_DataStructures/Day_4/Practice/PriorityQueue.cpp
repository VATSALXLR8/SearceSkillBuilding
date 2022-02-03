//c++ operator overloading compare function
#include <iostream>
#include <queue>
using namespace std;

struct Person {
	int age;
	float height;
	Person(int age, float height)
		: age(age), height(height)
	{
	}
};


struct CompareHeight {
	bool operator()(Person const& p1, Person const& p2)
	{
		return p1.height < p2.height;
	}
};

int main()
{
	priority_queue<Person, vector<Person>, CompareHeight> personQueue;

	
	float arr[5][2] = { { 50, 5 }, { 20, 6 },
					{ 22, 6 }, { 43, 6 }, { 23, 6.6 } };

	for (int i = 0; i < 5; ++i) {
		personQueue.push(Person(arr[i][0], arr[i][1]));

	}

	while (!personQueue.empty()) {
		Person p = personQueue.top();
		personQueue.pop();
		cout << p.age << " " << p.height << "\n";
	}
	return 0;
}
