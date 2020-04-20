
//for directed graphs
//PLS USE 0 INDEXED VERTICES
queue<int> order;//store topological reversal order
vector<int> comp;//store components
vector<int> assignment;//store 2-SAT solution

void init(int n){
  reset_graph(n);//from ./init.cpp
  while(order.size())
    order.pop();
  timer++;
  eds.clear();
  comp.assign(n,-1);
}

void dfs1(int u){
  vis[u] = timer;
  for(auto v : g[u]){
    if(vis[v] < timer){
      dfs1(v);
    }
  }
  order.push(u);
}

void dfs2(int u, int c){
  vis[u] = timer;
  comp[u] = c;
  for(auto v : g[u]){
    if(vis[v] < timer){
      dfs2(v, c);
    }
  }
}

void add_clause(int a, int b){//a and b has to be already at form 2k or 2k+1
  //a V b
  add(a^1, b);//not( a) => b
  add(b^1, a);//not( b) => a
}

bool scc(int n){//get sccs and solve 2-SAT (n has to be 2 times number of variables)
  timer++;
  for(int i = 0; i < n; i++)
    if(vis[i] < timer) 
      dfs1(i);

  timer++;
  int j = 0;
  while(order.size()){
    int u = order.front();
    order.pop();
    if(vis[u] < timer) 
      dfs2(u, j++);//j will be the number of the component
  }

  if(n%2==0){//solving 2-SAT here
    assignment.assign(n/2, false);
    for(int i=0;i<n;i+=2){
      if(comp[i] == comp[i+1])
        return false;
      assignment[i/2] = comp[i] > comp[i+1];
    }
  }
  return true;

}