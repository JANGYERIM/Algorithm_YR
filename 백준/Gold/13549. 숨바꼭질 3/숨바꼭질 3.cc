#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
#define endl '\n'

deque<int> Q;
int n, k;
int board[200002];

int moveFunction(int dir, int cur) {
    if (dir == 0) return cur * 2;
    else if (dir == 1) return cur + 1;
    else return cur - 1;
}

int main() {
    cin >> n >> k;
    memset(board, -1, sizeof(board));

    if (n == k) {
        cout << 0 << endl;
        return 0;
    }

    board[n] = 0;
    Q.push_front(n);

    while (!Q.empty()) {
        int cur = Q.front(); Q.pop_front();

        for (int dir = 0; dir < 3; dir++) {
            int nx = moveFunction(dir, cur);
            if (nx < 0 || nx >= 200002) continue;

            if (dir == 0 && (board[nx] == -1 || board[nx] > board[cur])) {
                board[nx] = board[cur];
                Q.push_front(nx);
            }
            else if (dir > 0 && (board[nx] == -1 || board[nx] > board[cur] + 1)) {
                board[nx] = board[cur] + 1;
                Q.push_back(nx);
            }
        }
    }

    cout << board[k] << endl;
    return 0;
}
