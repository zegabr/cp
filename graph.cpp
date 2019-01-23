////PRINTA GRAFO////
void pg(){
    for(int i=0;i<ms;i++){
        cout<<"g["<<i<<"]=> ";
        for(int v : g[i])cout<<sp<<v;
        cout<<pl;
    }
}

//////BFS///////
//BFS FOR UNWEIGHTED GRAPHS MINIMUM DISTANCE
int V;//#vertices
vector<int> g[V];
int dis[V];


int BFS(int start,int goal){
	queue<int> q;
	fill(dis,dis+V,inf);
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
return dis[goal]==inf ? -1 : dis[goal];  
}

////////DFS////////
vector<int> vis(N);
int tempo=1;
void dfs(int u){
	if(vis[u]==tempo) return;
	tempo++;
	for(auto v : g[u]){
		if(vis[v]==tempo) continue;
		dfs(v);
	}
}
///dfs bipartite check
bool dfsbicolor(int u){
	for(int v : g[u]){
		if(!vis[v]){
			vis[v]=1;
			color[v]=!color[u];
			if(!dfsbicolor(v)) return false;
		}else if(color[u]==color[v])
			return false;
	}
	return true;
}

//////DIJKSTRA///////
typedef pair<int,int> ii;
typedef vector<ii> vii;
int dis[N];
vii g[N];
priority_queue <ii,vii,greater<ii>> pq;
const int inf = 1231231;

bool dijkstra(int S, int T){
	bool way =false;
	fill(dis,dis+N,inf);
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
int g[N][N], dis[N][N], n;

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
int ds[N];
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
vector<int> g[N], vis(N);
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
vector<int> g[V]; //grafo bipartido
int matchl[V],matchr[V],tempo=1;
vector<int> vis(V);
//m vertices em um grupo, n vertices em outro m+n=V

void clrmatch(){
    for(int i=0;i<ms;i++)
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
bool findmatching(){
	int ans=0,aux=0;
	clrmatch();
	bool foundpath;
	do{
		tempo++;//unvisit everybody
		foundpath=0;
		for(int i=0;i<n;i++){//dfs em todos os vertices do grupo left (0..n-1)
			if(matchr[i]<0 and vis[i]<tempo)
				foundpath|=kuhn(i);
		}
	}while(foundpath);
	for(int i=0;i<n;i++) ans+=(matchr[i]>0);

	return ans==n;//perfect match
}
void printmatch(){
	for(int i=0;i<n;i++)
			cout<<"match["<<i<<"]="<<matchr[i]-n<<pl;		
}

/////MAXFLOW DINIC by tfg50//////////////////
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int V = 50;//num vertices
struct Edge {
	Edge(int a, int b){to = a;cap = b;}
	int to;
	int cap;
};

int n=V;
vector<vector<int> > edges(V);//arestas saindo de cada vertice
vector<Edge> list;//lista de arestas
vector<int> h, pt;//level do bfs e array


void addedge(int from, int to, int cap = 1) {
	edges[from].push_back(list.size());
	list.push_back(Edge(to, cap));
	edges[to].push_back(list.size());
	list.push_back(Edge(from, 0));
}

int dfs(int on, int sink, int flow = 1e9) {
	if(flow == 0) {
		return 0;
	}if(on == sink) {
		return flow;
	}
	for(; pt[on] < edges[on].size(); pt[on]++) {
		int cur = edges[on][pt[on]];
		if(h[on] + 1 != h[list[cur].to]) {
			continue;
		}
		int got = dfs(list[cur].to, sink, min(flow, list[cur].cap));
		if(got) {
			list[cur].cap -= got;
			list[cur ^ 1].cap += got;
			return got;
		}
	}
	return 0;
}

bool bfs(int src, int sink) {
	h = std::vector<int>(n, n);
	h[src] = 0;
	std::queue<int> q;
	q.push(src);
	while(q.size()) {
		int on = q.front();
		q.pop();
		for(auto a : edges[on]) {
			if(list[a].cap == 0) {
				continue;
			}
			int to = list[a].to;
			if(h[to] > h[on] + 1) {
				h[to] = h[on] + 1;
				q.push(to);
			}
		}
	}
	return h[sink] < n;
}
int maxflow(int src, int sink) {
	int ans = 0;
	while(bfs(src, sink)) {
		for(int i = 0; i < n; i++) {
			std::random_shuffle(edges[i].begin(), edges[i].end());
		}

		pt = std::vector<int>(n, 0);
		while(int flow = dfs(src, sink)) {
			ans += flow;
		}
	}
	return ans;
}