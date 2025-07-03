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

void bfs(int i, int j) {

    vis[i][j] = 1;
    queue<pair<int,int>> Q;

    Q.push({i,j});

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        
        for(int dir=0; dir < 4; dir ++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(outOfBound(nx,ny)) continue;
            if(vis[nx][ny] != -1 || board[i][j] != board[nx][ny]) continue;
            vis[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }
    
}

int area(){
    int cnt = 0;
    for(int i =0; i < n; i ++){
        for(int j=0; j< n; j ++){
            if(vis[i][j] ==-1){
                cnt ++;
                bfs(i,j);
            }
        }
    }
    return cnt;
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

    int rgb_cnt = area();


    memset(vis, -1, sizeof(vis));
    for(int i=0; i < m; i ++){
        for (int j=0; j< n; j++){
            if(board[i][j] =='G' ){
              board[i][j] = 'R';
                                    
                  }
              }
          }
    int rb_cnt = area();
    
    cout << rgb_cnt << ' ' << rb_cnt << endl;
    return 0;
}