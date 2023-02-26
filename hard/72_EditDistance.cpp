// Recursion
class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        d_ = vector<vector<int>>(l1 + 1, vector<int>(l2 + 1, -1));
        return minDistance(word1, word2, l1, l2);
    }
private:
    vector<vector<int>> d_;
    // minDistance from word1[0:l1-1] to word2[0:l2-1]
    int minDistance(const string& word1, const string& word2, int l1, int l2) {
        if (l1 == 0) return l2;
        if (l2 == 0) return l1;
        if (d_[l1][l2] >= 0) return d_[l1][l2];
        
        int ans;
        if (word1[l1 - 1] == word2[l2 - 1])
            ans = minDistance(word1, word2, l1 - 1, l2 - 1);
        else 
            ans = min(minDistance(word1, word2, l1 - 1, l2 - 1),
                  min(minDistance(word1, word2, l1 - 1, l2), 
                      minDistance(word1, word2, l1, l2 - 1))) + 1;
        
        return d_[l1][l2] = ans;        
    }
};

