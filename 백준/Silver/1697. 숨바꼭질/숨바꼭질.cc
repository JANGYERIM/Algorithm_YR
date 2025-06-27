#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
using namespace std;

int vis[200001];

int n, m;

int isDy(int dir, int cur){
    if(dir==2){
        return cur*2;
    }
    if(dir==1){
        return cur -1;
    }
    if(dir==0){
        return cur +1;
    }
    return -1;
}

int main() {
    cin >> n >> m;

    if(n ==m) {
        cout << 0 << endl;
        return 0;
    }
    
    memset(vis, -1, sizeof(vis));
    

    queue<int> Q;
    vis[n] = 0;
    Q.push(n);

    while(!Q.empty()){
        int cur = Q.front(); Q.pop();

        for(int dir=0; dir <3; dir ++){
            int ny = isDy(dir,cur);
            if(ny < 0 || ny >200000) continue;
            if(vis[ny] !=-1) continue;
            vis[ny] = vis[cur] + 1;
            if(ny == m) {
                cout << vis[m] << endl; 
                return 0;
            }
            Q.push(ny);
        }
    }

    
    
    return 0;
}