#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, T, P;
    vector<int> size(6);
    int t_order = 0;

    cin >> N;
    for (int i = 0; i < 6; i++) {
        cin >> size[i];
    }
    cin >> T >> P;

    for (int s : size) {
        t_order += (s + T - 1) / T;
    }

    cout << t_order << '\n';
    cout << N / P << " " << N % P << '\n';

    return 0;
}
