class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        // Data structure: Priority Queue, TreeSet
        // odd number: 3 -> 6 -> 3...(乘以二以後會變偶數循環)
        // even number: 20 -> 10 -> 5 -> 10...(除到變奇數後需乘以二開始循環)
        // idea 1 : transfer all odd numbers to even numbers
        // then all number can be decreased

        // start from the maximum number, and minus the minimum number
        // When to stop? the maximun number becomes the odd number
            set<int> s;
                for (int x : nums)
                s.insert(x & 1 ? x * 2 : x);
                int ans = *rbegin(s) - *begin(s);
                while (*rbegin(s) % 2 == 0) {
                s.insert(*rbegin(s) / 2);
                s.erase(*rbegin(s));
                ans = min(ans, *rbegin(s) - *begin(s));
                }
                return ans;
            }

};
