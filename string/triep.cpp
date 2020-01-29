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

const int alfa = 26;

class Node{  
  public: 
    char data;
    int endHere;//count many insertions
    int childrenCount;
    Node *child[alfa];

    Node(){
      fill(child, child + alfa, (Node *)NULL);
      endHere = 0;
      childrenCount = 0;
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

    void insert(string &s){
      Node *cur = root;
      root->childrenCount++;
      for(char c : s){
        int id = getId(c);
        if(cur->child[id] == NULL){
          cur->child[id] = new Node();
        }
        cur = cur->child[id];
        cur->childrenCount++;
      }
      cur->endHere++;
    }

    int count(string &s){//count how many times s was inserted
      Node *cur = root;
      for(char c : s){
        int id = getId(c);
        if(cur->child[id] == NULL){
          return 0;
        }
        cur = cur->child[id];
      }
      return cur->endHere;
    }

    int countWordsWithPrefix(string &prefix){
      Node *cur = root;
      for(char c : prefix){
        int id = getId(c);
        if(cur->child[id] == NULL){
          return 0;
        }
        cur = cur->child[id];
      }
      return cur->childrenCount;
    }

    void removeOne(string &s){//remove one occurrence

    }

    void removeAll(string &s){//remove all occurrences

    }

  private:
    int getId(char c){
      return c-'a';
    }

    void freeChildren(Node *cur){
      if(cur == NULL)
        return;
      for(Node *it : cur->child){
        freeChildren(it);
      }
      delete cur;
    }
};




int32_t main(){
  Trie trie;
  string s = "abacata";
  trie.insert(s);
  cout<<"abacata existe "<<trie.count(s)<<" vezes"<<endl;
  s = "abacate";
  trie.insert(s);
  cout<<"abacate existe "<<trie.count(s)<<" vezes"<<endl;

  s = "abaca";
  cout<<trie.countWordsWithPrefix(s)<<endl;


}
