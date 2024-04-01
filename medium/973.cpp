class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // min heap 
        // heapify operation O(n)
        auto cmp = [](const vector<int>& p1, const vector<int>& p2) {
            return (p1[0] * p1[0] + p1[1] * p1[1]) > (p2[0] * p2[0] + p2[1] * p2[1]);
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> min_heap(cmp); 

        for(auto& point : points){
            min_heap.push(point);
        }
        vector<vector<int>> result;
        for (int i = 0;i<k;i++) {
            result.push_back(min_heap.top());
            min_heap.pop();
        }

        return result;
    }
};
