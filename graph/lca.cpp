
const int ms=1e4+10, lg=25;
int up[ms][lg+1], lv[ms];
vector<int> g[ms];

void dfslca(int u,int p, int h=0){//chamar dfslca(root,root)
	lv[u]=h;
	up[u][0] = p;
	for(int i=1; i<=lg;i++) up[u][i] = up[up[u][i-1]][i-1];
	for(int v : g[u]){
		if(v!=p) dfslca(v, u, h+1);
	}
}

int lca(int a, int b){
	if(lv[b]>lv[a]) swap(a,b);
	int d = lv[a]-lv[b];
	for(int i=0;i<lg;i++) if((d>>i)&1) a = up[a][i];
	if(a==b) return a;
	for(int i=lg; i>=0 ; i--){
		if(up[a][i] != up[b][i]){
			a=up[a][i];
			b=up[b][i];
		}
	}
	return up[a][0]; 
}

int distance(int u, int v) {
	int lc = lca(u, v);
	return lv[u] + lv[v] - 2 * lv[lc];
}
