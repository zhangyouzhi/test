/*
*题目 
*有一个矩阵，行列都是排序的，给一个值，判断其在不在矩阵内。 
* 
* 
*从矩阵的右上角开始，若大于给定值，往左走，小于给定值，往下走 
* 算法复杂度O(m+n) 
*/

#include <stdio.h>
 
bool findValue(int *matrix, int m, int n, int value, int &row, int &col) 
{  
    if(matrix==NULL || m<=0 || n<=0)
    {
        return false;
    }

    row = 0;  
    col = n-1;  
    while(row <= m-1 && col >= 0) 
    {  
        if(*(matrix+row*n+col) > value) 
        { 
            col--;
        }  
        else if(*(matrix+row*n+col) < value) 
        {  
            row++;
        } 
        else
        {
            return true;
        } 
     }
     
     return false;  
}   

int main(int argc, char *argv[])
{
    int row, col; 
    bool ret; 
    int matrix[5][6]={{3,5,8,9,11,12},
                      {7,8,8,10,13,15},
                      {9,12,8,13,15,16},
                      {10,17,18,21,26,29},
                      {15,18,19,23,28,30}
                      };
                      
    ret=findValue(&matrix[0][0], 5, 6, 19, row, col);
    
    if (ret)
    {
        printf("Value found in row %d col %d\n", row, col); 
    } 
    else
    {
        printf("No result fould\n");
    }

    return 0; 
}
