#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

#define pl endl
#define endl '\n'

using namespace std;

typedef long long ll;
#define int ll
int n,k,a,b,q;

bool check(int m){
	int ba = k-a*m;
	if(ba<=0) return 0;
	int resto = ba-(n-m)*b;
	if(resto > 0) return 1;
	return 0;
}

int solve(int l, int r) {
	while(r - l > 1) {
		int m = (l+r)/2;
		if(check(m)) l = m;
		else r = m;
	}
	return check(r) ? r : l;
}

main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>q;
	while(q--){
		cin>>k>>n>>a>>b;
		int ans = solve(0,n);
		if(check(ans)) cout<<ans<<pl;
		else cout<<-1<<pl;


	}

}
