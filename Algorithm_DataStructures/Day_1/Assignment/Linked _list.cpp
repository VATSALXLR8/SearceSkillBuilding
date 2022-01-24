#include<iostream>
using namespace std;
class Node {
public:
	int value;
	Node* next;
	Node(int newValue) {
		this->value = newValue;
		this->next = NULL;
	}
};
void addNode(Node** head , int value) {
	Node* newNode = new Node(value);
	Node* last = *head;
	if (*head == NULL)
	{
		*head = newNode;
		return;
	}
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = newNode;
	return;
}
void printNode(Node** head) {
	Node* temp = *head;
	while (temp != NULL)
	{
		cout << temp->value << "\n";
		temp = temp->next;
	}
}
int main()
{
	Node* head = NULL;
	int n;
	cin >> n;
	
	for (int i = 0; i <= n; i++)
	{
		int value;
		cin >> value;
		addNode(&head, value);
	}
	printNode(&head);
	
}