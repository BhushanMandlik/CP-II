//8.2 Queue problem
#include <bits/stdc++.h>
using namespace std;
#define NMAX 14
long long perm [NMAX][NMAX][NMAX]; 

long long calculate(){
    perm [1][1][1] = 1;
    for (int n = 2; n < NMAX; n ++)
        for (int p = 1; p < NMAX; p ++)
            for (int r = 1; r < NMAX; r ++)
                perm [n][p][r] = (perm[n-1][p][r] * (n-2)) + perm[n-1][p-1][r] + perm[n-1][p][r-1];
}

int main(){
    int t,n,p,r;
    calculate();
    cin >> t;   //test cases
    while (t--)
    {
        cin >> n >> p >> r; //n = no. of peoples, p = no. of people can see out to the left,
        //r = no. of people can see out to the right
        cout << perm [n] [p] [r] << endl;
    }
}

/*
3
10 4 4
11 3 1
3 1 2
*/