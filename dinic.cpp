#include<bits/stdc++.h>
//fonte: https://linux.ime.usp.br/~marcosk/mac0499/codigos.html
using namespace std;
typedef long long ll;
const int INF = 0x3f3f3f3f;
struct Graph {
    struct Edge {
        int v;
        ll u;
        Edge(int _v, ll _u) : v(_v), u(_u) {}
    };

    int n;
    vector<Edge> edges;//lista de arestas
    vector<vector<int>> adj;//indices das arestas q saem de um vertice v => adj[v]

    Graph(int _n) : n(_n) { adj.resize(n); }

    void add_edge(int v, int w, ll u) {
        adj[v].push_back(edges.size());
        edges.push_back(Edge(w, u));
        adj[w].push_back(edges.size());//aresta reversa
        edges.push_back(Edge(v, 0));//trocar 0 por u em grafos nao direcionados
    }
};

vector<int> level;
bool bfs(Graph &g, int s, int t) {
    fill(level.begin(), level.end(), -1);
    level[s] = 0;
    queue<int> queue({s});
    while (!queue.empty()) {
        int v = queue.front();
        if (level[v] == level[t]) break;
        queue.pop();
        for (int i: g.adj[v]) {
            int w = g.edges[i].v;
            ll u = g.edges[i].u;
            if (level[w] == -1 && u > 0) {
                level[w] = level[v] + 1;
                queue.push(w);
            }
        }
    }
    return level[t] != -1;
}

vector<int> ptr;
ll augment(Graph &g, int v, int t, ll cap) {
    if (v == t) return cap;
    for (int &p = ptr[v]; p < (int)g.adj[v].size(); p++) {
        int i = g.adj[v][p];
        int w = g.edges[i].v;
        ll u = g.edges[i].u;
        if (level[w] == level[v] + 1 && u > 0) {
            ll eps = augment(g, w, t, min(cap, u));
            if (eps > 0) {
                g.edges[i].u -= eps;
                g.edges[i ^ 1].u += eps;
                return eps;
            }
        }
    }
    return 0;
}

ll maxflow(Graph &g, int s, int t) {
    level.resize(g.n), ptr.resize(g.n);
    ll total_flow = 0, cur_flow;
    while (bfs(g, s, t)) {
        fill(ptr.begin(), ptr.end(), 0);
        do {
            cur_flow = augment(g, s, t, INF);
            total_flow += cur_flow;
        } while (cur_flow > 0);
    }
    return total_flow;
}

int main(){
	int n,m;
		int u,v;
		ll w;
	cin>>n>>m;
	Graph g(n);
	while(m--){
		cin>>u>>v>>w;
		g.add_edge(u-1,v-1,w);
	}
	cout<<maxflow(g,0,n-1)<<'\n';
}
