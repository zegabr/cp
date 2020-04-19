
//for directed graphs
//pls use 0 indexed vertices
//import ./init.cpp
queue<int> order;
vector<int> comp;
vector<vector<int>> sccs;

void init(int n){
  cleargraph(n);//from ./init.cpp
  while(order.size())
    order.pop();
  timer++;
  sccs.clear();
  eds.clear();
  comp.assign(n,-1);
}

void dfs1(int u){
  vis[u]=timer;
  for(auto v : g[u]){
    if(vis[v]<timer){
      dfs1(v);
    }
  }
  order.push(u);
}

void dfs2(int u, int component){
  vis[u]=timer;
  comp[u]=component;
  for(auto v : g[u]){
    if(vis[v]<timer){
      dfs2(v, component);
    }
  }
}

void getsccs(int n){
  timer++;
  for(int i=0;i<n;i++)
    if(vis[i]<timer) 
      dfs1(i);


  timer++;
  while(order.size()){
    int u = order.front();
    order.pop();
    if(vis[u]<timer) 
      dfs2(u,order.size());//order.size will be the number of the component
  }
}

