//====lca==============
const int N=1e4+10, ln=25;
int up[N][ln+1], lv[N];
vector<int> g[N];

void dfs(int u,int p, int h=0){
	lv[u]=h;
	up[u][0] = p;
	for(int i=1; i<=ln;i++) up[u][i] = up[up[u][i-1]][i-1];
	for(int v : g[u]){
		if(v!=p) dfs(v, u, h+1);
	}
}

int lca(int a, int b){
	if(lv[b]>lv[a]) swap(a,b);
	int d = lv[a]-lv[b];
	for(int i=0;i<ln;i++) if((d>>i)&1) a = up[a][i];
	if(a==b) return a;
	for(int i=ln; i>-1 ; i--){
		if(up[a][i] != up[b][i]){
			a=up[a][i];
			b=up[b][i];
		}
	}
	return up[a][0]; 
}

