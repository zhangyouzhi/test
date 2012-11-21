/*
*题目:
* 左“{”，右”}"括号各N个，请打印出所有正确的组合，比如当N=3，{}{}{}，{{{}}}，
*等为正确的组合。如果写的代码是recursive，能否用iterative再写一个；反之亦然。 
*
*
*解答：
*可以类比这样一个问题，对于{{{}}}的全部输出，类似于所有小于等于111000的排列，并满足前面1的个数比0多，
*因为第一个必须为'{' ,最后一个必须为'}'所有第一个和最后一个不必用于计算下一个排列
* 
*程序中 函数bool nextOne(char *brackets, int len)用于求下一个排列， 
*函数 bool validMatch(char *brackets, int len)用于验证该排列的有效性 
*
*/

#include <stdio.h>
#include <string.h>

void swap(char *p, char*q)
{
     *p^=*q;
     *q^=*p;
     *p^=*q;
}

void reverse(char *begin, char *end)
{   
    if (begin==NULL || end == NULL)
    {
        return;
    }
    
    while(begin < end)
    {
       swap(begin, end);
       begin++;
       end--;
    }
}

bool nextOne(char *brackets, int len)
{
     char *cur;
     char *p;

     if (brackets == NULL || len <= 0)
     {
          return false;
     }
       
     cur=brackets+len-1;
     while(cur!=brackets)
     {
        if(*cur=='}' && *(cur-1)=='{')
        { 
            reverse(cur, brackets+len-1); 
            p=cur;
            while(*p!='}')
            {       
                p++;   
            }
            swap(cur-1, p);
            return true;
        }
        cur--;
     }
     
     return false;
}

bool validMatch(char *brackets, int len)
{
    char *cur=brackets;
    int count=0;

    if (brackets == NULL || len <=0)
    {
          return false;
    }
   
    while(len--)
    {
        if(count<0)
        {
            return false;
        }
        if(*cur=='{')
        {
            count++;
        }
        else
        {
            count--;
        }
        cur++;
    }
    
    return true;
}

void bracketMatch(char *brackets)
{
     int len;
     bool ret=true;
     int count=0;
     
     if(brackets == NULL)
     {
         return;
     }
     
     len = strlen(brackets);
     if(len&1)/*len must be even*/
     {
         return;
     }
     
     while(1)
     {
         printf("%s \n", brackets);
         count++;     
         while(1)
         {
             ret=nextOne(brackets+1, len-2);
             if (!ret)
             {
                 printf("total count %d\n", count);
                 return;
             }
             if (validMatch(brackets, len))
             {
                 break;
             }
         }
     }    
}

int main(int argc, int *argv[])
{
    char brackets[]="{{{}}}";
    
    bracketMatch(brackets);  

    return 0;
}
