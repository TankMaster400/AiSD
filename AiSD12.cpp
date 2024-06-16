#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

//LS //LE

// punkt -> punkt2 -> wartosc

//MN -> LN
//MN -> LE
//LN -> MN
//LN -> LE
//LE -> LN
//LE -> MN

// grafy wczytywanie z pliku
/*
5
0 2 0 13 0
2 0 7 0 6
0 7 0 5 10
13 0 5 0 0
0 6 10 0 0
*/

struct node
{
	//int x, y;
	int val;
	node* node;
};

int main()
{

	int size;
	int number;
	fstream plik;
	plik.open("graf2.txt");
		plik >> size;

		plik >> number;
		//int** T = new int* [size];
		node** T = new node * [size];

		for (int t = 0; t < size; t++)
		{
			T[t] = NULL;
			//T[t] = new node[size];
			//T[t] = new int[size];
		}
// do wartosci polaczen
	/*	for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
			
				int a;
				T[i][j].x = i;
				T[i][j].y = j;
				//plik >> T[i][j].val;
				
				// z wartosc polaczen do ich wystapienia
				plik >> a;
				if (a != 0)
				{
					T[i][j].val = 1;
				}
				else
				{
					T[i][j].val = 0;
				}
			}
		}
		*/
// do polaczen miedzy punktami
/*		int a, b;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				T[i][j].val = 0;
			}
		}
		for (int i = 0; i < number; i++)
		{
			plik >> a;
			plik >> b;

			T[a][b].val = 1;
		}
		*/
// lista saiedztwa
		int v1, v2;
		node* p;

		for (int i = 0; i < number; i++)
		{
			plik >> v1 >> v2;    
			p = new node;    
			p->val = v2;          
			p->node = T[v1];  
			T[v1] = p;
		}

		cout << endl;

	
		for (int i = 0; i < size; i++)
		{
			cout << "T [ " << i << " ] =";
			p = T[i];
			while (p)
			{
				cout << setw(3) << p->val;
				p = p->node;
			}
			cout << endl;
		}

//wypisanie 
		/*
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
			//	cout << T[i][j].x << ";";
			//	cout << T[i][j].y << ";";
				cout << T[i][j].val <<"		";
			}
			cout << endl;
		}
		*/
		plik.close();

		for (int i = 0; i < size; i++) {
			delete[] T[i];
		}
		delete[] T;

		system("pause");

		return 0;
}