class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> get_form;
        int num = 0;
        if (m != 0 && nums1.size()!= 0){
            get_form.push_back(nums1[0]);
            num+=1;
            for (int i = 1;i<nums1.size();i++){
                if (num == m){break;}
                get_form.push_back(nums1[i]);
                num+=1; 
            }
        }
        num = 0;
        if (n!= 0 && nums2.size()!= 0){
            get_form.push_back(nums2[0]);
            num+=1;
            for (int i = 1;i<nums2.size();i++){
                if (num ==n){break;}
                get_form.push_back(nums2[i]);
                num+=1;   
            }
        }
        nums1 = get_form;
        sort(nums1.begin(),nums1.end());
    }
};