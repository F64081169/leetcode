class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        
        for (int i = 0; i < spells.size(); i++) {
            int j = lower_bound(potions.begin(), potions.end(), (success + spells[i] - 1) / spells[i]) - potions.begin();
            ans.push_back(potions.size() - j);
        }
        
        return ans;
    }
};

