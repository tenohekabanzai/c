#include<stdio.h>

int nd_pt_array(){
    int **nums[2][2] = {{1,2},{3,4}};
    
    for(int i=0;i<sizeof(*nums)/4;i++)
    {
        for(int j=0;j<sizeof(**nums)/4;j++)
        printf("elements are :%d",**nums[i][j]);
        printf("\n");
    }
}

int main()
{
    int age = 40;
    int *agept = &age;
    printf("%p\n",agept);

    double gpa = 4.0;
    double *gpapt = &gpa;
    printf("%p\n",gpapt);

    printf("Age is: %d\n",*agept);
    printf("gpa is: %.2f\n",*gpapt);
}