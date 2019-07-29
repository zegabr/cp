#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;



int a[100000+5];
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	while(cin>>n){
		cin>>a[0];
		for(int i=1;i<n;i++){
			cin>>a[i];
		}
	
		int inf=2e5+5;
		int subtam=1,ans=0;
		for(int i=1;i<n;i++){	
			if(a[i]==a[i-1])subtam++;
			else{
			int aux=0;
				for(int j=i;j<subtam+i and j<n;j++){
					if(a[j]!=a[i-1])aux++;
					else break;
				}
				ans=max(ans,aux*2);
				subtam=1;
			}
		}
		cout<<ans<<pl;
		
		
	}
}