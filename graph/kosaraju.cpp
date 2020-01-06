//for directed graphs
//pls use 0 indexed vertices
vector<ii> eds;
queue<int> order;
vector<int> component;
vector<vector<int>> sccs;

void dfs1(int u){
  vis[u]=1;
  for(auto v : g[u]){
    if(vis[v]<timer){
      dfs1(v);
    }
  }
  order.push(u);
}

void dfs2(int u){
  vis[u]=1;
  component.pb(u);
  for(auto v : g[u]){
    if(vis[v]<timer){
      dfs2(v);
    }
  }
}

void init(int n){
  for(int i=0;i<n;i++){
    g[i].clear();
  }
  while(order.size())order.pop();
  vis.clear();
  sccs.clear();
  eds.clear();
  component.clear();
}

void getsccs(int n){
  vis.assign(n,0);
  for(int i=0;i<n;i++){
    if(vis[i]<timer) 
      dfs1(i);
  }

  vis.assign(n,0);
  while(order.size()){
    int u = order.front();
    order.pop();
    if(vis[u]<timer){
      dfs2(u);
      sccs.pb(component);//storing scc here
      component.clear();
    }
  }
}

