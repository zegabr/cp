
//supose A is cumulative sum array
//sum from i to j (i < j) will be the diference between A[j] and A[i-1]
//to maximiza A[j] - A[i-1] for each j, we want A[i-1] to be the minimum value that appeared in A (before j)

#include<vector>
class Kadane{
    public:
        int maxSubArray(std::vector<int>& nums) {
            int currsum = 0;
            int minsum = 0;
            int res = nums[0];
            for(int num : nums){
                currsum += num;
                res = std::max(currsum - minsum, res);
                minsum = std::min(minsum, currsum);
            }
            return res;
        }
};
