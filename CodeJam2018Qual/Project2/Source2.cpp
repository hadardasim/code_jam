// question 2
// https://codejam.withgoogle.com/2018/challenges/00000000000000cb/dashboard/00000000000079cb
#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h> 



// question 2
// Trouble Sort
int main()
{
	int nTests;
	std::cin >> nTests;

	for (int nCase = 0; nCase < nTests; ++nCase)
	{
		std::vector<long> even;
		std::vector<long> odd;
		long N;
		std::cin >> N;

		long cur_value = 0;
		for (long ind = 0; ind < N; ++ind)
		{
			std::cin >> cur_value;
			if ((ind & 1) == 0) // we want the first item to go into odd
				odd.push_back(cur_value);
			else
				even.push_back(cur_value);
		}

		std::sort(even.begin(), even.end());
		std::sort(odd.begin(), odd.end());

		assert(odd.size() >= even.size());

		long first_error = -1;
		for (long unsigned nPair = 0; nPair < even.size(); ++nPair)
		{
			if (even[nPair] < odd[nPair])
			{
				first_error = nPair * 2;
				break;
			}
			if (nPair + 1 < odd.size() && odd[nPair + 1] < even[nPair])
			{
				first_error = nPair * 2 + 1;
				break;
			}

		}

		if (first_error < 0)
			std::cout << "Case #" << nCase + 1 << ": " << "OK" << std::endl;
		else
			std::cout << "Case #" << nCase + 1 << ": " << first_error << std::endl;
	}
	
	return 0;
}