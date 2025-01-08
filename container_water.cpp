#include <algorithm>
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right= height.size()-1;
        int Area = 0;
        while (left < right){
            int current_area = min(height[right],height[left])*(right-left);
            Area = max(current_area,Area);
            if (height[right] >= height[left]){
                left++;
            }
            else{
                right--;
            }
        }
        return Area;
    }
    
};