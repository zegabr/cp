//=========BFS==========
//BFS FOR UNWEIGHTED GRAPHS MINIMUM DISTANCE
int V;//#vertices
vector<int> g[V];
int dis[V];
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
