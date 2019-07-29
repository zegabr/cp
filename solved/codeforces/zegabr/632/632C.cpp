#include <bits/stdc++.h>
using namespace std;
 //Compiler version g++ 6.3.0
int n;
string a[500000];
bool c(string s, string t){
	return (s+t)<(t+s);
}
 int main()
 {
 	 cin>>n;
 	 for(int i=0;i<n;i++)
 	   cin>>a[i];
 	 sort(a, a+n,c);
 	 for(int i=0;i<n;i++)
 	   cout<<a[i];
 	   cout<<'\n';
 	 
 }