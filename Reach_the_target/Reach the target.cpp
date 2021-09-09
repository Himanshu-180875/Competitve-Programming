#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
   
    while(t>0){
        int f,j,k,l;
        cin>>f>>j>>k>>l;
        int result=f;
        int d=l;
        while(d>0){
            if(result<k){
            result=result+j;
            }
            else{
                result=result-j;
            }
            d--;
        }
        if(result==k){
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