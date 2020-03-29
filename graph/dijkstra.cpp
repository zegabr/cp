
vector<ii> G[ms];//G[u] contains {w, v}

void dijkstra(int S, int T){//O(E logV)
	priority_queue <ii, vector<ii>, greater<ii>> pq;//contains {dis[u], u}
	pq.push(ii(0,S));
	dis.assign(ms, inf);
	dis[S]=0;

	while(pq.size()){
		int u=pq.top().second; 
		int disu = pq.top().first;
		pq.pop();
		if(disu > dis[u])continue;
		for(auto child : G[u]){
			int v = child.second,  w = child.first;
			if(dis[u] + w < dis[v]){           
				dis[v] = dis[u] + w;
				pq.push(ii(dis[v],v));
			}
		}
	}
}
