
template<typename T>
class Node{
    public:
        T val;
        Node<T> *next;
        Node<T> *prev;
        Node(T v): val(v), next(nullptr), prev(nullptr) {}
        Node(T v, Node<T>* n): val(v), next(n), prev(nullptr) {}
        Node(T v, Node<T>* n, Node<T>* p): val(v), next(n), prev(p) {}
};

template<typename T>
class Deque{
    private:
        int sz = 0;
        Node<T>* frontNode = nullptr;
        Node<T>* backNode = nullptr;

    public:
        int size(){
            return sz;
        }

        T front(){
            return frontNode->val;
        }

        T back(){
            return backNode->val;
        }

        void push_back(T val){
            Node<T> *newNode = new Node<T>(val); 
            if(size() == 0){
                frontNode = backNode = newNode;
            }else{
                newNode->prev = backNode;
                backNode->next = newNode;
                backNode = newNode;
            }
            sz++;
        }

        void push_front(T val){
            Node<T> *newNode = new Node<T>(val); 
            if(size() == 0){
                frontNode = backNode = newNode;
            }else{
                newNode->next = frontNode;
                frontNode->prev = newNode;
                frontNode = newNode;
            }
            sz++;
        }

        T pop_back(){
            T res = backNode->val;
            if(size() == 1){
                frontNode = backNode = nullptr;
            }else{
                backNode = backNode->prev;
                backNode->next = nullptr;
            }
            sz--;
            return res;
        }

        T pop_front(){
            T res = frontNode->val;
            if(size() == 1){
                frontNode = backNode = nullptr;
            }else{
                frontNode = frontNode->next;
                frontNode->prev = nullptr;
            }
            sz--;
            return res;
        }
};

template<typename T>
class Queue{
    private:
        Deque<T>* deque;

    public:
        Queue(){
            deque = new deque<T>();
        }

        T front(){
            return deque->front();
        }

        T back(){
            return deque->back();
        }

        T pop(){
            return deque->pop_front();
        }   

        void push(T val){
            deque->push_back(val);
        }

        int size(){
            return deque->size();
        }
};

template<typename T>
class Stack{
    private:
        Deque<T>* deque;

    public:
        Stack(){
            deque = new deque<T>();
        }

        T top(){
            return deque->front();
        }

        T pop(){
            return deque->pop_front();
        }   

        void push(T val){
            deque->push_front(val);
        }

        int size(){
            return deque->size();
        }
};

