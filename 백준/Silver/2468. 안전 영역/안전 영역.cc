#include <bits/stdc++.h>
#define X first
#define Y second
#define endl '\n'
using namespace std;

int board[200][200];
int vis[200][200];
int n,m;

bool outOfBound(int x, int y){
    return x<0 || x>=m || y<0|| y>=n ;
}

int dx[4] = { 1,0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
    cin >> n;
    m= n;
    int input;
    int input_m=0;
    memset(board, -1, sizeof(board));
    memset(vis, -1, sizeof(vis));
    for (int i=0; i< m; i++ ){
        for (int j=0; j<n; j++){
            cin >> input;
            if(input_m < input){
                input_m = input;
            }
            board[i][j] = input;
        }
    }

    queue<pair<int,int>> Q;
    int count=0;
    int max_c=0;
    
    for (int k=0; k<= input_m; k++ ){
        count = 0;
        memset(vis, -1, sizeof(vis));
        for (int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j] == -1 && board[i][j] >k){
                    vis[i][j] = 1;
                    Q.push({i,j});
                    count ++;

                    while(!Q.empty()){
                        pair<int,int> cur = Q.front(); Q.pop();

                        for(int dir=0; dir <4; dir ++){
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if(outOfBound(nx,ny))continue;
                            if(vis[nx][ny] != -1 || board[nx][ny] <=k) continue;

                            vis[nx][ny] = 1;
                            Q.push({nx,ny});
                        }
                    }
                }
            }
        }
        if(max_c < count) {
            max_c = count;
        }
    }

    cout << max_c << endl;  
    
    
    return 0;
}