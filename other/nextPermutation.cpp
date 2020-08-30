void nextPermutation(vector<int>& nums) {
        int ds = nums.size() - 1;
        while(ds > 0 and nums[ds - 1] >= nums[ds])
            ds--;
        if(ds == 0){
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int ie = ds - 1;
        int mb = nums[ds] , mbp=ds;
        for(int i = ds; i < nums.size(); i++){
            if(nums[i] > nums[ie]){
                mb = max(mb, nums[i]);
                mbp = i;
            }    
        }
        
        swap(nums[ie], nums[mbp]);
        reverse(nums.begin() + ds, nums.end());
        return;
 }
