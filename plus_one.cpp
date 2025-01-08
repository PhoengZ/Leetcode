class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int s_size = digits.size();
        digits[s_size-1] += 1;
        int plus = digits[s_size-1]/10;
        digits[s_size-1] = digits[s_size-1]%10;
        for (int i = s_size-2;i>=0;i--){
            if (plus!= 0){
                digits[i] += plus;
                plus = digits[i]/10;
                digits[i] = digits[i]%10;
            }
            else{break;}
        }
        if (plus!= 0){
            
            digits[0] = digits[0]%10;
            vector <int> vec = {plus};
            for (int i = 0;i<s_size;i++){
                vec.push_back(digits[i]);
            }
            return vec;
        }
        return digits;
    }
};