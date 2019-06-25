//========ARTICULATION POINT AND BRIDGES===========
const int unvisited = 0, visited=1, explored=2,V=1e6+5;
int timer, dfsroot, rootchildren;
vector<int>num(V), low(V), par(V), cutvertex(V), g[V];

void artpoints(int u){
	low[u]=num[u]=timer++;
	for(int v : g[u]){
		if(num[v]==unvisited){
			par[v]=u;
			if(u == dfsroot) rootchildren++;

			artpoints(v);

			if(low[v]>=num[u]){
				//cutvertex[u]=1;//vertex u is articulation point
			}
			if(low[v]>num[u]){
				//edge u v is bridge
			}
			low[u]=min(low[u], low[v]);
		}else if(v != par[u]) low[u]=min(low[u],num[v]);
	}
}

void find(){
	timer=0;
	num.assign(V,unvisited);
	low.assign(V,0);
	par.assign(V,0);
	cutvertex.assign(V,0);
	for(int i=0;i<V;i++){
		if(num[i]==unvisited){
			dfsroot=i; rootchildren=0; artpoints(i);
			cutvertex[i] = rootchildren > 1;
		}
	}
}


