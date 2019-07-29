#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;
#define int ll


int t,a,b,c,n;
main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>t;
	while(t--){
		a=b=c=0;
		cin>>n;
		//cout<<n<<sp;
		while(n%2==0)n/=2,a++;
		while(n%3==0)n/=3,b++;
		while(n%5==0)n/=5,c++;

		if(n>1){
			cout<<-1<<pl;
			continue;
		}
		//		cout<<"a="<<a<<" b="<<b<<" c="<<c<<pl;
		cout<<a+ b+c+c  + b + c<<pl;


	}
}
