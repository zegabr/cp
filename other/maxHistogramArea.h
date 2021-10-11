
#include <vector>
#include <stack>
#include <algorithm>
class MaxHistogramArea{
    public:
        int maxRectangleHistogramArea(std::vector<int>& H) {
            std::stack<int> pos;
            pos.push(-1);//to facilitate range calculations
            H.push_back(0);//to guarantees that stack ends empty
            int res = 0;
            for(int i = 0;i < H.size(); i++){
                while(pos.top() != -1 and H[i] < H[pos.top()]){
                    int h = H[pos.top()]; 
                    pos.pop();
                    res = std::max(res, h*( (i-1) - pos.top()));//here pos.top might be -1
                }
                pos.push(i);
            }
            return res;
        }
};
