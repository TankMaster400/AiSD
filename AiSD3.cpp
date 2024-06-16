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
		Show(H);
}

int main()
{
	node* H = NULL;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		AddSort(H, rand()%100);
	}
	AddSort(H,105);
	//Show(H);

	system("PAUSE");
	return 0;
}
/*
PD.

1. Co drugi element na koniec - sprawdzenie gdzie koniec

2. f(H,x,y) - obrocenie listy w okreslonym przedziale

3. usun z ciagu elemnty ciagu fibonacciego

*/