
int partition(vector<int> &nums, int l, int r){
    if(l >= r) return l;
    int pivot = nums[r];
    int i = l; //all numbers before nums[i] are less than pivot

    for(int j = l; j < r; j++)
        if(nums[j] < pivot)
            swap(nums[i++], nums[j]);//make ith element less than pivot, increment i

    swap(nums[i], nums[r]); //every element less than pivot was replaced to before nums[i]
    return i;
}
