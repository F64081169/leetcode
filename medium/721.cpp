class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToIndex;
        unordered_map<string, string> emailToName;
        int n = accounts.size();
        vector<int> parent(n);
        
        // Initialize the union-find structure
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        // Helper function to find the root of a component
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // Path compression
            }
            return parent[x];
        };
        
        // Helper function to union two components
        auto unionSets = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                parent[rootX] = rootY; // Union
            }
        };
        
        // Map emails to account index and name
        for (int i = 0; i < n; ++i) {
            string& name = accounts[i][0];
            for (int j = 1; j < accounts[i].size(); ++j) {
                string& email = accounts[i][j];
                emailToName[email] = name;
                if (emailToIndex.find(email) == emailToIndex.end()) {
                    emailToIndex[email] = i;
                } else {
                    unionSets(i, emailToIndex[email]);
                }
            }
        }
        
        // Group emails by root index
        unordered_map<int, vector<string>> indexToEmails;
        for (const auto& entry : emailToIndex) {
            string email = entry.first;
            int rootIndex = find(entry.second);
            indexToEmails[rootIndex].push_back(email);
        }
        
        // Prepare the result
        vector<vector<string>> mergedAccounts;
        for (const auto& entry : indexToEmails) {
            int index = entry.first;
            vector<string> emails = entry.second;
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), emailToName[emails[0]]);
            mergedAccounts.push_back(emails);
        }
        
        return mergedAccounts;
    }
};
