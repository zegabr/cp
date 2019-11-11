
vector<int> g[ms];
vector<int> grau(ms);//de entrada
vector<int> ans;

void toposort(){//O(V+E)
	priority_queue<int, vector<int>,greater<int>> pq;
	for(int i=0;i<n;i++)if(!grau[i])pq.push(i);
	while(pq.size()){
		int u = pq.top(); pq.pop();
		for(auto v : g[u]){
			if(--grau[v]==0) pq.push(v);
		}
		ans.push_back(u);
	}
}
