
const int alfa = 26;

class Node{  
  public: 
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
        if(!cur->child[id]){
          cur->child[id] = new Node();
        }
        cur = cur->child[id];
        cur->childrenCount++;
      }
      cur->endHere++;
    }

    void insert(int &s){
      Node *cur = root;
      root->childrenCount++;
      for(int i=0;i<32;i++){
        int id = (s>>i)&1;
        if(!cur->child[id]){
          cur->child[id] = new Node();
        }
        cur = cur->child[id];
        cur->childrenCount++;
      }
      cur->endHere++;
    }

    int count(string &s, bool isPrefix = false){
      //count how many times s was inserted or how many words has s as prefix
      Node *cur = root;
      for(char c : s){
        int id = getId(c);
        if(!cur->child[id]){
          return 0;
        }
        cur = cur->child[id];
      }
      if(isPrefix) return cur->childrenCount;
      return cur->endHere;
    }

    int count(int &s, bool isPrefix = false){
      //count how many times s was inserted or how many words has s as prefix
      Node *cur = root;
      for(int i=0;i<32;i++){
        int id = (s>>i)&1;
        if(!cur->child[id]){
          return 0;
        }
        cur = cur->child[id];
      }
      if(isPrefix) return cur->childrenCount;
      return cur->endHere;


    }
    void remove(string &s, bool removeAll = false){//remove one or all occurrences
      Node *cur = root;
      vector<Node*> parent;
      for(char c : s){
        int id = getId(c);
        if(!cur->child[id]) return;

        cur = cur->child[id];
        parent.pb(cur);
      }

      cur->endHere = max(0,cur->endHere - 1);//remove one
      if(removeAll)
        cur->endHere = 0;//remove all

      while(len(parent)){
        cur = parent.back();
        parent.ppb();
        if(cur->endHere>0) 
          continue;
        bool hasChild=false;
        for(int i=0;!hasChild and i<alfa;i++){
          hasChild |= (cur->child[i]!=NULL);
        }
        if(!hasChild)
          freeChildren(cur);
      }
    }

    void remove(int &s, bool removeAll = false){
      Node *cur = root;
      vector<Node*> parent;
      for(int i=0;i<32;i++){
        int id = (s>>i)&1;
        if(!cur->child[id]) return;

        cur = cur->child[id];
        parent.pb(cur);
      }

      cur->endHere = max(0,cur->endHere - 1);//remove one
      if(removeAll)
        cur->endHere = 0;//remove all

      while(len(parent)){
        cur = parent.back();
        parent.ppb();
        if(cur->endHere>0) 
          continue;
        bool hasChild=false;
        for(int i=0;!hasChild and i<alfa;i++){
          hasChild |= (cur->child[i]!=NULL);
        }
        if(!hasChild)
          freeChildren(cur);
      }
    }

    int solve(int n){
      int res = n;

      return res;
    }

  private:
    int getId(char c){
      return c-'a';
    }

    void freeChildren(Node *cur){
      if(!cur)
        return;
      for(Node *it : cur->child){
        freeChildren(it);
      }
      delete cur;
    }
};


