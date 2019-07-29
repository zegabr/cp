#include <bits/stdc++.h>
using namespace std;
 
set<double> sl;
int n;
double inf = 1e9,xi,yi,xs,ys;
 int main(){
 	cin.tie(0); ios::sync_with_stdio(0);
 	while(cin>>n>>xi>>yi){
 	sl.clear();
 		while(n--){
 			cin>>xs>>ys;
 			xs-=xi; ys-=yi;
 			if(ys==0)sl.insert(0);
 			else if(xs==0)sl.insert(inf);
 			else sl.insert(ys/xs);
 		}
 		cout<<sl.size()<<'\n';
 	}
 }