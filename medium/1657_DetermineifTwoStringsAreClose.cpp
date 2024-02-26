class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int hash1[26]={0};
        int hash2[26]={0};
        if(word1.size()!=word2.size())return false;
        for(int i=0;i<word1.size();i++){
            hash1[word1[i]-97]++;
        }
        for(int i=0;i<word2.size();i++){
            hash2[word2[i]-97]++;
        }
        int total1=0;
        int total2=0;
        for(int i=0;i<26;i++){
            if(hash1[i]==0&&hash2[i]!=0||hash1[i]!=0&&hash2[i]==0)return false;
        }
        sort(hash1,hash1+26);
        sort(hash2,hash2+26);
        for(int i=0;i<26;i++){
            if(hash1[i]!=hash2[i])return false;
        }
        return true;
    }
};
