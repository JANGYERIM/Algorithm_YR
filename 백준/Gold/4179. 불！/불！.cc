#include <bits/stdc++.h>
#define X first
#define Y second
#define endl '\n'

using namespace std;

char board[1100][1100];
int vis[1100][1100];
int escape[1100][1100];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int r,c;

bool outOfBound(int x, int y){
    return x<0||x>=r||y<0||y>=c;
}

int main() {
    cin >> r>>c;
    memset(board, -1, sizeof(board));
    memset(vis, -1, sizeof(vis));
    memset(escape, -1, sizeof(escape));
    char input;
    queue<pair<int,int>> FQ;
    queue<pair<int,int>> JQ;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >>input;
            board[i][j] = input;
            if(input == 'F'){
                vis[i][j] = 0;
                FQ.push({i,j});
            }
            if(input == 'J'){
                if(i == r-1 || j == c-1|| i== 0 || j ==0){
                    cout << 1<< endl;
                    return 0;
                }
                escape[i][j] =0;
                JQ.push({i,j});
            }
        }
    }

    while(!FQ.empty()){
        auto cur = FQ.front(); FQ.pop();

        for(int dir=0; dir<4; dir ++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(outOfBound(nx,ny)) continue;
            if(vis[nx][ny] != -1 || board[nx][ny] == '#') continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            FQ.push({nx,ny});
        }
    }

    int escapeTime = 0;
    while(!JQ.empty()){
        auto cur = JQ.front(); JQ.pop();

        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(outOfBound(nx,ny)) continue;
            if(escape[nx][ny] != -1 || board[nx][ny] == '#') continue;
            escape[nx][ny] = escape[cur.X][cur.Y] + 1;
            if(escape[nx][ny] < vis[nx][ny]|| vis[nx][ny] == -1){
                if(nx == r-1 || ny == c-1|| nx ==0 || ny == 0){
                    escapeTime = escape[nx][ny];
                    cout << escapeTime+1 << endl;
                    return 0;
                }
                JQ.push({nx,ny});
            }
            
        }
    }
    cout << "IMPOSSIBLE" << endl;
    
    
    return 0;
}