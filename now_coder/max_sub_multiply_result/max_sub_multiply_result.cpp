#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <stdio.h>
#include <stdlib.h>

using namespace std;

fstream fin("input.txt");
#define cin fin

struct max_min
{
	long long max_value;
	long long min_value;

	max_min() :max_value(0x8000000000000000), min_value(0x7fffffffffffffff) {}
	max_min(int max,int min):max_value(max), min_value(min){}
};

max_min dynamic_array[10][50];

class Solution
{
public:
	static long long max_multiply_result(const vector<int> &values, int k, int d)
	{
		int n = values.size();
		for (int row = 1; row < k; ++row)
		{
			for (int col =row ;col<n;++col)
			{
				if (col == row)
				{
					dynamic_array[row][col].max_value = dynamic_array[row - 1][col - 1].max_value * values[col];
					dynamic_array[row][col].min_value = dynamic_array[row - 1][col - 1].min_value * values[col];
				}
				else
				{
					for (int i = col - 1; i >= 0 && i >= col - d; --i)
					{
						if (values[col] >= 0)
						{
							dynamic_array[row][col].max_value = max(dynamic_array[row][col].max_value, 
																	values[col]*dynamic_array[row-1][i].max_value);
							dynamic_array[row][col].min_value = min(dynamic_array[row][col].min_value,
																	values[col] * dynamic_array[row - 1][i].min_value);
						}
						else
						{
							dynamic_array[row][col].max_value = max(dynamic_array[row][col].max_value,
																	values[col] * dynamic_array[row - 1][i].min_value);
							dynamic_array[row][col].min_value = min(dynamic_array[row][col].min_value,
																	values[col] * dynamic_array[row - 1][i].max_value);
						}
					}
				}
			}
		}

		long long max_result = 0xffffffffffffffff;
		for (int i = k-1; i < n; ++i)		
			max_result = max(max_result, dynamic_array[k - 1][i].max_value);
		
		return max_result;
	}
};

int main()
{
	int n;
	cin >> n;
	vector<int> values(n);
	// element in values could be negative
	for (int i = 0; i < n; ++i)
	{
		cin >> values[i];
		dynamic_array[0][i].max_value = values[i];// init
		dynamic_array[0][i].min_value = values[i];// init
	}
	
	int k, d;
	cin >> k >> d;
	cout<<Solution::max_multiply_result(values, k, d);
	

	return 0;
}