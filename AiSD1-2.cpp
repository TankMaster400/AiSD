#include <iostream>
using namespace std;

struct node
{
	int val;
	node* next;
};

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

void Del2(node* &H)
{
	
	if (H)
	{
	node* P = H;
	while(P)
	{
	
		if(P->next)
		{
			node* Q = P->next;
			P->next = Q->next;
			delete Q;	
			
		}
		P = P->next;
	}
    
}
}




int main()
{
	node* H = NULL;
	Add(H, 4);
	Add(H, 5);
	Add(H, 2);
	Add(H, 5);
	Add(H, 7);
	Add(H, 6);
		Add(H, 4);
	Add(H, 5);
	Add(H, 2);
	Add(H, 5);
	Add(H, 7);
	Add(H, 24);
		Add(H, 4);
	Add(H, 5);
	Add(H, 2);
	Add(H, 5);
	Add(H, 7);
	Add(H, 6);
	Show(H);
	
	Del2(H);
	Show(H);

	system("PAUSE");
	return 0;
}