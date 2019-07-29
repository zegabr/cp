#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
#define yes "YES\n"
#define no "NO\n"
using namespace std;
typedef long long ll;



set<char> vowels={'a','e','i','o','u','n'};
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	cin>>s;
	int n = s.size();
	if(vowels.count(s.back())==0){
		cout<<no;
		return 0;
	}else{
		for(int i=0;i<n-1;i++){
			if(vowels.count(s[i])==0 and (vowels.count(s[i+1])==0 or s[i+1]=='n')){
				cout<<no;
				return 0;
			}
		}
		cout<<yes;
		return 0;
	}
}