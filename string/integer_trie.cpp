#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
#define x first
#define y second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ll long long
#define ld long double
#define ii pair<int,int>
#define heap priority_queue
#define ull unsigned long long
#define all(k) k.begin(),k.end()
#define rall(k) k.rbegin(),k.rend()
#define len(v) ((int)v.size())
#define fa(a,c) for(auto &a:c)
#define endl '\n'


#define maxsize 6200001
#define alfa 2

class Trie{
  public:
    vector<vector<int>> trie;
    vector<int> isword;
    vector<int> pref;
    vector<int> data;
    int z;

    Trie() {
      trie.assign(maxsize,vector<int>(alfa,0));
      isword.assign(maxsize,0);
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
      isword[cur]++;
    }

    int count(int &s) {
      //count final words or common prefixes
      int cur = 0, id;
      for(int i = 31; i >= 0; i--) {
        id = getid(s,i);
        if(!trie[cur][id]) return 0;
        cur = trie[cur][id];
      }
      return isword[cur];
    }

    void remove(int &s, bool removeAll=false){
      //remove one or all ocurrences of s
      int cur = 0, id;
      vector<int> parentstack;
      parentstack.pb(cur);
      for(int i = 31; i >= 0; i--) {
        id = getid(s,i);
        if(!trie[cur][id]) return;
        cur = trie[cur][id];
        parentstack.pb(cur);
      }

      int toRemove = removeAll ? isword[cur] : 1;
      isword[cur] -= toRemove;

      while(len(parentstack)>1){
        cur = parentstack.back();
        parentstack.ppb();
        pref[cur] -= toRemove;
        
        if(isword[cur] or pref[cur]) continue;

        if(pref[cur]==0){
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
      pref[node]=isword[node]=0;
    }

    int getid(int &s, int &i) {
      return (s>>i)&1;
    }
};





int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0);

  Trie t;
  int q,v;
  char op;
  cin>>q;
  int a=0;
  t.insert(a);
  while(q--){
    cin>>op>>v;
    if(op=='+') t.insert(v);
    else if(op=='-') t.remove(v);
    else cout<<t.maximizeXorWith(v)<<endl;
  }



}
