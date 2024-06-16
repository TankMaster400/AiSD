#include <iostream>
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
  	if( p )
  	{
     while( p->next ) p = p->next;
     p->next = P;
  	}
  	else H = P;

}

void Divide2(node*& H,node*& D1,node*& D2)
{
	int counter = 0;
	node* T = H;
	while(H)
	{
		 
		if(counter % 2 == 0)
		{
			D1->next = T;
			D1 = T
		//Addk(D1, T->val);
		Del(T);
		}
		else
		{
		//Addk(D2, T->val);
		Del(T);
		}
		H = T->next;
		T = H;
		counter++;
	}
}
 void DivideH(node*& H,node*& D1,node*& D2)
{
	node* C = H;
	int counter = 0;
	while(C)
	{
		C = C->next;
		counter++;
	}
	Del(C);

	D1 = H;	
	node* T = H;
	for(int i = 0; i < ((counter-1) / 2); i++)
	{
		
		T = T->next;
		
	}
	
	D2 = T->next;
	T->next = NULL;
	H = NULL;
}
 
int main()
{
	node* H = NULL;
	
	Add(H, 1);
	Add(H, 2);
	Add(H, 3);
	Add(H, 4);
	Add(H, 5);
	Add(H, 6);
	Add(H, 7);
	Add(H, 8);
	Add(H, 9);
	Add(H, 10);

	Show(H);
	
	node* D1 = NULL;
	node* D2 = NULL;
	Divide2(H, D1, D2);
	Show(D1);
	Show(D2);
	
	cout<<endl;
	Add(H, 1);
	Add(H, 2);
	Add(H, 3);
	Add(H, 4);
	Add(H, 5);
	Add(H, 6);
	Add(H, 7);
	Add(H, 8);
	Add(H, 9);
	Add(H, 10);
	
	Show(H);
	
	node* H1 = NULL;
	node* H2 = NULL;
	DivideH(H, H1, H2);
	Show(H1);
	Show(H2);
	
	delete H;
	system("PAUSE");
	return 0;
}
