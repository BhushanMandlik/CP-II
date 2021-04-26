//8.3 Tug of war
#include <bits/stdc++.h>
using namespace std;
#define MAX_DIFF 450 //The maximum possible difference in weight between two people.

int tug_of_war (vector <int> & weight, int sum)
{
	//If there is only one person, obviously one team has a weight of 0, and the other team's 
	//weight is the weight of the only person participating in the picnic.
	if (weight.size () == 1)
		return 0;

	//Sort the weight values ​​in increasing order to obtain an increasing sequence of total weight values.
	sort (weight.begin (), weight.end ());

	int lower, upper;

	lower = weight.size ()/2-1;
	upper = lower + 1;

	//Find and replace the two players with the smallest weight difference between the first two teams 
	//found, the total weight of the current team is less than the latter, continue the process until the 
	//weight value of the previous team is equal to or greater than half of the total weight.
	int origin_lower, origin_upper;
	while (true)
	{
		int memo_lower, memo_upper;
		int diff_weight = MAX_DIFF;

		//Find the first two players with the smallest weight difference.
		bool changed = false;
		for (int m = 0; m <= lower; m ++)
		{
			for (int n = upper; n <weight.size (); n ++)
			{
				int tmp = weight.at (n)-weight.at (m);
				//Ensure that the weight of the original team after the exchange is greater.
				if (tmp> 0 && tmp <diff_weight)
				{
					memo_lower = m;
					memo_upper = n;
					diff_weight = weight.at (n)-weight.at (m);
					changed = true;
				}
			}
		}

		//If found, exchange the first two players with the smallest difference.
		if (changed == true)
		{
			origin_lower = weight.at (memo_lower);
			origin_upper = weight.at (memo_upper);

			int tmp = weight.at (memo_lower);
			weight.at (memo_lower) = weight.at (memo_upper);
			weight.at (memo_upper) = tmp;
		}

		//Calculate the weight sum of the previous team.
		int team_weight = 0;
		for (int i = 0; i <= lower; i ++)
			team_weight += weight.at (i);

		//No two players with a difference greater than 0, or the weight of the previous team equal to 
		//half of the total weight, return the current
		//The sum of the weight of the previous team is what the title asks for.
		if (changed == false || team_weight == (sum/2))
			return team_weight;

		//The weight of the previous team is less than half of the total weight, and the weights of the 
		//two teams are arranged in increasing order and continue to be replaced.
		if (team_weight <(sum/2))
		{
			sort (weight.begin (), weight.begin () + lower);
			sort (weight.begin () + upper, weight.end ());
			continue;
		}

		//The weight of the previous team ’s weight is greater than half of the total body weight, compare the weight difference between the previous replacement and the current team ’s weight, take
		//A group with a small difference.
		int team_a = 0, team_b = 0;
		for (int i = 0; i <= lower; i ++)
			team_a += weight.at (i);
		team_b = team_a + origin_lower-origin_upper;

		if (abs(2 * team_a-sum) < abs(2 * team_b-sum))
			return (sum-team_a);
		else
			return team_b;
	}
}

int main ()
{
	int cases; //Number of test cases
	vector <int> weight;//Record weight value

	cin >> cases;
	while (cases--)
	{
		int n; //The total number of people participating in the picnic
		int tmp; //tmp is the weight of a single person
		int sum = 0; //sum is the total weight

		weight.clear ();

		cin >> n;
		while (n--)
		{
			cin >> tmp;
			sum += tmp;
			weight.push_back (tmp);
		}

		int smaller = tug_of_war (weight, sum);
		cout << smaller << " " << (sum-smaller) << endl;

		if (cases)
			cout << endl;
	}
}

/*
1
3
100
90
200
*/