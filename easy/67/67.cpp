class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int carry = 0;
        reverse(a.begin(), a.end()); 
        reverse(b.begin(), b.end()); 
        int adigit,bdigit;
        for(int i = 0;i<max(a.size(),b.size());i++){
            if(i<a.size()){
                adigit = a[i]-'0';
            }else{
                adigit = 0;
            }
            if(i<b.size()){
                bdigit = b[i]-'0';
            }else{
                bdigit = 0;
            }
            int total =adigit+bdigit+carry;
            
            char c = char(total % 2+'0');
            res = c + res;
            carry = total / 2;
        }
        if(carry) res = char(carry+'0') + res;
        return res;
    }
};
