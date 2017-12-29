class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) 
    {
        int start_pos=0, end_pos=input.size();
        int pos;
        while(true)
        {
            pos=quick_sort_once(input, start_pos, end_pos);
            if(pos==k)
            	break;
            else if (pos<k)
                start_pos=pos+1;
            else
				end_pos=pos;
        }
        print(input, k);
        return input;
    }
    
    void print(const vector<int> &input, int k)
    {
        for(int i=0;i<k;++k)
            printf("%d\n",input[i]);
    }
    
    int quick_sort_once(vector<int> &input, int start_pos, int end_pos)
    {
        if(start_pos>=end_pos)
            return -1;
        
        int value=input[start_pos];
        int i=start_pos+1,j=end_pos-1;
        
        int index=start_pos;
        bool right=true;
        while(i<=j)
        {       
            if(!right)
            {
                while(i<=j && input[i++]<=value);            
            	input[index]=input[i-1];
            	index=i-1;
            }
			else
            {
        		while(i<=j && input[j--]>=value);                
                input[index]=input[j+1];
                index=j+1;
            }
        	left!=left;
        }
        input[index]=value;  
        return index;
    }
};