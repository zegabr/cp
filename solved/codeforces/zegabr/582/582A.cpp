#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	while(b) a%=b, swap(a,b);
	return a;
	
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,i,j,g,ma;
	vector<int> a;
	map<int, int> m;
	while(cin>>n){
	//cin>>n;
	m.clear(), a.clear();
	j=n*n;
	for(i=0;i<j;i++){
		cin>>g;
		m[g]++;
	}
	
	
	ma=m.rbegin()->first;//fazer substituicoes
	a.push_back(ma);
	cout<<ma<<' ';
	m[ma]--;
	if(!m[ma]) m.erase(ma);
	
	
	
	for(int k=0;k<n-1;k++){
		ma=m.rbegin()->first;
		a.push_back(ma);
		m[ma]--;
		if(!m[ma]) m.erase(ma);
		
		for(i = 0; i<a.size()-1;i++){
			g=gcd(a[i],a.back());
			m[g]-=2;
			if(!m[g]) m.erase(g);
		}
		cout<<a.back()<<(" \n"[k==n-2]);
		
	}
	
	
	
	}
}
