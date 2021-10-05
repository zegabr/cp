
#include<vector>
class DSU{
    std::vector<int> ds, sz;
    public:	
    
        DSU(int v){
            sz.assign(v+1, 1);
            ds.resize(v+1);
            for(int i=0; i <= v;i++) ds[i] = i;
        }

        int parent(int i){//find
            if(ds[i] != i) ds[i] = parent(ds[i]);
            return ds[i];
        }

        bool unify(int a, int b){//union
            a = parent(a), b = parent(b);
            if(a == b) return false;
            if(sz[a] < sz[b]) std::swap(a,b);
            sz[a] += sz[b];
            ds[b] = a;
            return true;
        }

        bool same(int a, int b){
            return parent(a) == parent(b);
        }

        int size(int a){
            return sz[parent(a)];
        }
};

