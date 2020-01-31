
#define maxsize 100001
#define alfa 26

class Trie{
  public:
    vector<vector<int>> trie;
    vector<int> isword;
    vector<int> pref;
    int z;

    Trie() {
      trie.assign(maxsize,vector<int>(alfa,0));
      isword.assign(maxsize,0);
      pref.assign(maxsize,0);
      z = 1;
    }

    void insert(string &s) {
      int cur = 0, id;
      pref[cur]++;
      for(int i = 0; i < len(s); i++) {
        id = getid(s[i]);
        if(!trie[cur][id]) {
          reset(z);
          trie[cur][id] = z++;
        }
        cur = trie[cur][id];
        pref[cur]++;
      }
      isword[cur]++;
    }

    int count(string &s, bool prefixQuery=false) {
      //count final words or common prefixes
      int cur = 0, id;
      for(int i = 0; i < len(s); i++) {
        id = getid(s[i]);
        if(!trie[cur][id]) return 0;
        cur = trie[cur][id];
      }
      return prefixQuery ? pref[cur] : isword[cur];
    }

    void remove(string &s, bool removeAll=false){
     //remove one or all ocurrences of s
      int cur = 0, id;
      vector<int> parentstack;
      for(int i = 0; i < len(s); i++) {
        id = getid(s[i]);
        if(!trie[cur][id]) return;
        cur = trie[cur][id];
        parentstack.pb(cur);
      }

      int toRemove = removeAll ? isword[cur] : 1;

      while(len(parentstack)){
        cur = parentstack.back();
        parentstack.ppb();
        isword[cur] -= toRemove;
        pref[cur] -= toRemove;
        if(pref[cur]==0){//not a prefix, hence has no child
          reset(cur);
        }
      }
    }

  private:
    void reset(int node){
      trie[node].assign(alfa,0);
      pref[node]=isword[node]=0;
    }

    int getid(char c) {
      return c - 'a';
    }
};

