#include<bits/stdc++.h>
using namespace std;
#define pl '\n'
#define sp ' '
typedef long long ll;
typedef pair<ll,ll> pll;
//elementary math
const ll maxn = 2500*5;



ll val;
ll n, z;
ll match[maxn];
ll arr[3];
vector<ll> g[maxn]; 
vector<bool> vis(maxn);
vector<pll> vp;
map<ll,ll> indof;
map<ll,ll> valof;
ll a,b;

void clrvis(){
    fill(vis.begin(),vis.end(),0);
}
void clrmatch(){
    fill(match,match+n,-1);//limpa de 0 a n-1 (tamanho utilizado do array de match)
}
bool dfs(ll u){
    if(vis[u]) return 0;
    vis[u]=1;
    for(ll v : g[u]){
        if(match[v]==-1 or dfs(match[v])){
            match[v]=u;
            return 1;
        }
    }
    return 0;
}
bool findMaxMatching(){
    ll ans=0LL, aux=0LL;
    clrmatch();//limpa array de matches
    for(ll i=n;i<z;i++){//dfs partindo de todos os valores (n...n+m-1)
        aux=0; 
        clrvis();//limpa os visitados
        dfs(i);
        for(ll j=0;j<n;j++) aux += (match[j]!=-1);//conta matches feitos (0..n-1)
        ans=max(ans,aux);
    }
return ans==n;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    z=n+1;
    for(ll i=0;i<n;i++){
        cin>>a>>b;
        vp.push_back({a,b});
        arr[0]=a+b , arr[1]=a-b, arr[2]=a*b;
        for(ll val : arr){
            if(indof.count(val)==0){//ainda nao indexado
                indof[val]=z;
                valof[z] = val;
                z++;
            } 
            g[i].push_back(indof[val]);
            g[indof[val]].push_back(i);
        }

    }
    
    if(!findMaxMatching()) cout<<"impossible"<<pl;
    else{
        for(ll i=0;i<n;i++){
            a=vp[i].first, b=vp[i].second;
           /*
            //printa grafo
            printf("g[%d]=%d,%d =>> ",i,a,b);
            for(int ind : g[i]) printf("%lld ",valof[ind]);
            printf("\n");
           */
            char c;
            val = valof[match[i]];
            if(val==a+b) c='+';
            else if(val==a-b) c='-';
            else c='*';
            //printa resposta
            printf("%lld %c %lld = %lld\n",a,c,b,val);

        }
    }
}