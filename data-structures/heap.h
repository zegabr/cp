
#include<queue>
#include<vector>
#include<functional>
template<class T> using maxheap = std::priority_queue<T>;
template<class T> using minheap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
std::priority_queue<int, std::vector<int>, std::function<bool(int,int)>> pq
            ( 
                [&](int a, int b) {
                    return a > b;
                }
                 
            );

