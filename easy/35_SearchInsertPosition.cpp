class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1; // array 長度 -1
        int mid = 0;
        while (left <= right) {
            mid = (left + right) / 2; // 用 int 的性質做無條件捨去
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return mid; // 剛好找到 target
            }
        }
        return  nums[mid] < target?mid+1:mid;
    }
};
