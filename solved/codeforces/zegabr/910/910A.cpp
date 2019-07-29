#include <bits/stdc++.h>
using namespace std;

#define pl '\n'
#define sp ' '


string s;
int n,d;
int mind[101];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    //cout<<fixed<<setprecision(10);
	while(cin>>n>>d>>s){
		for(int i=0;i<n;i++)mind[i]=2000;
		mind[0]=0;
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				for(int k=1;k<=d;k++){
					if(i+k>=n)continue;
					if(s[i+k]=='1'){
						mind[i+k]=min(mind[i+k],mind[i]+1);
					}
				}
			}
		}
		//cout<<s<<pl;
		//for(int i=0;i<n;i++)cout<<mind[i]<<sp;
		//cout<<pl;
		if(mind[n-1]==2000)cout<<-1<<pl;
		else cout<<mind[n-1]<<pl;
	}
	

}
