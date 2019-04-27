// question 1
// https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <assert.h> 

// question 1
int main()
{
	int nTests;
	std::cin >> nTests;

	for (int nCase = 0; nCase < nTests; ++nCase)
	{
		long long D;
		std::cin >> D;
		char P[31];
		std::cin >> P;

		int len = strlen(P);
		int charge = 0;
		//long arr_damage[30] = { 1 };
		// ingnore all charges in the end of the sequance since they have no effect
		while (len>0)
		{
			if (P[len-1] == 'S')
				break;
			len--;
		}
		P[len] = 0;

		long long cur_damage = 1;
		long long total_damage = 0;
		for (int ind = 0; ind < len; ++ind)
		{
			if (P[ind] == 'C')
			{
				charge++;
				cur_damage *= 2;
			}
			else
				total_damage += cur_damage;
		}

		int shots = len - charge;
		if (shots > D)
		{
			// the minimum damage will be if we move all the charges to the end
			std::cout << "Case #" << nCase + 1 << ": " << "IMPOSSIBLE" << std::endl;
			continue;
		}

		long swaps = 0;
		while (total_damage > D)
		{
			assert(charge > 0);
			assert(P[len - 1] == 'S');
			int last = len - 1;
			while (P[last] == 'S' && last > 0)
				--last;
			assert(P[last] == 'C');
			long long max_damage = 1 << charge;
			long long damage_save = max_damage / 2;
			while (total_damage > D && last < len - 1)
			{
				std::swap(P[last], P[last + 1]);
				last++;
				swaps++;
				total_damage -= damage_save;
			}
			if (last == len - 1)
			{
				len--;
				P[len] = 0;
				charge--;
			}
		}

	
		std::cout << "Case #" << nCase + 1 << ": " << swaps << std::endl;
	}
	
	return 0;
}