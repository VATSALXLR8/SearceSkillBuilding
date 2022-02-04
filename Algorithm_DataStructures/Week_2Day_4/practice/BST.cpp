#include<iostream>
using namespace std;
struct BT {
	int value;
	BT* LC;
	BT* RC;
	BT(int newValue) {
		this->value = newValue;
		this->RC = NULL;
		this->LC = NULL;
	}
};
BT* insert(BT* root, int value) {
	if (root == NULL)
	{
		root = new BT(value);
		return root;
	}
	 if (value < root->value)
		root->LC = insert(root->LC, value);
	 else if (value > root->value)
		root->RC = insert(root->RC, value);
	return root;

}



void inorderPrint(BT* root) {
	if (root != NULL)
	{
		inorderPrint(root->LC);
		cout << root->value << " ";
		inorderPrint(root->RC);
	}
}
int main() {
	BT* root = NULL;
	int n;
		cin >> n;
		
		for (int i = 0; i < n; i++)
		{
			int value;
			cin >> value;
			root = insert(root, value);
		}
		inorderPrint(root);
}