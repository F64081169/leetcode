class Solution {
public:
    string frequencySort(string s) {
        /*
        Solution 1:
            Using a map to store frequency
            and print out the keys by decreesing values order
        */
        string ans = "";
        unordered_map <char,int> char_freq;
        for(char c : s){
            char_freq[c]++;
        }
        // Order the answer by frequency
        vector<pair<char, int>> freq_vec(char_freq.begin(), char_freq.end());
        sort(freq_vec.begin(), freq_vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second; 
        });
        for (auto it = freq_vec.begin(); it != freq_vec.end(); it++) {
            // it->second copies of it->first
            ans += string(it->second, it->first);
        }      
        return ans;
    }
};
