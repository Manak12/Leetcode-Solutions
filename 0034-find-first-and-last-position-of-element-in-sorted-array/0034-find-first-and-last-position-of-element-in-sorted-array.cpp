class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int right = lower_bound(nums.begin(), nums.end(), target + 1) - nums.begin();
        if (left == right) return {-1, -1};
        return {left, right - 1};
    }
};