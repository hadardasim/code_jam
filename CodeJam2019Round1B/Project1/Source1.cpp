// question 1
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T> void PrintCase(int nCase, T _value)
{
	std::cout << "Case #" << nCase + 1 << ": " << _value << std::endl;
}

struct Person
{
	int x, y;
	char direction;
};

// question 1
int main()
{
	int nTests;
	std::cin >> nTests;

	for (int nCase = 0; nCase < nTests; ++nCase)
	{
		int P, Q;
		std::cin >> P >> Q;

		std::vector<Person> arrPersons;
		std::vector<int> xScore, yScore;
		arrPersons.resize(P);
		xScore.resize(Q+1, 0);
		yScore.resize(Q+1, 0);
		for (Person& cur : arrPersons)
		{
			std::cin >> cur.x >> cur.y;
			std::cin >> cur.direction;
			if (cur.direction == 'N')
			{
				for (auto i = cur.y + 1; i <= Q; ++i)
					yScore[i]++;
			}
			else if (cur.direction == 'S')
			{
				for (auto i = cur.y - 1; i >= 0; --i)
					yScore[i]++;
			}
			else if (cur.direction == 'E')
			{
				for (auto x = cur.x + 1; x <= Q; ++x)
				{
					xScore[x]++;
				}
			}
			else
			{
				for (auto x = cur.x - 1; x >= 0; --x)
				{
					xScore[x]++;
				}
			}
		}
				
		int out_x = Q;
		int out_y = Q;
		
		{
			int xmax = 0;
			for (auto x = Q; x >= 0; --x)
				if (xScore[x] >= xmax)
				{
					xmax = xScore[x];
					out_x = x;
				}
		}
		{
			int ymax = 0;
			for (auto y = Q; y >= 0; --y)
			{
				if (yScore[y] >= ymax)
				{
					ymax = yScore[y];
					out_y = y;
				}
			}
		}

		

		std::cout << "Case #" << nCase + 1 << ": " << out_x << " " << out_y << std::endl;
	}
	
	return 0;
}