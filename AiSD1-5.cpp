#include <iostream>
using namespace std;

struct node
{
	int val;
	node* next;
};

void Del(node* &H)
{
 if(H)
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

	cout << "NULL" << endl;
}

void Add(node* &H, int x)
{
	node* P = new node;
	P->val = x;
	P->next = H;
	H = P;

}

void CopyW(node* &H)
{
	if (H)
	{
	node* P = H;
	while(P)
	{
	int i = P->val;
	node* Q = P->next;
	node* Z = Q;
	for(int x = 1; x< i; x++)
	{
	
	node* W = new node;
	W->val = P->val;
	W->next = Z;
	Z = W;
}
	P->next = Z;
	P = Q;
}

}
	
}


int main()
{
	node* H = NULL;

	Add(H, 5);
	Add(H, 4);
	Add(H, 3);
	Add(H, 2);
	Add(H, 1);
	Show(H);
	
	CopyW(H);
	Show(H);
	
	
	system("PAUSE");
	return 0;
}