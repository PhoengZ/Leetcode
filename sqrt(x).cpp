#define ll long long
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0){return 0;}
        ll int left =0;
        ll int right = x;
        while ((right - left) != 1){
            ll int mid = left + (right - left)/2;
            if (mid*mid == x){return mid;}
            else if (mid*mid > x){
                right  = mid;
            }else{
                left = mid;
            }
        }
        if (right * right <= x){
            return right;
        }
        return left;
    }
};