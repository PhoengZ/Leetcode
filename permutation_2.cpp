class Solution {
    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(),candidates.end());
            vector<vector<int>>v;
            vector<int> now;
            f(v,candidates,now,target,0,0);
            return v;
        }
        void f(vector<vector<int>>&v, vector<int>&can, vector<int>&now,int target, int n, int idx){
            if (n == target){
                v.push_back(now);
                return;
            }
            if (n > target)return;
            for (int i = idx;i<can.size();i++){
                if (i>idx && can[i] == can[i-1])continue;
                now.push_back(can[i]);
                f(v,can,now,target,n+can[i],i+1);
                now.pop_back();
            }
        }
    };