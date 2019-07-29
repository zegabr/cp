#include<bits/stdc++.h>
#define sp ' '
#define pl '\n'
using namespace std;
typedef long long ll;


int a[] = {4,8,15,16,23,42};
int main(){
	//ios::sync_with_stdio(0); cin.tie(0);
	int a00,a11,a23,a34;
	cout<<"? 1 1"<<endl;
	cin>>a00;
	cout<<"? 2 2"<<endl;
	cin>>a11;
	cout<<"? 3 4"<<endl;
	cin>>a23;
	cout<<"? 4 5"<<endl;
	cin>>a34;

	do{
		if(a00==a[0]*a[0] and a11==a[1]*a[1] and a23==a[2]*a[3] and a34==a[3]*a[4]) break;
	}while(next_permutation(a,a+6));

	cout<<"!";
	for(int v : a)cout<<" "<<v;
	cout<<endl;
}
