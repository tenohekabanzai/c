#include<stdio.h>
#include "test.h" // -> header for self defined funcs

int main()
{   
    int age=10;
    char name[30];
    printf("What is your age ??\n");
    scanf("%d",&age);
    printf("Age is %d\n",age);
    
    printf("What is your name ??\n");
    // scanf("%s",name); // -> only reads stream till first space
    getchar(); // -> consuming the \n (newline) character to clear the buffer
    fgets(name,30,stdin);
    printf("Name is %s",name);
    
    // using self defined func in test.c
    printf("Using self defined add %d\n",_add(1,2));
    printf("Using self defined mul %d\n",_mul(4,2));


    
    return 0;
}