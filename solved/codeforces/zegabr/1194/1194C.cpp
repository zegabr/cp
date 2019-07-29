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



main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int q; cin>>q;
	string s,t,p;
	while(q--){
		cin>>s>>t>>p;
		map<char,int> fs,ft;
		for(int i=0;i<s.size();i++)fs[s[i]]++;
		for(int i=0;i<p.size();i++)fs[p[i]]++;
		for(int i=0;i<t.size();i++)ft[t[i]]++;
		bool possible=1;
		for(auto &pa: ft){
			if(pa.second > fs[pa.first]){
				possible=0;
				break;
			}	
		}
		if(!possible or s.size()>t.size() or (s.size()==t.size() and s!=t)){
			cout<<"no"<<endl;
			continue;
		}
		if(s==t) {
			cout<<"yes"<<endl;
			continue;
		}

		int j=0;
		for(int i=0;i<s.size() and possible;i++){
			possible=0;
			for(;j<t.size();j++){
				if(s[i]==t[j]){
					t[j]='.';
					possible=1;
					break;
				}
			}
		}
		if(possible){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}

	}

}
