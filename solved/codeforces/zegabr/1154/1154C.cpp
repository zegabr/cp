#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;




	int dia[7];
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int a,b,c;
	
	cin>>a>>b>>c;
	int sem=min(a/3, min(b/2,c/2));
	
	a-=sem*3;
	b-=sem*2;
	c-=sem*2;
	int ans = sem*7;
	for(int d=0;d<7;d++){
		int a2=a,b2=b,c2=c;
		int da=d;
		/*
			if(da==0){
				
			}else if(da==1){
				a2++;
			}else if(da==2){
				a2++; b2++;
			}else if(da==3){
				if(a2)a2--, dia[d]++;
				else break;
			}else if(da==4){
				if(c2)c2--, dia[d]++;
				else break;
			}else if(da==5){
				if(b2)b2--, dia[d]++;
				else break;
			}else if(da==6){
				if(a2)a2--, dia[d]++;
				else break;
			}
			*/
		while(true){
			if(da==0){
				if(a2)a2--, dia[d]++;
				else break;
			}else if(da==1){
				if(b2)b2--, dia[d]++;
				else break;
			}else if(da==2){
				if(c2)c2--, dia[d]++;
				else break;
			}else if(da==3){
				if(a2)a2--, dia[d]++;
				else break;
			}else if(da==4){
				if(c2)c2--, dia[d]++;
				else break;
			}else if(da==5){
				if(b2)b2--, dia[d]++;
				else break;
			}else if(da==6){
				if(a2)a2--, dia[d]++;
				else break;
			}
			da++; da%=7;
		}
	}	
		for(int i=0;i<7;i++) dia[i]+=ans;
		for(int i=0;i<7;i++) ans = max(ans, dia[i]);
	
	cout<<ans<<pl;
}
