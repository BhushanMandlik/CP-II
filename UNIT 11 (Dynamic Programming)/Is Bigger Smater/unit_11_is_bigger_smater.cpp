#include <bits/stdc++.h>
using namespace std;

#define MAXN 1001

typedef struct {
    int id, weight, iq;
} Elephant;

typedef struct {
    int value, parent;
} State;

Elephant elephants[MAXN]; //To store weights of an elephants 
State states[MAXN];       //To store IQ's of an elephants 

int cmp (const void *p1, const void *p2 )
{
    const Elephant *e1 = (const Elephant*)p1;
    const Elephant *e2 = (const Elephant*)p2;
    return (e1->iq == e2->iq) ? (e1->weight > e2->weight ? -1 : 1) : (e1->iq < e2->iq ? -1 : 1);
    //ternary operator
}

int main()
{ 
    int n = 0;
    Elephant *p = elephants;

    for (n = 0; scanf("%d %d", &(p->weight), &(p->iq)) != EOF; ++n) {  
        p->id = n+1;
        ++p;
    }

    if (n == 0) { 
        printf("0\n");
        return 0;
    }

    // sort elephants by an IQ (increasingly)
    qsort(elephants, n, sizeof(Elephant), cmp);

    //initial state of an arrays
    for (int i = 0; i < n; ++i) {
        states[i].parent = -1;
        states[i].value = 1;
    }

    int mi = 0, mv = 0;
    for (int i = 0; i < n; ++i) {
        p = elephants + i;
        for (int j = 0; j < i && elephants[j].iq < p->iq; ++j) {
            if (elephants[j].weight > p->weight && states[j].value >= states[i].value){
                states[i].value = states[j].value + 1;
                states[i].parent = j;
            }
        }
        if (states[i].value > mv){
            mi = i;
            mv = states[i].value;
        }
    }

    printf("%d\n", mv);
    while (mi >= 0) {
        printf("%d\n", elephants[mi].id);
        mi = states[mi].parent;
    }
}			

/*
6008 1300
6000 2100
500 2000
1000 4000
1100 3000
6000 2000
8000 1400
6000 1200
2000 1900
*/
