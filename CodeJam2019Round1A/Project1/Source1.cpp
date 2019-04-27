// question 1
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstring>

// https://codingcompetitions.withgoogle.com/codejam/round/0000000000051635/0000000000104e03

template<typename T> void PrintCase(int nCase, T _value)
{
	std::cout << "Case #" << nCase + 1 << ": " << _value << std::endl;
}

template <typename T>
class Matrix
{
private:
	T * m_pData;
	size_t m_cols;
	size_t m_rows;
public:
	Matrix(size_t rows, size_t cols): m_cols(cols), m_rows(rows)
	{
		m_pData = new T[rows*cols];
	}
	~Matrix()
	{
		delete m_pData;
	}
	T& get(int x, int y) const { return m_pData[x + m_cols * y]; }

	void Set(const T& value)
	{
		std::memset(m_pData, value, sizeof(T)*m_cols*m_rows);
	}

	bool Solve()
	{
		Set(0);
		return SolveRec(m_cols, m_cols + m_rows, 1);
	}

	bool SolveRec(size_t x, size_t y, int level)
	{
		if (level > m_cols*m_rows)
			return true;

		for (auto c = 0; c < m_cols; ++c)
		{
			if (c == x)
				continue;
			for (auto r = 0; r < m_rows; ++r)
			{
				if (r==y || get(c, r))
					continue;
				if (r - c == y - x)
					continue;
				if (r + c == y + x)
					continue;
				
				get(c, r) = level;
				bool bSolve = SolveRec(c, r, level+1);
				if (bSolve)
					return true;
				get(c, r) = 0;
			}
		}
		return false;
	}

	std::vector<std::pair<int, int>> GetSolution() const
	{
		std::vector<std::pair<int, int>> result;
		result.resize(m_cols*m_rows);
		for (auto x = 0; x < m_cols; ++x)
		{
			for (auto y = 0; y < m_rows; ++y)
			{
				auto val = get(x, y);
				assert(val > 0);
				result[val - 1] = std::pair<int, int>(y + 1, x + 1);
			}
		}
		return result;
	}
};

// question 1
int main()
{
	int nTests;
	std::cin >> nTests;

	for (int nCase = 0; nCase < nTests; ++nCase)
	{
		int R, C;
		std::cin >> R >> C;

		Matrix<int> grid(R, C);
		bool bSolve = grid.Solve();
		if (!bSolve)
			PrintCase(nCase, "IMPOSSIBLE");
		else
		{
			PrintCase(nCase, "POSSIBLE");
			auto results = grid.GetSolution();
			for (auto pair : results)
			{
				std::cout << pair.first << " " << pair.second << std::endl;
			}
		}
	}
	
	return 0;
}