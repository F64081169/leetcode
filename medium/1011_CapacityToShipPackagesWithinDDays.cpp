class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // Binary search
        int left = *max_element(weights.begin(), weights.end()); //left
        int right = accumulate(weights.begin(), weights.end(), 0); //right
        int mid = 0, total = 0, require_days = 0;

        while(left<=right){
            mid = (left+right)/2;
            total = 0;
            require_days = 0;
            for(int i = 0;i<weights.size();i++){
                total += weights[i];
                if(total>mid){
                    total = weights[i];
                    require_days++;
                }
            }
            require_days++;
            if(require_days<=days){ // find bigger
                right = mid - 1;
            }else{
                left = mid + 1; // find smaller
            }
        }
        return left;
    }
};

