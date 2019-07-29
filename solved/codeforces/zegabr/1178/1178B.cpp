#define debug 
#include <set>
#include <map>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <complex>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
//#include <random>
//#include <chrono>

#define endl '\n'
#define dif !=
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(k) (k).begin(),(k).end()
#define rall(k) (k).rbegin(),(k).rend()
#define db(k) cerr << #k<< " = " << k << endl
#define fr(i,a,b) for(int i=a; i<=b; i++) 
#define rf(i,a,b) for(int i=a; i>=b; i--) 
#define fauto(k,c) for(auto &k : c)
#define PI acos(-1)

#define pqueue priority_queue
#define uset unordered_set
#define umap unordered_map
#define ld long double
#define ll long long
#define int ll
using namespace std;
const int ms=1111111;
int r[ms],l[ms],ans;
main(){
	ios::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(20);
	//freopen("input","r",stdin);
	string s; cin>>s;
	if(s.size()<5){
		cout<<0<<endl;
		return 0;
	}
	fr(i,1,s.size()-1){
		l[i]=l[i-1]+ (s[i]=='v' and s[i-1]=='v');
	}
	rf(i,s.size()-2,0){
		r[i]=r[i+1] + (s[i]=='v' and s[i+1]=='v');
	}

	fr(i,1,s.size()-2){
		if(s[i]=='o') ans += l[i-1]*r[i+1];
	}

	cout<<ans<<endl;	
}
