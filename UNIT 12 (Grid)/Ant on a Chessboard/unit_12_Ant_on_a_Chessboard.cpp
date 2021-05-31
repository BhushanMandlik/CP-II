#include <bits/stdc++.h>
using namespace std;
 
int n, x, y;
int main() {
    while(true){
        scanf("%d", &n);
        if(n == 0) break;
 
        int root = ceil(sqrt(n));  //ceil(sqrt(8)) ---> ceil(2.82) ---> 3
        int c = root * root - root + 1;  //c = 3 * 3 - 3 + 1  ---> 7
        x = y = root; //x = y = 3
 
        if(root % 2 == 0) {       //3%2 != 0
            if(n > c) y -= n - c;
            else x -= c - n;
        } else {
            if(n > c) x -= n - c;  //8 > 7 ---> x = x - (n-c)  ---> x = 2
            else y -= c - n;
        }
        printf("%d %d\n", x, y);  //x = 2, y = 3
    }
}

/*
8
20
25
0
*/