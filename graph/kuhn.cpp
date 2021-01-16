
//bipartite unweighted graph maximum matching
//só precisa criar adjacencia de Left -> Right (como se tivesse direcionado)
int matchl[ms], matchr[ms];
vector<int> vis(ms);
//m vertices em um grupo, n vertices em outro m+n=ms
void clr(){
	for(int i = 0; i < ms; i++)
		matchr[i] = matchl[i] = -1;
}

bool kuhn(int v){//dfs 
	if(vis[v] == timer) return 0;
	vis[v] = timer;
	for(int to : g[v]){
		if(matchl[to] == -1 or kuhn(matchl[to])){
			matchl[to] = v;
			matchr[v] = to;
			return 1;
		}
	}
	return 0;
}

int findmatching(){//O(mn)
	int ans = 0;
	clr();
	for(int i = 0; i < n; i++){//vertices da esquerda
		timer++;
		ans += kuhn(i);
	}
	return ans;//qt arestas usadas no match maximo = minima qntidade de vertices que se retirados separam todo o grafo em 2 (min vertex cover)
	//return ans==n;//perfect match
}
//MAXIMUM INDEPENDENT SET = ms - MAXIMUM BIPARTITE MATCHING
void printmatch(){
	for(int i = 0; i < n; i++)
		cout << "match[" << i << "]=" << matchr[i] - n << endl;		
}
