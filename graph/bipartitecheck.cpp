
vector<bool> color(ms);

bool dfsbicolor(int u){
  for(int v : g[u]){
    if(vis[v]<timer){
      vis[v]=timer;
      color[v]=!color[u];
      return dfsbicolor(v);
    }else if(color[u]==color[v])
      return false;
  }
  return true;
}
