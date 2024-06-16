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
	if (p)
	{
		while (p->next) p = p->next;
		p->next = P;
	}
	else H = P;

}

void Change(node*& H, int x, int y)
{
	Add(H,-1);
	node* P = NULL;
	node* K = H;
	int i1, i2;
	if(x>y){i1 = x; i2 = y;}
	else{i1 =y; i2 = x;}
	
	while(K->val != i1)
	{
		if(K->next->val == i2){ P = K;}
		 K = K->next;
	}
	
	node* H2 = P->next;
	P->next = K->next;
	K->next = NULL;
	
	while(H2)
	{
	node * T = H2;
	H2 = T->next;
	T->next = P->next;
	P->next = T;
	
	
}
Del(H);
}
int main()
{
	node* H = NULL;

	for (int i = 0; i < 30; i++)
	{
		Addk(H, i+1);
	}
	Show(H);
	int x,y;
	cout<<"Podaj pierwsza liczbe:"<<endl;
	cin>> x;
	cout<<"Podaj druga liczbe:"<<endl;
	cin>> y;
	Change(H,x,y);
	
	Show(H);
	system("PAUSE");
	return 0;
}
