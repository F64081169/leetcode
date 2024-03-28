class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, res = 0;
        for(int i = 0;i<nums.size();i++){
            if(res==nums[i]){
                cnt++;
            }else{
                if(!cnt){
                    res=nums[i];
                    cnt=1;
                }else{
                    cnt--;
                }
            }
        }
        return res;
    }
};
