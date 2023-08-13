
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    const int size1 = nums1.size();
    const int size2 = nums2.size();
    if (size1 > size2)
      return findMedianSortedArrays(nums2, nums1);

    int left = 0;
    int right =size1;

    while (left <= right) {
      const int partition1 = left + (right-left) / 2;
      const int partition2 = (size1 + size2 + 1) / 2 - partition1;
      const int maxLeft1 = partition1 == 0 ? INT_MIN : nums1[partition1 - 1];
      const int maxLeft2 = partition2 == 0 ? INT_MIN : nums2[partition2 - 1];
      const int minRight1 = partition1 == size1 ? INT_MAX : nums1[partition1];
      const int minRight2 = partition2 == size2 ? INT_MAX : nums2[partition2];
      if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1)
        return (size1 + size2) % 2 == 0
                   ? (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) * 0.5
                   : max(maxLeft1, maxLeft2);
      else if (maxLeft1 > minRight2)
        right = partition1 - 1;
      else
        left = partition1 + 1;
    }
    throw;
  }
};