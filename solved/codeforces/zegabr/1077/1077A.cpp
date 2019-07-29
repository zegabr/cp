#include <bits/stdc++.h>
using namespace std;
char pl = '\n',sp=' ';
typedef long long ll;
typedef pair<int,int> pii;





ll a,b,k,t,i;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	cin>>t;
	while(t--){
		cin>>a>>b>>k;
		i=k>>1;
		cout<<((k-i)*a - i*b)<<pl;
	}

}
