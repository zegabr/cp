#define TESTCASE
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
#define x first
#define y second
#define ii pair<int,int>
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ll long long
#define ld long double
#define len(v) ((int)v.size())
#define fa(a,c) for(auto &a : c)
#define all(k) k.begin(),k.end()
#define rall(k) k.rbegin(),k.rend()
#define no cout<<"NO"<<endl
#define yes cout<<"YES"<<endl
#define db(x) cerr<<#x<<" = "<<x<<endl
#define codejam(k) cout<<"Case #"<<k<<": "
#define endl '\n'





void main2(int caso=0){
    codejam(caso);


}
int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cout<<setprecision(7);
    int t; 
#ifdef TESTCASE
    cin>>t;
#else 
    t = 1;
#endif
    for(int i=1;i<=t;i++) main2(i);
}
