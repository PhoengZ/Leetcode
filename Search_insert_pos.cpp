class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left =0;
        int right = nums.size();
        int pos;
        while (left < right){
            if((right-left) == 1){
                break;
            } 
            int mid = left + (right - left) / 2;
            if (nums[mid] < target){
                left = mid;
            }
            else if (nums[mid] > target){
                right = mid;
            }
            else{return mid;}
        }
        if (nums[left] >target){pos = left;}
        else if (target == nums[left]){pos = left;}
        else{pos=right;}
        
        
        
        return pos;
    }
};