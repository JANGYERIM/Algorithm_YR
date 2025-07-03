#include <bits/stdc++.h>
#define X first
#define Y second
#define endl '\n'

using namespace std;

char board[150][150];
int vis[150][150];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int m,n;

bool outOfBound(int x, int y){
    return x<0||x>=m||y<0||y>=n;
}


int main() {
    cin >> n;
    m=n;
    memset(board, 'Z', sizeof(board));
    memset(vis, -1, sizeof(vis));
    string input;
    for(int i=0; i < m; i ++){
        cin >> input;
        int j=0;
        for (auto c: input){
            board[i][j] = c;
            j++;
        }
    }
    queue<pair<int,int>> RQ;
    queue<pair<int,int>> BQ;
    queue<pair<int,int>> GQ;
    queue<pair<int,int>> R_GQ;
    int R =0; int B = 0; int G =0; int R_G =0;
    for(int i=0; i < m; i ++){
        for (int j=0; j< n; j++){
          if(vis[i][j] ==-1 && board[i][j] =='R' ){
              vis[i][j] = 1;
              RQ.push({i,j});
              R++;

              while(!RQ.empty()){
                  auto cur = RQ.front(); RQ.pop();
                  for(int dir =0 ; dir < 4; dir ++){
                      int nx = cur.X + dx[dir];
                      int ny = cur.Y + dy[dir];

                      if(outOfBound(nx,ny)) continue;
                      if(vis[nx][ny] != -1 || board[nx][ny] != 'R') continue;
                      vis[nx][ny] = 1;
                      RQ.push({nx,ny});
                      
                  }
              }
          }
            if(vis[i][j] ==-1 && board[i][j] =='G' ){
              vis[i][j] = 1;
              GQ.push({i,j});
              G++;

              while(!GQ.empty()){
                  auto cur = GQ.front(); GQ.pop();
                  for(int dir =0 ; dir < 4; dir ++){
                      int nx = cur.X + dx[dir];
                      int ny = cur.Y + dy[dir];

                      if(outOfBound(nx,ny)) continue;
                      if(vis[nx][ny] != -1 || board[nx][ny] != 'G') continue;
                      vis[nx][ny] = 1;
                      GQ.push({nx,ny});
                      
                  }
              }
          }

            if(vis[i][j] ==-1 && board[i][j] =='B' ){
              vis[i][j] = 1;
              BQ.push({i,j});
              B++;

              while(!BQ.empty()){
                  auto cur = BQ.front(); BQ.pop();
                  for(int dir =0 ; dir < 4; dir ++){
                      int nx = cur.X + dx[dir];
                      int ny = cur.Y + dy[dir];

                      if(outOfBound(nx,ny)) continue;
                      if(vis[nx][ny] != -1 || board[nx][ny] != 'B') continue;
                      vis[nx][ny] = 1;
                      BQ.push({nx,ny});
                      
                  }
              }
          }
        }
    }

    memset(vis, -1, sizeof(vis));
    for(int i=0; i < m; i ++){
        for (int j=0; j< n; j++){
            if(vis[i][j] ==-1 && (board[i][j] =='R'|| board[i][j] =='G' )){
              vis[i][j] = 1;
              R_GQ.push({i,j});
              R_G++;

              while(!R_GQ.empty()){
                  auto cur = R_GQ.front(); R_GQ.pop();
                  for(int dir =0 ; dir < 4; dir ++){
                      int nx = cur.X + dx[dir];
                      int ny = cur.Y + dy[dir];

                      if(outOfBound(nx,ny)) continue;
                      if(vis[nx][ny] != -1 || board[nx][ny] == 'B') continue;
                      vis[nx][ny] = 1;
                      R_GQ.push({nx,ny});
                      
                  }
              }
          }
        }
    }
    
    cout << R+G+B << ' ' << R_G + B << endl;

    
    
    return 0;
}