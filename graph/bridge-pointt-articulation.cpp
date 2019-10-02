
//for undirected graph
const int V=1e6+5;
int timer, dfsroot, rootchildren;
vector<int>num, low, par, cutvertex, g[V];

inline void iscutvertex(int v){
	cutvertex[v]=true;
}

inline void isbridge(int u, int v){

}

void dfspointbridge(int u){
	low[u]=num[u]=timer++;
	for(int v : g[u]){
		if(num[v]==0){
			par[v]=u;
			if(u == dfsroot) rootchildren++;

			dfspointbridge(v);

			if(low[v]>=num[u]){
				iscutvertex(v);
			}
			if(low[v]>num[u]){
				isbridge(u,v);
			}
			low[u]=min(low[u], low[v]);
		}else if(v != par[u]) low[u]=min(low[u],num[v]);
	}
}

void findpointbridge(int n=V){
	timer=0;
	num.assign(n+1,0);
	low.assign(n+1,0);
	par.assign(n+1,0);
	cutvertex.assign(n+1,0);
	for(int i=0;i<n;i++){
		if(num[i]==0){
			dfsroot=i; rootchildren=0; dfspointbridge(i);
			if(rootchildren > 1) iscutvertex(i);
		}
	}
}
