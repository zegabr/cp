#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

#define endl '\n'

using namespace std;

using ll = long long;
//#define int ll

int ans = 2;
vector<int> m[3];
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string t;
	for(int i=0;i<3; i++){
		cin>>t;
		if(t[1]=='m')m[0].push_back((int)t[0]-'0');
		if(t[1]=='s')m[1].push_back((int)t[0]-'0');
		if(t[1]=='p')m[2].push_back((int)t[0]-'0');
	}

	for(int i=0;i<3;i++){
		sort(m[i].begin(),m[i].end());
		//for(auto v:m[i])cout<<v<<' ';
		//cout<<endl;
		if(m[i].size()<2) continue;
		if(m[i].size()==3 and (m[i][0]==m[i][2] or (m[i][0]==m[i][1]-1 and m[i][0]==m[i][2]-2))){
			ans = min(ans,0);
		}else if(m[i].size()==3){
			if(m[i][0]==m[i][1]-1 or m[i][1]==m[i][2]-1 or m[i][0]==m[i][1] or m[i][1]==m[i][2] or m[i][1]-m[i][0]==2 or m[i][2]-m[i][1]==2 ){
				ans=min(ans,1);
			}
		}else{//size==2
			if(m[i][0]==m[i][1]-1 or m[i][0]==m[i][1] or m[i][0]==m[i][1]-2){
				ans=min(ans,1);
			}

		}
	}


	cout<<ans<<endl;




}
