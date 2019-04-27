// question 3
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <cmath>

// https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/000000000008830b

// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
class CPrimes
{
public:
	CPrimes(long long nMaxPrime)
	{
		std::vector<unsigned short> arrIsPrime;
		arrIsPrime.resize(nMaxPrime+1, 1);

		long long uCount = (long long)(ceil(sqrt(nMaxPrime)));
		for (long long x = 2; x < uCount; ++x)
		{
			if (arrIsPrime[x])
			{
				for (auto y = x * x; y < nMaxPrime; y += x)
					arrIsPrime[y] = 0;
			}
		}
		for (auto x = 2; x <= nMaxPrime; ++x)
			if (arrIsPrime[x])
				m_arrPrimes.push_back(x);
	}
	std::vector<long long> m_arrPrimes;
	long long GetMinPrimeDivider(const long long nNum) const
	{
		for (auto x : m_arrPrimes)
		{
			if (nNum % x == 0)
				return x;
		}
		return -1;
	}
};

template<typename T> void PrintCase(int nCase, T _value)
{
	std::cout << "Case #" << nCase + 1 << ": " << _value << std::endl;
}

// question 3
int main()
{
	int nTests;
	std::cin >> nTests;

	for (int nCase = 0; nCase < nTests; ++nCase)
	{
		long long nMaxPrime;
		static_assert(sizeof(long long) >= 8, "");
		int nListLength;
		std::vector<long long> arrCode;
		std::cin >> nMaxPrime >> nListLength;
		arrCode.resize(nListLength);
		for (auto x = 0; x < nListLength; ++x)
		{
			std::cin >> arrCode[x];
		}

		CPrimes primes(nMaxPrime);
		std::set<long long> setPrimComp;
		std::vector<long long> arrMinDivider;
		
		for (auto x : arrCode)
		{
			auto n1 = primes.GetMinPrimeDivider(x);
			auto n2 = x / n1;
			setPrimComp.insert(n1);
			setPrimComp.insert(n2);
			arrMinDivider.push_back(n1);
		}

		std::map<long long, char> mapPrimeToChar;

		char c = 'A';
		for (auto x : setPrimComp)
		{
			mapPrimeToChar[x] = c;
			++c;
		}
		
		auto solve = [=](long long firstPrime)
		{
			long long prev = firstPrime;
			static std::string strResult;
			strResult = "";
			for (auto x = 0; x < nListLength; ++x)
			{
				if (arrCode[x] % prev)
					return (const char *)nullptr;
				strResult += mapPrimeToChar.find(prev)->second;
				prev = arrCode[x] / prev;
			}
			strResult += mapPrimeToChar.find(prev)->second;
			return strResult.c_str();
		};
		const char *strOut = solve(arrMinDivider[0]);
		if (!strOut)
			strOut = solve(arrCode[0]/arrMinDivider[0]);
		
		PrintCase(nCase, strOut);
	}

	return 0;
}