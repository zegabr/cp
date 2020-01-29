
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

    void remove(string &s, bool removeAll = false){//remove one or all occurrences
      //TODO: use a stack of Node* to backtrack path and go back deleting the nodes with no children
      Node *cur = root;
      for(char c : s){
        int id = getId(c);
        if(cur->child[id] == NULL){
          return;
        }
        cur = cur->child[id];
      }

      cur->endHere = max(0,cur->endHere - 1);//remove one

      if(removeAll)
        cur->endHere = 0;//remove all
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


