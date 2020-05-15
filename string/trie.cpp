
#define maxsize 2111111
#define alfa 128 //can use all ascii characters

class Trie{
    public:
        vector<vector<int>> trie;
        vector<int> isword;
        vector<int> pref;
        vector<int> data;//used for debugging and removals
        int z;

        Trie() {
            trie.assign(alfa,vector<int>(maxsize,0));
            isword.assign(maxsize,0);
            pref.assign(maxsize,0);
            data.assign(maxsize,0);
            z = 1;
        }

        void insert(string &s) {
            int cur = 0, id;
            pref[cur]++;
            for(int i = 0; i < len(s); i++) {
                id = getid(s[i]);
                if(!trie[id][cur]) {
                    reset(z);
                    trie[id][cur] = z++;
                }
                cur = trie[id][cur];
                data[cur]=id;
                pref[cur]++;
            }
            isword[cur]++;
        }

        int count(string &s, bool prefixQuery=false) {
            //count final words or common prefixes
            int cur = 0, id;
            for(int i = 0; i < len(s); i++) {
                id = getid(s[i]);
                if(!trie[id][cur]) return 0;
                cur = trie[id][cur];
            }
            return prefixQuery ? pref[cur] : isword[cur];
        }

        void remove(string &s, bool removeAll=false){
            //remove one or all ocurrences of s
            int cur = 0, id;
            vector<int> parentstack;
            parentstack.pb(cur);
            for(int i = 0; i < len(s); i++) {
                id = getid(s[i]);
                if(!trie[id][cur]) return;
                cur = trie[id][cur];
                parentstack.pb(cur);
            }

            int toRemove = removeAll ? isword[cur] : 1;
            isword[cur] -= toRemove;

            while(len(parentstack)>1){
                cur = parentstack.back();
                parentstack.ppb();
                pref[cur] -= toRemove;

                if(pref[cur]){
                    continue;
                } else{
                    //not a prefix, hence has no child
                    trie[data[cur]][parentstack.back()]=0;
                }
            }
        }

    private:
        void reset(int node){
            for(int i=0;i<alfa;i++) trie[i][node] = 0;
            pref[node]=isword[node]=0;
        }

        int getid(char c) {//carefull if alphabet is different from [a-z]
            if(alfa == 128) return c;
            //write get here      

        }
};
