class Solution {
    public:
        int maxSubArray(vector<int>& nums) {
            int cur,ans;
            cur = ans = nums[0];
            for (int i = 1;i<nums.size();i++){
                cur = max(cur+nums[i],nums[i]);
                ans = max(ans,cur);
            }
            return ans;
        }
    };