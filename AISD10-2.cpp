#include <iostream>
#define size 12

using namespace std;

struct tree
{
  int val;
  tree *L;
  tree *R;
  tree *Up;
} *root = NULL;

int search (int t[], int min, int max, int x)
{
  int pivot = (max - min) / 2 + min;
  if (max - min <= 1)
    return -1;
  else
    {
      if (t[pivot] == x)
    return pivot;
      else if (pivot[t] > x)
    search (t, min, max - ((max - min) / 2), x);
      else if (pivot[t] < x)
    search (t, min + ((max - min) / 2), max, x);
    }
}

void Delete(tree *&T){
    if(T->L!=NULL)
        Delete(T->L);
    if(T->R!=NULL)
        Delete(T->R);
    if(T->L==NULL && T->R==NULL){
        if(T->Up->L == T)
            T->Up->L = NULL;
        else if(T->Up->R == T)
            T->Up->R = NULL;
    delete(T);
    }
}

void SearchTreeAndDelete(tree *&T, int val){
    if(T!=NULL){
        if(T->val == val){
            Delete(T->L);
            Delete(T->R);
        }
        else{
                SearchTreeAndDelete(T->L,val);
                SearchTreeAndDelete(T->R,val);
        }
    }
}


int main ()
{

  int tab[size];

  for (int i = 0; i < size; i++)
    {
      tab[i] = i*2;
    }
  cout << search (tab, 0, size, 8);


  return 0;
}