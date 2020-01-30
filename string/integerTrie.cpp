
#define alfa 2

class Node{  
  public: 
    int data;
    int isword;//count many insertions
    int prefix_count;
    Node *child[alfa];

    Node(){
      fill(child, child + alfa, (Node *)NULL);
      isword = 0;
      prefix_count = 0;
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
      root->prefix_count++;
      for(int i=31;i>=0;i--){
        int id = getid(s,i);
        if(!cur->child[id]){
          cur->child[id] = new Node();
        }
        cur = cur->child[id];
        cur->data = id;
        cur->prefix_count++;
      }
      cur->isword++;
    }

    int count(int s){
      Node *cur = root;
      for(int i=31;i>=0;i--){
        int id = getid(s,i);
        if(!cur->child[id]){
          return 0;
        }
        cur = cur->child[id];
      }
      return cur->isword;
    }

    void remove(int s, bool removeAll = false){//remove one or all occurrences
      Node *cur = root;
      vector<Node*> parent = {cur};
      for(int i=31;i>=0;i--){
        int id = getid(s,i);
        if(!cur->child[id]) 
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

      while(len(parent)>1){
        cur = parent.back();
        parent.ppb();
        cur->prefix_count-=quantity;
        if(cur->isword>0 or cur->prefix_count>0) 
          continue;

        bool hasChild=false;
        for(int i=0;!hasChild and i<alfa;i++){
          hasChild |= (cur->child[i]!=NULL);
        }
        if(!hasChild){
          int id = cur->data;
          parent.back()->child[id]=NULL;
          //freeChildren(cur);
        }
      }
    }

    int maximizeXorWith(int s){
      int res = 0;
      Node *cur = root;
      for(int i=31;i>=0;i--){
        int id = getid(s,i);
        if(cur->child[!id]){
          res += (1<<i);
          cur = cur->child[!id];
        }else if(cur->child[id]){
          cur = cur->child[id];
        }
      }
      return res;
    }

  private:
  int getid(int &s, int i){
    return (s>>i)&1;
  }
    void freeChildren(Node *cur){
      if(cur==NULL)
        return;
      for(Node *it : cur->child){
        freeChildren(it);
      }
      delete cur;
    }
};

