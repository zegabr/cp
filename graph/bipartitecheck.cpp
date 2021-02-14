
bool isbipartite(vector<vector<int>>& g) {
    queue<int> q({0});
    int n = g.size();
    const int mx = 100; // change this
    int color[mx] = {0};
    for(int i = 0; i < n; i++){
        if(!color[i]){
            q.push(i);
            color[i] = 1;
            while(q.size()){
                int u = q.front(); q.pop();
                for(int v : g[u]){
                    if(color[v] == color[u]){
                        return false;
                    }else{
                        if(!color[v]){    
                            q.push(v);
                            color[v] = color[u] == 1 ? 2 : 1;
                        }
                    }
                }
            }
        }
    }
    return true;
}
