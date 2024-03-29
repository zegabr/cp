
#include<vector>
#include<iostream>
class Trie{
    private:
        static const int maxsize = 2111111;
        static const int alfa = 128; //can use all ascii characters
    public:
        std::vector<std::vector<int>> trie;
        std::vector<int> isword;
        std::vector<int> pref;
        std::vector<int> data;//used for debugging and removals
        int z;

        Trie() {
            trie.assign(maxsize,std::vector<int>(alfa,0));
            isword.assign(maxsize,0);
            pref.assign(maxsize,0);
            data.assign(maxsize,0);
            z = 1;
        }

        void insert(std::string &s) {
            int cur = 0, id;
            pref[cur]++;
            for(int i = 0; i < s.size(); i++) {
                id = getid(s[i]);
                if(!trie[cur][id]) {
                    reset(z);
                    trie[cur][id] = z++;
                }
                cur = trie[cur][id];
                data[cur]=id;
                pref[cur]++;
            }
            isword[cur]++;
        }

        int count(std::string &s, bool prefixQuery=false) {
            //count final words or common prefixes
            int cur = 0, id;
            for(int i = 0; i < s.size(); i++) {
                id = getid(s[i]);
                if(!trie[cur][id]) return 0;
                cur = trie[cur][id];
            }
            return prefixQuery ? pref[cur] : isword[cur];
        }

        void remove(std::string &s, bool removeAll=false){
            //remove one or all ocurrences of s
            int cur = 0, id;
            std::vector<int> parentstack;
            parentstack.push_back(cur);
            for(int i = 0; i < s.size(); i++) {
                id = getid(s[i]);
                if(!trie[cur][id]) return;
                cur = trie[cur][id];
                parentstack.push_back(cur);
            }

            int toRemove = removeAll ? isword[cur] : 1;
            isword[cur] -= toRemove;

            while(parentstack.size()>1){
                cur = parentstack.back();
                parentstack.pop_back();
                pref[cur] -= toRemove;

                if(pref[cur]){
                    continue;
                } else{
                    //not a prefix, hence has no child
                    trie[parentstack.back()][data[cur]]=0;
                }
            }
        }

    private:
        void reset(int node){
            trie[node].assign(alfa,0);
            pref[node]=isword[node]=0;
        }

        int getid(char c) {//carefull if alphabet is different from [a-z]
            if(alfa == 128) return c;
            //write get here      

        }
};
