#include<stdio.h>
#include<stdlib.h>

int main()
{
    // ptr = (cast-type) malloc(byte-size)
    int *ptr = (int *) malloc(4*sizeof(int)); // int arr[4] dynamically

    if(ptr == NULL)
    {
        printf("Mem not allocated\n");
        exit(0);
    }

    for(int i=0;i<4;i++)
    *(ptr+i) = i;

    for(int i=0;i<4;i++)
    printf("Posn is %d and num stored is %d\n",i,*(ptr+i));

    // calloc() ->> allocates memory and initializes all values with value=0

    char *ptr1 = (char*) calloc(4,sizeof(char));
    for(int i=0;i<4;i++)
    printf("char at posn %d and char is %c\n",i,*(ptr1+i));

    // realloc() ->> similar to malloc, only repoints the pointer to some other mem loc
    ptr1 = (char*)realloc(ptr1,10*sizeof(char));

    for(int i=0;i<10;i++)
    printf("Posn is %d and num stored is %d\n",i,*(ptr1+i));

    

}
