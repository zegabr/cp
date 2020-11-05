
long long inf = 0x3f3f3f3f;//atualizar com fluxo maximo possivel em caso de runtime error
const int ms = 5555; // Quantidade maxima de vertices
const int me = 63333; // Quantidade maxima de arestas

int to[me], ant[me], z;
int adj[ms], copy_adj[ms], fila[ms], level[ms];
long long wt[me];

void add(int u, int v, long long k,long long rev =0) {//adiciona aresta e aresta residual (2 arestas)
	//chamar add(a,b,cap) se direcionado
	//chamar add(a,b,cap,cap) se nao direcionado
	to[z] = v;
	ant[z] = adj[u];
	wt[z] = k;
	adj[u] = z++;
	swap(u, v);
	to[z] = v;
	ant[z] = adj[u];
	wt[z] = rev;
	adj[u] = z++;
}

int bfs(int source, int sink) {
	memset(level, -1, sizeof level);
	level[source] = 0;
	int front = 0, size = 0, v;
	fila[size++] = source;
	while(front < size) {
		v = fila[front++];
		for(int i = adj[v]; i != -1; i = ant[i]) {//percorre adjacencia de v (existem arestas v->to[i])
			if(wt[i] && level[to[i]] == -1) {
				level[to[i]] = level[v] + 1;
				fila[size++] = to[i];
			}
		}
	}
	return level[sink] != -1;
}

long long dfs(int v, int sink, long long flow) {
	if(v == sink) return flow;
	long long f;
	for(int &i = copy_adj[v]; i != -1; i = ant[i]) {
		if(wt[i] && level[to[i]] == level[v] + 1 and
		(f = dfs(to[i], sink, min(flow, wt[i])))) {
			wt[i] -= f;
			wt[i ^ 1] += f;
			return f;
		}
	}
	return 0;
}

long long maxflow(int source, int sink) {
	long long ret = 0, flow;
	while(bfs(source, sink)) {
		memcpy(copy_adj, adj, sizeof adj);
		while((flow = dfs(source, sink, inf))) {
			ret += flow;
		}
	}
	return ret;
}

void clear() { // Lembrar de chamar no main
	memset(adj, -1, sizeof adj);
	z = 0;
}
