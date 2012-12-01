/**
*题目：
*有一个数组，每次从中间随机取一个，然后放回去，当所有的元素都被取过，返回总共的取的次数。
*写一个函数实现。复杂度是什么 
*
*解答：
* 使用bit打点记录已经取的数， 
* 复杂度分析，假设数组总长度为n 
* 取到第1个之前未被取到的数的期望 E(1)=1 
* 取到第2个之前未被取到的数的期望 E(2)=n/n-1 
* 取到第3个之前未被取到的数的期望 E(3)=n/n-2 
* ...
* 取到第n个之前未被取到的数的期望 E(n)=n/1 
* 总得期望次数E=n+n/(n-1)+n/(n-2)+...+n/1;
*              =n(1+1/(n-1)+1/(n-2)+...+1/1) 
*              =nln(n) 
*所以算法平均复杂度为nlogn 
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
