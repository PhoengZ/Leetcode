#include <queue>
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        queue <int> get_val;
        vector <int> num;
        for (int & e:nums){
            if (e != val){
                get_val.push(e);
            }
        }
        while (!get_val.empty()){
            num.push_back(get_val.front());
            get_val.pop();
        }
        nums = num;
        return num.size();
    }
};