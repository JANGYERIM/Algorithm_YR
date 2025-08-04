#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
#define endl '\n'

int n, k;
int board[200002];
deque<int> Q;

int main() {
    cin >> n >> k;
    memset(board, -1, sizeof(board));
    board[n] = 0;
    Q.push_front(n);

    while (!Q.empty()) {
        int cur = Q.front(); Q.pop_front();

        for (int dir = 0; dir < 3; dir++) {
            int nx;
            int cost;
            if (dir == 0) {
                nx = cur * 2;
                cost = 0;
            } else if (dir == 1) {
                nx = cur + 1;
                cost = 1;
            } else {
                nx = cur - 1;
                cost = 1;
            }

            if (nx < 0 || nx >= 200002) continue;

            if (board[nx] == -1 || board[nx] > board[cur] + cost) {
                board[nx] = board[cur] + cost;
                if (cost == 0) Q.push_front(nx);
                else Q.push_back(nx);
            }
        }
    }

    cout << board[k] << endl;
    return 0;
}
