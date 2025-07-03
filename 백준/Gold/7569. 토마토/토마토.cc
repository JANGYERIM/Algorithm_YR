#include <bits/stdc++.h>
#define X first
#define Y second
#define endl '\n'

using namespace std;

int board[110][110][110];
int vis[110][110][110];

int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int m,n,h;

bool outOfBound(int x, int y, int z){
    return x<0||x>=m||y<0||y>=n|| z<0||z>=h;
}

int main() {
    cin >> n>>m>>h;
    memset(board, -1, sizeof(board));
    memset(vis, -1, sizeof(vis));
    int input;
    queue<tuple<int,int,int>> Q;
    for(int z=0; z<h; z++){
        for(int i=0; i < m; i ++){
            for(int j=0; j< n; j++){
                cin >> input;
                board[i][j][z] = input;
                if(vis[i][j][z] == -1 && board[i][j][z] ==1){
                    vis[i][j][z] = 0;
                    Q.push({i,j,z});
                }
            }
        }
    }
    

    while(!Q.empty()){
        auto [x,y,z] = Q.front(); Q.pop();
    
        for(int dir=0; dir<6; dir ++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];
    
            if(outOfBound(nx,ny,nz)) continue;
            if(vis[nx][ny][nz] != -1 || board[nx][ny][nz] != 0) continue;
            vis[nx][ny][nz] = vis[x][y][z] + 1;
            Q.push({nx,ny,nz});
            
        }
    }

    int area=0;
    for(int z=0; z<h; z++){
        for(int i=0; i< m; i ++){
            for(int j=0; j< n; j ++){
                if(board[i][j][z] == 0 && vis[i][j][z] == -1){
                    cout << -1 << endl;
                    return 0;
                }
                if(area < vis[i][j][z]){
                    area = vis[i][j][z];
                }          
            }
        }
    }
    cout << area << endl;
    
    
    return 0;
}