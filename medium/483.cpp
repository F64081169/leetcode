class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.length() < p.length()) return ans; 

        vector<int> pFreq(26, 0), sFreq(26, 0); 
        
   
        for(char ch : p) {
            pFreq[ch - 'a']++;
        }

    
        for(int i = 0; i < p.length(); i++) {
            sFreq[s[i] - 'a']++;
        }

 
        if(pFreq == sFreq) ans.push_back(0);

  
        for(int i = p.length(); i < s.length(); i++) {
    
            sFreq[s[i] - 'a']++;
           
            sFreq[s[i - p.length()] - 'a']--;

            
            if(pFreq == sFreq) ans.push_back(i - p.length() + 1);
        }

        return ans;
    }
};
