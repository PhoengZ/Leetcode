#include <algorithm>
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int val = nums[0];
        vector<vector<int>> vec;
        for (int i =0;i<nums.size();i++){
            if (i > 0 && nums[i] == nums[i-1]){continue;}
            for(int j= i+1;j<nums.size();j++){
                if (j > i+1 && nums[j] == nums[j-1]){continue;}
                int left= j+1;
                int right = nums.size()-1;
                while (left < right){
                    long long int sum = (long long int)nums[i] + (long long int)nums[j] + (long long int)nums[left] + (long long int)nums[right];
                    //cout << "sum = "<<sum<<endl;
                    if (target == sum){
                        vector<int> out = {nums[i],nums[j],nums[left],nums[right]};
                        vec.push_back(out);
                        left++;
                        right--;
                        while (left < right && nums[right] == nums[right+1]){right--;}
                        while (left < right && nums[left] == nums[left-1]){left++;}
                        //cout << "ind i = "<< i << " ind j = " << j <<endl;
                        //cout << "left = "<< left << " right = " << right <<endl;
                    }
                    else if (sum>target){
                        right--;
                    }
                    else{
                        left++;   
                    }
                    
                }
            }
        }
        return vec;
    }
};