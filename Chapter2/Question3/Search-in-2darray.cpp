bool search_in_2Darray(int &array, int rows, int cols, int value)
{
	if(array==NULL || rows<0||cols<0)
	{
		printf("Please input valid array\n");
		return false;
	}
	
	int r=0,c=cols-1;
	int address=0;
	while(r<rows&&c>=0)
	{
		address=r*cols+cols;
		if(array[address]==value)
			return true;		
		else if(array[address]>value)		
			--c;		
		else(array[address]<value)		
			++r;		
	}
	return false;
}