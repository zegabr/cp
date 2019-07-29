#include <bits/stdc++.h>
using namespace std;
char pl = '\n',sp=' ';
typedef long long ll;
typedef pair<int,int> pii;







int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	ll k,w,n;
	cin>>k>>n>>w;
	cout<<max(0LL,(k*(1+w)*w)/2-n);

}
