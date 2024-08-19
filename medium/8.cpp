class Solution {
public:
    int myAtoi(string s) {
        if (s.length() == 0) return 0;
        int index = 0;
        while (index < s.length() && s[index] == ' ') {
            index++;
        }
        if (s.length() == 0) return 0;
        
        int sign = 1;
        if(s[index] == '-' ||s[index] == '+'){
            sign = s[index] == '-' ? -1 : 1;
            index++;
        }

        int res = 0;
        while(index<s.length()){
            int digit = s[index] - '0';
            if(digit<0||digit>9) break;
            if (res > (INT_MAX-digit)/10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            res = res * 10 + digit;
            index++;
        }
        return res*sign;
    }
};
