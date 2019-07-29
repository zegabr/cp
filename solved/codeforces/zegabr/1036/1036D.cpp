#include <bits/stdc++.h>
using namespace std;
char bb = '\n',sp=' ';

long long a[300005],b[300005],suma,sumb,aux,tam,n,m,i,j;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		suma+=a[i];
	}
	cin>>m;
	for(i=0;i<m;i++){
		cin>>b[i];
		sumb+=b[i];
	}
	if(suma!=sumb)cout<<-1<<bb;
	else{
		i=n-1;j=m-1;
		suma=a[i];
		sumb=b[j];
		while(i*j>0){
			if(suma==sumb){
				tam++;
				i--;j--;
				suma=a[i];
				sumb=b[j];
			}else{
				if(sumb>suma){
					i--;
					suma+=a[i];	
				}else if(suma>sumb){
					j--;
					sumb+=b[j];
				
				}
			
			}
			
		}
		cout<<tam+1<<bb;
	}
    return 0;
}


