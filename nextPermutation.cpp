#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void nextPermutation(vector<int>& nums) {        
    
}
void generatePermutations(std::vector<int>& nums, int start, int end) {
    if (start == end) {
        for (int num : nums) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    } else {
        for (int i = start; i <= end; i++) {
            std::swap(nums[start], nums[i]); // Swap current element with start
            generatePermutations(nums, start + 1, end);
            std::swap(nums[start], nums[i]); // Backtrack
        }
    }
}
int main(){
    vector<int> vt = {1,2,3};
    generatePermutations(vt,0,vt.size()-1);
    return 0;
}