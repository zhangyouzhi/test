/*
*题目：
*3个字符串a，b，c。判断c是否是a和b的interleave，也就是c中应该有a，b中所有字 符，
*并且c中字符顺序和a，b中一样。比如，a = "ef" b = "gh" c = "egfh" return true；
*a = "ef" b = "gh" c = "ehgf" return false。
*
* 
*解答： 
*本题难点主要是可能有重复字符，使用动态规划， 设f(i,j)表示c的前i+j个字符是否为a的前
*i个字符和b的前j个字符的interleave，
*最优子结构为f(i,j)=(f(i-1, j)&&a[i-1]==c[i+j-1]) || (f(i, j-1)&&b[j-1]==c[i+j-1]) 
*由于f(i,j)只与 f(i-1, j) 及f(i, j-1)有关，空间可以优化为O(min(strlen(a), strlen(b)))
*（本代码空间直接用O(strlen(a)) 
* 
*时间复杂度O(strlen(a)*strlen(b)), 另外本题可以用bitset代替bool数组进一步优化空间 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool interleave(const char *a, const char *b, const char *c)
{
    int lena,lenb,lenc, i, j;
    bool *temp;
    bool value;
     
    if(a==NULL || b==NULL || c==NULL)
    {
        return false;
    }
     
    lena=strlen(a);
    lenb=strlen(b);
    lenc=strlen(c);
     
    if(lena+lenb!=lenc)
    {
        return false;
    }
     
    temp=(bool*)malloc(lena*sizeof(bool));
    memset(temp, 0, lena*sizeof(bool));
     
    for (j=0; j<lena; j++)
    {
        if(a[j]==c[j])
        {
            temp[j]=true;
        }
        else
        {
            break;/*the rest false*/
        }
    }
     
    for (i=0; i<lenb; i++)
    {
        value=(b[i]==c[i]);

        temp[0]=(value && a[0]==c[i+1])|| (temp[0]&&b[i]==c[i+1]);

        for (j=1; j<lena; j++)/*update temp value*/
        {    
            temp[j]=(temp[j-1] && a[j]==c[i+j+1])|| (temp[j]&&b[i]==c[i+j+1]);      
        }
    }
    
    value=temp[lena-1];
    free(temp);
    
    return value;
}

int main(int argc, char *argv[])
{
    char strA[]="accedf";
    char strB[]="bddccfg";
    char strC[]="acbddccedcffg";
    char strD[]="acbddeccdcffg";
    
    if(interleave(strA, strB, strC))
    {
        printf("strC is interleave of strA and strB\n");
    }
    else 
    {
        printf("strC is not interleave of strA and strB\n");
    }
    
    if(interleave(strA, strB, strD))
    {
        printf("strD is interleave of strA and strB\n");
    }
    else 
    {
        printf("strD is not interleave of strA and strB\n");
    }
    
    return 0; 
}
