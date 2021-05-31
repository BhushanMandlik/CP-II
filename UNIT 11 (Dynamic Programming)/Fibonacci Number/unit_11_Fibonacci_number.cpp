// Fibonacci Number (Using Dynamic Programming)
#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    int f[n + 2];
    int i;
    f[0] = 0;  //initalize first element to zero
    f[1] = 1;  //initalize second element to one
    for(i = 2; i <= n; i++){
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main (){
    //0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ……..
    int n;  //index number
    cin >> n;
    cout << fib(n);
    return 0;
}