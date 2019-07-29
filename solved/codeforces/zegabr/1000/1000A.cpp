#include <bits/stdc++.h>
using namespace std;

int n,sec;
string s;
map <string,int> m1,m2;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		m1[s]++;
	}
	for(int i=0;i<n;i++){
		cin>>s;
		m2[s]++;
	}
	for (auto it : m1) 
		n -= min(it.second, m2[it.first]);
	cout<<n<<endl;

    return 0;
}


