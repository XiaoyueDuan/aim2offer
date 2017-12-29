#include <vector>
#include <fstream>
#include <iostream>

using namespace std;
fstream fin("input.txt");
#define cin fin

//class MaxDivision {
//public:
//	int findMaxDivision(vector<int> &A, int n)
//	{
//		// write code here
//		int min_value = 1000, max_value = 0;
//		for (int i = 0; i < n; ++i)
//		{
//			min_value = (A[i] < min_value) ? A[i] : min_value;
//			max_value = (A[i] > max_value) ? A[i] : max_value;
//		}
//
//		vector<int> min_in_backet(n, -1);
//		vector<int> max_in_backet(n, -1);
//
//		min_in_backet[0] = max_in_backet[0] = min_value;
//		min_in_backet[n - 1] = max_in_backet[n - 1] = max_value;
//
//		for (int i = 0; i < n; ++i)
//		{
//			int idx = (A[i] - min_value) * (n - 1) / (max_value - min_value);//(input[i] - min_value)/interval
//
//			if (min_in_backet[idx] < 0 && max_in_backet[idx] < 0)				// empty
//			{
//				min_in_backet[idx] = A[i];
//				max_in_backet[idx] = A[i];
//			}
//			else if (A[i] < min_in_backet[idx])
//				min_in_backet[idx] = A[i];
//			else if (A[i] > max_in_backet[idx])
//				max_in_backet[idx] = A[i];
//		}
//
//		int max_interval = 0;
//		int last_non_empty_backet = 0;
//		for (int i = 1; i < n; ++i)
//		{
//			if (min_in_backet[i] < 0 && max_in_backet[i] < 0)				// empty
//				continue;
//
//			int inter = min_in_backet[i] - max_in_backet[last_non_empty_backet];
//			if (inter > max_interval)
//				max_interval = inter;
//			last_non_empty_backet = i;
//		}
//		return max_interval;
//	}
//};

int main()
{
	int n;
	cin >> n;
	vector<int> input(n, 0);
	int min_value = 1000, max_value = 0;
	for (int i = 0; i < n; ++i)
	{
		int value;
		cin >> value;
		input[i] = value;

		min_value = (value < min_value) ? value : min_value;
		max_value = (value > max_value) ? value : max_value;
	}
	float interval = (max_value - min_value) / float(n - 1);

	vector<int> min_in_backet(n, -1);
	vector<int> max_in_backet(n, -1);

	min_in_backet[0] = max_in_backet[0] = min_value;
	min_in_backet[n - 1] = max_in_backet[n - 1] = max_value;

	for (int i = 0; i < n; ++i)
	{
		int idx = (input[i] - min_value) * (n - 1) / (max_value - min_value);//(input[i] - min_value)/interval

		if (min_in_backet[idx] < 0 && max_in_backet[idx] < 0)				// empty
		{
			min_in_backet[idx] = input[i];
			max_in_backet[idx] = input[i];
		}
		else if (input[i] < min_in_backet[idx])
			min_in_backet[idx] = input[i];
		else if (input[i] > max_in_backet[idx])
			max_in_backet[idx] = input[i];
	}

	int max_interval = 0;
	int last_non_empty_backet = 0;
	for (int i = 1; i < n; ++i)
	{
		if (min_in_backet[i] < 0 && max_in_backet[i] < 0)				// empty
			continue;

		int inter = min_in_backet[i] - max_in_backet[last_non_empty_backet];
		if (inter > max_interval)
			max_interval = inter;
		last_non_empty_backet = i;
	}

	return 0;
}