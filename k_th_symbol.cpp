class Solution {
public:
    int kthGrammar(int n, int k) {
        int power = 1;
        for (int i = 1;i<n;i++){
            power*=2;
        }        
        int result =  loop(k,false, power);
        return result;
    }
    int loop (int k, bool flip, int len){
        if (len == 1){
            return flip ? 1:0;
        }
        if (k > len/2){
            return loop(k-(len/2),!flip, len/2);
        }
        return loop(k,flip,len/2);
    }
};
//  
// 0 01 0110 0110/1001 01101001/10010110
// 1 2   4      8              16