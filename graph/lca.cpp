
const int lg=25;
int up[lg+1][ms], lv[ms];


void dfslca(int u,int p, int h=0){//call dfslca(root,root)
  lv[u]=h;
  up[0][u] = p;
  for(int i=1; i<=lg;i++) up[i][u] = up[i-1][up[i-1][u]];
  for(int v : g[u]){
    if(v!=p) dfslca(v, u, h+1);
  }
}

int lca(int a, int b){
  if(lv[b]>lv[a]) swap(a,b);
  int d = lv[a]-lv[b];
  for(int i=0;i<lg;i++) if((d>>i)&1) a = up[i][a];
  if(a==b) return a;
  for(int i=lg; i>=0 ; i--){
    if(up[i][a] != up[i][b]){
      a=up[i][a];
      b=up[i][b];
    }
  }
  return up[i][a]; 
}

int distance(int u, int v) {
  int lc = lca(u, v);
  return lv[u] + lv[v] - 2 * lv[lc];
}
