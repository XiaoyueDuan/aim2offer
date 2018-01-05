#include <fstream>
#include <iostream>
using namespace std;

fstream fin("input.txt");
#define cin fin

class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		// i=1,个位
		// i=2,百位
		// ...

		int num = 0;
		for (int i = 1, base = 10; n / (base/10) != 0; ++i, base*=10)
		{
			int base_add = n / base * (base / 10);
			int condition = n%base / (base / 10);
			if (condition>1)
				base_add += (base / 10);
			else if (condition == 1)
				base_add += n%(base/10) + 1;

			num += base_add;
		}

		return num;
	}
};

int main()
{
	int n;
	cin >> n;

	Solution s;
	s.NumberOf1Between1AndN_Solution(n);
}