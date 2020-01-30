
#define alfa 2

class Node{  
  public: 
    int isword;//count many insertions
    int children;
    bool deleted;
    Node *child[alfa];

    Node(){
      fill(child, child + alfa, (Node *)NULL);
      isword = 0;
      children = 0;
      deleted = false;
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
      root->children++;
      for(int i=31;i>=0;i--){
        int id = (s>>i)&1;
        if(isnull(cur->child[id])){
          cur->child[id] = new Node();
        }
        cur = cur->child[id];
        cur->children++;
      }
      cur->isword++;
    }

    int count(int s){
      Node *cur = root;
      for(int i=31;i>=0;i--){
        int id = (s>>i)&1;
        if(isnull(cur->child[id])){
          return 0;
        }
        cur = cur->child[id];
      }
      return cur->isword;
    }

    void remove(int s, bool removeAll = false){//remove one or all occurrences
      Node *cur = root;
      vector<Node*> parent;
      for(int i=31;i>=0;i--){
        int id = (s>>i)&1;
        if(isnull(cur->child[id])) 
          return;

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
        cur = parent.back();
        parent.ppb();
        cur->children-=quantity;
        if(cur->isword>0 or cur->children>0) 
          continue;

        bool hasChild=false;
        for(int i=0;!hasChild and i<alfa;i++){
          hasChild |= (!isnull(cur->child[i]));
        }
        if(!hasChild){
          cur->deleted = true;//gambiarra1
        }
      }
    }

    int maximizeXorWith(int n){
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
    bool isnull(Node *cur){//gambiarra2
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
