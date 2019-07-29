#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;
//#define int ll



int t,n,a,b,c,ans; 
main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		map<int,int> m;
		for(int i=0;i<n;i++){
			int in;
			cin>>in;
			in%=3;
			//cout<< in<<sp;
	
			m[in]++;
		}
		ans = m[0];
		int aux = min(m[2],m[1]); 
		ans+=aux;
		m[2]-=aux; m[1]-=aux;
		ans+=m[2]/3 + m[1]/3;
		cout<<ans<<pl;
		}

}
/*
#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;
#define int ll



int t,n,a,b,c,ans; 
main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		vector<int>a(n),aux;
		for(int &in : a){
			cin>>in;
			in%=3;
			if(in==0)in=3;
			ans+=in;
		}
		cout<<min(ans/3, n)<<pl;
	}

}*/
