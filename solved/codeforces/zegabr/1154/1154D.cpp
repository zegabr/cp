#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;




	
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n,b,a;
	cin>>n>>b>>a;
	int ans=0;
	int ma=a;
	while(n--){
		int s; cin>>s;
		if(s){
			if(b and a<ma)b--, a=min(a+1,ma), ans++;
			else if(a) a--,ans++;
			else if(b) b--, ans++;
			else break;
		}else{
			if(a){
				a--;ans++;
			}else if(b){
				b--;ans++;
			}else break;
		}
	}
	cout<<ans<<pl;
}
