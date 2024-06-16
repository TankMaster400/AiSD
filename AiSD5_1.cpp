#include <iostream>
#include <stdlib.h>   
#include <time.h>
using namespace std;

//709 B5 20.00 - 21.00

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

void Swap(node*& P)
{
	node* S = P->next;
	P->next = S->next;
	S->next = S->next->next;
	P->next->next = S;
}

void Swap2(node*& P1, node*& P2)
{
	if(P1->next == P2)
	{
	node* T1 = P1->next;
	node* T2 = P2->next;
	
	
	P2->next = T2->next;
	P1->next = T2;
	T2->next = P2;
	P2 = P1->next;
	}
	else
	{

	node* T1 = P1->next;
	node* T2 = P2->next;
	node* T3 = T2->next;

	P2->next = T1;
	P1->next = T2;
	T2->next = T1->next;
	T1->next = T3;
}
}

void SortG(node*& H)
{
	int counter = 0;
	node* N = H;

	while (N)
	{
		counter++;
		N = N->next;

	}
	delete N;
	Add(H, 0);
	node* P1;
		node* P2;
		
	//gap counter/1.3
		int gap = counter / 1.3;
	
		while (gap > 0)
		{
			
			P1 = H;
			P2 = P1;
			for (int i = 1; i <= gap; i++ )
			{
				if (P2 == NULL) { break; }
				P2 = P2->next;
			}
			
			while ( P2->next != NULL)
			{
				if (P1->next->val > P2->next->val) { cout<<P1->next->val << "		"<<P2->next->val<<endl; Show(H); Swap2(P1, P2); }
				
				P1 = P1->next;
				
				P2 = P2->next;
		
			}
		
			gap = gap / 1.3;
		} 
	

			Del(H);
}


int main()
{
	node* H = NULL;


	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		Add(H, rand() % 51 - 20);
	}

	Show(H);

	SortG(H);

	Show(H);
	

	system("pause");
	return 0;
}