class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> cnt;
        for(int i = 0;i<nums.size();i++){
            cnt[nums[i]]++;
            if(cnt[nums[i]]>=2) return true;
        }
        return false;
    }
};
