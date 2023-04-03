class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // Prompt: a modifies knapsack problem
        // sort the people array in increasing sequence
        sort(people.begin(),people.end());
        int numBoat = 0;
        int light = 0;
        int heavy = people.size()-1;

        // Main question: Can the heaviest person be paired with the lightest person?
        while(light<=heavy){
            if((people[light]+people[heavy]) <= limit){
                light++;
                heavy--;
            }else{
                heavy--;
            }
            numBoat++;
        }

        return numBoat;

    }
};
