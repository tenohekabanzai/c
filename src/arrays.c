#include<stdio.h>

int main()
{
    int even[10] = {2,4,6,10,12};
    printf("%d\n",even[2]);
    printf("%d\n",even[6]); // -> prints 0
    printf("%d\n",even[101]); // -> prints garbadge value
    even[1]=80;

    printf("%d\n",even[1]);



}