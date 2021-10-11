
#include <vector>
#include <stack>
#include <algorithm>
class NextPermutation{
    public:
        void nextPermutation(std::vector<int>& nums) {
            int decreasingStart = nums.size() - 1;
            while(decreasingStart > 0 and nums[decreasingStart - 1] >= nums[decreasingStart])
                decreasingStart--;
            if(decreasingStart == 0){
                reverse(nums.begin(), nums.end());
                return;
            }

            int increasingEnd = decreasingStart - 1;
            int mb = nums[decreasingStart] , mbp = decreasingStart;
            for(int i = decreasingStart; i < nums.size(); i++){
                if(nums[i] > nums[increasingEnd]){
                    mb = std::max(mb, nums[i]);
                    mbp = i;
                }    
            }

            std::swap(nums[increasingEnd], nums[mbp]);
            reverse(nums.begin() + decreasingStart, nums.end());
            return;
        }
};

