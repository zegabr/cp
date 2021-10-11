
#include <vector>
#include <algorithm>
int partition(std::vector<int> &nums, int l, int r){
    if(l >= r) return l;

    int randomPos = rand() % (r-l+1) + l;
    std::swap(nums[randomPos], nums[r]);
    int pivot = nums[r];

    int i = l; //all numbers before nums[i] are less than pivot

    for(int j = l; j < r; j++)
        if(nums[j] < pivot)
            std::swap(nums[i++], nums[j]);//make ith element less than pivot, increment i

    std::swap(nums[i], nums[r]); //every element less than pivot was replaced to before nums[i]
    return i;
}
