///////KUHN'S ALGORITHM//////////////////////////////
//bipartite unweighted graph maximum matching

//vector<int> g[V]; //grafo bipartido
//int matchl[V],matchr[V],tempo=1;
//vector<int> vis(V);
//m vertices em um grupo, n vertices em outro m+n=V

void clrmatch(){
    for(int i=0;i<ms;i++)
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

bool findmatching(){//O(mn)
	int ans=0,aux=0;
	clrmatch();
	bool foundpath;
	do{
		tempo++;//unvisit everybody
		foundpath=0;
		for(int i=0;i<n;i++){//dfs em todos os vertices do grupo left (0..n-1)
			if(matchr[i]<0 and vis[i]<tempo)
				foundpath|=kuhn(i);
		}
	}while(foundpath);
	for(int i=0;i<n;i++) ans+=(matchr[i]>0);

	return ans==n;//perfect match
}

void printmatch(){
	for(int i=0;i<n;i++)
			cout<<"match["<<i<<"]="<<matchr[i]-n<<pl;		
}
