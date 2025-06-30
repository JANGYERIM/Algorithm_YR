#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
using namespace std;

int board[200][200];
int vis[200][200];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int n,m,k;
bool outOfBounds(int x, int y) {
    return x<0 || x>=n || y<0 || y>=m ;
}

int main() {
    
    cin >> n>> m >>k;
    
    memset(board,-1,sizeof(board));
    memset(vis,-1,sizeof(vis));

    for(int i=0; i<k; i++){
        int x1,y1,x2,y2;
        cin >> x1>> y1 >> x2 >> y2 ;
        for(int j=y1; j<y2; j++){
            for(int t=x1; t<x2; t++){
                board[j][t] =1;
            }
        }
    }
    
    queue<pair<int,int>> Q;
    queue<int> Q2;
    int count=0;
    int extent =0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(vis[i][j]==-1 && board[i][j]!=1){
                vis[i][j] =1;
                Q.push({i,j});
                count ++;
            extent =0;
            while(!Q.empty()){
                pair<int,int> cur = Q.front(); Q.pop();
                extent ++;
                for(int dir=0; dir <4; dir++){
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];

                    if(outOfBounds(nx,ny)) continue;
                    if(vis[nx][ny]==1 || board[nx][ny] != -1) continue;
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }
                Q2.push(extent);
            }
            
        }
    }

    vector<int> result;
    while(!Q2.empty()){
        result.push_back(Q2.front());
        Q2.pop();
    }
    sort(result.begin(), result.end());
    cout << count << endl;
    for(int i=0 ; i<result.size() ; i++){
        cout << result.at(i) << ' ';    
    }


    return 0;
}