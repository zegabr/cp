//for directed graphs
//pls use 0 indexed vertices
const int V = 1e5+5;
vector<int> g[V];
vector<bool> used;
vector<int>  component;
queue<int> order;
vector<vector<int>> sccs;

void dfs1(int u){
  used[u]=1;
  for(auto v : g[u]){
    if(!used[v]){
      dfs1(v);
    }
  }
  order.push(u);
}

void dfs2(int u){
  used[u]=1;
  component.pb(u);
  for(auto v : g[u]){
    if(!used[v]){
      dfs2(v);
    }
  }
}

void init(int n){
  for(int i=0;i<n;i++){
    g[i].clear();
  }
  while(order.size())order.pop();
  used.clear();
  sccs.clear();
  component.clear();
}

void add(int u, int v){
  u--;v--;//if already 0-indexed, comment this line
  g[u].pb(v);
}



void getsccs(int n){
  used.assign(n,0);
  for(int i=0;i<n;i++)
    if(!used[i]) dfs1(i);

  used.assign(n,0);
  while(order.size()){
    int u = order.front();
    order.pop();
    if(!used[u]){
      dfs2(u);
      sccs.pb(component);//storing scc here
      component.clear();
    }
  }
}

