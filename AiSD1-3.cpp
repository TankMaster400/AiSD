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

void Copy(node* &H)
{
	if (H)
	{
	node* P = H;
	while(P)
	{
	node* Q = new node;
	Q->val = P->val;
	Q->next = P->next;
	P->next = Q;
	P = Q->next;
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
	
	Copy(H);
	Show(H);
	
	
	system("PAUSE");
	return 0;
}