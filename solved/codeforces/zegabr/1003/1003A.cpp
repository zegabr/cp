#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> m;
int n,total,aux;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	while(n--){
		cin>>aux;
		m[aux]++;
		total=max(total,m[aux]);
	}
	cout<<total<<endl;

    return 0;
}


