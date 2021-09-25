#include<iostream>
using namespace std;
#include<algorithm>
struct Item{
    string name;
    int price;
};
void swap(Item *xp, Item *yp)
{
    Item temp = *xp;
    *xp = *yp;
    *yp = temp;
}
bool compareItems(Item a, Item b){
    if(a.price==b.price){
        return a.name < b.name;
    }
    return a.price < b.price;
}
int partition (Item *arr, int low, int high)
{
    Item pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (compareItems(arr[j],pivot)==true)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(Item *arr, int low, int high)
{
    
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
// A function to implement bubble sort
void bubbleSort(Item *arr, int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)    
     
    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (compareItems(arr[j+1] ,arr[j])==true)
            swap(&arr[j], &arr[j+1]);
}
void merge(Item *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;
   Item larr[nl], rarr[nr];
   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real array
   while(i < nl && j<nr) {
      if(compareItems(larr[i], rarr[j])==true) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //extra element in left array
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //extra element in right array
      array[k] = rarr[j];
      j++; k++;
   }
}
void mergeSort(Item *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}

void display(Item *a, Item *b,int p, int q, int j, int k){
    while(j<p && k<q){
	        if(a[j].price < b[k].price){
	            cout<<a[j].name<<" ";
	            j++;
	        
	    }
	    else if(a[j].price == b[k].price){
	        if(a[j].name < b[k].name){
	            cout<<a[j].name<<" ";
	            j++;
	        }
	        else{
	            cout<<b[k].name<<" ";
	            k++;
	        }
	    }
	    
	    else{
	        cout<<b[k].name<<" ";
	        k++;
	    }
	    }
	    while(j<p){
	        cout<<a[j].name<<" ";
	        j++;
	    }
	    while(k<q){
	        cout<<b[k].name<<" ";
	        k++;
	    }
}
int main() {
	//code
	int t,n,m,p,q;
	cin>>t;
	while(t>0){
	    cin>>n>>m>>p>>q;
	    Item a[n],b[m];
	    for(int i=0;i<n;i++){
	        cin>>a[i].name>>a[i].price;
	    }
	    for(int i=0;i<m;i++){
	        cin>>b[i].name>>b[i].price;
	    }
	    int choice;
	    
	    cout<<"Select Sorting: "<<endl;
	    cout<<"1. Bubble Sort"<<endl;
	    cout<<"2. Quick Sort"<<endl;
	    cout<<"3. Merge Sort"<<endl;
	    
	    cin>>choice;
	    switch (choice)
        {
            case 1:
            
    	    bubbleSort(a,n);
    	    bubbleSort(b,m);
    	    break;
    	    case 2:
    	    
        	quickSort(a, 0, n-1);
        	quickSort(b, 0, m-1);
        	break;
        	case 3:
        	
    	    mergeSort(a, 0, n-1);
    	    mergeSort(b, 0, n-1);
    	    break;
        }
	    int j=0;
	    int k=0;
	    display(a,b,p,q,j,k);
	    cout<<endl;
	    t--;
	}
	return 0;
}