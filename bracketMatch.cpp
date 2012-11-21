/*
*��Ŀ:
* ��{�����ҡ�}"���Ÿ�N�������ӡ��������ȷ����ϣ����統N=3��{}{}{}��{{{}}}��
*��Ϊ��ȷ����ϡ����д�Ĵ�����recursive���ܷ���iterative��дһ������֮��Ȼ�� 
*
*
*���
*�����������һ�����⣬����{{{}}}��ȫ�����������������С�ڵ���111000�����У�������ǰ��1�ĸ�����0�࣬
*��Ϊ��һ������Ϊ'{' ,���һ������Ϊ'}'���е�һ�������һ���������ڼ�����һ������
* 
*������ ����bool nextOne(char *brackets, int len)��������һ�����У� 
*���� bool validMatch(char *brackets, int len)������֤�����е���Ч�� 
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
