class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // 子陣列問題通常可以使用 Sliding Window 求解
        // 第一個不合法的位置減去第一個合法的位置就是目前 window 可以產生的子陣列總數
        // 上句什麼意思？？
        int sum1=0,sum2=0;
        int l1=0,l2=0;
        int ans=0;
        for(int i = 0;i<nums.size();i++){
            sum1+=nums[i];
            sum2+=nums[i];
            while(sum2>goal){
                sum2 -= nums[l2++];
            }
            while(sum1>=goal && l1<=i){
                sum1 -= nums[l1++];
            }
            ans += (l1-l2);
        }     
        return ans;   
    }
};
