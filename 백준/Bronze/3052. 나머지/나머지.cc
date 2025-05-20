#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> input(10);
    vector<int> condition(43);
    int result=0;

    for(int i =0; i <10;i ++){
        cin >> input[i];
        input[i] = input[i] %42;
    }

    for(int i: input){
        condition[i] ++;
    }

    for(int i: condition){
        if(i >0){
            result ++;
        }
    }

    cout << result;

    


    
    return 0;
}