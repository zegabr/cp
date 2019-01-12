vector<int> g[maxn], topo;
int vis[maxn], 
void toposort(int u){
    visited[u]=1;
        for(auto v : g[u]){
            if(!visited[v]){
                toposort(v);
            }
        }
    topo.push_back(u);
}

void solve(){
    fill(vis,vis+maxn,0);
    for(int i=0; i< V; i++) toposort(i);
    reverse(topo.begin(), topo.end());
}

/////-----------or iterative----------////
vector<int> g[maxn], vis[maxn];
map<int,int>grau;

void toposort(){
    priority_queue<int, vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++)if(grau[i]==0)pq.push(i);
    while(pq.size()){
        int u = pq.top(); pq.pop();
        for(auto v : g[u]){
            grau[v]--;
            if(!vis[v] and grau[v]==0) pq.push(v);
        }
        topo.push_back(u);
        vus[u]=1;
    }
}