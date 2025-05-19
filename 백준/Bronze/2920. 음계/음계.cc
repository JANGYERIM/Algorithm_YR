#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int main() {
    vector<int> input(8);  // 8개의 간격 비교면 9개 필요
    for (int i = 0; i < 8; i++) {
        cin >> input[i];
    }

    bool isAscending = true;
    bool isDescending = true;

    for (int i = 1; i < 8; i++) {
        if (input[i] > input[i - 1]) {
            isDescending = false;
        } else if (input[i] < input[i - 1]) {
            isAscending = false;
        }
    }

    if (isAscending) {
        cout << "ascending";
    } else if (isDescending) {
        cout << "descending";
    } else {
        cout << "mixed";
    }

    return 0;
}
