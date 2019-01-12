typedef pair<int,int> ii;
typedef vector<ii> vii;
int dis[maxn];
vii g[maxn];
priority_queue <ii,vii,greater<ii>> pq;
const int infi = 1231231;

bool dijkstra(int S, int T){
    bool way =false;
    fill(dis,dis+maxn,infi);
    dis[S]=0;
    pq.push(ii(0,S));
    while(pq.size()){
        ii aux=pq.top(); pq.pop();
        int u=aux.second;
        for(auto child : g[u]){
            int ew=child.first, v=child.second;
            if(v==T)
                way=true;
            if(dis[u]+ew<dis[v]){           
                dis[v]=dis[u]+ew;
                pq.push(ii(dis[v],v));
            }
        }
    }
    return way;
}