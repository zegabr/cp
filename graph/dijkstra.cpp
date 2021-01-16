
vector<pair<int,int>> G[ms];//G[u] contains {w, v}

void dijkstra(int S, int T){//O(E logV)
    priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;//contains {dis[u], u}
	pq.push({0, S});
	dis.assign(ms, inf);
	dis[S] = 0;

	while(pq.size()){
		int u, disu;
		tie(disu, u) = pq.top();
		pq.pop();
		if(disu > dis[u])continue;
		for(auto child : G[u]){
			int v, w;
			tie(w, v) = child;
			if(dis[v] > dis[u] + w){           
				dis[v] = dis[u] + w;
				pq.push({dis[v], v});
			}
		}
	}
}
