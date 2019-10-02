
//bipartite unweighted graph maximum matching
const int V = 2e6+5;
vector<int> g[V]; //grafo bipartido//só precisa criar adjacencia de Left -> Right
int matchl[V],matchr[V],tempo=1;
vector<int> vis(V);
//m vertices em um grupo, n vertices em outro m+n=V
void clr(){
	for(int i=0;i<V;i++)
		matchr[i]=matchl[i]=-1;
}

bool kuhn(int v){//dfs 
	if(vis[v]==tempo) return 0;
	vis[v]=tempo;
	for(int to : g[v]){
		if(matchl[to]==-1 or kuhn(matchl[to])){
			matchl[to]=v;
			matchr[v]=to;
			return 1;
		}
	}
	return 0;
}

int findmatching(){//O(mn)
	int ans=0;
	clr();
	for(int i=0;i<n;i++){//vertices da esquerda
		tempo++;
		ans+=kuhn(i);
	}
	return ans;//qt arestas usadas no match maximo = minima qntidade de vertices que se retirados separam todo o grafo em 2 (min vertex cover)
	//return ans==n;//perfect match
}
//MAXIMUM INDEPENDENT SET = V - MAXIMUM BIPARTITE MATCHING
void printmatch(){
	for(int i=0;i<n;i++)
		cout<<"match["<<i<<"]="<<matchr[i]-n<<endl;		
}
