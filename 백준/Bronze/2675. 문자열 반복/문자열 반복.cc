#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


int main() {

    int n, tryCount;
    string input ;
    string result ;

    cin >> n;

    for(int i=0; i<n; i++){
        cin >> tryCount >> input;
        for (char i : input){
            for (int j = 0; j < tryCount; j ++){
                result += i;
            }
        }
        cout << result << endl ;
        result = "";
    }
    return 0;
}