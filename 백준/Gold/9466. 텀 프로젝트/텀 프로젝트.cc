#include <bits/stdc++.h>
#define X first
#define Y second
#define endl '\n'
using namespace std;

int board[100001];
int state[100001];
const int NOT_VISITED = 0;
const int CYCLE_IN = -1;

void run(int x){
    int cur = x;
    while(true) {
        state[cur] = x;
        cur = board[cur];
        //이번 방문에서 지나간 학생에 도달했을 경우
        if(state[cur] == x){
            while(state[cur]!=CYCLE_IN){
                state[cur] = CYCLE_IN;
                cur = board[cur];
            }
            return;
        }
        //이전 방문에서 지나간 학생에 도달했을 경우
        else if(state[cur] != 0) return;
    }
}

int main() {

    int t,n;
    cin >> t;
    for(int i=0; i<t; i++){
        memset(board,-1,sizeof(board));
        memset(state, 0, sizeof(state));
        cin >> n;
        for(int j=1; j<=n; j++){
            cin >> board[j] ;
        }
        for(int j=1; j<=n; j++){
            if(state[j] == NOT_VISITED) run(j);
        }
        int cnt =0;
        for(int j=1; j<=n; j++){
            if(state[j] != CYCLE_IN) cnt++;
        }
        cout << cnt << endl;
    }
    
    return 0;
}