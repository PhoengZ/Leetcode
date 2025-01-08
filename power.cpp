#include <iostream>

using namespace std;

double myPow(double x, int n,double base) {
    if (n == 0)return 1;
    if (n == 1)return x;
    if (n==-1)return (double)1/x;
    if (n<0){
        return myPow((1/x)*(1/base),n+1,base);
    }
    return myPow(x*base,n-1,base);
}

int main(){
    double x;
    int n;
    cin>>x >> n;
    cout << myPow(x,n,x);
    return 0;
}