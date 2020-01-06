
int timer=1;
/*
   vis[u]<timer ==> u nao visitado
   vis[u]==timer ==> u visitado
   timer++ ==> desvisita todo mundo
   */
const int ms=2e7+5;
const int inf = 1e8+5;
vector<int> g[ms], dis(ms,inf), vis(ms); 
vector<ii> eds;

//PLS USE 0 INDEXED VERTICES
void add(int u, int v){
  u--;v--;//if already 0-indexed, comment this line
  g[u].pb(v);
  g[v].pb(u);
  eds.pb({u,v});
}

void cleargraph(){
  for(int i=0;i<ms;i++){
    g[i].clear();
  }
  dis.assign(ms,inf);
}
