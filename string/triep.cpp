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

#include <unordered_map>

const int alfa = 26;

class Node{  
  char data;
  bool isEnd;
  int childrenCount;
  Node *childs[alfa];
  
  Node(){
    for(int i=0;i<alfa;i++){
      childs[i]=(Node *)NULL;
    }
  }
  
};

class Trie{
  
  Trie(){

  }
};




int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0);
  




}
