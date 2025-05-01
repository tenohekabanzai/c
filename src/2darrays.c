#include<stdio.h>


int main(){
    int nums[5] = {1,2,3,4};

    int nd_nums[5][2] = 
    {
        {1,2},
        {3,4},
        {5,6},
        {7,8},
        {9,10},
    };

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<2;j++)
        printf("%d ",nd_nums[i][j]);
        printf("\n");
    }
}