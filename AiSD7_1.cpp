
#include <iostream>
using namespace std;

struct node
{
	int val;
	node* next;

};

void push(int* &S, int &Swsk, int n, int x)
{
	if (Swsk < n) S[Swsk++] = x;
}

void pop(int &Swsk)
{
	if (Swsk != -1)
	{
		Swsk--;
	}
	
}

bool isEmpty( int Swsk)
{
	if (Swsk != -1)
	{
		cout << "istnieje" << endl;
		return false;
	}
	else
	{
		cout << "nie istnieje" << endl;
		return true;
	}

}

void Top(int* S,int Swsk)
{
	if (Swsk != -1)
	{
		cout << S[Swsk--] << endl;
	}
}


int main()
{
	int n = 10;
	int* S = new int[n];
	int Swsk = -1;

	isEmpty(Swsk);
	Top(S,Swsk);
	push(S, Swsk, n, 7);
		push(S, Swsk, n, 8);
		isEmpty(Swsk);
		push(S, Swsk, n, 10);
	Top(S,Swsk);
	
	pop(Swsk);
	push(S, Swsk, n, 12);
	Top(S, Swsk);


	cout << endl;

	system("pause");
	return 0;
}