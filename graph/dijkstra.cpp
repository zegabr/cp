//====================================================
#include<queue>
int dis[N];
vector<pair<int,int>> g[N];
const int inf = 1231231;
bool dijkstra(int S, int T){//O(E logV)
	priority_queue <pair<int,int>> pq;
	bool way =false;
	fill(dis,dis+N,inf);
	dis[S]=0;
	pq.push({0,S});
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
				pq.push({-dis[v],v});
			}
		}
	}
	return way;
}
//====================================================