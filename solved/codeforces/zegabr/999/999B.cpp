#include <bits/stdc++.h>
using namespace std;


int n;
string k;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		if(n%i==0){
			reverse(k.begin(),k.begin()+i);
		}
	}
	
cout<<k<<endl;
    return 0;
}


