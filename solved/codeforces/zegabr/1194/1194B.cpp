#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

#define endl '\n'
#define ll long long
#define ld long double
//#define int ll

using namespace std;

string t[50000];
int row[50000], col[50000];
int q,m,n,ans,c;
main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>q;
	while(q--){
		cin>>n>>m;
		fill(row,row+n,0);
		fill(col,col+m,0);

		for(int i=0;i<n;i++){
			cin>>t[i];
			for(int j=0;j<t[i].size();j++){
				col[j]+=t[i][j]=='.';
				row[i]+=t[i][j]=='.';
			}
		}
		ans = m*n;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(t[i][j]=='.')
					ans = min(ans, row[i]+col[j]-1);
				else ans = min(ans, row[i]+col[j]);
			}
		}

		cout<<ans<<endl;

	}
}
