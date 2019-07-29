#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;
//#define int ll



int n,v;
unordered_map<int,int> m;
main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	int ans=0;
	for(int i=0;i<n;i++){
		cin>>v;
		if(v==4){
			m[4]++;
		}else if(v==8){
			if(m[4]>m[8]) m[8]++;
			else ans++;
		}else if(v==15){
			if(m[8]>m[15]) m[15]++;
			else ans++;
		}else if(v==16){
			if(m[15]>m[16]) m[16]++;
			else ans++;
		}else if(v==23){
			if(m[16]>m[23]) m[23]++;
			else ans++;
		}else if(v==42){
			if(m[23]>m[42]) m[42]++;
			else ans++;
		}
	}
	int a[] = {4,8,15,16,23,42};
	int mini = 0x3f3f3f3f;
	for(int &k:a) mini=min(mini,m[k]);
	
	cout<<n-6*mini<<pl;
	
	
}
