class Solution {
public:
    bool isAnagram(string s, string t) {
        // sorted order and check if same?
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
        // hashmap solution
        // map<char, int> smap, tmap;
        // for (char ch : s) {
        //     smap[ch]++;
        // }
        // for (char ch : t) {
        //     tmap[ch]++;
        // }
        // if (smap.size() != tmap.size()) {
        //     return false;
        // }
        // for (const auto& pair : smap) {
        //     if (tmap.find(pair.first) == tmap.end() || tmap[pair.first] != pair.second) {
        //         return false;
        //     }
        // }
        // return true;
    }
};
