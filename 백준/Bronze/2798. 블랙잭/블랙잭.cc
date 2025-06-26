#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    int n, m, input;
    cin >> n >> m ;
    vector<int> card(n) ;

    for(int i=0; i<n ; i ++){
        cin >> input;
        card[i] = input;
    }

    int max = 0;
    int sum = 0;

    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int z=j+1; z<n; z++){
                sum = card[i] + card[j]+ card[z];
                    if(sum > max) {
                        if(sum > m) { continue;}
                        max = sum;
                    }
            
                
            }
        }
    }
    
    
    cout << max << endl;
    return 0;
}

