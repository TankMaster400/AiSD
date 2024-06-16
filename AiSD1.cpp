#include <iostream>
using namespace std;

struct node
{
	int val;
	node* next;
};

void Del(node* &H)
{
	if (H)
	{
		node* P = H;
			H = P->next;
		delete P;
	}
}

void Show(node* H)
{
	cout << "H->";
	node* P = H;
	while (P != NULL)
	{
		cout << P->val << "->";
		P = P->next;
	}
	/*
	for(node* P = H; P != NULL; P = P->next)
	*/
	cout << "NULL" << endl;
}

void Add(node* &H, int x)
{
	node* P = new node;
	P->val = x;
	P->next = H;
	H = P;

}


int main()
{
	node* H = NULL;
	//Pierwsza metoda
	/*Add(H, 5);
	Show(H);

	Add(H, 4);
	Add(H, 3);
	Add(H, 2);
	Show(H);

	Del(H);
	Show(H);
	*/

	//Druga metoda

	Add(H, 3);
	Add(H->next, 8);
	Show(H);
	Add(H->next, 10);
	Show(H);
	Del(H ->next);
	Show(H);
	system("PAUSE");
	return 0;
}