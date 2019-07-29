#include <bits/stdc++.h>
using namespace std;
#define pl '\n'
#define sp ' '

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    //cout<<fixed<<setprecision(10);
	int t,n,k,i;
	cin>>t;
	while(t--){
		cin>>n>>k;
		i=0;
		while(n--){
			cout<<(char)((i+'a'));
			i=(i+1)%k;
			
		}
		cout<<pl;
	}
    return 0;
}

