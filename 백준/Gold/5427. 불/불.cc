

#include <bits/stdc++.h>
#define X first
#define Y second
#define endl '\n'

using namespace std;

char board[1100][1100];
int vis[1100][1100];
int escape[1100][1100];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int r,c;

bool outOfBound(int x, int y){
    return x<0||x>=r||y<0||y>=c;
}
bool isEscape_F(int x, int y) {
    return x==-1||x==r || y==-1|| y ==c; 
}

int main() {
    int n;
    cin >> n ;
    for(int k=0; k< n; k++){
        cin >> c>> r;
        memset(board, -1, sizeof(board));
        memset(vis, -1, sizeof(vis));
        memset(escape, -1, sizeof(escape));
        char input;
        bool isEscape = false;
        queue<pair<int,int>> FQ;
        queue<pair<int,int>> SQ;
        for(int i=0; i<r; i ++){
            for(int j=0; j<c; j++){
                cin >> input;
                board[i][j] = input;

                if(input == '*'){
                    vis[i][j] = 0;
                    FQ.push({i,j});
                }
                if(input == '@'){
                    if(isEscape_F(i,j)){
                        if(!isEscape){
                            cout << 1 << endl;
                            isEscape = true;
                            break; 
                        }
                    }
                    escape[i][j] = 0;
                    SQ.push({i,j});
                }
            }
        }

        while(!FQ.empty()&&!isEscape){
            auto cur = FQ.front(); FQ.pop();

            for(int dir=0; dir < 4; dir ++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

                if(outOfBound(nx,ny)) continue;
                if(vis[nx][ny] != -1 || board[nx][ny] == '#') continue;
                vis[nx][ny] = vis[cur.X][cur.Y] + 1;
                FQ.push({nx,ny});
            }
        }
        int escapeTime = r*c;
        while(!SQ.empty()&&!isEscape){
            auto cur = SQ.front(); SQ.pop();

            for(int dir=0; dir < 4; dir ++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(isEscape_F(nx,ny)){
                    isEscape = true;
                    cout << escape[cur.X][cur.Y]+1<< endl;
                    break;
                }
                if(escape[nx][ny] != -1 || board[nx][ny] == '#') continue;
                escape[nx][ny] = escape[cur.X][cur.Y] +1;
                if(escape[nx][ny] < vis[nx][ny] || vis[nx][ny] == -1){
                    
                    SQ.push({nx,ny});
                }
            }
        }

        
        

        
        if(!isEscape){
            cout << "IMPOSSIBLE" << endl;
        }
    }
    

    
    
    return 0;
}