//==========GRID MOVING=======
int movx[] = {-1, 0, 1, 0,-1, 1, 1, -1};
int movy[] = {0, 1, 0, -1, 1, 1, -1, -1};
for(int i = 0; i < 8;++i){//u,r,d,l,ur,dr,dl,ul
	int nx = movx[i] + x;
	int ny = movy[i] + y;
	//if safe then dfs(nx,ny)
}
//separar
//=========BFS==========
//BFS FOR UNWEIGHTED GRAPHS MINIMUM DISTANCE
//int V;//#vertices
//vector<int> g[V];
//int dis[V];
int BFS(int start,int goal){//O(V+E)
	fill(dis,dis+V,inf);
	dis[start]=0;
	queue<int> q({start});
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
return dis[goal]==inf ? -1 : dis[goal];  
}

//==========DFS=============
//vector<int> vis(N);
int tempo=1;//fazer tempo++ para cada vez que precisar zerar visitados
void dfs(int u){//O(V+E)
	if(vis[u]==tempo) return;
	vis[u]=tempo;
	for(auto v : g[u]){
		if(vis[v]==tempo) continue;
		dfs(v);
	}
}

///dfs bipartite check
bool dfsbicolor(int u){
	for(int v : g[u]){
		if(vis[v]<tempo){
			vis[v]=tempo;
			color[v]=!color[u];
			if(!dfsbicolor(v)) return false;
		}else if(color[u]==color[v])
			return false;
	}
	return true;
}

//========TOPOSORT=========(ITERATIVO e intuitivo)
//vector<int> g[N], vis(N);
//map<int,int>grau;
void toposort(){//O(V+E)
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

//=========DIJKSTRA===============
//typedef pair<int,int> ii;
//typedef vector<ii> vii;
//int dis[N];
//vii g[N];
///priority_queue <ii,vii,greater<ii>> pq;
//const int inf = 1231231;
bool dijkstra(int S, int T){//O(E logV)
	bool way =false;
	fill(dis,dis+N,inf);
	dis[S]=0;
	pq.push(ii(0,S));
	while(pq.size()){
		ii aux=pq.top(); pq.pop();
		int u=aux.second;
		for(auto child : g[u]){
			int w = child.first, v = child.second;
			if(w>dist[v]) continue;
			if(v==T)
				way = true;
			if(dis[u] + w < dis[v]){           
				dis[v] = dis[u] + w;
				pq.push(ii(dis[v],v));
			}
		}
	}
	return way;
}

//=============FLOYD WARSHALL=============
//const int inf = 0x3f3f3f3f;
//int g[N][N], dis[N][N], n;
//int p[N][N];
void clear() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			g[i][j] = i == j ? 0 : inf;
			//p[i][j]=i;
		}
	}
}

void add(int u, int v, int w) {
	g[u][v] = min(w, g[u][v]);
}

void floydWarshall() {//O(V³)
	memcpy(dis, g, sizeof dis);
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) { 
			for(int j = 0; j < n; j++) {
				//if pode atualizar, faz p[i][j]=p[k][j]
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}
void printpath(int i,int j){
	if(i!=j)	printpath(i,p[i][j]);
	cout<<' '<<j;
}

//============KUHN'S ALGORITHM====================
//bipartite unweighted graph maximum matching

//vector<int> g[V]; //grafo bipartido//só precisa criar adjacencia de Left -> Right
//int matchl[V],matchr[V],tempo=1;
//vector<int> vis(V);
//m vertices em um grupo, n vertices em outro m+n=V
void clrmatch(){
	for(int i=0;i<V;i++)
		matchr[i]=matchl[i]=-1;
}

bool kuhn(int v){//dfs 
	if(vis[v]==tempo) return 0;
	vis[v]=tempo;
	for(int to : g[v]){
		if(matchl[to]==-1 or kuhn(matchl[to])){
			matchl[to]=v;
			matchr[v]=to;
			return 1;
		}
	}
	return 0;
}

int findmatching(){//O(mn)
	int ans=0;
	clr();
	for(int i=0;i<n;i++){//vertices da esquerda
		tempo++;
		ans+=kuhn(i);
	}
	return ans;//qt arestas usadas no match maximo = minima qntidade de vertices que se retirados separam todo o grafo em 2 
	//return ans==n;//perfect match
}

void printmatch(){
	for(int i=0;i<n;i++)
		cout<<"match["<<i<<"]="<<matchr[i]-n<<pl;		
}

