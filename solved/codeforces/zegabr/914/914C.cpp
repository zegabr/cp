#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;
const int mod = 1e9+7;

int dp[1010][1010];

int C(int n, int k){
	if(k<0 or k>n) return 0;
	if(k==0 or k==n) return 1;
	if(dp[n][k]) return dp[n][k];
	return dp[n][k] = (C(n-1,k)+C(n-1,k-1))%mod; 

}

int ord(int v){
	int a=0;
	while(v!=1){
		a++;
		v=__builtin_popcount(v);
	}
	return a;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string num;
	int k;
	cin>>num>>k;
	if(k==0){
		cout<<1<<pl;
		return 0;
	}
	int tam=num.size();
	int totaluns=0;

	int ans=0;
	for(char c : num) totaluns+= c=='1';
	if(ord(totaluns)==k-1) ans++;
	if(k==1) ans--;
	for(int i=1;i<=tam;i++){
		if(ord(i)==k-1){
			//cout<<"opa"<<endl;
			int uns=0;
			for(int j=0;j<tam;j++){
				if(num[j]=='1'){
					ans = (ans + C(tam-j-1, i-uns))%mod;
					uns++;
				}
			}
			
		}

	} 

	cout<<ans<<pl;




}