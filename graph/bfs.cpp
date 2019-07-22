//====================================================
//BFS FOR UNWEIGHTED GRAPHS MINIMUM DISTANCE
int V;//#vertices
vector<int> g[V];
vector<int> dis(V);
int BFS(int start,int goal){//O(V+E)
	fill(all(dis), 0x3f3f3f3f);
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
//====================================================