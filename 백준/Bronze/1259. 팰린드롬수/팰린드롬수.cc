#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
using namespace std;

int main() {

    string input;
    while(true) {
    cin >> input;
    if (input == "0") break;
    
    queue<char> arr;
    queue<char> arr2;
    int n = input.length();
    int len_2 = input.length()/2;
    for (int i=0; i< len_2; i ++){
        arr.push(input[i]);
    }
    int mid = (n%2 ==0)? len_2 : len_2 +1;

    for(int i=n-1; i>=mid;i--){
            arr2.push(input[i]);
    }

    bool is_result = true;
    while(!arr.empty() && !arr2.empty() ){
        if(arr.front() != arr2.front()){
            is_result = false;
        }
        arr.pop(); arr2.pop();
    }

    cout << (is_result? "yes": "no")<< endl;
    }
    
    return 0;
}