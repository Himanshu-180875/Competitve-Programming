#include <iostream>
using namespace std;

int main() {
	//code
	int t,i,ans;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    int n,c=0;
	    cin>>n;
	    while(n)
	    {
	       c+=n&1;
	       n >>=1;
	    }
	    cout<<c<<endl;
	}
	return 0;
}