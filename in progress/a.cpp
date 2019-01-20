#include<bits/stdc++.h>
using namespace std;
#define pl '\n'
#define sp ' '
typedef long long ll;

//kattis apparatus
#define ms 1000
#define mod 1000003

void impossible(){
    cout<<0<<pl;
    exit(0);
}
bitset<ms> g[ms],da,db,tmp(0);
int m,n,fat[ms+5];
map<int,int> f;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    fat[0]=1;
    for(int i=0;i<n;i++){
        tmp.set(i);
        fat[i+1]=((i+1)*fat[i])%mod;
    }
    if(m==0){
        cout<<fat[n]<<pl;
        return 0;
    }
    for(int i=0;i<n;i++) g[i]=tmp;

    for(int i=0;i<m;i++){
        cin>>da>>db;

        if(da.count() != db.count())
            impossible();//dicas inconsistentes
        
        for(int a=0;a<n;a++){
            if(g[a]==0)continue;

            if(da[a]==1)g[a] &= db;
            else g[a] &= (~db);

            int c=g[a].count();
            if(c==0) 
                impossible();//algum vertice tem grau 0    
            else if(c==1){
                c=0;
                while(g[a][0]==0)g[a]>>1, c++;
                g[a].reset();
                for(int j=0;j<n;j++){
                    g[j].reset(c);
                    if(g[j].count()==0)
                        impossible();

                } 
            }
        }
    }

    for(int i=0;i<n;i++) f[g[i].count()]++;
    
    

    int ans=1;
    for(auto p : f){
        if(p.first!=0){
            if(p.first==p.second) ans = (ans * fat[p.first])%mod;
            else ans = (ans * p.second)%mod;
        }
    }
    cout<<ans<<pl;
}
