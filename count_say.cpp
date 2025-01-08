#include <iostream>
#include <string>

using namespace std;

int main(){
    string cas = "1";
    int n;
    cin>>n;
    for (int i = 1;i<n;i++){
        string N = "";
        char old = cas[0];
        int cou = 1;
        for (int j = 1;j<=cas.length();j++){
            if (cas[j] != old){
                N+= to_string(cou);
                N+= old;
                cou = 1;
                old = cas[j];
            }else{
                cou++;
            }
        }
        cas = N;
    }
    cout << cas;
    return 0;
}
