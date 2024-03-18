class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // solution 2
        // hash map
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.count(target - nums[i])) {
                return {m[target - nums[i]], i};
            }
            m[nums[i]] = i;
        }
        return {-1, -1};

/*
        // solution 1
        // nested loop
        vector<int>a(2,-1);
        for(int i = 0;i<nums.size();i++){
            for(int j = i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    a = {i,j};
                    return a;
                }
            }
        }
        return a;
*/
    }
};
