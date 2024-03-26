// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // binary search?
        // minimal API calls
        long l = 1,r = n;
        long result = n;
        while(l<=r){
            int mid = (l+r)/2;
            if(!isBadVersion(mid)){
                l = mid+1;
            }else{
                result = mid;
                r = mid-1;
            }
        }
        return result;
    }
};
