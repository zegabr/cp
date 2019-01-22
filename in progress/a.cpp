//MAXFLOW
#include<vector>
const int E = 2e5+5;
const int V = 2e5+5;
struct ed{
	int to,f,c;
}edges[E];

vector<int> g[V];

int ind=0;
void addEd(int a,int b,int cap,int revcap){
	edges[ind].to=b; edges[ind].f=0; edges[ind].c=cap;
	g[a].push_back(ind++);
	edges[ind].to=a; edges[ind].f=0; edges[ind].c=revcap;
	g[b].push_back(ind++);
}
int time=1;//if vis[u]<time, u has not been visited, visit it by doing vis[u]=time
int dfs(int s,int t, int F){
	if(s==t) return F;
	vis[s]=time;
	for(int e : g[s]){
		int k = edges[e].c - edges[e].f;
		if(vis[edges[e]] and  k){
			if(int a = dfs(edges[e].to, t, min(F,k))){
				edges[e].f += a;
				edges[e^1].f -= a;
				return a;
			}
		}
	}
	return 0;
}

int  maxflow(){
	int flow = 0; //max flow here
	while(int a = dfs(s,t,INT32_MAX)){
		flow+=a;
		time++;//unvisit everybody
	}
	return flow;
}


//////HUNGARIAN-> MAX WEIGHTED BIPARTITE MATCHING	
