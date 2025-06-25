#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n ;
    int count=0;

    for(int i=0; i< n; i++){
        bool result = true;
        int input;
        cin >> input;

        if(input == 1){
            result =false;
        }
        else{
            for(int j=2; j<input; j++){
                if(input%j == 0){
                    result = false;
                    break;
                }
            }
        }
        if(result != false){
        count ++;
        }
    }

    cout << count << '\n';
}