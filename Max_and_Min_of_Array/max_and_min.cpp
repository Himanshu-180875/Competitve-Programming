
#include <iostream>

using namespace std;
struct Pair{
    int min;
    int max;
};
struct Pair getMinMax(int arr[], int low, int high){
    struct Pair minmax;
    if(low==high){
        minmax.min=arr[0];
        minmax.max=arr[0];
        return minmax;
    }
    else if(high == low+1){
        if(arr[low]>arr[high]){
            minmax.max=arr[low];
            minmax.min=arr[high];
        }
        else{
            minmax.max=arr[high];
            minmax.min=arr[low];
        }
        return minmax;
    }
   int mid= (low+high)/2;
   struct Pair arrl,arrR;
   arrl=getMinMax(arr, low, mid);
   arrR=getMinMax(arr,mid+1,high);
   if(arrl.min>arrR.min){
       minmax.min=arrR.min;
       
   }
   else{
       minmax.min=arrl.min;
   }
   if(arrl.max<arrR.max){
       minmax.max=arrR.max;
   }
   else{
       minmax.max=arrl.min;
   }
   return minmax;
   
}
int main()
{
    int arr[] = { 1000, 11, 445,
                  1, 330, 3000 };
    int arr_size = 6;
     
    struct Pair minmax = getMinMax(arr, 0,
                             arr_size - 1);
                              
    cout << "Minimum element is "
         << minmax.min << endl;
    cout << "Maximum element is "
         << minmax.max;
          
    return 0;
}