
// Useful for knowing if node is inside other node's subtree
class ETT{

    vector<int> in, out;
    int visTime;

    public:
    ETT(vector<vector<int>> &tree, int root){
        in.resize(tree.size());
        out.resize(tree.size());
        visTime = 0;

        this.dfs(root, tree);

    }

    bool isDescendentOf(int a, int b){
        return in[b] < in[a] and out[a] < out[b];
    }

    private:
    void dfs(int curr, vector<vector<int>> &tree){
        in[curr] = visTime++;
        for(int &child : tree[curr]) dfs(child, tree);
        out[curr] = visTime++;
    }

}
