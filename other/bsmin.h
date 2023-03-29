namespace binarySearchMin{
    inline bool check(int m){

    }

    inline int bsmin(int l, int r){
        while(l < r){
            int m = l + (r - l)/2;
            if(check(m)) r = m;
            else l = m + 1;
        }
        return r;
    }
}
