class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size(),score=0;
        sort(tokens.begin(),tokens.end());
        int i=0,j=n-1;
        while(i<j){
            if(power>=tokens[i]){
                power-=tokens[i++];
                score++;
            }
            else if(score>=1 && power+tokens[j]>=tokens[i]){
                power+=tokens[j--];
                score--;
            }
            else{
                break;
            }
        }
        while(i<j+1 && power>=tokens[i]){
            power-=tokens[i++];
            score++;
        }
        return score;
    }
};