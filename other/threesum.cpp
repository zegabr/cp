class ThreeSum{
    // TODO: returning vectors is too time consuming, must do all of it in the same method
    public:
        vector<vector<int>> getTwoSum(vector<int> &nums, int start, int desiredSum){// O(n)
            int l = start, r = nums.size() - 1;
            vector<vector<int>> res;
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

        vector<vector<int>> threeSum(vector<int> &nums, int desiredSum){
            if(nums.size() < 3) return {};
            sort(nums.begin(), nums.end());

            set<vector<int>> aux; // to remove duplicates

            for(int i = 0; i < nums.size() - 2; i++){//O(n)
                vector<vector<int>> pairs = getTwoSum(nums, i+1, desiredSum - nums[i]); //O(n)
                for(auto& p: pairs){
                    aux.insert({nums[i], p[0], p[1]});
                }
            }

            vector<vector<int>> res(aux.begin(), aux.end());
            return res;
        }
};
