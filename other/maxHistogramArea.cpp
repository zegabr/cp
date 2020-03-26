int largestRectangleArea(vector<int>& H) {
        stack<int> pos;
        int n = H.size();
        int res = 0;
        pos.push(-1);
        for(int i=0;i<H.size();i++){
            while(pos.top()!=-1 and H[i]<H[pos.top()]){
                int r = i;
                int l = pos.top(); pos.pop();
                res = max(res, H[l]*(r-pos.top()-1));
            }
            pos.push(i);
        }
        
        while(pos.top()!=-1){
                int r = n;
                int l = pos.top(); pos.pop();
                res = max(res, H[l]*(r-pos.top()-1));
        }
        
        return res;
    }
