#include <iostream>
using namespace std;

struct node
{
	int val;
	node* L;
	node* R;
	node* F;
	int h;
};

int max(int a, int b) {
	return (a > b) ? a : b;
}

int height(node* N) {
	if (N == NULL)
		return 0;
	return N->h;
}

node* newNode(int key) 
{
	node* node2 = new node;
	node2->val = key;
	node2->L = NULL;
	node2->R = NULL;
	node2->F = NULL;
	node2->h = 1;
	return (node2);
}

node* rightRotate(node* y) {
	node* x = y->L;
	node* T2 = x->R;
	x->R = y;
	y->L = T2;
	y->h = max(height(y->L),
		height(y->R)) +
		1;
	x->h = max(height(x->L),
		height(x->R)) +
		1;
	return x;
}

node* leftRotate(node* x) {
	node* y = x->R;
	node* T2 = y->L;
	y->L = x;
	x->R = T2;
	x->h = max(height(x->L),
		height(x->R)) +
		1;
	y->h = max(height(y->L),height(y->R)) +
		1;
	return y;
}

int getBalanceFactor(node* N) {
	if (N == NULL)
		return 0;
	return height(N->L) - height(N->R);
}

node* insertNode(node* node, int key) {

	if (node == NULL)
		return (newNode(key));
	if (key < node->val)
		node->L = insertNode(node->L, key);
	else if (key > node->val)
		node->R = insertNode(node->R, key);
	else
		return node;

	node->h = 1 + max(height(node->L),height(node->R));
	int balanceFactor = getBalanceFactor(node);
	if (balanceFactor > 1) {
		if (key < node->L->val) {
			return rightRotate(node);
		}
		else if (key > node->L->val) {
			node->L = leftRotate(node->L);
			return rightRotate(node);
		}
	}
	if (balanceFactor < -1) {
		if (key > node->R->val) {
			return leftRotate(node);
		}
		else if (key < node->R->val) {
			node->R = rightRotate(node->R);
			return leftRotate(node);
		}
	}
	return node;
}

node* Max(node* root)
{
	if (root)
	{
		while (root->R)
		{
			root = root->R;
		}
		return root;
	}
}

node* Min(node* root)
{
	if (root)
	{
		while (root->L)
		{
			root = root->L;
		}
		return root;
	}
}

node* Wyszukaj(int x, node* root)
{
	if (root)
	{
		while (root->val != x && root != NULL)
		{
			if (x >= root->val) { root = root->R; }
			else { root = root->L; }
		}

		if (root == NULL) { cout << "nie znaleziono" << endl; }
		else
		{
			return root;
		}
	}
}

node* WyszukajR(int x, node* root)
{
	if (root)
	{

		if (root->val != x)
		{
			if (x >= root->val) { root = root->R; WyszukajR(x, root); }
			else { root = root->L; WyszukajR(x, root); }
		}
		else
		{
			return root;
		}
	}

}


node* deleteNode(node* root, int key)
{

	if (root)
	{
		if (key < root->val)
		{

			root->L = deleteNode(root->L, key);
		}
		else if (key > root->val)
		{
			root->R = deleteNode(root->R, key);
		}
		else {

			if (root->L == NULL and root->R == NULL)
			{
				return NULL;
			}
			else if (root->L == NULL)
			{
				node* temp = root->R;
				free(root);
				return temp;
			}
			else if (root->R == NULL)
			{
				node* temp = root->L;
				free(root);
				return temp;
			}

			node* temp = Min(root->R);

			root->val = temp->val;

			root->R = deleteNode(root->R, temp->val);
		}
		return root;
	}

	root->h = 1 + max(height(root->L), height(root->R));
	int balanceFactor = getBalanceFactor(root);
	if (balanceFactor > 1) {
		if (key < root->L->val) {
			return rightRotate(root);
		}
		else if (key > root->L->val) {
			root->L = leftRotate(root->L);
			return rightRotate(root);
		}
	}
	if (balanceFactor < -1) {
		if (key > root->R->val) {
			return leftRotate(root);
		}
		else if (key < root->R->val) {
			root->R = rightRotate(root->R);
			return leftRotate(root);
		}
	}
	return root;
}


void INORDER(node* root)
{
	if (root)
	{
		INORDER(root->L);
		cout << root->val << "	";
		INORDER(root->R);
	}

}

void printTree(node* root, string indent, bool last) {
	if (root != nullptr) {
		cout << indent;
		if (last) {
			cout << "R----";
			indent += "   ";
		}
		else {
			cout << "L----";
			indent += "|  ";
		}
		cout << root->val << endl;
		printTree(root->L, indent, false);
		printTree(root->R, indent, true);
	}
}

int main()
{
	node* root = NULL;

	root = insertNode(root, 33);
	root = insertNode(root, 13);
	root = insertNode(root, 53);
	root = insertNode(root, 9);
	root = insertNode(root, 21);
	root = insertNode(root, 61);
	root = insertNode(root, 8);
	root = insertNode(root, 11);
	printTree(root, "", true);
	cout << endl;
	INORDER(root);
	cout << endl;
	root = deleteNode(root, 13);
	printTree(root, "", true);
	cout << endl;
	INORDER(root);
	system("pause");
	return 0;
}