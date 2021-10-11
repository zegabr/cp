
#include<iostream>
#include<algorithm>
class Node{  
    private:
        static const int alfa = 128;
    public: 
        int data;
        int isword;//count many insertions
        int pref;
        Node *child[alfa];

        Node() : data(0), isword(0), pref(0) 
    {
        std::fill(child, child + alfa, (Node *)NULL);
    }
};

class Trie{
    private:
        static const int alfa = 128;
    public:
        Node *root;

        Trie() : root(new Node()) {}

        ~Trie(){
            freeChildren(root);
        }

        void insert(std::string &s){
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

        int count(std::string &s, bool isPrefix = false){
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


