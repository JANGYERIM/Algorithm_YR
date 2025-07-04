#include <bits/stdc++.h>
#define X first
#define Y second
#define endl '\n'
using namespace std;

int l, r, c ;
int vis[50][50][50];
char board[50][50][50];

int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,-1,0,1,0,0};
int dz[6] = {0,0,0,0,1,-1};

bool outOfBound(int x, int y, int z) {
    return x<0|| x>=r || y<0 || y>=c|| z<0 || z>=l ;
}

int main() {
    while(true){
        cin >> l >> r >> c;
        if(l==0 && r==0 && c==0){
            break;
        }
        memset(vis, -1, sizeof(vis));
        memset(board, 'Z', sizeof(board));
        bool isescape = false;
        char input ;
        queue<tuple<int,int,int>> Q;
        for(int i = 0; i<l ; i++){
            for(int j=0; j<r ; j++){
                for (int k=0; k<c ; k++){
                    cin >> input;
                    board[j][k][i] = input;

                    if(input == 'S'){
                        vis[j][k][i] = 0;
                        Q.push({j,k,i});
                    }
                }
            }
        }

        while(!Q.empty() && !isescape){
            auto [x, y, z] = Q.front(); Q.pop();

            for(int dir=0; dir<6; dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                int nz = z + dz[dir];

                if(outOfBound(nx,ny,nz)) continue;
                if(vis[nx][ny][nz] != -1 || board[nx][ny][nz] == '#') continue;
                vis[nx][ny][nz] = vis[x][y][z] + 1;
                if(board[nx][ny][nz] == 'E'){
                    cout << "Escaped in "<<vis[nx][ny][nz] <<" minute(s)." <<endl;
                    isescape = true;
                    break;
                }
                Q.push({nx,ny,nz});
            }
        }

        if(!isescape){
            cout << "Trapped!" << endl;
        }
    
        
    }
    return 0;
}