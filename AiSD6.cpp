#include <iostream>
using namespace std;

struct node
{
	int val;
	node* L;
	node* R;
	node* F;
	
};

void insertBST(int x, node* &root, node* T = NULL)
{
	if (root == NULL)
	{
		node* P = new node;
		P->val = x;
		P->L = NULL;
		P->R = NULL;
		P->F = T;
		root = P;
	}
	else
	{
		if (x >= root->val) insertBST(x, root->R, root);
		else insertBST(x, root->L, root);
	}
}

node* Max(node* root)
{
	if (root)
	{
		while (root->R)
		{
			root = root->R;
		}
		return root;
	}
}

node* Min(node* root)
{
	if (root)
	{
		while (root->L)
		{
			root = root->L;
		}
		return root;
	}
}

node* Wyszukaj(int x, node* root)
{
	if (root)
	{
		while (root->val != x && root != NULL)
		{
			if (x >= root->val) { root = root->R; }
			else { root = root->L; }
		}

		if (root == NULL) { cout << "nie znaleziono" << endl; }
		else
		{
			return root;
		}
	}
}

node* WyszukajR(int x, node* root)
{
	if (root)
	{

		if (root->val != x)
		{
			if (x >= root->val) { root = root->R; WyszukajR(x, root); }
			else { root = root->L; WyszukajR(x, root); }
		}
		else
		{
			return root;
		}
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


node* deleteNode(node* root, int key)
{
   
    if (root)
	{
    if (key < root->val)
    {
	
        root->L = deleteNode(root->L, key);
	}
    else if (key > root->val)
    {
	    root->R = deleteNode(root->R, key);
	}
    else {
       
        if (root->L==NULL and root->R==NULL)
     	{
			return NULL;
		}
        else if (root->L == NULL) 
		{
        	node* temp = root->R;
            free(root);
            return temp;
        }
        else if (root->R == NULL) 
		{
            node* temp = root->L;
            free(root);
            return temp;
        }

    	node* temp = Min(root->R);

        root->val = temp->val;

        root->R = deleteNode(root->R, temp->val);
    }
    return root;
	}
}

int main()
{
	node* root = NULL;
	/*
	insertBST(3, root);
	insertBST(10, root);
	insertBST(-3, root);
	insertBST(3, root);
	insertBST(10, root);
	insertBST(8, root);
	insertBST(-6, root);
	insertBST(0, root);
	insertBST(2, root);
	*/
	insertBST(10, root);
	insertBST(-20, root);
	insertBST(-33, root);
	insertBST(-12, root);
	insertBST(-10, root);
	insertBST(8, root);
	insertBST(30, root);
	insertBST(20, root);
	insertBST(25, root);
	insertBST(60, root);
	insertBST(50, root);
	insertBST(20, root);
	insertBST(80, root);
	insertBST(18, root);

	cout << root->val << endl;
	//cout << root->R->val << endl;
	//cout << root->L->val << endl;

	cout << (Max(root))->val << endl;
	cout << (Min(root))->val << endl;

	//int x, x2;
	//cin >> x;
	//cout << Wyszukaj(x, root)->val << endl;
	//cin >> x2;
	//cout << WyszukajR(x2, root)->val << endl;

	INORDER(root);

	cout << endl;
	cout << root->L->R->F->F->val << endl;

	int key;
	
	cin >> key;
	deleteNode(root, key);
	INORDER(root);
	cout<<endl;	
		
	cin >> key;
	deleteNode(root, key);
	INORDER(root);
	cout<<endl;	
		
	cin >> key;
	deleteNode(root, key);
	INORDER(root);
	cout<<endl;	
	
	system("pause");
	return 0;
}

