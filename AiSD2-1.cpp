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
void Connect(node*& H, node*& P)
{
	node* Q = P; 
	node* Q2;  
	node* D2;
	if(Q->val < H->val)
	{
	P = Q->next;
	Q2 = Q;
	Q2->next = H;
	H = Q2;

	Q = P;
		

	}
	node* D = H->next; 
	while(Q)
	{

	while(Q->val > D->next->val)
	{

	if(D->next->next != NULL)
	{
	D = D->next;
	}
	else {
			D = D->next;
			break;
			}
	} 

	P = Q->next;
	Q2 = Q;
	D2 = D;
	Q2->next = D2->next;
	D2->next = Q2;

	Q = P;	
	


	
	}
		
}

int main()
{
	node* H = NULL;
	
	Addk(H, 5);
	Addk(H, 8);
	Addk(H, 13);
	Addk(H, 21);
	Show(H);

	node* H2 = NULL;
	
	Addk(H2, 4);
	Addk(H2, 12);
	Addk(H2, 24);
	Addk(H2, 27);
	Show(H2);

	Connect(H,H2);
	delete H2;
	Show (H);

	system("PAUSE");
	return 0;
}
