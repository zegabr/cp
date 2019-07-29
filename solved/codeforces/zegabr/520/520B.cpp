#include <bits/stdc++.h>
using namespace std;
int f(int n, int m){
	if(n>=m) return n-m;
	if(m&1) return 2+f(n,(m+1)>>1);
	else return 1+f(n,m>>1);

}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<f(a,b)<<endl;
}

