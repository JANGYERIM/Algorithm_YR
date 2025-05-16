#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int h, w, n;
        cin >> h >> w >> n;

        int floor = n % h;
        int room = n / h + 1;

        if (floor == 0) {
            floor = h;
            room = n / h;
        }

        cout << floor * 100 + room << '\n';
    }

    return 0;
}
