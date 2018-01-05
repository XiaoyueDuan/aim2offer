#include <vector>

using namespace std;

fstream fin("input.txt");
#define cin fin

class Solution {
public:
	int GetUglyNumber_Solution(int index) 
	{
		if (index < 7)return index;

		vector<int> ugly_numbers(index);
		ugly_numbers[0] = 1;
		int t2 , t3 ,t5;
		t2 = t3 = t5 = 0;

		for (int i = 1; i < index; ++i)
		{
			ugly_numbers[i]=min(ugly_numbers[t2] *2, ugly_numbers[t3] *3, ugly_numbers[t5] *5);

			while (ugly_numbers[t2] * 2 <= ugly_numbers[i]) ++t2;
			while (ugly_numbers[t3] * 3 <= ugly_numbers[i]) ++t3;
			while (ugly_numbers[t5] * 5 <= ugly_numbers[i]) ++t5;
		}
		return ugly_numbers[index - 1];
	}

	int min(int n1, int n2, int n3)
	{
		int min_value = (n1 < n2) ? n1 : n2;
		min_value = (min_value < n3) ? min_value : n3;

		return min_value;
	}
};

int main()
{
	int n=6;
	Solution s;
	s.GetUglyNumber_Solution(n);
}