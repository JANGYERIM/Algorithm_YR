#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    int input;
    cin >> input ;
    int n=1;
    int count =1;
    while(n < input){
        n += (6*count);
        count ++;
    }
    
    cout << count << endl;
    return 0;
}

