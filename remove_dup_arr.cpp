#include <queue>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        queue <int> num;
        vector <int> test; 
        int dup;
        
        for (int i = 0;i<nums.size();i++){
            if (dup != nums[i]){
                dup = nums[i];
                num.push(nums[i]);
            }
        }
        while (!num.empty()){
            test.push_back(num.front());
            num.pop();
        }
        nums = test;
        return nums.size();
    }
};