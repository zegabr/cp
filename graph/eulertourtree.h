
#include "graph.h"
// Useful for knowing if node is inside other node's subtree
class EulerTourTree : public Graph{

    std::vector<int> in, out;
    int visTime;

    public:
    EulerTourTree(std::vector<std::vector<int>> &g, int root){
        in.resize(g.size());
        out.resize(g.size());
        visTime = 0;
        dfs(root, g);
    }

    bool isDescendentOf(int a, int b){
        return in[b] < in[a] and out[a] < out[b];
    }

    private:
    void dfs(int curr, std::vector<std::vector<int>> &g){
        in[curr] = visTime++;
        for(int &child : g[curr]) dfs(child, g);
        out[curr] = visTime++;
    }
};
