#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


int main() {

    int a,b,c;
    int mul ;
    vector<int> result(10) ;

    cin >> a >> b >> c;

    mul = a*b*c;
    
    string s_mul = to_string(mul);

    for(auto i : s_mul){
        result[i-'0'] ++;
    }

    for(int i = 0; i < 10; ++i){
        cout << result[i] <<endl;
    }
    
    return 0;
}