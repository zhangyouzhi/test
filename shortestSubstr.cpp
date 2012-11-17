/*
*题目：从一个长字符串中查找包含给定字符集合的最短子串。例如，长串为"aaaaaaaaaacbebbbbbdddddddcccccc"，
*字符集为{abcd}，那么最短子串是"acbebbbbbd"。如果将条件改为“包含且只包含给定字符集合”，
*你的算法和实现又将如何改动。
*
*解答
*将目标字符集放入hashMap，查找子串是否包含所有的子串（判断方法：我们使用一个targetValue值判断。targetValue的值为目标串的所有
*字符之和，curValue的值表示当前子串中含有的目标串的字符之和，当curValue与T、targetValue相等时，说明子串包括目标串，hashMap
*包含当前子串中各个目标字符的计数） 
*在找到第一个包含目标字符集的子串后，分别移动子串的头指针和尾指（当当前子串不包括目标字符集，移动尾指针，当当前目标字符串包含
*目标字符集时，移动头指针, flag为移动指针的判断标识) 
*
*如果将条件改为“包含且只包含给定字符集合”，我们可以我们可以再字符串中找第一个在字符集中的字符位置point1, 以及从point1开始第一个不在
*字符集的字符的位置point2,对于point1和point2中的字符串，调用上述函数，然后依次更新point1和point2的位置，调用上述函数 
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
