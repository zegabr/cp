#include <bits/stdc++.h>
using namespace std;

#define pl '\n'
#define sp ' '
typedef long long ll;
typedef pair<int,int> pii;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    //cout<<fixed<<setprecision(10);
	ll n, s, a[1005],aux;
	cin>>n>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
		aux+=a[i];
	}
	if(aux<s){
		cout<<-1<<pl;
		return 0;
	}
	sort(a,a+n);
	ll mi=a[0];
	for(int i=1;i<n;i++){
		if(a[i]>mi){
			if(a[i]-mi >= s){
				cout<<mi<<pl;
				return 0;
			}else{
				//a[i]=mi;
				s=s-(a[i]-mi);
			}
		}
	}	
	//all a[i] is now mi, so we have n*mi
	while(s>0){
		mi--;
		s-=n;
	}
	cout<<mi<<pl;
	
	

}
