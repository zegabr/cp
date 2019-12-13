
const int V=222222;//#vertices
const int inf = 0x3f3f3f3f;
vector<int> g[V];
vector<int> dis(V);

void bfs(int start){//O(V+E)
	dis.assign(V, inf);
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

