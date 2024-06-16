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

void Swap(node*& P)
{
	node* S = P->next;
	P->next = S->next;
	S->next = S->next->next;
	P->next->next = S;
}

void SortB(node*& H)
{
	// 1 wersja
	//1) miejsce ostatniej zamiany
	//2) flaga 0-1
	// licznik porwnan
	// licznik sortowan 
	Add(H, -1);
	node* T = H;
	node* K = H;
	node* F = NULL;
		node* F2 = NULL;
	while(T )
	{
		while (K->next->next != NULL && K->next != F2)
		{
		
			if(K->next->val > K->next->next->val)
			{
				
				Swap(K);
			F=K->next->next;
				
}
			
			K=K->next;
		}
		F2 = F;
		cout<<"koniec na:" <<F2->val<< "	"<< K->val <<endl;
		
		Show(H);
		K = H;
		T = T->next;
	}


	Del(H);
}

int main()
{
	node* H = NULL;


	srand(time(NULL));
	for (int i = 0; i < 15; i++)
	{
		Add(H, rand() % 51);
	}
	Addk(H, 52);
	Addk(H, 53);
	Addk(H, 54);
	Show(H); 

	SortB(H);

	Show(H);

	system("pause");
	return 0;
}