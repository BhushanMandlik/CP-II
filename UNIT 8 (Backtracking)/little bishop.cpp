//8.1 Little Bishops

#include <bits/stdc++.h>
using namespace std;
#define MAXN 8
long long solution_count;

void construct_candidates (int bishops [], int c, int n, int candidates [], int * ncandidates)
{
    bool legal_move;
    int start = 0;
    if (c){
        start = bishops [c-1];
    }
    * ncandidates = 0;
    for (int p=start; p<n*n; p++)
    {
        legal_move = true;
    
        //If the condition is not met, exit the loop as soon as possible.
        for (int j=0; j<c; j++){
            if (abs(bishops [j]/n-p/n) == abs(bishops [j]% n-p% n))
            {
                legal_move = false;
                break;
            }
        }
    
        //If the bishop position is legal, add it to the candidate set.
        if (legal_move == true)
            //cout << "Hi" << endl;
            candidates [(* ncandidates) ++] = p;
    }
}

//Look back for all possible solutions.
void backtracking (int bishops [], int c, int n, int k)
{
    if (c == k){
        solution_count ++;
        //cout << solution_count << endl;
    }
    else
    {
        int ncandidates;
        int candidates [MAXN * MAXN];
        //Build the candidate set.
        construct_candidates (bishops, c, n, candidates, & ncandidates);
        for (int i = 0; i <ncandidates; i ++)
        {
            bishops [c] = candidates [i];
            backtracking (bishops, c+1, n, k);
        }
    }
}

long long little_bishops_by_backtracking (int n, int k)
{
    int bishops [2 * (MAXN-1) + 1];
    solution_count = 0;
    backtracking (bishops, 0, n, k);
    return solution_count;
}
    
int main()
{
    int n, k;
    while (cin >> n >> k, n || k)
        // here n = size of chessboard & k = No. of Bishops
        cout << little_bishops_by_backtracking (n, k) << endl;
    return 0;
}

/*
8 6
4 4
0 0
*/