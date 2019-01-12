//BFS FOR UNWEIGHTED GRAPHS MINIMUM DISTANCE

int V;//#vertices
vector<int> g[V];
int dis[V];

int BFS(int start,int goal){
    queue<int> q;
    fill(dis,dis+V,maxn);
    dis[start]=0;
    q.push(start);
    while(q.size()){
        int u = q.front(); q.pop();
        for(auto v : g[u]){
                if(dis[u]+1<dis[v]){
                    dis[v]=dis[u]+1;
                    q.push(v);
                }
            }
        }
    }
    //retorna -1 se nao houver caminho, menor caminho caso contrario
    return dis[goal]==V ? -1 : dis[goal];  
}