#include<map>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std; typedef long long ll;
#define sp ' '
#define pl '\n'
#define rep(i,a,b) for(int i = a; (a>b? i>=b : i<=b) ; (a>b? i-- : i++) )
const int N = 5 + 1e5 * 3;
const int mod = 1e9+7;




int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	int big = -1;
	cin>>n;
	map<int, int> m;
	while(n--){
		int a;
		cin>>a;
		m[a]++;
		if(a>big) big=a;
	}
	cout<<big<<sp;
	for(auto p : m){
		if(big%p.first==0){
			m[p.first]--;

		}
	}
	big=-1;
	for(auto p : m){
		if(p.second and p.first>big) big=p.first;
	}	
	cout<<big<<pl;
}
