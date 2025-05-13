#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    int n, x;
    cin >> n >> x ;
    
    vector<int> A(n);
    for (int i= 0 ; i < n; i++){
        cin >> A[i] ;
    }

    for (int i = 0 ; i < n; i ++){
        if (A[i] < x) {
            cout << A[i] << ' ' ;
        }
    }
    return 0;

}