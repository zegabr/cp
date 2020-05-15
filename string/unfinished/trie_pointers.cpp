
#define alfa 128

class Node{  
    public: 
        int data;
        int isword;//count many insertions
        int pref;
        Node *child[alfa];

        Node(){
            fill(child, child + alfa, (Node *)NULL);
            isword = 0;
            pref = 0;
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
            root->pref++;
            for(char &c : s){
                int id = getid(c);
                if(!cur->child[id]){
                    cur->child[id] = new Node();
                }
                cur = cur->child[id];
                cur->data = id;
                cur->pref++;
            }
            cur->isword++;
        }

        int count(string &s, bool isPrefix = false){
            //count how many times s was inserted or how many words has s as prefix
            Node *cur = root;
            for(char &c : s){
                int id = getid(c);
                if(!cur->child[id]){
                    return 0;
                }
                cur = cur->child[id];
            }
            if(isPrefix) return cur->pref;
            return cur->isword;
        }

        /*
         *seems that remove does not work
         * */
        void remove(string &s, bool removeAll = false){//remove one or all occurrences
            Node *cur = root;
            vector<Node*> parent = {cur};
            for(char &c : s){
                int id = getid(c);
                if(!cur->child[id]) 
                    return;

                cur = cur->child[id];
                parent.pb(cur);
            }

            int quantity=1;
            if(removeAll){
                quantity = cur->isword;
                cur->isword = 0;//remove all
            }else{
                cur->isword--;//remove one
            }

            while(len(parent)>1){
                cur = parent.back();
                parent.ppb();
                id = cur->data;
                cur->pref-=quantity;
                if(cur->isword>0 or cur->pref>0) 
                    continue;

                bool haschild=false;
                for(int i=0;!haschild and i<alfa;i++){
                    haschild |= (cur->child[i]!=NULL);
                }
                if(!haschild){
                    id = cur->data;
                    freeChildren(parent.back()->child[id]);
                    parent.back()->child[id]=NULL;
                }
            }
        }

    private:
        int getid(char c){
            if(alfa == 128) return c;
            //write get here


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


