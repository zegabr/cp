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

///////TOPOSORT////////(ITERATIVO e intuitivo)
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

///////KUHN'S ALGORITHM//////////////////////////////
//bipartite unweighted graph maximum matching
vector<int> g[200]; //grafo bipartido
vector<bool> vis(200);
int match[200];
//m vertices em um grupo, n vertices em outro
void clrvis(){
    fill(vis.begin(),vis.end(),0);
}
void clrmatch(){
    fill(match,match+n+m,-1);//só é necessario limpar o range utilizado nos matchs (m ou n)
}
bool kuhn(int u){//dfs based
    if(vis[u]) return 0;
    vis[u]=1;
    for(int v : g[u]){
        if(match[v]==-1 or kuhn(match[v])){
            match[v]=u;
            return 1;
        }
    }
    return 0;
}
int findMaxMatching(){
    int ans=0, aux=0;
    clrmatch();//limpa array de matches
    for(int i=n;i<n+m;i++){//dfs em todos os vertices do 2o grupo (n...n+m-1)
        aux=0; 
        clrvis();//limpa os visitados
        kuhn(i);
        for(int j=0;j<n;j++) aux += (match[j]!=-1);//conta os utilizados do 1o grupo (0..n-1)
        ans=max(ans,aux);
    }
return ans;
}
