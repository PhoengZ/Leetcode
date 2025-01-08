#include <algorithm>
#include <cmath>
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int val = nums[0] + nums[1] + nums[2]; 
    
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
        
            int left = i + 1;
            int right = nums.size() - 1;
        
            while (left < right) {
                int value = nums[i] + nums[left] + nums[right];
                int check_1 = abs(value - target);
                int check_2 = abs(val - target);
            
                if (value == target) {
                    return target;
                } else if (value > target) {
                    right--;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                } else {
                    left++;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                }
            
                if (check_2 > check_1) {
                    val = value;
                }
            
            
                
            
                
            }
        }
    
        return val;
        
    }
};