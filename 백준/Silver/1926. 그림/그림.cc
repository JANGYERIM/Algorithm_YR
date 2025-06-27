#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
using namespace std;

int board[1000][1000];
bool vis[1000][1000];
int n, m;

int dx[4] = {1,0,-1,0};
int dy[4] = {0, -1, 0, 1};

bool isBound(int x, int y) {
    return x <0 || x>=n || y <0 || y>=m ;
}

int main() {

    memset(board, -1, sizeof(board));
    memset(vis, 0, sizeof(vis));
    
    cin >> n >> m;
    int input;
    for (int i = 0; i <n ; i++){
        for (int j=0; j <m ; j++){
            cin >> input;
            board[i][j] = input;
        }
    }

    queue<pair<int,int>> Q;
    int count = 0;
    int extent = 0;
    int max = 0;
    for (int i = 0; i <n ; i++){
        for (int j=0; j <m ; j++){
            if(board[i][j] == 1 && vis[i][j] ==0){
                vis[i][j] = 1;
                Q.push({i,j});
                extent =0;
                count ++;
                
            }

            while(!Q.empty()){
                pair<int,int> cur = Q.front(); Q.pop();
                extent ++;

                for(int dir =0; dir < 4; dir ++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(isBound(nx,ny)) continue;
                    if(vis[nx][ny] ==1 || board[nx][ny] != 1) continue;
                    vis[nx][ny] =1;
                    Q.push({nx,ny});
                }
            }

            if(max < extent){
                max = extent;
            }
        
        }
        
    }

    cout << count << endl << max << endl;
    

    
    return 0;
}