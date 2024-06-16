// quick-sort -- 3 metody
// sortowanie - jakies
// kolos - drzewa i sortowanie -- teoria i praktyka
// drzewa avl, bst i tak ogolnie
// sort - bubble, Comb, Heap, Quick, hybrydowe ? 
// elementy : 10, 1000, 100000
// random, posortowanie, odwrotnie posortowana


#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

//#define i1  10
//#define i1  1000
#define i1  20000

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}

int getNextGap(int gap)
{
	// Shrink gap by Shrink factor
	gap = (gap * 10) / 13;

	if (gap < 1)
		return 1;
	return gap;
}

// Function to sort a[0..n-1] using Comb Sort
void combSort(int a[], int n)
{
	// Initialize gap
	int gap = n;

	// Initialize swapped as true to make sure that
	// loop runs
	bool swapped = true;

	// Keep running while gap is more than 1 and last
	// iteration caused a swap
	while (gap != 1 || swapped == true)
	{
		// Find next gap
		gap = getNextGap(gap);

		// Initialize swapped as false so that we can
		// check if swap happened or not
		swapped = false;

		// Compare all elements with current gap
		for (int i = 0; i < n - gap; i++)
		{
			if (a[i] > a[i + gap])
			{
				swap(a[i], a[i + gap]);
				swapped = true;
			}
		}
	}
}

void heapify(int i, int heapsize, int* tab)
{
	int l = 2 * i;
	int r = 2 * i + 1;
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

void swap2(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void BuildHeap(int* tab, int heapsize)
{
	for (int i = heapsize / 2; i > 0; i--)
	{
		heapify(i, heapsize, tab);
	}
}

int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i
		= (low
			- 1); // Index of smaller element and indicates
				  // the right position of pivot found so far

	for (int j = low; j <= high - 1; j++) {
		// If current element is smaller than the pivot
		if (arr[j] < pivot) {
			i++; // increment index of smaller element
			swap2(&arr[i], &arr[j]);
		}
	}
	swap2(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high) {
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void insertion_sort(int arr[], int low, int n)
  {
 
    for(int i=low+1;i<n+1;i++)
    {
      int val = arr[i] ;
      int j = i ;
    while (j>low && arr[j-1]>val)
      {
        arr[j]= arr[j-1] ;
      j-= 1;
    }
    arr[j]= val ;
    }
 
  }
 
int partition2(int arr[], int low, int high)
{
  int pivot = arr[high] ;
  int i ,j;
  i = low;
  j = low;
 
  for (int i = low; i < high; i++)
     {
      if(arr[i]<pivot)
      {
        int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      j += 1;
      }
    }
   
    int temp = arr[j];
    arr[j] = arr[high];
    arr[high] = temp;
 
  return j;
  }
 
void quick_sort2(int arr[], int low,int high)
{
  if (low < high)
  {
    int pivot = partition2(arr, low, high);
    quick_sort2(arr, low, pivot-1) ;
    quick_sort2(arr, pivot + 1, high) ;
   
   
  }
}
 
// Hybrid function -> Quick + Insertion sort
 
void hybrid_quick_sort(int arr[], int low, int high)
{
  while (low < high)
    {
 
    // If the size of the array is less
    // than threshold apply insertion sort
    // and stop recursion
 
    if (high-low + 1 < 10)
      {
        insertion_sort(arr, low, high);
      break;
    }
 
    else
       
        {
          int pivot = partition(arr, low, high) ;
 
      // Optimised quicksort which works on
      // the smaller arrays first
 
      // If the left side of the pivot
      // is less than right, sort left part
      // and move to the right part of the array
 
      if (pivot-low<high-pivot)
        {
          hybrid_quick_sort(arr, low, pivot - 1);
        low = pivot + 1;
      }
      else
        {
 
        // If the right side of pivot is less
        // than left, sort right side and
        // move to the left side
           
        hybrid_quick_sort(arr, pivot + 1, high);
        high = pivot-1;
        }
 
     }
 
   }
}

int main()
{

	clock_t time_req;

	//i
	int tab1[i1], tab2[i1], tab3[i1], tab4[i1];
    int tab1p[i1];
	int tab1r[i1], tab2r[i1], tab3r[i1], tab4r[i1];

	srand(time(NULL));

	for (int i = 0; i < i1; i++)
	{
		int x = rand() % 100000;
		tab1[i] = x;
		tab2[i] = x;
		tab3[i] = x;
		tab4[i] = x;
	}

	for (int i = 0; i < i1; i++)
	{
		tab1p[i] = i;

	}

	for (int i = i1; i > 0; i--)
	{
		tab1r[i1 - i] = i;
		tab2r[i1 - i] = i;
		tab3r[i1 - i] = i;
		tab4r[i1 - i] = i;
	}

cout<< "bubble" <<endl;
	time_req = clock();
	bubbleSort(tab1, i1);
	time_req = clock() - time_req;
	cout << (float)time_req / CLOCKS_PER_SEC << endl;
		
	time_req = clock();	 
	bubbleSort(tab1p, i1);
		time_req = clock() - time_req;
	cout << (float)time_req / CLOCKS_PER_SEC << endl;
	
	time_req = clock();
	bubbleSort(tab1r, i1);
		time_req = clock() - time_req;
	cout << (float)time_req / CLOCKS_PER_SEC << endl;


cout<< "comb" <<endl;

	time_req = clock();
	combSort(tab2, i1);
		time_req = clock() - time_req;
	cout << (float)time_req / CLOCKS_PER_SEC << endl;
	
	time_req = clock();
	combSort(tab1p, i1);
		time_req = clock() - time_req;
	cout << (float)time_req / CLOCKS_PER_SEC << endl;
	
	time_req = clock();
	combSort(tab2r, i1);
	time_req = clock() - time_req;
	cout << (float)time_req / CLOCKS_PER_SEC << endl;

cout<< "heap" <<endl;

	time_req = clock();
	BuildHeap(tab3, i1);
	for(int t = 0; t < i1; t++)
	{
		cout<< tab3[t]<<endl;
	}
	time_req = clock() - time_req;
	cout << (float)time_req  << endl;
	
	time_req = clock();
	BuildHeap(tab1p, i1);
	time_req = clock() - time_req;
	cout << (float)time_req  << endl;
	
	time_req = clock();
	BuildHeap(tab3r, i1);
	time_req = clock() - time_req;
	cout << (float)time_req  << endl;

cout<< "quick" <<endl;
	
	time_req = clock();
	quickSort(tab4, 0, i1 - 1);
	time_req = clock() - time_req;
	cout << (float)time_req / CLOCKS_PER_SEC << endl;
	
	time_req = clock();
	quickSort(tab1p, 0, i1 - 1);
	time_req = clock() - time_req;
	cout << (float)time_req / CLOCKS_PER_SEC << endl;
	
	time_req = clock();
	quickSort(tab4r, 0, i1 - 1);
    time_req = clock() - time_req;
	cout << (float)time_req / CLOCKS_PER_SEC << endl;
	// hybryda



	system("pause");     
                   
	return 0;
}                      
                        
                        