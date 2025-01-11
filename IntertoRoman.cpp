#include <iostream>

using namespace std;
string intToRoman(int num) {
    string s = "";
    int value = num;
    int M = value/1000;
    value = value - (M*1000);
    if (M != 0){
        for (int i = 0;i<M;i++){
            s+= "M";
        }
    }
    int D = value/500;
    value -= (D*500);
    int C = value/100;
    value -= (C*100);
    if (D == 1 && C == 4){
        s+= "CM";
    }else if (D == 0 && C == 4){
        s+= "CD";
    }else{
        for (int i = 0;i<D;i++){
            s+= "D";
        }
        for (int i = 0;i<C;i++){
            s+= "C";
        }
    }
    int L = value/50;
    value -= (L*50);
    int X = value/10;
    value -= (X*10);
    if (L == 1 && X == 4){
        s+= "XC";
    }else if (L == 0 && X == 4){
        s+= "XL";
    }else{
        for (int i = 0;i<L;i++){
            s+= "L";
        }
        for (int i = 0;i<X;i++){
            s+= "X";
        }
    }
    int V = value/5;
    value -= (V*5);
    int I = value/1;
    value -= (I*1);
    if (V == 1 && I == 4){
        s+= "IX";
    }else if (V == 0 && I == 4){
        s+= "IV";
    }else{
        for (int i = 0;i<V;i++){
            s+= "V";
        }
        for (int i = 0;i<I;i++){
            s+= "I";
        }
    }
    return s;
}
int main(){
    int n;
    cin>>n;
    cout << intToRoman(n);
    return 0;
}