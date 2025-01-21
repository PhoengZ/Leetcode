class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>sol;
        vector<bool>used(nums.size());
        my_recur(v,sol,nums,0,nums.size(),used);
        return v;
    }
    void my_recur(vector<vector<int>>&v, vector<int>&sol, vector<int>&c,int len, int target,vector<bool>&used){
        if (len < target){
            for (int i =0;i<c.size();i++){
                if (!used[i]){
                    sol.push_back(c[i]);
                    used[i] = true;
                    my_recur(v,sol,c,len+1,target,used);
                    sol.pop_back();
                    used[i] = false;
                }
                
            }
        }else v.push_back(sol);
        
    }
};