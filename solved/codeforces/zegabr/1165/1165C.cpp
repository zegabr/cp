#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;




int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; string s;
	cin>>n>>s;
	int c=0;
	for(int i=0; i <n-1;i++){
		if(~(i-c)&1 and s[i+1]==s[i]){
			c++;
			s[i]=sp;
		}
	}
	if((n-c)&1){
		int i=n-1;
		while(i>=0 and s[i]==sp)i--;
			c++;
			s[i]=sp;
		
	}

	cout<<c<<pl;
	for(int i=0;i<n;i++){
		if(s[i]!=sp)cout<<s[i];
	}
	cout<<pl;

}
