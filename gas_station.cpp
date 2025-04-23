class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int sumCost = 0;
            int sumGas = 0;
            int cap = 0;
            int idx = 0;
            for (int i = 0;i<gas.size();i++){
                sumCost += cost[i];
                sumGas += gas[i];
                cap+= gas[i] - cost[i];
                if (cap < 0){
                    idx = i+1;
                    cap = 0;
                }
            }
            if (sumCost > sumGas)return -1;
            return idx;
        }
    };