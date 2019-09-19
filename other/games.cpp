/*
 *Sprague-Grundy Theorem:
 the player starting first is guaranteed to win if the XOR of the grundy numbers of position in each sub-games at the beginning of the game is non-zero. Otherwise, if the XOR evaluates to zero, then player A will lose definitely, no matter what.*/
#include<unordered_map>
#include<unordered_set>
int getmex(unordered_set<int> &s){
	int mex=0;
	while(s.count(mex))mex++;
	return mex;
}


unordered_map<int,int> Grund;//pd
int grundy(int n){//varia dependendo do jogo, deve retornar 0 se for estado de perda, numero grande se for estado de vencimento
	//caso base
	if(n<=1) return 0;//retorna 0 se nao pode retirar pedras num jogo com n pedras
	if(Grund.count(n)) return Grund[n];
	unordered_set<int> nex;
	//adicionar em nex os proximos valores
	nex.insert(grundy(n-2));
	nex.insert(grundy(n-3));

	return Grund[n] = getmex(nex);
}

int newgrundy(int n){
	//em caso de TLE, achar padrao e inserir aqui
	return 0;
}
//======================================
//=============GAMES ON ARBITRARY GRAPHS=======
vector<vector<int>> adj_rev;//reversed edges graph

vector<bool> winning;
vector<bool> losing;
vector<bool> visited;
vector<int> degree;//outgoing degree of vertices on reversed grapf

void dfs(int v) {//start from already defined vertices
	visited[v] = true;
	for (int u : adj_rev[v]) {
		if (!visited[u]) {
			if (losing[v])
				winning[u] = true;
			else if (--degree[u] == 0)
				losing[u] = true;
			else
				continue;
			dfs(u);
		}
	}
}
