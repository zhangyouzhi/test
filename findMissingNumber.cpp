/*
*题目 
*给一串整数 0，1，2，...，N，其中一个整数缺失。也就是说，如果是排序好放到大小为N的数组中，其实最大的整数应该是N+1。
*你的任务和算法是找出其中缺失的整数。如果是排序好的，怎么做？如果是无序的，又该如何做？时间复杂度各是什么？
*你能想到的最优算法是什么？动手写下你的代码吧。
*
*
*解答：
*对题目的一点说明，一串整数 0，1，2，...，N，其中一个整数缺失。如果是排序好放到大小为N的数组中，其实最大的整数应该是N
*因为整数包括0
*对于排好序的，可以二分查找，复杂度O(logn) 
*对于未排序的，可以异或，结果再与与1-N的整数异或，最终结果为缺失的值.复杂度O(n) 
*/

#include <stdio.h>

int findMissingSorted(int *array, int N)
{
    int begin=0, end=N-1;
    int mid;
    
    if(array == NULL||N<0)
    {
        return -1;
    }
    
    while(begin<end)
    {
        mid=((begin+end)>>1);
        if (array[mid] == mid)/*missing number is in the last half*/
        {
            if (array[mid+1] != mid+1)
            {
                return mid+1;
            }
            begin=mid+1;
        }
        else
        {
            end=mid-1;        
        }
    }
    
    if (array[begin] == begin)
    {
        return N;/*the last umber is missing*/
    }

     return begin;
} 

int findMissingUnsorted(int *array, int N)
{
    int xorValue=0;
    int index;
    
    if(array==NULL || N<0)
    {
        return -1;
    }
    
    for (index = 0; index<N; index++)
    {
        xorValue ^= (index^array[index]);
    }
    
    return (xorValue^N);
} 


int main(int argc, char *argv[])
{
    int sorted[]={0,1,2,4,5,6};
    int unsorted[]={6,2,4,1,5,0};
    
    printf("Missing sorted number %d\n", findMissingSorted(sorted, 6));
    printf("Missing unsorted number %d\n", findMissingUnsorted(unsorted, 6));

    return 0;
}
