// question 2
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <string>
#include <sstream>
#include <array>

//https://codingcompetitions.withgoogle.com/codejam/round/0000000000051635/0000000000104f1a

template<typename T> void PrintCase(int nCase, T _value)
{
	std::cout << "Case #" << nCase + 1 << ": " << _value << std::endl;
}

template <typename T>
void split_string(std::string strIn, std::vector<T>& arrOut, char seperator=' ')
{
	std::istringstream f1(strIn);
	std::string s;
	while (getline(f1, s, seperator))
	{
		std::istringstream f2(s);
		T val;
		f2 >> val;
		arrOut.push_back(val);
	}
}

// question 2
int main()
{
	std::array<int, 7> arrBlades = { 16,9,5,7,11,13,17 };
	const int nWindmills = 18;

	unsigned long nMaxVal = 1;
	for (auto num : arrBlades)
		nMaxVal *= num;
	
	unsigned int nTests, nNights, nMaxGophers;
	std::cin >> nTests >> nNights >> nMaxGophers;

	assert(nNights >= sizeof(arrBlades) / sizeof(arrBlades[0]));
	assert(nMaxVal >= nMaxGophers);

	for (unsigned int nCase = 0; nCase < nTests; ++nCase)
	{
		std::vector<int> arrModulu;
		for (auto blade : arrBlades)
		{
			std::cout << blade;
			for (auto n = 1; n < nWindmills; ++n)
				std::cout << " " << blade;
			std::cout << std::endl;
			
			// we assume that for a line seperated with spaces, each cin call will get a single word
			unsigned int nSum = 0;
			for (auto x=0; x< nWindmills; ++x)
			{
				int nResponse = -1;
				std::cin >> nResponse;
				if (nResponse < 0)
					return -1;
				nSum += (unsigned int)nResponse;
			}
			arrModulu.push_back(nSum % blade);
		}

		unsigned int solved_g = 1;
		for (unsigned int guess = 0; guess <= nMaxGophers; ++guess)
		{
			bool bMatch = true;
			for (auto ind = 0; bMatch && ind < arrBlades.size(); ++ind)			
				if ((guess % arrBlades[ind]) != arrModulu[ind])
					bMatch = false;
			if (bMatch)
			{
				solved_g = guess;
				break;
			}
		}
					
		std::cout << solved_g << std::endl;
		int correct = 0;
		std::cin >> correct;
		if (correct < 0)
			return -2;
	}
	
	return 0;
}