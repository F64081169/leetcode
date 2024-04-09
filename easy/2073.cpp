class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
       int times = 0;
       while (1)
            for (int i = 0; i != tickets.size(); ++i)
                if (tickets[i]) {
                    ++times;
                    --tickets[i];
                    if (i == k && !tickets[k])
                        return times;
                }
        return -1; 
    }
};
