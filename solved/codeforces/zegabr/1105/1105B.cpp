#include <bits/stdc++.h>
using namespace std;
#define pl '\n'
#define sp ' '
#define Y "YES"
#define N "NO"
typedef long long ll;
typedef pair<ll,ll> pll;






ll maxfreq=0;
string s;
map<char,ll> freq;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10);
	int n,k;
	cin>>n>>k>>s;
	int pd[n+1];
	pd[0]=1;
	if(k==1) freq[s[0]]=1;
	maxfreq = max(maxfreq, freq[s[0]]);
	for(int i=1;i<s.size();i++){
		if(s[i]==s[i-1] and pd[i-1]<k){
			pd[i]=pd[i-1]+1;	
		}else pd[i]=1;
		if(pd[i]==k){
				freq[s[i]]++;
				maxfreq = max(maxfreq, freq[s[i]]);
		}
	}
cout<<maxfreq<<pl;


}
