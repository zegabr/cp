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
#define popcount(a) __builtin_popcountll((long long)(a))
#define fr(i,a,b) for(int i=a; i<=b; i++) 
#define rf(i,a,b) for(int i=a; i>=b; i--) 
#define fauto(k,c) for(auto &k : c)
#define PI acos(-1)

#define pqueue priority_queue
#define uset unordered_set
#define umap unordered_map
#define ld long double
#define ll long long
// #define int ll
using namespace std;

int num[11];
main(){
 	ios::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(20);
	//freopen("input","r",stdin);
	
	pqueue<int> pq;
	int n; cin>>n;
	if(n==1){
		cout<<-1<<endl;
		return 0;
	}
	fr(i,1,n){
		int v;
		cin>>v;
		num[i]=v;
		pq.push(-v);
	}

	int greg = -pq.top();
	pq.pop();
	//db(greg);
	int andr=0;
	while(pq.size()){
		andr+= -pq.top();
		pq.pop();
	}

	if(greg==andr){
		cout<<-1<<endl;
		return 0;
	}
	fr(i,1,10){

		if(num[i]==greg){greg=i;break;}
	}

	cout<<1<<endl<<greg<<endl;

}
