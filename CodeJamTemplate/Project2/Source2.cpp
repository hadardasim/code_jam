// question 2
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T> void PrintCase(int nCase, T _value)
{
	std::cout << "Case #" << nCase + 1 << ": " << _value << std::endl;
}

// question 2
int main()
{
	int nTests;
	std::cin >> nTests;

	for (int nCase = 0; nCase < nTests; ++nCase)
	{
		int N;
		std::cin >> N;

		PrintCase(N, "val");
	}
	
	return 0;
}