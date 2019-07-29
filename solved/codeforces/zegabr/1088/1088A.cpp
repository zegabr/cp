#include<iostream>
#include<algorithm>
#include<vector>
using namespace std; typedef long long ll;
#define sp ' '
#define pl '\n'
const int N = 5 + 1e5 * 3;


ll b,k,x;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>x;
	for(int b=1;b<=x;b++){
		for(int k=1;k<x;k++){
			if(b*b*k > x and k < x){
				cout<<b*k<<sp<<b;
				return 0;
			}
		}
	}
	cout<<-1<<pl;
}
