#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
using namespace std;

int board[500][500];
int vis[500][500];

int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0, 1, 0 , -1};

bool outOfBound(int x, int y) {
    return x<0 || x>=n || y<0|| y>=m ;
}

int main() {
    cin >> n >> m;

    memset(board,-1,sizeof(board));
    memset(vis, 0, sizeof(vis));
    string value;
    
    
    for(int i=0; i<n; i++){
            cin >> value;
            int j=0;
            for(auto c: value){
                board[i][j] = c -'0';
                j++;
            }
    }
    
    queue<pair<int,int>> Q;
    vis[0][0] = 1;
    Q.push({0,0});

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();

        for(int dir=0; dir<4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(outOfBound(nx,ny)) continue;
            if(vis[nx][ny] !=0 || board[nx][ny] !=1) continue;
            vis[nx][ny]= vis[cur.X][cur.Y] +1;
            Q.push({nx,ny});
            
        }
    }
    cout << vis[n-1][m-1] << endl;
    
    return 0;
}