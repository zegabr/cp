//find bridges in graphs by cp-algorithms
int n; // number of nodes
vector<vector<int>> g; // adjacency list of graph
vector<bool> vis;
vector<int> tin, low;
int timer;
void IS_BRIDGE(int u, int v){
	//something here
}

void dfs(int u, int p = -1) {
	vis[u] = 1;
	tin[u] = low[u] = timer++;
	for (int v : g[u]) {
		if (v == p) continue;
		if (vis[v]) {
			low[u] = min(low[u], tin[v]);
		} else {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > tin[u])
				IS_BRIDGE(u, v);
		}
	}
}

void find_bridges() {
	timer = 0;
	vis.assign(n, 0);
	tin.assign(n, -1);
	low.assign(n, -1);
	for (int i = 0; i < n; ++i) {
		if (!vis[i])
			dfs(i);
	}
}
