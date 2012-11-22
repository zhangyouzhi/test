/*
*��Ŀ��
*3���ַ���a��b��c���ж�c�Ƿ���a��b��interleave��Ҳ����c��Ӧ����a��b�������� ����
*����c���ַ�˳���a��b��һ�������磬a = "ef" b = "gh" c = "egfh" return true��
*a = "ef" b = "gh" c = "ehgf" return false��
*
* 
*��� 
*�����ѵ���Ҫ�ǿ������ظ��ַ���ʹ�ö�̬�滮�� ��f(i,j)��ʾc��ǰi+j���ַ��Ƿ�Ϊa��ǰ
*i���ַ���b��ǰj���ַ���interleave��
*�����ӽṹΪf(i,j)=(f(i-1, j)&&a[i-1]==c[i+j-1]) || (f(i, j-1)&&b[j-1]==c[i+j-1]) 
*����f(i,j)ֻ�� f(i-1, j) ��f(i, j-1)�йأ��ռ�����Ż�ΪO(min(strlen(a), strlen(b)))
*��������ռ�ֱ����O(strlen(a)) 
* 
*ʱ�临�Ӷ�O(strlen(a)*strlen(b)), ���Ȿ�������bitset����bool�����һ���Ż��ռ� 
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
