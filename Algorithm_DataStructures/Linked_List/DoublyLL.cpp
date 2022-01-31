#include<iostream>
using namespace std;
struct Node {
public:
	int value;
	Node* next;
	Node* prev;
	Node(int newValue) {
		this->value = newValue;
		this->next = NULL;
		this->prev = NULL;
	}
};
void insertAtEnd(Node** head,Node** tail, int value) {
	Node* newNode = new Node(value);
	if (*head == NULL)
	{
		*head = newNode;
		*tail = newNode;
		return;
	}
	(*tail)->next = newNode;
	newNode->prev = *tail;
	(*tail) = newNode;

}
void print(Node** head){
	Node* temp = *head;
	while (temp != NULL)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << "\n";
}
void reversePrint(Node** tail) {
	Node* temp = *tail;
	while (temp != NULL)
	{
		cout << temp->value << " ";
		temp = temp->prev;
	}
	cout << "\n";
}
int main() {
	Node* head = NULL;
	Node* tail = NULL;
	insertAtEnd(&head,&tail, 20);
	insertAtEnd(&head, &tail, 30);
	insertAtEnd(&head, &tail, 40);
	insertAtEnd(&head, &tail, 50);
	insertAtEnd(&head, &tail, 60);
	insertAtEnd(&head, &tail, 70);
	insertAtEnd(&head, &tail, 20);
	print(&head);
	reversePrint(&tail);
}