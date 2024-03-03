class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size()-1;
        
        queue<int>rad, dir;

        for(int i = 0;i<senate.size();i++){
            if(senate[i]=='R') rad.push(i);
            else dir.push(i);
        }

        while(!rad.empty() && !dir.empty()){
            n++;
            if(rad.front() < dir.front()){
                rad.pop();
                dir.pop();
                rad.push(n);
            }else{
                rad.pop();
                dir.pop();
                dir.push(n);
            }
        }

        return (rad.empty()) ? ("Dire") : ("Radiant");
    }
};
