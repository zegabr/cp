#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
#define fi first
#define se second
#define mod(X) (X)%MOD
#define rep(i,a,b) for(int i = a; (a>b? i>=b : i<=b) ; (a>b? i-- : i++) )
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
//==================================
#define x real()
#define y imag()
#define PI 3.1415926535897932384626

const ld eps=1e-13;

typedef complex<ld> P;
set<pll> polA,polB;
ll cross(const P &p,const P &q){
	return (conj(p)*q).y;
}
P orig;
bool comp(const P &a, const P &b){//works on leftmost
	//compare by angle between a-orig and b-orig
	ld arg1 = (ld)arg(a-orig), arg2 = (ld)arg(b-orig);
	ld abs1 = (ld)abs(a-orig), abs2 = (ld)abs(b-orig);
	
	if(fabs(arg1-arg2)<eps){
		if(fabs(arg1-PI/2.0)<eps)return abs1-abs2>eps;
		return abs1-abs2<eps;
	}
	else return arg1<arg2;
	
	
	
}//working

//================================
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,m;
	int a,b;
	vector<P> v;
	cin>>n;
	rep(i,1,n){//n
		cin>>a>>b;
		polA.insert({a,b});
		P p(a,b);
		v.push_back(p);
	}
	cin>>m;
	rep(i,1,m){//nlogm
		cin>>a>>b;
		if(polA.count({a,b})){
			cout<<"NO"<<pl;
			return 0;
		}
		P p(a,b);
		v.push_back(p);

	}
//=========================================convexhull
	int	ind = 0;
	rep(i,1,v.size()-1){
		//get leftmost
		if(v[i].x<v[ind].x or (v[i].x==v[ind].x and v[i].y<v[ind].y)) ind=i;
	}
	orig=v[ind];
	swap(v[0],v[ind]);
	sort(v.begin()+1,v.end(),comp);//counterclockwise


	int s=3;
	for(int i=3; i<v.size(); i++){
		while(s>=3 and cross(v[s-1]-v[s-2], v[i]-v[s-1])<0LL){//while turn right 
		//cout<<"right turn in the sequence "<<v[s-2].x<<sp<<v[s-2].y<<'/'<<v[s-1].x<<sp<<v[s-1].y<<'/'<<v[i].x<<sp<<v[i].y<<pl;
			s--;
		}
		v[s]=v[i];
		s++;
	}
//v.resize(s);
////==================================================
	if(n==s){
		bool ok=1;
		for(int i=0;i<s and ok;i++){	
			ok=polA.count({v[i].x, v[i].y});
		}
		if(ok){
			cout<<"YES"<<pl;
			return 0;
		}
	}

	cout<<"NO"<<pl;
	return 0;



}
