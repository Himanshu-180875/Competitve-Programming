#include <iostream>
#include <string>
#include <vector>
using namespace std;


int cnt[100001][26];
int ct[100001];

vector<int> getdiv(string s,int n,int k)
{
    int l = s.length();
    vector<int> divs;
    for(int i=1;i*i<=l;i++)
    {
        if(l%i==0)
            {
                divs.push_back(i);
                if(l!=i)
                {
                    divs.push_back(l/i);
                }
            }
    }
    return divs;
}

int calc(string s,long int l,int d)
{
    long int m=l/d;
    for(int i=0;i<m;i++){
        ct[i]=0;
        for(int j=0;j<26;j++){
          cnt[i][j]=0;
        }
      }
      for(int i=0;s[i];i++){
        cnt[i%m][(s[i]-'a')]++;
        ct[i%m]=max(ct[i%m],cnt[i%m][(s[i]-'a')]);
      }
      long int count=0;
      for(int i=0;i<m;i++){
        count+=(d-ct[i]);
      }
      return count;
}



int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    long int n,k;
	    cin>>n>>k;
	    string s;
	    cin>>s;
	    if(k<=n)
	        cout<<0<<"\n";
	    else 
	    {
	         long int ans = 1e9;
    	     auto divs = getdiv(s,n,k);
    	     long int l = s.length();
    	     for(auto d:divs)
    	     {
    	         if(d*n-d+1<k)continue;
    	         long int c = calc(s,l,d);
    	         if(c<ans)
    	            ans = c;
    	     }
    	     cout<<ans<<"\n";
	    }
	    
	}
	return 0;
}