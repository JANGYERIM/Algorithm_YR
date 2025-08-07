#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
#define endl '\n'

int board[201][201];
int vis[201][201][31];

int dx[12] = {1,0,-1,0, 1,2,-1,-2,1,2,-1,-2};
int dy[12] = {0,1,0,-1, 2,1,2,1,-2,-1,-2,-1};

int w, h, k;
bool outofbound(int nx, int ny, int z){
    return nx<0||nx >= h || ny<0 || ny >=w || z > k ;
}


int main() {
    
    cin >> k >> w >> h;
    memset(board, -1, sizeof(board));
    memset(vis, -1, sizeof(vis));
    
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> board[i][j];
        }
    }

    queue<tuple<int,int,int>> Q;
    vis[0][0][0] = 0;
    Q.push({0,0,0});

    while(!Q.empty()){
        auto [x,y,z] = Q.front(); Q.pop();

        for(int dir=0; dir<12; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(dir <4){
                if(outofbound(nx,ny, z)) continue;
                if(board[nx][ny]) continue;
                if(vis[nx][ny][z] >=1) continue;
                vis[nx][ny][z] = vis[x][y][z] + 1;
                Q.push({nx,ny,z});
            }
            else{
                if(outofbound(nx,ny, z+1)) continue;
                if(board[nx][ny]) continue;
                if(vis[nx][ny][z+1] >=1) continue;
                vis[nx][ny][z+1] = vis[x][y][z] + 1;
                Q.push({nx,ny,z+1});
            }
        }
    }


    int result = INT_MAX;
    for(int i=0; i<=k; i++){  // <= k 로 변경!
        if(vis[h-1][w-1][i] != -1 && vis[h-1][w-1][i] < result){
            result = vis[h-1][w-1][i];
        }
    }


    if (result==INT_MAX){
        result = -1;
    }

    cout << result << endl;
    
    
    return 0;
}