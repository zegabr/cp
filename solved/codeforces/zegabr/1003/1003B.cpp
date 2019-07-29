#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define sp ' '
#define pl '\n'
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rep(i, a, b) for(int i=a;i<=b;i++)//ri=a+b-i to revert loop

typedef long long ll;
const ll mod=1e9+7;
const ll N=1e5+5;

string s;
int a,b,xx,k;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10);
	cin>>a>>b>>xx;
	if(xx&1){
		if(a>b){
		rep(i,1,xx/2) s+="01";
		rep(i,1,a-xx/2) s+='0';
		rep(i,1,b-xx/2) s+='1';
		}else{
		rep(i,1,xx/2) s+="10";
		rep(i,1,b-xx/2) s+='1';
		rep(i,1,a-xx/2) s+='0';
		}
	}else{
		if(a>b){
		rep(i,1,xx/2) s+="01";
		rep(i,1,b-xx/2) s+='1';
		rep(i,1,a-xx/2) s+='0';
		}else{
		rep(i,1,xx/2) s+="10";
		rep(i,1,a-xx/2) s+='0';
		rep(i,1,b-xx/2) s+='1';
		}		
	}	
	cout<<s<<pl;	
		
	
}
