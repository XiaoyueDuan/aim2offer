class Solution {
public:
	vector<string> Permutation(string str) {
		vector<string> all_permutation;
		permutation(str, 0, all_permutation);
		return all_permutation;
	}

	void permutation(string &str, const int start_pos, vector<string> &str_list)
	{
		if (start_pos == str.length() - 1)
		{
			str_list.push_back(str);
			return;
		}

		string origin = str;
		char start_char = str[start_pos];
		for (int i = start_pos; i < str.length(); ++i)
		{
			char change_char = str[i];
			if (change_char == start_char&&i != start_pos)
				continue;

			//  alphabet ranking
			//  e.g. abcd=>adbc
			for (int j = i; j >start_pos; --j)
				str[j] = str[j - 1];
			str[start_pos] = change_char;

			permutation(str, start_pos + 1, str_list);
			str = origin;
		}
	}
};