
//generally as fast as dijkstra
const int ms = 2e7+5;
vector<int> dis(ms), vis(ms);
vector<bool> inq(ms);
vector<pair<int,int>> g[ms];//g[u] contains {w, v}
const int inf = 0x3f3f3f3f;
int V;//numero de vertices, atualizar no main

int spfa(int S, int T){
    bool way = false;
    dis.assign(ms, inf);
    inq.assign(ms,0);
    vis.assign(ms,0);
    
    queue<int> q({S});
    dis[S]=0;
    inq[S]=1;

    while(q.size()){
        int u = q.front(); 
        q.pop(); inq[u]=0;
        if(vis[u] > V) return -1;//has negative cycle
        for(auto child : g[u]){
            int v = child.second, w = child.first;
            if(dis[u]+w < dis[v]){
                dis[v] = dis[u]+w;
                if(!inq[v]){
                    q.push(v); 
                    inq[v]=1;
                    vis[v]++;
                }
            }
        }
    }
    return dis[T];
}
