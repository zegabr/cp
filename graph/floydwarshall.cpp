//=============FLOYD WARSHALL=============
const int inf = 0x3f3f3f3f;
int g[N][N], dis[N][N], n;
int p[N][N];
void clear() {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			g[i][j] = i == j ? 0 : inf;
			//p[i][j]=i;
		}
	}
}

void add(int u, int v, int w) {
	g[u][v] = min(w, g[u][v]);
}

void floydWarshall() {//O(V³)
	memcpy(dis, g, sizeof dis);
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) { 
			for(int j = 0; j < n; j++) {
				//if pode atualizar, faz p[i][j]=p[k][j]
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
}
void printpath(int i,int j){
	if(i!=j)	printpath(i,p[i][j]);
	cout<<' '<<j;
}