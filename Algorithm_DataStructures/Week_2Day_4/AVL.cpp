#include<iostream>
using namespace std;
struct BT {
	int value;
	BT* LC;
	BT* RC;
	int height;
	BT(int newValue) {
		this->value = newValue;
		this->RC = NULL;
		this->LC = NULL;
		this->height = 1;
	}
};

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int height(BT* N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

BT* rightRotate(BT* y)
{
	BT* x = y->LC;
	BT* T2 = x->RC;

	// Perform rotation
	x->RC = y;
	y->LC = T2;

	// Update heights
	y->height = max(height(y->LC),
		height(y->RC)) + 1;
	x->height = max(height(x->LC),
		height(x->RC)) + 1;

	// Return new root
	return x;
}

BT* leftRotate(BT* x)
{
	BT* y = x->RC;
	BT* T2 = y->LC;

	// Perform rotation
	y->LC = x;
	x->RC = T2;

	// Update heights
	x->height = max(height(x->LC),
		height(x->RC)) + 1;
	y->height = max(height(y->LC),
		height(y->RC)) + 1;

	// Return new root
	return y;
}

int getBalance(BT* N)
{
	if (N == NULL)
		return 0;
	return height(N->LC) - height(N->RC);
}

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
	else
		return root;

	root->height = 1 + max(height(root->LC),
		height(root->RC));

	int balance = getBalance(root);
	if (balance > 1 && value < root->LC->value)
		return rightRotate(root);

	// Right Right Case
	if (balance < -1 && value > root->RC->value)
		return leftRotate(root);

	// Left Right Case
	if (balance > 1 && value > root->LC->value)
	{
		root->LC = leftRotate(root->LC);
		return rightRotate(root);
	}

	// Right Left Case
	if (balance < -1 && value < root->RC->value)
	{
		root->RC = rightRotate(root->RC);
		return leftRotate(root);
	}

	/* return the (unchanged) node pointer */
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

void preOrder(BT* root) {
	if (root != NULL)
	{
		cout << root->value << " ";
		inorderPrint(root->LC);
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
	cout << "\n";
	preOrder(root);
}