#include <iostream>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include <cmath>
using namespace std;

struct node
{
	int val;
	node* R;
	node* L;
	node* F;
	int tabp;
};


void Buildtree(node* &H, int* tab, int heapsize, int i,node* T = NULL)
{
	int c = 2*i;
	int d = 2 * i + 1;

	
	if (i <= heapsize)
	{
	
		node* P = new node;
	if (H == NULL)
	{
		
		P->val = tab[i];
		P->L = NULL;
		P->R = NULL;
		P->F = T;
		H = P;
	}
		
		Buildtree(P->L, tab, heapsize, c, P);
		Buildtree(P->R, tab, heapsize, d, P);
	}
}

void heapify(int i, int heapsize, int* tab)
{
	int l = 2*i;
	int r = 2*i + 1;
	int max;
	if (l <= heapsize && tab[l] > tab[i]) max = l;
	else max = i;

	if (r <= heapsize && tab[r] > tab[max]) max = r;

	if (max != i)
	{
		swap(tab[i], tab[max]);
		heapify(max, heapsize, tab);
	}


}

void INORDER(node* root)
{
	if (root)
	{
		INORDER(root->L);
		cout << root->val << "	";
		INORDER(root->R);
	}

}

void BuildHeap(int *tab, int heapsize)
{
	for (int i = heapsize / 2; i > 0; i--)
	{
		heapify(i, heapsize, tab);
	}
}

int main()
{
		
	clock_t time_p;
	
	srand((unsigned)time(NULL));
	int heapsize = 8;
	int* tab = new int[heapsize+1];

	for (int i = 1; i < heapsize + 1; i++)
	{
		tab[i] = rand() % 30;
//			cout << tab[i]<<"	";
	}
	cout << endl;

	node* root = NULL;
		
	time_p = clock();
	
	BuildHeap(tab, heapsize);

	time_p = clock() - time_p;
	
	for (int i = 1; i < heapsize + 1; i++)
	{	
//	cout << tab[i] << "	";
	}
	cout << endl;

	cout<<"Pomiar czasu "<< (float)time_p/CLOCKS_PER_SEC <<endl;
	
	Buildtree(root, tab, heapsize, 1);

//	INORDER(root);

	system ("pause");
	return 0;
}

// najmniejsze do najwiekszego
// najwieksze do najmniejszego 
// heapsize-- (co to bylo)