class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int len; 
        if(word1.length() >= word2.length()) len = word2.length();
        else len = word1.length();

        for(int i = 0;i<len;i++){
            ans.push_back(word1[i]);
            ans.push_back(word2[i]);
        }

        for(auto it = word1.begin() + len;it!=word1.end();++it){
            ans.push_back(*it);
        }

        for(auto it = word2.begin() + len;it!=word2.end();++it){
            ans.push_back(*it);
        }

        return ans;
    }
};
