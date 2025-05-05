#include<stdio.h>

double div(int a,int b)
{
    return a/(1.0*b);
}

int main()
{
    printf("Hello World\n");

    unsigned int age = -1;
    printf("%d\n",age);
    printf("%.2f\n",div(10,3));
    printf("%.2f\n",div(10,0)); // floating pt div by 0 is allowed
    return 0;
}