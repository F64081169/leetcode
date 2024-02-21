class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Maintain a sliding window where there is at most one zero on it.
        int zero_cnt = 0;
        int res = 0;
        int left = 0;
        int max_ones = 0;
        for(int right = 0;right<nums.size();right++){
            if(nums[right] == 0) zero_cnt++;
            while(zero_cnt > 1){
                if(nums[left] == 0) zero_cnt--;
                left += 1;
            }
            int curr = right - left;
            if(curr > max_ones) max_ones = curr;
        }
        return max_ones;
    }
};
