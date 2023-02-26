class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int m=nums.size(),n=nums[0].size();
        unordered_map<int,int> mp;
        for(int i=0;i<m;i++){
            for(int j=0;j<nums[i].size();j++){
                mp[nums[i][j]]++;
            }
        }
        vector<int> v;
        for(auto i:mp){
            if(i.second==m) v.push_back(i.first);
        }
        sort(v.begin(),v.end());
        return v;
    }
};