
namespace binarySearchMax{
    inline bool check(int m){

    }

    inline int bsmax(int l, int r){
        while(l < r){
            int m = l + (r - l + 1) / 2;
            if(check(m)) l = m;
            else r = m - 1;
        }
        return l;
    }
}
