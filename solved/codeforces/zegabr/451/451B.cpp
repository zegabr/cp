#include <bits/stdc++.h>
using namespace std;
char pl='\n', sp=' ';


int a[100005],n,i,j;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	while(cin>>n){
		//cout<<pl;
		for(i=0;i<n;i++) cin>>a[i];
		i=0;
		while(a[i]<=a[i+1] and i<n-1)i++; 
		if(i==n-1){
			cout<<"yes\n1 1\n";//is sorted
		}else{
			j=n-1;
			while(a[j-1]<=a[j] and j>1)j--;
			reverse(a+i,a+j+1);

			//for(int k=0;k<n;k++) cout<<a[k]<<sp;  
			//cout<<pl<<i<<sp<<j<<pl;
			
			if(is_sorted(a,a+n)){
				cout<<"yes\n"<<i+1<<sp<<j+1<<pl;
			}else{
				cout<<"no"<<pl;
			}

		}
	}	

}