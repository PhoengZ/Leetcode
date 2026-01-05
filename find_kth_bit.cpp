class Solution {
public:
    char findKthBit(int n, int k) {
        int total = 1;
        int pow = 2;
        for (int i = 1;i<n;i++){
            total += pow;
            pow*=2;
        }
        char result = loop(k, false, total);
        return result;
    }
    char loop(int k, bool flip, int len){
        if (len == 1){
            return flip ? '1':'0';
        }
        int split = len/2;
        if (k == split + 1){
            return flip ? '0':'1';
        }
        if (k > split + 1){
            return loop(len + 1 - k, !flip, len/2);
        }
        return loop(k, flip, len/2);
    }
};
//                 4, true       12, false
// |0| |0 1 1| |011 1 001| |0111001 1 0110001|
// 1       3        7              15 
//     2         4          8