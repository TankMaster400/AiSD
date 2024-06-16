//kolejka na tablicy
//stos na tablicy

#include <iostream>
using namespace std;

struct node
{
	int val;
	node* next;

};

void push(node * &S, int x)
{
	node* P = new node;
	P->val = x;
	P->next = S;
	S = P;
}

void pop(node * &S)
{
	if (S)
	{
		node* P = S;
		S = P->next;
		delete P;
	}
}

bool isEmpty(node* S)
{
	if (S)
	{
		cout << "stos istnieje" << endl;
		return false;
	}
	else
	{
		cout << "stos nie istnieje" << endl;
		return true;
	}
}

void Top(node* S)
{
	if (S)
	{
		cout << S->val << endl;
	}
}

void Enqueue(int x, node * &Q, node * &T)
{
	node* P = new node;
	P->val = x;
	P->next = NULL;

	if (Q == NULL)
	{
		Q = P;
		T = P;
	}
	else
	{
		T->next = P;
		T = P;
	}


}

void Dequeue(node* &Q, node* &T)
{
	if (Q)
	{
		
		node* P = Q;
		Q = P->next;
		delete P;
		if (Q == NULL)
		{
			T = NULL;
		}
	}
}

bool isEmptyQ(node* Q)
{
	if (Q)
	{
		cout << "kolejka istnieje" << endl;
		return false;
	}
	else
	{
		cout << "kolejka nie istnieje" << endl;
		return true;
	}
}

void Front(node* Q)
{
	if (Q)
	{
		cout << Q->val << endl;
	}
}

void Rear(node* T)
{
	if (T)
	{
		cout << T->val << endl;
	}
}


class STab {
    int size = 10;
    int* S = new int[size];
    int top = -1;

public:
    bool isEmpty() {
        if (top == -1) return true;
        return false;
    }

    int topVal() {
        if (!isEmpty()) return S[top];
        return NULL;
    }

    void push(int x) {
        if (top < size) {
            top++;
            S[top] = x;
        }
    }

    void pop() {
        if (!isEmpty()) {
            top--;
        }
    }
};

//kolejka tablicowo

class QTab {
    int size = 5;
    int NofEl = 0;
    int* Q = new int[size];
    int front = 0;
    int rear = -1;

public:
    bool isEmpty() {
        if (NofEl == 0) return true;
        return false;
    }

    int frontVal() {
        if (!isEmpty()) return Q[front];
        return NULL;
    }

    void enqueue(int x) {
        if (NofEl < size) {
            if (rear == -1) {
                rear++;
                Q[rear] = x;
            }
            else {
                rear++;
                rear = rear % size;

                Q[rear] = x;
            }
            NofEl++;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            front++;
            front = front % size;
            NofEl--;
        }
    }
};


int main()
{
	node* S = NULL;

	isEmpty(S);
	Top(S);
	push(S, 1);
	Top(S);
	push(S, 2);
	isEmpty(S);
	push(S, 3);
	Top(S);
	pop(S);
	Top(S);

	cout << endl;

	node* Q = NULL;
	node* T = NULL;
	isEmptyQ(Q);
	Enqueue(10, Q, T);
	Front(Q);
	Enqueue(12, Q, T);
	Enqueue(15, Q, T);
	Front(Q);
	Rear(T);
	Dequeue(Q,T);
	Front(Q);
	Enqueue(12, Q, T);
	Enqueue(14, Q, T);
	Enqueue(21, Q, T);
	Rear(T);
	isEmptyQ(Q);
	
	 cout << "\nSTOS TABLICOWO:\n";

    STab stosT;

    stosT.push(4);
    stosT.push(8);
    stosT.push(9);

    cout << stosT.topVal() << endl;

    stosT.pop();

    cout << stosT.topVal() << endl;

    cout << "\nKOLEJKA TABLICOWO:\n";

    QTab kolTab;

    kolTab.enqueue(6);
    kolTab.enqueue(7);
    kolTab.enqueue(9);
    kolTab.enqueue(11);

    cout << kolTab.frontVal() << endl;

    kolTab.dequeue();

    cout << kolTab.frontVal() << endl;

    kolTab.dequeue();
    kolTab.dequeue();
    kolTab.dequeue();

    kolTab.enqueue(6);
    kolTab.enqueue(7);
    kolTab.enqueue(9);
    kolTab.enqueue(11);

    cout << kolTab.frontVal() << endl;

    kolTab.dequeue();
    kolTab.dequeue();

    cout << kolTab.frontVal() << endl;
	system("pause");
	return 0;
}