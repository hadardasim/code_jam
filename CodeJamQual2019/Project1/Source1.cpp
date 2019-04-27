// question 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/0000000000088231

template<typename T> void PrintCase(int nCase, T _value)
{
	std::cout << "Case #" << nCase + 1 << ": " << _value << std::endl;
}

// question 1
int main()
{
	int nTests;
	std::cin >> nTests;

	for (int nCase = 0; nCase < nTests; ++nCase)
	{
		
		string strNum;
		cin >> strNum;
		string strA, strB;
		for (auto c : strNum)
		{
			if (c != '4')
			{
				strA += c;
				strB += '0';
			}
			else
			{
				strA += '2';
				strB += '2';
			}
		}

		// trim leading zero in strB
		size_t start = 0;
		for (; start < strB.size(); ++start)
			if (strB[start] != '0')
				break;

		string strResult = strA + ' ' + strB.substr(start);
		PrintCase(nCase, strResult);
	}
	
	return 0;
}