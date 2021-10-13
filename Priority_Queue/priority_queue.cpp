#include <iostream>
using namespace std;
#include<queue>
void printIndex(int n, int arr[]){
      priority_queue<pair<int,int>>pq;
      for(int i=0;i<n;i++){
           pq.push(make_pair(arr[i], i+1));
      }
       while (!pq.empty()) {
        cout << pq.top().second<<" ";
        pq.pop();
    }
   
}
int main() {
    int t;
    cin>>t;
    while(t>0){
        int N;
        cin>>N;
        int arr[N];
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }
        printIndex(N,arr);
        cout<<endl;
        t--;
    }
	//code
	return 0;
}