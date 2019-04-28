// question 2
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T> void PrintCase(int nCase, T _value)
{
	std::cout << "Case #" << nCase + 1 << ": " << _value << std::endl;
}

// https://codingcompetitions.withgoogle.com/codejam/round/0000000000051706/0000000000122838

// question 3
int main()
{
	int nTests;
	std::cin >> nTests;

	for (int nCase = 0; nCase < nTests; ++nCase)
	{
		int N, K;
		std::cin >> N >> K;
		std::vector<int> arrC, arrD;
		arrC.resize(N);
		arrD.resize(N);
		for (int& c : arrC)
			std::cin >> c;
		for (int& d : arrD)
			std::cin >> d;
		std::vector<int> arrDiff;
		arrDiff.resize(N);
		for (int ind=0; ind< N; ++ind)
		{
			arrDiff[ind] = arrC[ind] - arrD[ind];
		}

		// brute force
		int count = 0;
		for (int R = N - 1; R >= 0; --R)
		{
			for (int L = 0; L <= R; ++L)
			{
				int maxC = 0;
				int maxD = 0;
				for (int n = L; n <= R; ++n)
				{
					maxC = std::max(maxC, arrC[n]);
					maxD = std::max(maxD, arrD[n]);
				}
				if (abs(maxC - maxD) <= K)
					++count;
			}
		}
		

		PrintCase(nCase, count);
	}
	
	return 0;
}