class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> m;

        for(int i = 0;i<arr.size();i++){
            bool find = false;
            for(auto it = m.begin(); it != m.end(); it++)
                if(it->second == arr[i]) find = true;
            if(!find){
                int cnt = 0;
                for(int j = i;j<arr.size();j++)
                    if(arr[i]==arr[j]) cnt++;
                if(m.find(cnt) == m.end())
                    m.insert({cnt,arr[i]});
                else return false;
            }
        }
        return true;
    }
};
