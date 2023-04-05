class Solution {
public:
    // hash table O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (hash_map.find(complement) != hash_map.end()) {
                return {hash_map[complement], i};
            }
            hash_map[nums[i]] = i;
        }
        return {};
    }
};

/*
// Two pointer O(nlogn)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        vector<pair<int, int>> nums_with_index;
        for (int i = 0; i < nums.size(); i++) {
            nums_with_index.push_back({nums[i], i});
        }
        sort(nums_with_index.begin(), nums_with_index.end());
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int sum = nums_with_index[left].first + nums_with_index[right].first;
            if (sum == target) {
                result.push_back(nums_with_index[left].second);
                result.push_back(nums_with_index[right].second);
                break;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return result;
    }
};

*/
