#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;
//#define int ll



main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	if(n&1)cout<<0<<pl;
	else cout<< (1<<(n/2))<<pl;
}
