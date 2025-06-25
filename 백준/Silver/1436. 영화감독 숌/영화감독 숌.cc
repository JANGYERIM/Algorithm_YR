#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

bool sixcount(int num) {
    int i = 0;
    while (num > 0) {
        if (num % 10 == 6) {
            i++;
            if (i == 3) {
                return true;
            }
        } else {
            i = 0;
        }
        num /= 10;
    }
    return false;
}

int main() {
    int input;
    cin >> input ;

    int count = 0;
    int result = 0;
    int sum = 0;
    while (count < input){
        result += 1;
        sum = result;
        if (sixcount(sum)){
            count ++;
        }
    }

    cout << result << endl;
    
    return 0;
}