#include <bits/stdc++.h>
 using namespace std;
  char bb = '\n',sp=' '; 
  long long m,n,d,f,i,j,mmo,totalf,maxf;
   pair<long long,long long> a[1000005]; 
   int main(){
   	 ios::sync_with_stdio(0); cin.tie(0); 	
   	 cin>>n>>d; 
   	 for(i=0;i<n;i++){ 	
   	 		cin>>m>>f; 	
   	 		a[i]={m,f}; 
   	 }
   	 sort(a,a+n);//sort by money 	
  	 mmo=a[0].first; 
  	 totalf=maxf=a[0].second;
  	 
  	 i=j=0; 
   	 while(i<n){ 	
   	 		if(j<n-1){
  					while((a[j+1].first - mmo <d) && j<n-1){ 
   	 					j++; 
   	 				    totalf+=a[j].second;
   	  				} 
   	 					maxf=max(maxf,totalf);			 
   	 		} 	
   	 								
   	 	totalf-=a[i].second;//delete last friend 	
   	 	i++;//go to next minimum money friend whose friendship has already been addded to totalf 
   		mmo=a[i].first;//new minimum money 
   	 } 
   	cout<<maxf<<bb;
   	 					
}
