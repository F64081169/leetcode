class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> m1;
        map<char,int> m2;
        for(char c:ransomNote){
            m1[c]++;
        }
        for(char c:magazine){
            m2[c]++;
        }
        for(auto& p : m1) {
            char c = p.first;
            if(m2[c] < m1[c]) {
                return false;
            }
        }
        
        return true;
    }
};
