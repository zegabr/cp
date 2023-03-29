
#include<string>
#include<tuple>
#include<vector>
#include<algorithm>
typedef std::pair<long long, unsigned long long> Hash;//double hash is better than single hash

class Hasher{
    private:
        static const long long base = 137;//cover all ascii values
        static const unsigned long long mod = (1ll<<31)-1; //mod2 = 1<<64

        bool isReversed;
        std::vector<Hash> H;

        void buildPow(std::vector<Hash> &POW, int maxsize = 2000000){
            int nexPosition = std::max(1,(int)POW.size());
            POW.resize(maxsize);
            POW[0].first = POW[0].second = 1;
            for(int i = nexPosition; i < maxsize; i++){
                POW[i].first = POW[i-1].first * base % mod;
                POW[i].second = POW[i-1].second * base;
            }
        }

        Hash getPow(int i){
            static std::vector<Hash> POW;
            if(i >= (int)POW.size()) {//prevent out of bounds
                buildPow(POW, i+1);
            }
            return POW[i];
        }

        Hash addChar(Hash &hash, char &c){//add char to cumulative hash
            long long a = (hash.first * base % mod + c) %mod;
            unsigned long long b = (hash.second * base + c);
            return Hash(a,b);
        }

        Hash subtract(Hash &head, Hash &tail, int patternSize){//used to get hash of window/substd::string
            Hash power = getPow(patternSize);
            long long a = (head.first - tail.first * power.first % mod + mod) % mod;
            unsigned long long b = head.second - tail.second * power.second;
            return Hash(a,b);
        }

        Hash removeFromLeft(Hash &window, char c, int patternSize){// if sliding window must use after adding char
            Hash power = getPow(patternSize);
            long long a = (window.first - c * power.first % mod + mod) %mod;
            unsigned long long b = window.second - c * power.second;
            return Hash(a,b);
        }

    public:
        // full std::string hash O(N)
        Hasher(std::string &s, bool reversed = false): isReversed(reversed) {
            int n = s.size();
            H.resize(n);
            H[0].first = H[0].second = s[0];
            for(int i = 1;i < n;i++){
                H[i] = addChar(H[i-1], s[i]);
            }
        }

        //window std::string hash O(1)
        Hash get(int l, int r){
            int n = H.size();
            if(isReversed){ // TODO: add an explanation for this
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

        Hash getUniqueHash(std::string &s){
            Hash hash = {0,0};
            for(char c : s) hash = addChar(hash, c);
            return hash;
        }

        int findFirst(std::string &text, std::string &pattern){// find first pattern in text O(N)
            int n = text.size(), m = pattern.size();
            if(m == 0) return 0;

            Hash patternHash, window = {0,0};
            patternHash = getUniqueHash(pattern);

            for(int i = 0; i < m; i++) window = addChar(window, text[i]);
            if(window == patternHash) return 0; // is at the beggining

            for(int i = m; i < n; i++){
                window = addChar(window, text[i]); // add next
                window = removeFromLeft(window, text[i-m], m); // remove first
                if(window == patternHash) return i - m + 1; // if i = m, return 1 and so on
            }

            return -1;
        }
};


