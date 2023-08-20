class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
      const int mid = left + (right - left)/2;
      if (nums[ mid ] == target)
        return  mid ;
      if (nums[left] <= nums[ mid ]) {  // nums[left..m] are sorted
        if (nums[left] <= target && target < nums[mid])
          right =  mid  - 1;
        else
          left =  mid  + 1;
      } else {  // nums[m..n - 1] are sorted
        if (nums[ mid ] < target && target <= nums[right])
          left =  mid  + 1;
        else
          right =  mid  - 1;
      }
    }
    return -1;
  }
};