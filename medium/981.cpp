class TimeMap {
public:
    unordered_map<string, map<int, string>> timeMap;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (timeMap.find(key) == timeMap.end()) {
            return "";
        }
        
        auto it = timeMap[key].upper_bound(timestamp);
        if (it == timeMap[key].begin()) {
            return "";  
        }
        
        --it;
        return it->second;
    }
};
