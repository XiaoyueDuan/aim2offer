#include <stdio.h>

void spaceSubstitute(char *str)
{
	if (str == NULL)
		return;

	int initLength = 0, wholeLength = 0, spaceNum = 0;
	while (str[initLength] != '\0')
	{
		if (str[initLength] == ' ')
			++spaceNum;
		++initLength;
	}

	wholeLength = initLength + 2 * spaceNum;
	while (spaceNum)
	{
		if (str[initLength] == ' ')
		{
			str[wholeLength--] = '0';
			str[wholeLength--] = '2';
			str[wholeLength--] = '%';
			--initLength;	// skip this space
			--spaceNum;
		}
		else
			str[wholeLength--] = str[initLength--];
	}
	printf("%s\n", str);
}

int main()
{
	// Normal
	char str[10000] = "Hi, how are you?";

	// No / Multi spaces
	char str1[10000] = "Hi";
	char str2[10000] = "Hi,        how are you?";

	// NULL
	char *str3 = nullptr;

	spaceSubstitute(str);
	spaceSubstitute(str1);
	spaceSubstitute(str2);
	spaceSubstitute(str3);

	return 0;
}