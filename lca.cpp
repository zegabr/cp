//cp-algorithms lca
//O(NlogN) preprocessing + O(log N)/query
int n, l;
vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p)
{
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p)
            dfs(u, v);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, vector<int>(l + 1));
    dfs(root, root);
}
//==================================================
//gap implementation
int par[ms][mlg+1], lvl[ms];
vector<int> g[ms];

void dfs(int v, int p, int l = 0) { // chamar como dfs(root, root)
  lvl[v] = l;
  par[v][0] = p;
  for(int k = 1; k <= mlg; k++) {
    par[v][k] = par[par[v][k-1]][k-1];
  }
  for(int u : g[v]) {
    if(u != p) dfs(u, v, l + 1);
  }
}

int lca(int a, int b) {
  if(lvl[b] > lvl[a]) swap(a, b);
  for(int i = mlg; i >= 0; i--) {
    if(lvl[a] - (1 << i) >= lvl[b]) a = par[a][i];
  }
  if(a == b) return a;
  for(int i = mlg; i >= 0; i--) {
    if(par[a][i] != par[b][i]) a = par[a][i], b = par[b][i];
  }
  return par[a][0];
}
