//Bee Maja
#include <bits/stdc++.h>
using namespace std;
#define MAXN 102200
 
int offset[5][2] = {{-1,0}, {0,-1}, {1,-1}, {1,0}, {0,1}};
pair<int,int> maja_bee[MAXN];
 
int main()
{
	for (int i=1, j=1, k=0; i<MAXN ; i += j, j += 6, k++)
	{
		maja_bee[i] = make_pair(0, k);
		for (int m = 0; m < k; m++)
			maja_bee[i-m] = make_pair(m, k-m);
 
		int current = i;
		for (int m = 0; m < 5; m++)
			for (int n=0; n<k; n++)
			{
				int x = maja_bee[current].first + offset[m][0];
				int y = maja_bee[current].second + offset[m][1];
				maja_bee[current + 1] = make_pair(x,y);
				current++;
			}
	}
 
	int willi_bee;
	while(cin >> willi_bee){
		cout << maja_bee[willi_bee].first << " " << maja_bee[willi_bee].second << endl;
	}
}

/*
1
2
3
4
5
*/