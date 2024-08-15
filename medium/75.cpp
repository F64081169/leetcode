class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ptr=0,l = 0;
        int r = nums.size()-1;

        while(ptr<=r){
            if(nums[ptr] == 0){
                swap(nums[l],nums[ptr]);
                l++;
                ptr++;
            }else if(nums[ptr] == 1){
                ptr++;
            }else{ // nums[ptr] == 2
                swap(nums[r],nums[ptr]);
                r--;
            }
        }
    }
};
