#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    int count;
    cin >> count;
    stack<int> result;

    for (int i = 0; i < count; ++i) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int number;
            cin >> number;
            result.push(number);
        }
        else if (cmd == "pop") {
            if (result.empty()) cout << -1 << endl;
            else {
                cout << result.top() << endl;
                result.pop();
            }
        }
        else if (cmd == "top") {
            if (result.empty()) cout << -1 << endl;
            else cout << result.top() << endl;
        }
        else if (cmd == "empty") {
            cout << result.empty() << endl;  // true -> 1, false -> 0
        }
        else if (cmd == "size") {
            cout << result.size() << endl;
        }
    }

    return 0;
}
