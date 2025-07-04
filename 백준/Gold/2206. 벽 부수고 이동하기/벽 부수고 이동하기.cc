#include <bits/stdc++.h>
#define X first
#define Y second
#define endl '\n'
using namespace std;

int board[1001][1001];
int dis[1001][1001][5];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n, m;

bool outOfBound(int x, int y, int z) {
    return x<0 || x>= n || y<0 || y>= m || z>=2;
}

int main() {
    cin >> n >> m ;
    if(n ==1 && m==1){ cout << 1<< endl; return 0;}
    memset(board, -1, sizeof(board));
    memset(dis, -1, sizeof(dis));
    string input;
    for(int i=0; i<n; i++){
        cin >> input;
        int j=0;
            for(auto c: input){
                board[i][j] = c-'0';
                j++;
            }
    }
    queue<tuple<int,int,int>> Q;
    if(board[0][0] == 0){
        
        dis[0][0][0] = 0;
        Q.push({0,0,0});

        while(!Q.empty()){
            auto [x,y,z] = Q.front(); Q.pop();

            for(int dir=0; dir < 4; dir ++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];

                if(outOfBound(nx,ny,z)) continue;
                if(dis[nx][ny][z] != -1) continue;
                if(board[nx][ny] == 1){
                    dis[nx][ny][z+1] = dis[x][y][z] +1;
                    Q.push({nx,ny,z+1});
                }
                if(board[nx][ny] == 0){
                    dis[nx][ny][z] = dis[x][y][z] + 1;
                    Q.push({nx,ny,z});
                }
                if(nx == n-1 && ny ==m-1){
    
                    int result=0;
                    if(dis[nx][ny][1] == -1 || dis[nx][ny][0] == -1) {
                        result = max(dis[nx][ny][1], dis[nx][ny][0]);
                    }
                    else {
                        result = min(dis[nx][ny][1], dis[nx][ny][0]);
                    }
                    cout << result +1 << endl;
                    return 0;
                }
                
            }
        }

        cout << -1 << endl;

    }
    else { cout << -1 << endl;}

    


    return 0;
}