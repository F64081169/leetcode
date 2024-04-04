class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int max_size = 0; 
        int l = 0;
        unordered_set<char> charset; 

        for (int r = 0; r < s.size(); r++) {
            while (charset.find(s[r]) != charset.end()) { 
                charset.erase(s[l]); 
                l++;
            }
            charset.insert(s[r]); 
            max_size = std::max(max_size, r - l + 1); 
        }
        return max_size;
    }
};
