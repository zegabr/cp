int largestRectangleArea(vector<int>& H) {
        stack<int> pos;
        int n = H.size();
        int res = 0;
        pos.push(-1);
        for(int i=0;i<n;i++){
            while(pos.top()!=-1 and H[i]<H[pos.top()]){
                int h = H[pos.top()]; 
                pos.pop();
                res = max(res, h*( (i-1) - pos.top()));
            }
            pos.push(i);
        }
        while(pos.top()!=-1){
            int h = H[pos.top()]; 
            pos.pop();
            res = max(res, h*( (n-1) - pos.top()));
        }
        return res;
    }
