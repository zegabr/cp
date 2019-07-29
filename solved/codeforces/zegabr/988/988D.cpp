#include <bits/stdc++.h>
using namespace std;

int n,j,x,p;
set <int> s;
bool is3,is2;
int main(){
    cin>>n;
    while(n--){
        cin>>x;
        s.insert(x);
    }
    for(j=0;j<=30;j++){
        p=1<<j;
        for(int x : s){
            if(s.count(x-p)&&s.count(x+p)){
                cout<<3<<endl;
                cout<<x-p<<" "<<x+p<<" "<<x<<endl;
                return 0;
            }
        }
    }
    for(j=0;j<=30;j++){
        p=1<<j;
        for(int x : s){
            if(s.count(x+p)){
                cout<<2<<endl;
                cout<<x+p<<" "<<x<<endl;
                return 0;
            }
        }
    }
    cout<<1<<endl;
    cout<<*s.begin()<<endl;
    return 0;
}