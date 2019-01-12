//////BFS///////
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

////////DFS////////
void dfs(int u){
    if(vis[u]) return;
    vis[u]=true;
    for(auto v : g[u]){
        if(vis[v]) continue;
        
        dfs(v);
    }
}

//////DIJKSTRA///////
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

////////FLOYD WARSHALL///////
const int inf = 0x3f3f3f3f;
int g[ms][ms], dis[ms][ms], n;

void clear() {
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      g[i][j] = i == j ? 0 : inf;
    }
  }
}

void add(int u, int v, int w) {
  g[u][v] = min(w, g[u][v]);
}

void floydWarshall() {
  memcpy(dis, g, sizeof dis);
  for(int k = 0; k < n; k++) {
    for(int i = 0; i < n; i++) { 
      for(int j = 0; j < n; j++) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
}

/////////KRUSKAL///////
int ds[200000+10];
vector <iii> edges;
iii ed;
//DISJOINT SET UNION FUNCTIONS
void makeset(){
    for(int i=0;i<v;i++) ds[i]=i;
}
int find(int i){//find
	if(ds[i]==i)
		return i;
	return ds[i]=find(ds[i]);
}
bool uni(int a, int b){//union
	if(find(a)==find(b)) 
        return false;
    ds[find(b)]=find(a); 
    return true;
}

int main(){
    //salva arestas em edges
    sort(edges.begin(),edges.end());
    makeset();
    for(auto ed : edges){
        a=ed.second.first; b=ed.second.second;
        if(uni(a,b)){
            mst+=ed.first;//aqui uma aresta foi adicionada na mst
        }
    
    }
    
    cout<<mst<<endl;

	
	

    return 0;
}

///////TOPOSORT////////(ITERATIVO)
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
        vis[u]=1;
    }
}

