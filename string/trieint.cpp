#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <bitset>
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
//#define endl '\n'


const int alfa = 2;

class Node{  
  public: 
    int isword;//count many insertions
    int childrenCount;
    bool deleted;
    Node *child[alfa];

    Node(){
      fill(child, child + alfa, (Node *)NULL);
      isword = 0;
      childrenCount = 0;
      deleted=false;
    }
};

class Trie{
  public:
    Node *root;

    Trie(){
      root = new Node();
    }
    ~Trie(){
      freeChildren(root);
    }
    void insert(int s){
      Node *cur = root;
      root->childrenCount++;
      for(int i=31;i>=0;i--){
        int id = (s>>i)&1;
        if(isnull(cur->child[id])){
          //cout<<"criando "<<id<<endl;
          cur->child[id] = new Node();
        }
        cur = cur->child[id];
        cur->childrenCount++;
      }
      cur->isword++;
    }

    int count(int s, bool isPrefix = false){
      //count how many times s was inserted or how many words has s as prefix
      Node *cur = root;
      for(int i=31;i>=0;i--){
        int id = (s>>i)&1;
        if(!cur->child[id]){
          return 0;
        }
        cur = cur->child[id];
      }
      if(isPrefix) return cur->childrenCount;
      return cur->isword;
    }

    void remove(int s, bool removeAll = false){//remove one or all occurrences
      Node *cur = root;
      vector<Node*> parent;
      for(int i=31;i>=0;i--){
        int id = (s>>i)&1;
        if(isnull(cur->child[id])) return;

        cur = cur->child[id];
        parent.pb(cur);
      }
      int quantity=1;
      cur->isword = max(0,cur->isword - 1);//remove one
      if(removeAll){
        quantity = cur->isword;
        cur->isword = 0;//remove all
      }

      while(len(parent)){
        Node* cur2 = parent.back();
        parent.ppb();
        cur2->childrenCount-=quantity;
        if(cur2->isword>0 or cur2->childrenCount>0) 
          continue;

        bool hasChild=false;
        for(int i=0;!hasChild and i<alfa;i++){
          hasChild |= (!isnull(cur2->child[i]));
        }
        if(!hasChild){
          cur2->deleted = true;
        }
      }
    }

    int solve(int n){
      int res = 0;
      Node *cur = root;
      for(int i=31;i>=0;i--){
        int id = (n>>i)&1;
        if(!isnull(cur->child[!id])){
          res += (1<<i);
          cur = cur->child[!id];
        }else if(!isnull(cur->child[id])){
          cur = cur->child[id];
        }
      }
      return res;
    }

  private:

    bool isnull(Node *cur){
      return cur == (Node*)NULL or cur->deleted==true;
    }

    void freeChildren(Node *cur){
      if(cur==(Node*)NULL)
        return;
      for(Node *it : cur->child){
        freeChildren(it);
      }
      delete cur;
    }
};





int32_t main(){
  ios::sync_with_stdio(0); cin.tie(0);


  int q, v;
  char op;
  cin>>q;
  Trie t;
  int a=0;
  t.insert(a);
  while(q--){
    cin>>op>>v;
    if(op=='+'){
      t.insert(v);
    }else if(op=='-'){
      t.remove(v);
    }else if (op=='?'){
      cout<<t.solve(v)<<endl;
    }
  }


}
