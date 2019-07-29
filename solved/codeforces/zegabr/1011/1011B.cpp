#include <bits/stdc++.h>
using namespace std;
#define pl '\n'
#define sp ' '
int n,m,val;
map<int,int> freq;
//int range[101];
bool check(const int &d){
    int k=0;
    for(auto p : freq)k+=(p.second/d);
    return k>=n;
}
int bs(int l=1,int r=m){
    int m;
    while(r-l>1){
        m=(l+r)/2;
        if(check(m)) l=m;
        else r=m;
    }
    return check(r) ? r:l;
}

int main(){
    cin>>n>>m;
    if(n>m){
        cout<<0<<pl;
        return 0;
    }
    for(int i=1;i<=m;i++){
        //range[i]=i;
        cin>>val;
        freq[val]++;
    }
    //binary search here
    int ans = bs();
    
    
    
    
    cout<<ans<<pl;
}