
int maxSubArray(vector<int>& nums) {
        int currsum = 0;
        int minsum = 0;
        int res = nums[0];
        for(int num : nums){
            currsum += num;
            res = max(currsum - minsum, res);
            minsum = min(minsum, currsum);
        }
        return res;
}
//supose A is cumulative sum array
//sum from i to j (i < j) will be the diference between A[j] and A[i-1]
//to maximiza A[j] - A[i-1] for each j, we want A[i-1] to be the minimum value that appeared in A (before j)
