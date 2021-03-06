//9.3 Hanoi Tower Troubles Again!

#include <bits/stdc++.h>
using namespace std;

int T, N, tot;
int peg[55];

void backtrack(int v, int p) {
  if(p == N) return;
  if(peg[p] == 0) {
    peg[p] = v;
    tot++;
    return backtrack(v + 1, p);
  }
  
  for(int i = 0; i <= p; i++) {
    int root = (int) sqrt(peg[i] + v);
    if(root * root == peg[i] + v) {
      peg[i] = v;
      tot++;
      return backtrack(v + 1, p);
    }
  }
  backtrack(v, p + 1);
}

int main() {
  scanf("%d", &T);
  while(T--) {
    scanf("%d", &N);
    memset(peg, 0, sizeof peg);
    tot = 0;
    backtrack(1, 0);
    printf("%d\n", tot);
  }
}

/*
2
4
25
*/