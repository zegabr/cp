#include <bits/stdc++.h>
using namespace std;
char pl='\n',sp=' ';


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    long long n,m,rem;
    
while(cin>>n>>m){
    if(n<=m)
    	cout<<n<<pl;
    else{
    	n-=m;
    	long long l=0, r=2e9;
    	
    	while(l<r){
    		long long m=(l+r)>>1;
    		rem=m*(m+1)/2;
    		if(rem>=n)
    			r=m;
    		else
    			l=m+1;
    	}
    	cout<<l+m<<pl;
    
    }
    
}    
    return 0;
}