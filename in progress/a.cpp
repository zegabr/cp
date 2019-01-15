#include<bits/stdc++.h>
using namespace std;
#define pl '\n'
#define sp ' '
typedef long long ll;
typedef pair<ll,ll> pll;
//gopher 2




char c;
ll X1,X2,Y1,Y2;
ll m,n,s,V;
vector<pll> gophers;
vector<int> g[200]; 
vector<bool> vis(200);
int match[200];

void clrvis(){
    fill(vis.begin(),vis.end(),0);
}
void clrmatch(){
    fill(match,match+n+m,-1);
}
bool dfs(int u){
    if(vis[u]) return 0;
    vis[u]=1;
    for(int v : g[u]){
        if(match[v]==-1 or dfs(match[v])){
            match[v]=u;
            return 1;
        }
    }
    return 0;
}
int findMaxMatching(){
    int ans=0, aux=0;
    clrmatch();//limpa array de matches
    for(int i=n;i<n+m;i++){//dfs em todos os buracos (n...n+m-1)
        aux=0; 
        clrvis();//limpa os visitados
        dfs(i);
        for(int j=0;j<n;j++) aux += (match[j]!=-1);//conta gophers salvos (0..n-1)
        ans=max(ans,aux);
    }
return ans;
}

int main(){
    while(cin>>n>>m>>s>>V){
        V*=10; //em decimetros/seg
        //cout<<s*s*V*V<<pl;
        gophers.clear();
        for(int i=0;i<n;i++){
            g[i].clear();
            cin>>X1>>c>>X2>>Y1>>c>>Y2;
            X1=X1*10+X2; Y1=Y1*10+Y2; //em decimetros
            //cout<<X1<<sp<<Y1<<pl;
            gophers.emplace_back(X1,Y1);
        }
        for(int j=0+n;j<m+n;j++){
            g[j].clear();
            cin>>X1>>c>>X2>>Y1>>c>>Y2;
            X1=X1*10+X2; Y1=Y1*10+Y2; //em decimetros
            //cout<<X1<<sp<<Y1<<pl;
            
            for(int i =0 ; i< n; i++){
                X2=gophers[i].first; Y2=gophers[i].second;
                ll d2 = (X1 - X2)*(X1 - X2) + (Y1 - Y2)*(Y1 - Y2);//quadrado da distancia
                //cout<<d2<<pl;
                //cout<<s*s*V*V<<pl;//nao deveria dar overflow
                if(d2 <= s*s*V*V or s*s>=INT64_MAX/V/V){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        
        //gophers de 0 a n-1, buracos de n a n+m-1
        for(int i =0; i<n;i++){
            cout<<"gopher num "<<i<<": ";
            for(int j : g[i])cout<<j<<sp;
            cout<<pl;
        }
        
        cout<<n - findMaxMatching()<<pl;


    }
}