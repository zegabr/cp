
#define maxsize 6200001 
#define alfa 2

class Trie{
  public:
    vector<vector<int>> trie;
    vector<int> word;
    vector<int> pref;
    vector<int> data;//used for debug and removal
    int z;

    Trie() {
      trie.assign(maxsize,vector<int>(alfa,0));
      word.assign(maxsize,0);
      pref.assign(maxsize,0);
      data.assign(maxsize,0);
      z = 1;
    }

    void insert(int &s) {
      int cur = 0, id;
      pref[cur]++;
      for(int i = 31; i >= 0;i--) {
        id = getid(s,i);
        if(!trie[cur][id]) {
          reset(z);
          trie[cur][id] = z++;
        }
        cur = trie[cur][id];
        data[cur]=id;
        pref[cur]++;
      }
      word[cur]++;
    }

    int count(int &s) {
      int cur = 0, id;
      for(int i = 31; i >= 0; i--) {
        id = getid(s,i);
        if(!trie[cur][id]) return 0;
        cur = trie[cur][id];
      }
      return word[cur];
    }

    void remove(int &s, bool removeAll=false){
      //remove one or all ocurrences of s
      int cur = 0, id;
      vector<int> parentstack;
      parentstack.push_back(cur);
      for(int i = 31; i >= 0; i--) {
        id = getid(s,i);
        if(!trie[cur][id]) return;
        cur = trie[cur][id];
        parentstack.push_back(cur);
      }

      int toRemove = removeAll ? word[cur] : 1;
      word[cur] -= toRemove;

      while(len(parentstack)>1){
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

    int maximizeXorWith (int &s){
      int res = 0, id, cur=0;
      for(int i=31;i>=0;i--){
        id = getid(s,i);
        if(trie[cur][!id]){
          res += (1<<i);
          cur = trie[cur][!id];
        }else{
          cur = trie[cur][id];
        }
      }
      return res;
    }

  private:
    void reset(int node){
      trie[node].assign(alfa,0);
      pref[node]=word[node]=0;
    }

    int getid(int &s, int &i) {
      return (s>>i)&1;
    }
};
