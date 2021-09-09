#include <iostream>
using namespace std;

bool IsReachingTarget(int i,int j, int k, int l){
    if(l==0){
        if(i==k){
            return true;
            
        }
        else{
            return false;
        }
    }
    if(i<k){
        IsReachingTarget(i+j,j,k,l-1)
    }
    else{
        IsReachingTarget(i-j,j,k,l-1)
    }

}

int main() {
    int t;
    cin>>t;
   
    while(t>0){
        int f,j,k,l;
        cin>>f>>j>>k>>l;
        bool result;
        result=IsReachingTarget(f,j,k,l);
        if(result){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
        t--;
    }
    
	//code
	return 0;
}