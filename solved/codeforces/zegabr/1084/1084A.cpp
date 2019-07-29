#include <bits/stdc++.h>
using namespace std;

#define pl '\n'
#define sp ' '
typedef long long ll;
typedef pair<int,int> pii;
ll a[101],ans=2e9+10,aux;


inline ll f(const ll &x, const ll &i){
	return 2*a[i]*(abs(i-x)+i+x);
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    //cout<<fixed<<setprecision(10);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	cin>>a[i];
	for(int x=0;x<100;x++){
		aux=0;
		for(int i=0;i<100;i++){
			aux+=f(x,i);
		}
		ans=min(ans,aux);
	
	}
	cout<<ans<<pl;

}
