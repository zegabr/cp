#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;




int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	int a[n];
	for(int &v : a) cin>>v;


	for(int i=0;i<n;i++){
		int c=0;
		for(int j=0;j<n;j++){
			c+= a[j]>a[i];
		}
		cout<<c+1<<sp;
	}

	cout<<pl;
}
