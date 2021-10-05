
#define MIN 1
#define MAX 2
#define SUM 3

template<typename T>
class segtree{
    private:
        T none; //valor que nao atrapalhe
        std::vector<T> seg;//0 indexed
        int tam;//tamanho
        int op;

        T merge(T e, T d){
            if(op==MIN) return std::min(e,d);
            else if(op==MAX) return std::max(e,d);
            else if(op==SUM) return e+d;
        }

        void update(int a, T val, int x, int l, int r) {
            if(l > a or r < a) return;
            if(l == r) {
                seg[x] = val;
                return;
            }
            int m = (l+r)/2, e = x+x, d = e+1;
            update(a,val, e, l, m); 
            update(a, val, d, m + 1, r);
            seg[x] = merge(seg[e] , seg[d]); 
        }

        T get(int a, int b, int x, int l , int r) {
            if(b < l || a > r) return none; // Valor que nao atrapalhe
            if(a <= l && r <= b) return seg[x];
            int m = (l+r)>>1, e=x+x, d=e+1; 
            return merge(get(a, b, e, l, m), get(a, b, d, m + 1, r)); 
        }

        void build(std::vector<T> &v, int x, int l, int r) {
            if(l == r) {
                seg[x] = v[l];
                return;
            }
            int m = (l+r)>>1,e=x+x, d=e+1;
            build(v, e, l, m); 
            build(v, d, m + 1, r);
            seg[x] = merge(seg[e], seg[d]);
        }

    public:
        segtree(std::vector<T> &v, int opp){
            seg.resize(4*v.size());
            op = opp;
            tam = v.size();
            if(op==MIN) none = 0x3f3f3f3f;
            else if(op==MAX) none = -0x3f3f3f3f;
            else if(op==SUM) none = 0;
            int x = 1, l = 0, r = tam - 1;
            build(v, x, l, r);
        }

        void update(int a, T val){
            update(a, val, 1,0,tam-1);
        }

        T get(int a, int b){
            return get(a,b,1,0,tam-1);
        }
};
