//algorytm prima
//-tablica kolorow

//algorytm kurskala
//-tablica kolorów
//-tablica lasów
//-lista jakas
//-lista krawêdzi
//zamiana grafów!!

//kolosy - jeden graf w drugi graf (sposoby) z jakimœ dzialaniem
// jeden z tych algorytmow prima/kurskala

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <time.h>
using namespace std;

struct node
{
	int x, y;
	int val;
	node* node;
};


int main()
{

	srand(time(NULL));

	int size;
	
	fstream plik;
	plik.open("graf3.txt");

	plik >> size;
	
	node** T = new node * [size];

	for (int t = 0; t < size; t++)
	{
		T[t] = NULL;
		
	}

	int ST = rand() % size;

	node* p;



	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{

			int a;
			plik >> a;

			if (a != 0)
			{
				p = new node;
				p->val = a;
				p->x = i;
				p->y = j;
				p->node = T[i];
				T[i] = p;

				
				
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		cout << "T [ " << i << " ] =";
		p = T[i];
		while (p)
		{
			cout << " " << p->x << " ; " << p->y << " ; " << p->val << "   ";
			p = p->node;
		}
		cout << endl;
	}

	int* tabk = new int[size];
	for (int i = 0; i < size; i++)
	{
		tabk[i] = 0;

	}

	tabk[ST] = 1;

	node* H = NULL;

	int zmienna = 0;
	int min = -1;

	while (zmienna == 0)
	{
		node* s = T[ST];

	}

	while (H != NULL)
	{
		cout << " " << H->x << " ; " << H->y << " ; " << H->val << "   ";
		H = H->node;

	}

	plik.close();

	for (int i = 0; i < size; i++) {
		delete[] T[i];
	}
	delete[] T;

	system("pause");

	return 0;
}