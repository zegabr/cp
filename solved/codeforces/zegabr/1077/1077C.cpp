#include <bits/stdc++.h>
using namespace std;
char pl = '\n',sp=' ';
typedef long long ll;
typedef pair<int,int> pii;
ll a[200005],sum,k,n,i,aux;
vector<int> poss;
map<int,int> m;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		m[a[i]]++;
		sum+=a[i];
	}
	for(i=0;i<n;i++){
	aux = (sum-a[i]);
		if(aux%2==0 and ((m[aux/2]>0 and a[i]!=aux/2) or (m[aux/2]>1) ) and aux/2 <=1e6) 
			poss.push_back(i+1);
	}
	cout<<poss.size()<<pl;
	for(i=0;i<poss.size();i++)
		cout<<poss[i]<<(i==poss.size()-1 ? pl : sp);
	
	
}