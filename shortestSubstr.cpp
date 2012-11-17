/*
*��Ŀ����һ�����ַ����в��Ұ��������ַ����ϵ�����Ӵ������磬����Ϊ"aaaaaaaaaacbebbbbbdddddddcccccc"��
*�ַ���Ϊ{abcd}����ô����Ӵ���"acbebbbbbd"�������������Ϊ��������ֻ���������ַ����ϡ���
*����㷨��ʵ���ֽ���θĶ���
*
*���
*��Ŀ���ַ�������hashMap�������Ӵ��Ƿ�������е��Ӵ����жϷ���������ʹ��һ��targetValueֵ�жϡ�targetValue��ֵΪĿ�괮������
*�ַ�֮�ͣ�curValue��ֵ��ʾ��ǰ�Ӵ��к��е�Ŀ�괮���ַ�֮�ͣ���curValue��T��targetValue���ʱ��˵���Ӵ�����Ŀ�괮��hashMap
*������ǰ�Ӵ��и���Ŀ���ַ��ļ����� 
*���ҵ���һ������Ŀ���ַ������Ӵ��󣬷ֱ��ƶ��Ӵ���ͷָ���βָ������ǰ�Ӵ�������Ŀ���ַ������ƶ�βָ�룬����ǰĿ���ַ�������
*Ŀ���ַ���ʱ���ƶ�ͷָ��, flagΪ�ƶ�ָ����жϱ�ʶ) 
*
*�����������Ϊ��������ֻ���������ַ����ϡ������ǿ������ǿ������ַ������ҵ�һ�����ַ����е��ַ�λ��point1, �Լ���point1��ʼ��һ������
*�ַ������ַ���λ��point2,����point1��point2�е��ַ�������������������Ȼ�����θ���point1��point2��λ�ã������������� 
*/


#include <iostream>
#include <ext/hash_map>

namespace std { using namespace __gnu_cxx; }
using namespace std;
using namespace __gnu_cxx;

char* shortestSubstr(char *src, const char *target)
{
    hash_map<char, int> targetMap;
    hash_map<char, int>::iterator it;
    int targetValue=0;
    int curValue=0;
    int len=0;
    int flag=0;/*flag for mov begin or end*/
    
    char *begin, *end, *cur;
    
    if (src == NULL || target == NULL)
    {
        return NULL;
    }
    
    while(*target)
    {
        targetValue+=*target;   
        targetMap[*target++];
    }
    
    begin = src;
    while(*begin)
    {
         it=targetMap.find(*begin);
         if (it != targetMap.end())
         {
             curValue=*begin;/*first begin*/
             (it->second)++;
             break;
         }
         begin++;
    }
    cur=begin;
    end = begin+1;
   
    while(*end)
    {
        it=targetMap.find(*end);
        if (it != targetMap.end())
        {
            (it->second)++;
            if ((it->second) == 1)
            {
                curValue+=*end;/*first end*/
                if (targetValue == curValue)
                {
                    len=end-begin+1;
                    break;
                }
            } 
        }
        end++;
    }
     
    if (len == 0)/*no substring found*/ 
    {
        return NULL;
    } 
    
    end++;
    while(begin<end)
    {
        if (!flag)/*move begin point*/
        {
            it=targetMap.find(*begin);
            if (it != targetMap.end())
            {
                (it->second)--;
                if ((it->second) == 0)
                {            
                    curValue-=*begin;
                    flag=1;
                    if (end-begin<len)/*update found substr*/ 
                    {
                        cur=begin;
                        len=end-begin;
                    }
                }    
            }
            begin++;
        }
        else if(*end)/*move end point*/ 
        {
            it=targetMap.find(*end);
            if (it != targetMap.end())
            {
                (it->second)++;
                if ( (it->second) == 1)
                {
                    curValue+=*end;
                    if (targetValue == curValue)
                    {
                        flag=0;
                    }
                } 
            }
            end++;
        }
        else
        {
            break;
        }
    }
    
    *(cur+len)='\0';
    return cur;
}

int main(int argc, char **argv)
{   
    char src[]="aaaaaaaaaacbebbbbbdddddddcccccc";
    char target[]="abcd"; 
    char *result = NULL;
    
    result = shortestSubstr(src, target);
    
    if (result != NULL)
    {
        cout<<"result:"<<result<<endl;
    }
    else
    {
        cout<<"No result found"<<endl;
    }

    return 0;
}
