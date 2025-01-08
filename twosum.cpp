class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;
        unsigned int size = nums.size();
        for (unsigned int i = 0;i<nums.size();i++){
            for (unsigned int j =0;j<nums.size();j++){
                if (i!=j){
                    int answer = (nums[i]+nums[j]);
                    if (answer == target){
                        output.push_back(i);
                        output.push_back(j);
                        return output;
                    }
                }
                
            }
        }
        return output;
    }
};