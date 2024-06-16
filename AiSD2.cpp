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

void change(node* &H, node* P)
{
	if (H)
	{
		Add(H, 0); // wartownik
		/*if (P && P->next)
		{
			node* T = P->next;
			P->next = T->next;
			T->next = T->next->next;
			P->next->next = T;
		}
		else if (P == NULL)
		{
			node* K = H;
			H = H->next;
			K->next = K->next->next;
			H->next = K;
		}
		*/
			//node* T = P->next;
			//P->next = T->next;
			//T->next = T->next->next;
			//P->next->next = T;
		
		Del(H);

	}
}

int main()
{
	node* H = NULL;
	
	Add(H, 5);
	Add(H, 4);
	Add(H, 3);
	Add(H, 2);
	Show(H);
	change(H, NULL);
		Show(H);

	system("PAUSE");
	return 0;
}
/*Pd.
stos i kolejka
poprawic poprzednie
1. laczanie 2  list posortowanych
2. rozdielanie list na mniejsze listy - co drugi lub polowa
*/