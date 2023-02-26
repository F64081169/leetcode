class Solution {
public:
    int sum(int num1, int num2) {
        int low=-201, high = 201;
        while(low<high){
            int mid = (low+high)>>1;
            if(mid == num1+num2) return mid;
            else if(num1+num2 > mid) low = mid+1;
            else high = mid-1;
        }
        return low;
    }
};

// Use Binary search 
// also can use return num1 + num2;
