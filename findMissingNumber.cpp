/*
*��Ŀ 
*��һ������ 0��1��2��...��N������һ������ȱʧ��Ҳ����˵�����������÷ŵ���СΪN�������У���ʵ��������Ӧ����N+1��
*���������㷨���ҳ�����ȱʧ�����������������õģ���ô�������������ģ��ָ��������ʱ�临�Ӷȸ���ʲô��
*�����뵽�������㷨��ʲô������д����Ĵ���ɡ�
*
*
*���
*����Ŀ��һ��˵����һ������ 0��1��2��...��N������һ������ȱʧ�����������÷ŵ���СΪN�������У���ʵ��������Ӧ����N
*��Ϊ��������0
*�����ź���ģ����Զ��ֲ��ң����Ӷ�O(logn) 
*����δ����ģ�������򣬽��������1-N������������ս��Ϊȱʧ��ֵ.���Ӷ�O(n) 
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
