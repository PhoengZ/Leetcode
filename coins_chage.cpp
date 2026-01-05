class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int>sol(amount+1,100000);
        sol[0] = 0;
        for (int i = 1;i<=amount;i++){
            for(auto&e:coins){
                if ((i - e) >= 0){
                    sol[i] = min(sol[i],sol[i-e] +1);
                }
            } 
        }
        return sol[amount] == 100000?-1:sol[amount];
    }
};