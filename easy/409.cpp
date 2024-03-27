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
/*
// faster sol
class Solution {
public:
    int longestPalindrome(string s) {
        // greedy count the frequency of each alphabet
        vector<int> freq(128);
        int result = 0,odd = 0;
        for(char c:s) freq[c]++;
        for(int i=0;i<128;i++){
            result += freq[i]&(~1);
            if(freq[i]&1)odd=1;
        } 
        return result+odd;
    }
};
*/
