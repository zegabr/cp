#include<vector>
#include<algorithm>
#include<set>
class ThreeSum{
    // TODO: returning vectors is too time consuming, must do all of it in the same method
    public:
        std::vector<std::vector<int>> getTwoSum(std::vector<int> &nums, int start, int desiredSum){// O(n)
            int l = start, r = nums.size() - 1;
            std::vector<std::vector<int>> res;
            while(l < r){
                int sum = nums[l] + nums[r];
                if(sum == desiredSum){
                    res.push_back({nums[l], nums[r]});
                    l++; r--;
                }else if(sum > desiredSum) r--;
                else l++;
            }
            return res;
        }

        std::vector<std::vector<int>> threeSum(std::vector<int> &nums, int desiredSum){
            if(nums.size() < 3) return {};
            sort(nums.begin(), nums.end());

            std::set<std::vector<int>> aux; // to remove duplicates

            for(int i = 0; i < nums.size() - 2; i++){//O(n)
                std::vector<std::vector<int>> pairs = getTwoSum(nums, i+1, desiredSum - nums[i]); //O(n)
                for(auto& p: pairs){
                    aux.insert({nums[i], p[0], p[1]});
                }
            }

            std::vector<std::vector<int>> res(aux.begin(), aux.end());
            return res;
        }
};
