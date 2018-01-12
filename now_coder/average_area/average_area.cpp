#include <iostream>
#include <fstream>
#include <string>

using namespace std;

fstream fin("input.txt");
#define cin fin

int array_value[75][75];
int sum_value[76][76];
int n, m;

class Solution
{
public:
	static bool check(int value)
	{
		for(int j1=1; j1 < n-2; ++j1)
			for (int j2 = j1+1; j2<n - 1; ++j2)
				for (int j3 = j2+1; j3 < n; ++j3)
				{
					int cnt = 0, pcut=0;
					for (int i = 1; i <= m; ++i)
					{
						int area[4];
						area[0] = subarray_sum(0, pcut, j1, i);
						area[1] = subarray_sum(j1, pcut, j2, i);
						area[2] = subarray_sum(j2, pcut, j3, i);
						area[3] = subarray_sum(j3, pcut, n, i);

						if (area[0] >= value&&area[1] >= value&&area[2] >= value&&area[3] >= value)
						{
							++cnt;
							pcut = i;
							if (cnt == 3)
							{
								if (i<m)
								{
									area[0] = subarray_sum(0, pcut, j1, m);
									area[1] = subarray_sum(j1, pcut, j2, m);
									area[2] = subarray_sum(j2, pcut, j3, m);
									area[3] = subarray_sum(j3, pcut, n, m);
									if (area[0] >= value&&area[1] >= value&&area[2] >= value&&area[3] >= value)
										return true;
									else
										break;
								}
							}								
						}
					}
				}
		return false;
	}

	static void cal_sum_value()
	{
		for (int row = 0; row < n; ++row)
			sum_value[row][0] = 0;
		for (int col = 0; col < m; ++col)
			sum_value[0][col] = 0;

		for(int row=1; row<=n; ++row)
			for (int col = 1; col <=m; ++col)			
				sum_value[row][col] = sum_value[row][col-1] + array_value[row-1][col-1];			

		for(int col=0; col<=m; ++col)
			for (int row = 1; row <= n; ++row)			
				sum_value[row][col] += sum_value[row - 1][col];			
	}

	static int subarray_sum(int row1, int col1, int row2, int col2)
	{
		return sum_value[row1][col1] + sum_value[row2][col2] - sum_value[row1][col2] - sum_value[row2][col1];
	}
};

int main()
{
	cin >> n >> m;

	for (int row = 0; row < n; ++row)
	{
		string tmp;
		cin >> tmp;
		for (int col = 0; col < m; ++col)		
			array_value[row][col] = tmp[col] - '0';
	}
		
	Solution::cal_sum_value();
	int small = 0, large = sum_value[n][m];
	int mid,ans;
	while (small <= large)
	{
		mid = (small + large) >> 1;
		if (Solution::check(mid))
		{
			small = mid + 1;
			ans = mid;
		}		
		else		
			large = mid - 1;		
	}

	cout << ans;

	return 0;
}