#include <iostream>
#include <stdlib.h>   
#include <time.h>
using namespace std;

struct node //utworzenie elementu listy
{
	int val;
	node* next;
};

void Del(node* &H) //usuniecie pierwszego elementu
{
 if(H)
 {
 	node* P = H;
 	H = P->next;
 	delete P;
 }
}

void Show(node* H) //wyswietl wszystko
{
	cout << "H->";
	node* P = H;
	while (P != NULL)
	{
		cout << P->val << "->";
		P = P->next;
	}
	
	/*
	for(node* P = H; P != NULL; P = P->next)
	*/
	
	cout << "NULL" << endl;
}

void Add(node* &H, int x) // Dodaj na poczatku
{
	node* P = new node;
	P->val = x;
	P->next = H;
	H = P;

}
void Addk(node*& H, int x) //Dodaj na koncu
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
void change(node* &H, node* P) // zamien
{
	if (H)
	{
		
		if (P && P->next)
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

	}
}

// opcja uzycia wartownikow

void AddZ(node* &H, int x, int y) // Dodaj za konkretnym elementem
{
    node* P = H;
	while(P->val != y  )
	{
		P = P->next;
		if(P == NULL)
		{
			break;
		}
	}
	if(P == NULL)
	{
		cout<<"Nie znaleziono wartosci"<<endl;
		
	}
	else
	{
	node* Q = new node;
	Q->next = P->next;
    Q->val = x;
    P->next = Q;
	}
}

void Del2(node* &H) // usun co drugi
{
	
	if (H)
	{
	node* P = H;
	while(P)
	{
	
		if(P->next)
		{
			node* Q = P->next;
			P->next = Q->next;
			delete Q;	
			
		}
		P = P->next;
	}
    
}
}

void Copy(node* &H) //kopiowanie za elementem
{
	if (H)
	{
	node* P = H;
	while(P)
	{
	node* Q = new node;
	Q->val = P->val;
	Q->next = P->next;
	P->next = Q;
	P = Q->next;
	}
}
}
void CopyB(node* &H) // kopiuj z tylu
{
	if (H)
	{
	node* P = H;
	node* Q = H;
	int i = 0;
	while(Q->next){ Q = Q->next;i++;}
	for(int x = 0;x<=i;x++)
	{
	node* W = new node;
	W->val = P->val;
	W->next = NULL;
	Q->next = W;
	Q = Q->next;
	P = P->next;
}
}
}

void CopyW(node* &H) // kopuj okreslona liczbe razy
{
	if (H)
	{
	node* P = H;
	while(P)
	{
	int i = P->val;
	node* Q = P->next;
	node* Z = Q;
	for(int x = 1; x< i; x++)
	{
	
	node* W = new node;
	W->val = P->val;
	W->next = Z;
	Z = W;
}
	P->next = Z;
	P = Q;
}

}
	
}

void CopyL(node* &H) //kopiuj z tylu odwrocone
{
	if (H)
	{
/*	node* P = H;
	node* Q = H;
	int i = 0;
	while(Q->next){ Q = Q->next;i++;}
	for(int x = 0;x<=i;x++)
	{
	node* W = new node;
	W->val = P->val;
	W->next = Q->next;
	Q->next = W;
	P = P->next;
}
	
}*/
	node* P = H;
	node* Q = NULL;
	while(P)
	{
	Add(Q, P->val);

	if(P->next){P = P->	next;}
	else{break;}
}
	P->next = Q;
	Q = NULL;
	delete Q;
}
}
void Connect(node*& H, node*& P) //Polacz listy
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

void Divide2(node*& H,node*& D1,node*& D2) //podziel na 2
{
	int counter = 0;
	node* T = H;
	while(H)
	{
		H = T->next; 
		if(counter % 2 == 0)
		{
		Addk(D1, T->val);
		Del(T);
		}
		else
		{
		Addk(D2, T->val);
		Del(T);
		}
		T = H;
		counter++;
	}
}

 void DivideH(node*& H,node*& D1,node*& D2) // podziel w polowie
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
 
 void AddSort(node*& H, int x) // dodaj sortujac
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
		Show(H);
}

void Move(node*& H) // Przenies na koniec
{
	node* P = H;
	node* Q = NULL;
	node* QP = NULL;
	
	while(P->next!= NULL )
	{
		if(Q == NULL)
		{
		Q = P->next;
		QP = Q;
		}
		else
		{
		Q->next	 = P->next;
		Q = Q->next;
		}
		
		if(P->next->next == NULL){ break;}
		
		P->next = P->next->next;
		P = P->next;
		Q->next = NULL;

	
	}
	
	P->next = QP;
	
	
}

int fib(int i) // fibbonacci
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


void DelF(node* &H) //usun fibonacci
{
	int max = 34;
	int i = 0;
	int f = 0;
	node* P = H;

	while(f<= max)
	{
		if(H->val == f)
		{
		while(H->val == f)	
		{
		Del(H);
		}	
	
		}
		else
		{
		P =  H;	
		while(P->next != NULL)
		{
			
			
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
		
	
	}
	
}

void Change(node*& H, int x, int y) // zamien pomiedzy wybranymi
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

void Swap(node*& P)//zamien 
{
	node* S = P->next;
	P->next = S->next;
	S->next = S->next->next;
	P->next->next = S;
}

void SortB(node*& H) //sortowanie
{
	// 1 wersja
	//1) miejsce ostatniej zamiany
	//2) flaga 0-1
	// licznik porwnan
	// licznik sortowan 
	Add(H, -1);
	node* T = H;
	node* K = H;
	while(T)
	{
		while (K->next->next != NULL)
		{
			if(K->next->val > K->next->next->val)
			{
				Swap(K);
			}
			K = K->next;
			
		}

		K = H;
		T = T->next;
	}


	Del(H);
}


int main()
{
	node* H = NULL;

	Add(H, 5);
	Add(H, 4);
	Add(H, 3);
	Add(H, 2);
	Add(H, 1);
	Show(H);

/*	int x,y;
	cout<<"Podaj wartosc x"<<endl;
	
	cin>>x;
	cout<<"Podaj wartosc y"<<endl;
	
	cin>>y;
    AddZ(H, x, y);
	Show(H);
*/
	Del2(H);
	Show(H);
		
	Copy(H);
	Show(H);
	
	CopyB(H);
	Show(H);
	
	node* H2 = NULL;


	srand(time(NULL));
	for (int i = 0; i < 15; i++)
	{
		Add(H2, rand() % 51);
	}
	Addk(H2, 52);
	Addk(H2, 53);
	Addk(H2, 54);
	Show(H2); 

	SortB(H2);

	Show(H2);


	
	system("PAUSE");
	
	return 0;
}