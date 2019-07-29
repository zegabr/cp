#include <bits/stdc++.h>
using namespace std;
char pl = '\n',sp=' ';
typedef long long ll;
typedef pair<int,int> pii;
int n,p;
	vector<int> a(101);
	vector<int> ma;
	int i,j;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<n;i++){//i>1 i<n
		if(a[i-1] and a[i+1] and !a[i]) ma.push_back(i);
	}
	if(ma.empty()){
		cout<<0<<pl;
		return 0;
	}
	i=0;j=1;
	while(j<ma.size()){
		if(ma[j]-ma[i]==2){
		 p++; 	
		 //cout<<ma[i]<<sp<<ma[j]<<"se seáram por 2"<<pl; 	
		 i+=2;j+=2;
		}
		else{
			i++,j++;
		}
	}
	
	cout<<ma.size()-p<<pl;
}
