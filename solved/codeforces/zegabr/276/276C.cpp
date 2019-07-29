#include<bits/stdc++.h>
using namespace std;
#define pl '\n'
#define sp ' '
#define maxn 400005
typedef unsigned long long ll;
ll bit[maxn],a[maxn],n,q,i,j, ans;
vector<ll> qnt, v;

ll sum(ll i){
    ll res =0;
    while (i){
        res += bit[i];
        i-= i&-i;
    }
    return res;
}
void ad(ll i,ll val){
    while(i<=n){
        bit[i]+=val;
        i+= i&-i;
    }
}
void pbit(){
    for(int i=0;i<=n;i++)cout<<i<<sp;
    cout<<pl;
    for(int i=0;i<=n;i++)cout<<sum(i)<<sp;
    cout<<pl<<pl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(i=0;i<n;i++){
        cin>>j;
        v.push_back(j);
    }
    while(q--){
        cin>>i>>j;
        ad(i,1);
        ad(j+1,-1);
       // pbit();//working
    }
    for(i=1;i<=n;i++){
        qnt.push_back(sum(i));
    }
    ans=0LL;
    sort(v.begin(),v.end());
    sort(qnt.begin(),qnt.end());
     for(i=0;i<n;i++){
        ans+=qnt[i]*v[i];
    }
    cout<<ans<<pl;
}