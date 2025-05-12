#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    cin >> a ;
    for (int i = 1; i <= a ; i ++){
        cout << "*";
        for (int j = 1; j <i ; j ++){
            cout << "*";
        }
        cout << endl;
    }
}