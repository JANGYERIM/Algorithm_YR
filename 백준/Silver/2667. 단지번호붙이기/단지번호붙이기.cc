#include <bits/stdc++.h>
#define X first
#define Y second
#define endl '\n'
using namespace std;

int board[30][30];
int vis[30][30];
int m, n;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool outOfBound(int x, int y){
    return x<0 || x>=m || y<0 || y>=n;
}

int main() {
    cin >> m ; 
    n = m;
    string input;
    memset(board, -1, sizeof(board));
    memset(vis, -1, sizeof(vis));

    for(int i=0; i<m; i++){
        cin >> input ;
        int j=0;
        for(auto c: input){
            board[i][j] = c -'0';
            j++;
        }
    }
    int count=0;
    queue<pair<int,int>> Q;
    queue<int> Q2;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(vis[i][j] == -1 && board[i][j]== 1){
                vis[i][j] = 1;
                Q.push({i,j});
                count ++;
                int area=0;

                while(!Q.empty()){
                    pair<int,int> cur = Q.front(); Q.pop();
                    area++;
                    for(int dir=0; dir<4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if(outOfBound(nx,ny))continue;
                        if(vis[nx][ny] == 1 || board[nx][ny] !=1) continue;

                        vis[nx][ny] =1;
                        Q.push({nx,ny});
                    }
                }
                Q2.push(area);
            }
        }
    }
    cout<< count << endl;
    int result[count] ;
    for (int i=0; i<count; i++){
        result[i] = Q2.front(); Q2.pop();
    }
    sort(result, result+count);
    for(auto c:result){
        cout << c<< endl;
    }

    return 0;
}