#include<bits/stdc++.h>

using namespace std;

#define MAX 100001
 

int prime[MAX], countdiv[MAX];
 

void FindingPrimeFactors()
{
    for (int i = 2; i * i <= MAX; ++i)
    {
        if (!prime[i])
            for (int j = i * 2; j <= MAX; j += i)
                prime[j] = i;
    }
 
 
    for (int i = 1; i < MAX; ++i)
        if (!prime[i])
            prime[i] = i;
}
 

int largestGCDSubsequence(int arr[], int n)
{
    int ans = 0;
    for (int i=0; i < n; ++i)
    {
        int element = arr[i];
 
       
        while (element > 1)
        {
            int div = prime[element];
 
          
            ++countdiv[div];
 
            
            ans = max(ans, countdiv[div]);
 
            while (element % div==0)
                element /= div;
        }
    }
 
    return ans;
}

int main() {
    FindingPrimeFactors();
    int testcases;
    cin>>testcases;
  
    while(testcases>0){
        int N;
        cin>>N;
        int arr[N];
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }
         for(int i=0;i<MAX;i++)
        countdiv[i]=0;
        
        cout<<largestGCDSubsequence(arr,N);
        cout<<endl;
        testcases--;
    }

	return 0;
}