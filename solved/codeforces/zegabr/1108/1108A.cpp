#include<algorithm>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<bitset>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#include<map>
#include<set>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;





int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10);
	int q; cin>>q;
	int r1,l1,r2,l2;
	while(q--){
	cin>>l1>>r1>>l2>>r2;
	if(l2<l1)cout<<l1<<sp<<l2<<pl;
	else cout<<l1<<sp<<r2<<pl;
	}

}
