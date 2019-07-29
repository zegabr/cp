#include <bits/stdc++.h>
using namespace std;

string s,t;
unordered_map<char,int> m;
int n,c;
int main(){
	while(cin>>n>>s>>t){
		 c=0;
		for(int i=0,j=n-1;i<n/2;i++,j--){
			m.clear();
			m[s[i]]++; m[s[j]]++;
			m[t[i]]++; m[t[j]]++;
			if(m.size()==4)c+=2;
			else if(m.size()==3){
				if(s[i]==s[j]) c+=2;
				else c++;
			}else if(m.size()==2 and m[s[i]]&1)c++;
		}
		if(n&1 and s[n/2]!=t[n/2])c++;
		cout<<c<<endl;
	
	
	
	
	}
	


}
