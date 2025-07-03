#include <bits/stdc++.h>
#define X first
#define Y second
#define endl '\n'

using namespace std;

int board[1100][1100];
int vis[1100][1100];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int m,n;

bool outOfBound(int x, int y){
    return x<0||x>=m||y<0||y>=n;
}

int main() {
    cin >> n>>m;
    memset(board, -1, sizeof(board));
    memset(vis, -1, sizeof(vis));
    int input;
    for(int i=0; i < m; i ++){
        for(int j=0; j< n; j++){
            cin >> input;
            board[i][j] = input;
        }
    }
    queue<pair<int,int>> Q;

    for(int i=0; i < m; i ++){
        for(int j=0; j< n; j++){
            if(vis[i][j] == -1 && board[i][j] == 1){
                vis[i][j] = 0;
                Q.push({i,j});

                    }
                }
            }
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
    
        for(int dir=0; dir<4; dir ++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
    
            if(outOfBound(nx,ny)) continue;
            if(vis[nx][ny] != -1 || board[nx][ny] != 0) continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
            
        }
    }

    int area=0;
    for(int i=0; i< m; i ++){
        for(int j=0; j< n; j ++){
            if(board[i][j] == 0 && vis[i][j] == -1){
                cout << -1 << endl;
                return 0;
            }
            if(area < vis[i][j]){
                area = vis[i][j];
            }          
        }
    }
    cout << area << endl;
    
    
    return 0;
}