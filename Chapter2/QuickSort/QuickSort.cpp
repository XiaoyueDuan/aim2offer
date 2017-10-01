int onceLoop(int *array, const unsigned int &start, const unsigned int &end)
{
	if (start >= end || start<0)
		return -1;

	int value = array[start];
	int head = start, tail = end;
	while (head<tail)
	{
		while (head<tail&&array[tail] >= value)
			--tail;
		if (head<tail)
			array[head++] = array[tail];
		while (head<tail&&array[head] <= value)
			++head;
		if (head<tail)
			array[tail--] = array[head];
	}
	array[head] = value;
	return head;
}

void quicksort(int *array, const unsigned int &size, const unsigned int &start, const unsigned int &end)
{
	if (start == end)
		return;

	int pos = onceLoop(array, start, end);
	if (pos>start)
		quicksort(array, size, start, pos - 1);
	if (pos<end)
		quicksort(array, size, pos + 1, end);
}

int main()
{
	int array[8]={7, 1, 9, 10, -1, 3, 6, 11};
	unsigned int length = sizeof(array) / sizeof(int);
	quicksort(array, length, 0, length - 1);

	return 0;
}