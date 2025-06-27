#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
using namespace std;

int board[1500][1500];
bool vis[1500][1500];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int m, n, k;

bool OutOfBounds(int x, int y){
    return x < 0 || x >= m || y < 0 || y >= n;
}

int main() {
    int input;
    cin >> input;

    for(int i=0; i<input; i++){
        memset(board,-1,sizeof(board));
        memset(vis, 0, sizeof(vis));
        queue<pair<int,int>> Q;
        
        cin >> m >> n>> k ;

        for(int j=0; j<k; j++){
            int col, row;
            cin >> col >> row;
            board[col][row] = 1;
            
        }
        
        int count = 0;
        for(int j=0; j< m ; j++){
            for(int t=0; t<n; t++){
                if(board[j][t] == 1 && vis[j][t] ==0){
                    vis[j][t] = 1;
                    Q.push({j,t});
                    count ++; 

                while(!Q.empty()){
                    pair<int,int> cur = Q.front(); Q.pop();
                    
                    for(int dir = 0; dir <4; dir ++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(OutOfBounds(nx, ny)) continue;
                        if(vis[nx][ny] ==1 || board[nx][ny] != 1) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
                
                }
            }
        }

        cout << count << endl;

    }
    
    return 0;
}