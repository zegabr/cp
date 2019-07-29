#include <bits/stdc++.h>
using namespace std;

stack <int> stk;
int n,k,a,total;
bool streak=true;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a<=k && streak){	
			total++;
		}else{
			streak=false;
			stk.push(a);
		}
	}
	if(!stk.empty()){
	while(stk.top()<=k){
		stk.pop();
		total++;
	}
	}
		cout<<total<<endl;
	

    return 0;
}


