/////MAXFLOW DINIC by tfg50//////////////////
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int V = 50;//num vertices
struct Edge {
	Edge(int a, int b){to = a;cap = b;}
	int to;
	int cap;
};

int n=V;
vector<vector<int> > edges(V);//arestas saindo de cada vertice
vector<Edge> list;//lista de arestas
vector<int> h, pt;//level do bfs e um array

void addedge(int from, int to, int cap = 1) {
	edges[from].push_back(list.size());
	list.push_back(Edge(to, cap));
	edges[to].push_back(list.size());
	list.push_back(Edge(from, 0));
}

int dfs(int on, int sink, int flow = 1e9) {
	if(flow == 0) {
		return 0;
	}if(on == sink) {
		return flow;
	}
	for(; pt[on] < edges[on].size(); pt[on]++) {
		int cur = edges[on][pt[on]];
		if(h[on] + 1 != h[list[cur].to]) {
			continue;
		}
		int got = dfs(list[cur].to, sink, min(flow, list[cur].cap));
		if(got) {
			list[cur].cap -= got;
			list[cur ^ 1].cap += got;
			return got;
		}
	}
	return 0;
}

bool bfs(int src, int sink) {
	h = std::vector<int>(n, n);
	h[src] = 0;
	std::queue<int> q;
	q.push(src);
	while(q.size()) {
		int on = q.front();
		q.pop();
		for(auto a : edges[on]) {
			if(list[a].cap == 0) {
				continue;
			}
			int to = list[a].to;
			if(h[to] > h[on] + 1) {
				h[to] = h[on] + 1;
				q.push(to);
			}
		}
	}
	return h[sink] < n;
}
int maxflow(int src, int sink) {
	int ans = 0;
	while(bfs(src, sink)) {
		/*
		for(int i = 0; i < n; i++) {
			std::random_shuffle(edges[i].begin(), edges[i].end());
		}
		*/
		pt = std::vector<int>(n, 0);
		while(int flow = dfs(src, sink)) {
			ans += flow;
		}
	}
	return ans;
}