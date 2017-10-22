class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.size() <= 0)
			return false;

		if (sequence.size() == 1) //empty or only 1 element
			return true;

		int root_index = sequence.size() - 1;
		int root_value = sequence[root_index];

		// left subtree
		int i = 0;
		vector<int> left_sequence;
		for (; i < sequence.size() - 1; ++i)
		{
			if (sequence[i] > root_value)
				break;
			left_sequence.push_back(sequence[i]);
		}
		if (left_sequence.size() != 0 && !VerifySquenceOfBST(left_sequence))
			return false;

		// right subtree
		vector<int> right_sequence;
		for (; i < sequence.size() - 1; ++i)
		{
			if (sequence[i] < root_value)
				return false;
			right_sequence.push_back(sequence[i]);
		}
		if (right_sequence.size() != 0 && !VerifySquenceOfBST(right_sequence))
			return false;

		return true;
	}
};