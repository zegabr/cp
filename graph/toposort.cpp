
vector<int> dg(ms);//entry degree
vector<int> ans;

void toposort(int n){//O(V+E)
	priority_queue<int, vector<int>,greater<int>> pq;
	for(int i=0;i<n;i++)if(!dg[i])pq.push(i);
	while(pq.size()){
		int u = pq.top(); pq.pop();
		for(auto v : g[u]){
			if(--dg[v]==0) pq.push(v);
		}
		ans.push_back(u);
	}
}
