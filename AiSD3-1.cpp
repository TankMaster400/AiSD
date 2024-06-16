#include <iostream>
#include <stdlib.h>   
#include <time.h>
using namespace std;

struct node
{
	int val;
	node* next;
};

void Del(node*& H)
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

	cout << "NULL" << endl;
}

void Add(node*& H, int x)
{
	node* P = new node;
	P->val = x;
	P->next = H;
	H = P;

}

void Addk(node*& H, int x)
{
	node* P = new node;
	P->val = x;
	P->next = NULL;


	node* p = H;
	if (p)
	{
		while (p->next) p = p->next;
		p->next = P;
	}
	else H = P;

}

void AddSort(node*& H, int x)
{
	node* P = new node;
	

		if (  H  == NULL|| x < H->val)
		{
			Add(H, x);
		}
		else
		{
			node* D = H;
			while (D->next && x > D->next->val)
			{
					D = D->next;
			}
			Add(D->next, x);
			
		}
		
}

void Move(node*& H)
{
	node* P = H;
	node* Q = NULL;
	node* QP = NULL;
	
	while(P->next!= NULL )
	{
		if(Q == NULL)
		{
		Q = P->next;
		QP = Q;
		}
		else
		{
		Q->next	 = P->next;
		Q = Q->next;
		}
		
		if(P->next->next == NULL){ break;}
		
		P->next = P->next->next;
		P = P->next;
		Q->next = NULL;

	
	}
	
	P->next = QP;
	
	
}

int main()
{
	node* H = NULL;
	srand(time(NULL));
	for (int i = 0; i < 4	; i++)
	{
		AddSort(H, rand()%50);
	}
	Show(H);
	
	Move(H);
	Show(H);
	system("PAUSE");
	return 0;
}
