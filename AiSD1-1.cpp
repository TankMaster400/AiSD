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

void Addp(node* &H, int x, int y)
{
    node* P = H;
	while(P->val != y)
	{
		P = P->next;
	}
	
	node* Q = new node;
	
	Q->next = P->next;
    Q->val = x;
    P->next = Q;
	 
}


int main()
{
	node* H = NULL;
	Add(H, 4);
	Add(H, 34);
	Add(H, 2);
	Add(H, 5);
	Add(H, 7);
	Add(H, 6);
	Show(H);
	
	int x,y;
	cout<<"Podaj wartosc x"<<endl;
	
	cin>>x;
	cout<<"Podaj wartosc y"<<endl;
	
	cin>>y;
	Addp(H, x, y);
	Show(H);

	system("PAUSE");
	return 0;
}