
// finds SCC and solve 2 - SAT (same as tarjanSCC.cpp)
//PLS USE 0 INDEXED VERTICES
vector<int> order;//store topological reversal order
vector<int> comp;//store components
vector<int> assignment;//store 2-SAT solution

void dfs1(int u){
    vis[u] = timer;
    for(auto v : g[u]){
        if(vis[v] < timer){
            dfs1(v);
        }
    }
    order.push_back(u);
}

void dfs2(int u, int c){
    vis[u] = timer;
    comp[u] = c;
    for(auto v : inv[u]){
        if(vis[v] < timer){
            dfs2(v, c);
        }
    }
}

int getsccs(int n){//get sccs using kosaraju
    comp.assign(n,-1);
    timer++;
    for(int i = 0; i < n; i++)
        if(vis[i] < timer) 
            dfs1(i);

    timer++;
    int j = 0;
    while(order.size()){
        int u = order.back();
        order.pop_back();
        if(vis[u] < timer)
            dfs2(u, j++);//j will be the number of the component
    }
    return j; //number of SCCs
}

//2-sat below
void add_clause(int a, int b){//a and b has to be already at form 2k or 2k+1
    //a V b
    add(a^1, b, false, true);//not( a) => b
    add(b^1, a, false, true);//not( b) => a
}

void add_coincidence(int a, int b){
    //~a V b and ~b V a
    add_clause(a, b^1);
    add_clause(b, a^1);
}

void add_xor(int a, int b){
    //a V b and ~a V ~b
    add_clause(a, b);
    add_clause(a^1, b^1);
}

bool is_2SAT(int n){//solve 2-SAT (n has to be 2 times number of variables)
    assignment.assign(n/2, false);
    for(int i=0;i<n;i+=2){
        if(comp[i] == comp[i+1])
            return false;
        assignment[i/2] = comp[i] > comp[i+1];
    }
    return true;
}
