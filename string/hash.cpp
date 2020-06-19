
typedef pair<long long, unsigned long long> Hash;
const long long base = 137;//cover all ascii values
const unsigned long long mod = (1ll<<31)-1ll;
//mod2 = 1<<64

class Hasher{
    private:
        vector<long long> h1;
        vector<unsigned long long> h2;
        bool isReversed;
    
        vector<long long> pot1;//be aware of MLE, maybe put pot1 and pot2 as global
        vector<unsigned long long> pot2;
        void buildpot(int maxsize = 2000000){
            pot1.resize(maxsize);
            pot2.resize(maxsize);
            pot1[0] = pot2[0] = 1;
            for(int i = 1;i < maxsize;i++){
                pot1[i] = pot1[i-1] * base % mod;
                pot2[i] = pot2[i-1] * base;
            }   
        }
    public:
        Hasher(string &s, bool reversed = false){
            isReversed = reversed;
            if(pot1.empty())
                buildpot(s.size());
            int n = s.size();
            h1.resize(n);
            h2.resize(n);
            h1[0] = h2[0] = s[0];
            for(int i = 1;i < n;i++){
                h1[i] = (h1[i-1] * base % mod + s[i]) % mod;
                h2[i] = h2[i-1] * base + s[i];
            }
        }

        Hash get(int l, int r){
            int n = h1.size();
            if(isReversed){
                int R=r,L=l;
                r = n-L-1;
                l = n-R-1;
            }
            long long res1 = h1[r];
            unsigned long long res2 = h2[r];
            if(l>0){
                res1 = (res1 - pot1[r-l+1]*h1[l-1]%mod + mod)%mod;
                res2 = res2 - pot2[r-l+1] * h2[l-1];
            } 
            return Hash(res1,res2);
        }

        Hash getpref(int m){
            return get(0,m-1);
        }

        Hash getsuff(int m){
            int n = h1.size();
            return get(n-m,n-1);
        }
    
        int size(){
            return h1.size();
        }
};