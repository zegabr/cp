
class Dsu{
    vector<int> ds, sz;
    public:	
    Dsu(int v){
        sz.assign(v+1, 1);
        ds.resize(v+1);
        for(int i=0; i <= v;i++) ds[i] = i;
    }

    int par(int i){//find
        if(ds[i] != i) ds[i] = par(ds[i]);
        return ds[i];
    }

    bool uni(int a, int b){//union
        a = par(a), b = par(b);
        if(a == b) return false;
        if(sz[a] < sz[b])swap(a,b);
        sz[a] += sz[b];
        ds[b] = a;
        return true;
    }

    bool same(int a, int b){
        return par(a) == par(b);
    }

    int size(int a){
        return sz[par(a)];
    }
};

