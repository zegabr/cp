
const int alfa = 26;

class Node{  
  public: 
    int isword;//count many insertions
    int prefix_count;
    bool deleted;
    Node *child[alfa];

    Node(){
      fill(child, child + alfa, (Node *)NULL);
      isword = 0;
      prefix_count = 0;
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

    void insert(string &s){
      Node *cur = root;
      root->prefix_count++;
      for(char &c : s){
        int id = getId(c);
        if(isnull(cur->child[id])){
          cur->child[id] = new Node();
        }
        cur = cur->child[id];
        cur->prefix_count++;
      }
      cur->isword++;
    }

    int count(string &s, bool isPrefix = false){
      //count how many times s was inserted or how many words has s as prefix
      Node *cur = root;
      for(char &c : s){
        int id = getId(c);
        if(isnull(cur->child[id])){
          return 0;
        }
        cur = cur->child[id];
      }
      if(isPrefix) return cur->prefix_count;
      return cur->isword;
    }


    void remove(string &s, bool removeAll = false){//remove one or all occurrences
      Node *cur = root;
      vector<Node*> parent;
      for(char &c : s){
        int id = getId(c);
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
        cur->prefix_count-=quantity;
        if(cur->isword>0 or cur->prefix_count>0) 
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

  private:
    bool isnull(Node *cur){//gambiarra2
      return cur == (Node*)NULL or cur->deleted==true;
    }
    int getId(char c){
      return c-'a';
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


