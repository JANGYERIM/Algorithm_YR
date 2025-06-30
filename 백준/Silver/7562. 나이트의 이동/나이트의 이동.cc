#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
using namespace std;

int size_b;
int vis[500][500];
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};



int main() {
    int r;
    cin >> r;

    for(int i=0; i<r; i++){
        memset(vis, -1, sizeof(vis));
        int m, n;
        cin >> size_b >> n >> m;
        queue<pair<int,int>> Q;
        vis[n][m] =0;
        Q.push({n,m});
        
        cin >> n>> m;
        pair<int,int> goal = {n,m};

        while(!Q.empty()){
            pair<int,int> cur = Q.front(); Q.pop();
            if(cur.X == goal.X && cur.Y == goal.Y){
                cout << vis[cur.X][cur.Y] << endl;
                break;
            }

            for(int dir=0; dir<8; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if(nx>=size_b || nx<0 || ny>=size_b || ny<0) continue;
                if(vis[nx][ny] != -1 ) continue;
                vis[nx][ny] = vis[cur.X][cur.Y] +1;
                if(nx == goal.X && ny == goal.Y){
                    cout << vis[nx][ny] <<endl;
                    break;
                }
                Q.push({nx,ny});
            }
        }
    }
    
    return 0;
}