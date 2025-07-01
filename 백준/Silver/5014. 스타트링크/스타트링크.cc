#include <bits/stdc++.h>
#define X first
#define Y second
#define endl '\n'
using namespace std;

int vis[1100000];
int u, d,f;


bool outOfBound(int x){
    return x<=0 || x>f ;
}

int main() {
    int s, g, result;
    memset(vis, -1, sizeof(vis));
    cin >> f >> s>> g>> u>> d;
    int dx[2] = {u, -d};
    queue<int> Q;
    int goal = g;
    vis[s] = 0;
    Q.push(s);
    if(s==g) {cout << 0<< endl; return 0;}

    while(!Q.empty()){
        int location = Q.front(); Q.pop();

        for(int dir=0; dir<2; dir++){
            int nx = location + dx[dir];
            if(outOfBound(nx)) continue;
            if(vis[nx] !=-1 ) continue;
            vis[nx] = vis[location] + 1;
            if(nx == goal) {
                cout << vis[nx] << endl;
                return 0;
            }
            Q.push(nx);
        }
    }


    cout << "use the stairs" << endl;
    
    return 0;
}