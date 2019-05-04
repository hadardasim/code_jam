// question 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

// https://codingcompetitions.withgoogle.com/codejam/round/00000000000516b9/0000000000134c90

template<typename T> void PrintCase(int nCase, T _value)
{
	std::cout << "Case #" << nCase + 1 << ": " << _value << std::endl;
}



// question 1
int main()
{
	int nTests;
	std::cin >> nTests;

	std::unordered_map<char, int> charToVal;
	charToVal['R'] = 0;
	charToVal['P'] = 1;
	charToVal['S'] = 2;

	char valToChar[3] = { 'R', 'P', 'S' };
	

	for (int nCase = 0; nCase < nTests; ++nCase)
	{
		int A;
		std::cin >> A;
		std::vector<std::string> arrMoves;
		arrMoves.resize(A);
		
		for (std::string& str : arrMoves)
			std::cin >> str;

		std::string strResult;
		char charPerRobot[256];
		
		for (int ind = 0; ind < 500 && arrMoves.size(); ++ind)
		{
			// find a character which either wins or equal
			int arrCount[3] = { 0,0,0 };
			for (auto x = 0; x < arrMoves.size(); ++x)
			{
				const std::string& cur = arrMoves[x];
				charPerRobot[x] = cur[ind % cur.size()];

				auto val = charToVal[charPerRobot[x]];
				arrCount[val]++;
			}
			int nunZero = 0;
			for (int y = 0; y < 3; ++y)
				if (arrCount[y])
					nunZero++;
			if (nunZero==3)
			{
				strResult = "IMPOSSIBLE";
				break;
			}
			int nWin = 1;
			int nLoose = 0;
			if (nunZero == 1)
			{				
				for (int y = 0; y < 3; ++y)
					if (arrCount[y])
					{
						nWin = (y + 1) % 3;
						break;
					}				
			}
			else
			{
				for (int y = 0; y < 3; ++y)
					if (arrCount[y] && arrCount[(y+1)%3])
					{
						nWin = (y + 1) % 3;
						break;
					}
			}

			char cWin = valToChar[nWin];
			char cLoose = valToChar[(nWin + 2) % 3];

			strResult += cWin;
			// remove all losing
			for (int x = arrMoves.size()-1; x>=0; --x)
			{
				char c = charPerRobot[x];
				if (c == cLoose)
					arrMoves.erase(arrMoves.begin() + x);
			}
			
		}

		PrintCase(nCase, strResult);
	}
	
	return 0;
}