#include<iostream>
using namespace std;
struct Node {
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

void insertAtfirst(Node** head, int value) {
	Node* newNode = new Node(value);
	if (*head == NULL)
	{
		*head = newNode;
		return;
	}
	newNode->next = *head;
	*head = newNode;
	return;
}

void insertAtPosition(Node** head, int value, int position) {
	Node* newNode = new Node(value);
	if (*head == NULL)
	{
		*head = newNode;
		return;
	}
	Node* temp = *head;
	int count = 1;
	while (count!=(position-1) )
	{
		temp = temp->next;
		count++;
	}
	newNode->next = temp->next;
	temp->next = newNode;
	
}

void deleteFirst(Node** head) {
	if (*head == NULL)
	{
		return;
	}
	Node* temp = *head;
	*head = temp->next;
}
void deleteEnd(Node** head) {
	if (*head == NULL)
	{
		return;
	}
	Node* temp = *head;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = NULL;
}

void deletePos(Node** head, int pos) {
	if (*head == NULL)
	{
		return;
	}
	Node* temp = *head;
	int count = 1;
	while (count != (pos - 1)) {
		temp = temp->next;
		count++;
	}
	temp->next = temp->next->next;
}
void reverse(Node** head) {
	Node* temp = *head;
	Node* prev = NULL, *next = NULL;
	while (temp != NULL)
	{
		next = temp->next;

		temp->next = prev;

		prev = temp;
		temp = next;
		
	}
	*head = prev;
}
void printNode(Node** head) {
	Node* temp = *head;
	while (temp != NULL)
	{
		cout << temp->value << "\n";
		temp = temp->next;
	}
	cout << "\n";
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
	insertAtfirst(&head, 100);
	printNode(&head);
	insertAtPosition(&head, 120, 4);
	printNode(&head);
	deleteFirst(&head);
	printNode(&head);
	deleteEnd(&head);
	printNode(&head);
	deletePos(&head,4);
	printNode(&head);
	reverse(&head);
	printNode(&head);
	
}