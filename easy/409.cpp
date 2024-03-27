class Solution {
public:
    int longestPalindrome(string s) {
        // greedy count the frequency of each alphabet
        map<char,int> m;
        int result = 0;
        for(char c:s){
            m[c]++;
            if(m[c]==2){
                result+=2;
                m.erase(c);
            }
        }
        return (!m.empty())? result+1:result;
    }
};
