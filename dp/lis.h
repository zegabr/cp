
#include<vector>
#include<algorithm>
class LIS{
    private:
        int ceilindex(std::vector<int> &v,std::vector<int> &T, int l, int r, int key){
            while(r-l > 1){
                int m = l + (r-l)/2;
                if(v[T[m]]>=key) r=m;
                else l=m;
            }
            return r;
        }

    public:
        std::vector<int> lis(std::vector<int> &v){//return largest sequence
            std::vector<int> ans;
            if(v.size()==0) return ans;
            std::vector<int> tail(v.size(),0);
            std::vector<int> prev(v.size(),-1);
            int len = 1;
            for(int i=1;i<v.size();i++){
                if(v[i] < v[tail[0]]) tail[0]=i;
                else if(v[i] > v[tail[len-1]]){
                    prev[i] = tail[len-1];
                    tail[len++] = i;
                }else{
                    int pos = ceilindex(v,tail, -1, len-1 , v[i]);
                    prev[i] = tail[pos-1];
                    tail[pos]=i;
                }
            }
            for(int i=tail[len-1]; i>=0; i=prev[i])ans.push_back(v[i]);
            std::reverse(ans.begin(),ans.end());
            return ans;
        }

        std::vector<int> getlen(std::vector<int> &v){//return lis size ending at each element
            std::vector<int> L;
            std::vector<int> len(v.size(),0);
            for(int i = 0; i < v.size(); i++){
                int pos = std::lower_bound(L.begin(), L.end() ,v[i])-L.begin();
                if(pos==L.size()) L.push_back(v[i]);
                else L[pos]=v[i];
                len[i]=pos+1;
            }
            return len;
        }
};
