// question 2
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>

template<typename T> void PrintCase(int nCase, T _value)
{
	std::cout << "Case #" << nCase + 1 << ": " << _value << std::endl;
}

// question 2
int main()
{
	/*
	std::string test = "ABD";
	auto x = test.find('A');
	int y = test.find('Z');
	*/

	int nTests, F;
	std::cin >> nTests >> F;

	int arrMinDigit[5] = { 119, 23, 5, 1 , 0};

	for (int nCase = 0; nCase < nTests; ++nCase)
	{
		std::string strResult;
		std::vector<int> arrSubset;
		for (auto x = 0; x < 119; ++x)
			arrSubset.push_back(x);

		for (auto digit = 0; digit < 3; ++digit)
		{
			int arrCount[5] = { 0,0,0,0,0 };
			char c;
			int arrWhich[119];

			if (arrSubset.size() != arrMinDigit[digit])
				return -1;

			for (auto n = 0; n < arrSubset.size(); ++n)
			{
				auto x = arrSubset[n];
				std::cout << 1 + x * 5 + digit << std::endl;
				std::cin >> c;
				int d = c - 'A';
				arrWhich[n] = d;
				arrCount[d]++;
			}

			int nWhich = -1;
			for (auto x = 0; x < 5; ++x)
			{
				if (arrCount[x] == arrMinDigit[digit+1])
				{
					strResult += 'A' + x;
					nWhich = x;
					break;
				}
			}
			if (nWhich < 0)
				return -1;

			// search the next subset
			std::vector<int> arrSubset2;
			for (auto x = 0; x < arrSubset.size(); ++x)
			{
				if (arrWhich[x] == nWhich)
					arrSubset2.push_back(arrSubset[x]);
			}
			arrSubset = arrSubset2;
		}

		assert(strResult.size() == 3);
		std::cout << 1 + arrSubset[0] * 5 + 3 << std::endl;
		char c4, c5;
		std::cin >> c5;
		std::cout << 1 + arrSubset[0] * 5 + 4 << std::endl;
		std::cin >> c4;
		
		// add last chars
		strResult += c4;
		strResult += c5;

		// print the solution
		std::cout << strResult << std::endl;

		char reply;
		std::cin >> reply;
	}
	
	return 0;
}