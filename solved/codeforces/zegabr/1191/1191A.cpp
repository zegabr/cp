#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

//#define endl '\n'

using namespace std;

using ll = long long;
//#define int ll



main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	while(cin>>n){
		n%=4;
		if(n==1)	cout<<"0 A"<<endl;
		else if(n==3) cout<<"2 A"<<endl;
		else if(n==2) cout<<"1 B"<<endl;
		else cout<< "1 A"<<endl;
	}
}
