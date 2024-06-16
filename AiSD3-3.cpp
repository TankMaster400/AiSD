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

int fib(int i)
{
	static int n1=1, n2=1, n3;    
    if(i>1){    
         n3 = n1 + n2;    
         n1 = n2;    
         n2 = n3;
       
         return n3;
	}
	else 
	
	return i;
}

void DelF(node* &H)
{
	int max = 0;
	int i = 0;
	int f = 0;
	node* P = H;
	node* S = H;
	while(f<= max)
	{
		if(H->val == f)
		{
		while(H->val == f)	
		{
		Del(H);
		}	
		P =  H;	
		}
		else
		{
		while(P->next != NULL)
		{
			if(P->val> max){max = P->val;}
			
			
			if(f == P->next->val)
			{
			node* Q = P->next;
			P->next = Q->next;
			delete Q;
			}
			else
			{
			P=P->next;
			}
		}
		}
		i++;
		f = fib(i);
		P = S;
	
	}
	
}

int main()
{
	node* H = NULL;
	srand(time(NULL));
	for (int i = 0; i <30; i++)
	{
		AddSort(H, rand()%56 );
	}
	Show(H);
	DelF(H);
	Show(H);

	system("PAUSE");
	return 0;
}
