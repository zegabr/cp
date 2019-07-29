#include <iostream>
using namespace std;
 //Compiler version g++ 6.3.0
int n,indx,q[150],freq[150],k;
string s;
 int main()
 {
 	cin>>n>>k>>s;
 	for(int i=0;i<n;i++){
 		freq[s[i]]++;
 	}
 	for(int i='a';i<='z';i++){
 		if(freq[i]<k){
 			q[i]+=freq[i];
 			k-=freq[i];
 		}
 		else{
 			q[i]+=k;
 			k=0;
 			break;
 		}
 	}
     for(int i =0; i < n;i++){
     	char c=s[i];
     	if(q[c]>0){
     		q[c]--;
     	}else
     	cout<<c;
     }

cout<<endl;




 }