/**
*��Ŀ��
*��һ�����飬ÿ�δ��м����ȡһ����Ȼ��Ż�ȥ�������е�Ԫ�ض���ȡ���������ܹ���ȡ�Ĵ�����
*дһ������ʵ�֡����Ӷ���ʲô 
*
*���
* ʹ��bit����¼�Ѿ�ȡ������ 
* ���Ӷȷ��������������ܳ���Ϊn 
* ȡ����1��֮ǰδ��ȡ������������ E(1)=1 
* ȡ����2��֮ǰδ��ȡ������������ E(2)=n/n-1 
* ȡ����3��֮ǰδ��ȡ������������ E(3)=n/n-2 
* ...
* ȡ����n��֮ǰδ��ȡ������������ E(n)=n/1 
* �ܵ���������E=n+n/(n-1)+n/(n-2)+...+n/1;
*              =n(1+1/(n-1)+1/(n-2)+...+1/1) 
*              =nln(n) 
*�����㷨ƽ�����Ӷ�Ϊnlogn 
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

bool bitOperate(char *p, int pos)
{
     int byte=pos>>3;
     int bit=pos&0x7;
     
     p+=byte;
     
     if (*p&(1<<bit))
     {
        return false;/*already set*/
     }
     else
     {
         *p|=1<<bit;/*set bit*/
         return true;
     }
}

int accessTimes(int array[], const int n)
{
    int times=0;
    int bitSet=0;
    char *p;
    
    if (array == NULL || n <=0)
    {
        return -1;
    }
     
    p=(char *)calloc(1, (n+7)>>3);
    
    if (p == NULL)
    {
       return -1;
    }
    
    srand(time(NULL));
    while(bitSet<n)
    {
        times++;
        if (bitOperate(p, rand()%n))
        {
            bitSet++;
        }
    }
    
    free(p);
    
    return times;
}

int main(int argc, char **argv)
{
    int a[]={1,3,7,8,9,5};
    
    printf("Total access times %d\n", accessTimes(a, 6));
  
    return 0;
}
