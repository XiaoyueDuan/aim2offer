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

class Solution {
public:
	string PrintMinNumber(vector<int> &numbers) 
	{
		vector<string> str_numbers;
		
		for (int i = 0; i < numbers.size(); ++i)
			str_numbers.push_back(to_string(numbers[i]));

		sort(str_numbers.begin(), str_numbers.end(), compare_length_then_string_lt);	

	

		string result;
		for (int i = 0; i < str_numbers.size(); ++i)
			result += str_numbers[i];

		return result;
	}

	static bool compare_length_then_string_lt(const string& a, const string& b) 
	{
		string ab = a + b;
		string ba = b + a;
		return (ab.compare(ba)<0);
	}
};

int main()
{
	int n;
	cin >> n;

	vector<int> numbers;
	for (int i = 0; i < n; ++i)
	{
		int value;
		cin >> value;

		numbers.push_back(value);
	}

	Solution s;
	s.PrintMinNumber(numbers);
}