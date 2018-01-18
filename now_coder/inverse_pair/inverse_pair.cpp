#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

fstream fin("input.txt");
#define cin fin


class MonoSum {
public:
	int calcMonoSum(vector<int> A, int n) {
		// write code here
		return mergesort(A);
	}

	int mergesort(vector<int> &A)
	{
		int start = 0, end = A.size();

		vector<int> assist(A.size());
		for (int i = 0; i < A.size(); ++i)
			assist[i] = A[i];

		int sum;
		return merge(A, assist, 0, end, sum);
	}

	int merge(vector<int> &A,vector<int> &assist, int start, int end, int &sum)
	{
		if (start == end-1)
		{
			sum = A[start];
			return 0;
		}

		int mid = (start + end) >> 1;
		int sum_left, sum_right;
		int left_result = merge(assist, A, start, mid, sum_left);
		int right_result = merge(assist, A, mid, end, sum_right);
		sum = sum_left + sum_right;

		int result = left_result + right_result;
		int p1 = mid - 1, p2 = end - 1;
		int p = end - 1;
		while (p1 >=start&&p2>=mid)
		{
			if (A[p2] < A[p1])
			{
				assist[p] = A[p1];
				sum_left -= A[p1];
				--p1;
			}
			else
			{
				assist[p] = A[p2];
				result += sum_left;
				--p2;
			}
			--p;
		}

		if (p1 >= start)
		{
			while (p>=start)			
				assist[p--] = A[p1--];			
		}
		else if (p2 >= mid)
		{
			while (p >= start)
				assist[p--] = A[p2--];
		}

		return result;
	}
};

int main()
{
	MonoSum m;
	
	int n;
	cin >> n;
	vector<int> vector(n);
	for (int i = 0; i < n; ++i)	
		cin >> vector[i];

	cout << m.calcMonoSum(vector, n);

	return 0;
}