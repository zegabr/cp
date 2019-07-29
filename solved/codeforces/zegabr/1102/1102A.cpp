#include<iostream>
using namespace std;

long long n;
int main(){
    cin>>n;
    n=((1+n)*n)/2;
    if(n&1)cout<<1<<endl;
    else cout<<0<<endl;
    
    
}