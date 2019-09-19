vector<int>g[ms], vis(ms);
vector<bool> color(ms);
int timer=1;
bool dfsbicolor(int u){
	for(int v : g[u]){
		if(vis[v]<timer){
			vis[v]=timer;
			color[v]=!color[u];
			if(!dfsbicolor(v)) return false;
		}else if(color[u]==color[v])
			return false;
	}
	return true;
}
