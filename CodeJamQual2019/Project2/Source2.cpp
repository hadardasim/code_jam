// question 2
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/00000000000881da

template<typename T> void PrintCase(int nCase, T _value)
{
	std::cout << "Case #" << nCase + 1 << ": " << _value << std::endl;
}

// question 2
int main2()
{
	int nTests;
	std::cin >> nTests;

	for (int nCase = 0; nCase < nTests; ++nCase)
	{
		long long N;
		std::cin >> N;
		std::string strMoves1;
		std::cin >> strMoves1;

		std::string strMoves2;
		for (auto c : strMoves1)
		{
			char c2 = (c == 'E') ? 'S' : 'E';
			strMoves2 += c2;
		}

		PrintCase(nCase, strMoves2);
	}
	
	return 0;
}