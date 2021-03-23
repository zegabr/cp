
typedef pair<long long, unsigned long long> Hash;//double hash is better than single hash

class Hasher{
    private:
        const long long base = 137;//cover all ascii values
        const unsigned long long mod = (1ll<<31)-1; //mod2 = 1<<64

        bool isReversed;
        vector<Hash> H;

        void buildPow(vector<Hash> &POW, int maxsize = 2000000){
            int nexPosition = max(1,(int)POW.size());
            POW.resize(maxsize);
            POW[0].first = POW[0].second = 1;
            for(int i = nexPosition; i < maxsize; i++){
                POW[i].first = POW[i-1].first * base % mod;
                POW[i].second = POW[i-1].second * base;
            }   
        }

        Hash getPow(int i){
            static vector<Hash> POW;
            if(i >= (int)POW.size()) {//prevent out of bounds
                buildPow(POW, i+1);
            }
            return POW[i];
        }

        void addChar(Hash &hash, char &c){//add char to cumulative hash
            hash.first = (hash.first * base % mod + c) %mod;
            hash.second = (hash.second * base + c);
        }

        Hash subtract(Hash &head, Hash &tail, int patternSize){//used to get hash of window
            Hash power = getPow(patternSize);
            long long a = (head.first - tail.first * power.first % mod + mod) % mod;
            unsigned long long b = head.second - tail.second * power.second;
            return Hash(a,b);
        }

    public: 
        // full string hash O(N)
        Hasher(string &s, bool reversed = false): isReversed(reversed) {
            int n = s.size();
            H.resize(n);
            H[0].first = H[0].second = s[0];
            for(int i = 1;i < n;i++){
                H[i] = H[i-1];
                addChar(H[i], s[i]);
            }
        }

        //window string hash O(1)
        Hash get(int l, int r){
            int n = H.size();
            if(isReversed){
                int R = r,L = l;
                r = n - L - 1;
                l = n - R - 1;
            }

            Hash res = H[r];
            if(l>0) res = subtract(res, H[l-1], r-l+1);
            return res;
        }

        Hash getpref(int m){
            return get(0,m-1);
        }

        Hash getsuff(int m){
            int n = H.size();
            return get(n-m,n-1);
        }

    public: 
        //rabin karp constructor
        Hasher(){}

        Hash getUniqueHash(string &s){
            Hash hash = {0,0};
            for(char c : s) addChar(hash, c);
            return hash;
        }

        int findFirst(string &text, string &pattern){// find first pattern in text O(N)
            int n = text.size(), m = pattern.size();
            if(m == 0) return 0;

            Hash patternHash, cumulativeHead, cumulativeTail;
            patternHash = getUniqueHash(pattern);

            for(int i = 0; i < n; i++){
                if(i >= m) addChar(cumulativeTail, text[i-m]);
                addChar(cumulativeHead, text[i]);

                Hash currHash = subtract(cumulativeHead, cumulativeTail, m); 
                // this can be done as:
                // addnextchar(cumulative, text[i]); 
                // removefirstchar(cumulative, text[i-m], m); -> cumulative = (cumulative - text[i-m] * b^m + mod) % mod;
                // advantages: does not need to use cumulativeTail uhuu
                
                if(i >= m-1 and currHash == patternHash) return i - m + 1;
            }

            return -1;
        }
};


