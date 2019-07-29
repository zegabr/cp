#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define sp ' '
#define pl '\n'
#define pb push_back
#define sz size
#define all(x) (x).begin(),(x).end()

typedef long long ll;
char m[27]={'Z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
ll fexp(ll a, ll b){
	ll ans =1;
	while(b){
		if(b&1) ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;

}
string s;
vector<string> v;
void resetv(){
	v.clear();
	string aux;
	for(int i=0;i<s.sz();){
	aux="";
		if(s[i]>='A' and s[i]<='Z'){
			int j=i;
			while(s[j]>='A' and s[j]<='Z') aux+=s[j++];
			v.pb(aux);
			i=j;
		}else{
			int j=i;
			while(s[j]>='0' and s[j]<='9') aux+=s[j++];
			v.pb(aux);
			i=j;
		}
	}
	//for(auto k : v)cout<<k<<sp;
	//cout<<pl;

}
bool isnormal(const string &s){

	if(v.size()==2) return false;
	
	//normaltoalfa here
	ll col = stoll(v.back());
	string aux="";
//	if(col<27) aux=m[col], col=0;
	while(col){
		ll r=col%26;
		aux=  m[r]+aux;
		col-=r;
		col/=26;
		if(!r)col--;
	}
	cout<<aux<<v[1]<<pl;
	return true;

}
void alfatonormal(const string &s){
	
	string aux="R";
	aux+=v.back();
	
	aux+='C';
	string col = v[0];
	int n = col.sz();
	ll colnum=0;
	for(int i=0;i<n;i++){
		int ind = n-1-i;
		colnum+=((ll)(col[ind] - 'A' +1))*fexp(26, i);
	}
	aux+=to_string(colnum);
	cout<<aux<<pl;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10);
	int n;
	bool normal;
	cin>>n;
	while(n--){
		
		cin>>s;
		resetv();
		normal=isnormal(s);
		if(!normal) alfatonormal(s);
	
	}

}
