
#include<vector>
class LIS_BIT{
    private:
        static const int ms = 2222222;//biggest number
        int bit[ms];
        int dp[ms];

    public:
        void update(int x, int v){
            for(;x<ms;x+=x&-x)
                bit[x] = std::max(bit[x],v);
        }

        int get(int x){
            int res = 0;
            for(;x;x-=x&-x)
                res = std::max(bit[x], res);
            return res;
        }

        int lis(std::vector<int> &v){
            int res =0, n = v.size();
            for(int i=0;i<n;i++){
                dp[i] = 1 + get(v[i]);
                update(v[i], dp[i]);
                res = std::max(res, dp[i]);
            }
            return res;
        }
};
