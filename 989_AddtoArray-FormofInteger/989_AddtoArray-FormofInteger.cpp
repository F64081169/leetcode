class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
       vector<int> n = {};
       bool f = 0;
       for(int i = num.size()-1;i>-1;i--){
           int x = (k%10)+num.at(i);
           if(x>9){
               if(!f){
                f = 1;
                n.push_back(x-10);
               }else{
                   f = 1;
                   n.push_back(x-10+1);
               }
           }
           else{
               if(!f){
                n.push_back(x);
               }else{
                   if(x+1>9)
                       { f = 1;
                         x-=10;
                       }
                    else 
                       f = 0;
                   n.push_back(x+1);
               }
           }
           k/=10;
           
       }
       if(k>0){
           if(f){
             if(k%10+1>9)
                 {f = 1;n.push_back(1+k%10-10);}
             else {f = 0;n.push_back(1+k%10);}   
             
             k/=10;
               
             while(k>0){
                 if(f){
                     if(k%10+1>9)
                 {f = 1;n.push_back(1+k%10-10);}
                    else {f = 0;n.push_back(1+k%10);}   
             
                        k/=10;
                 }else{
                 n.push_back(k%10);
                 k/=10;
                 }
             }
           }
           else{
               while(k>0){
                 n.push_back(k%10);
                 k/=10;
             }
           }
       }
       if(f){
           n.push_back(1);
       }
       reverse(n.begin(), n.end());
       return n; 
    }
};