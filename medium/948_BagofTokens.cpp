class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        //當有score 拿最高power
        //當有power 買最低token
        int score = 0;

        sort(tokens.begin(), tokens.end());

        while (!tokens.empty()) {
            if (power < tokens[0]) {
                if (score <= 0) break;
                if (tokens.size()==1) break;
                power += tokens.back();
                tokens.pop_back();
                score--;
            } else {
                power -= tokens[0];
                tokens.erase(tokens.begin());
                score++;
            }
        }
        return score;
    }
};
