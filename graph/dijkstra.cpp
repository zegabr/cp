//====================================================
#define ii pair<int,int>
vector<int> dis(N);
vector<ii> g[N];
const int inf = 1231231;

bool dijkstra(int S, int T){//O(E logV)
	priority_queue <ii> pq;
	bool way =false;
	fill(dis.begin(),dis.end(),inf);
	dis[S]=0;
	pq.push({0,S});
	while(pq.size()){
		ii aux=pq.top(); pq.pop();
		int u=aux.second;
		for(auto child : g[u]){
			int w = child.first, v = child.second;
			if(w>dis[v]) continue;
			if(v==T) way = true;
			if(dis[u] + w < dis[v]){           
				dis[v] = dis[u] + w;
				pq.push({-dis[v],v});
			}
		}
	}
	return way;
}
//====================================================