class Solution {
public:
    void reOrderArray(vector<int> &array, bool (*fun)(int)) {
        int head=0,tail=array.size()-1;
        while(head<tail)
        {
        	while(head<=tail&&fun(array[head]))
                ++head;
            while(tail>head&&!fun(array[head]))
                --tail;
            
            if(head<tail){
                int tmp=array[head];
                array[head]=array[tail];
                array[tail]=tmp;
            }
        }
    }
    
    bool isOdd(int n){
        return (n&0x1)!=0;
    }
};

