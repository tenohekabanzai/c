#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE * fpointer = fopen("test.txt","w");
    fprintf(fpointer,"Abc Def, Hello World!!!");
    fclose(fpointer);

    FILE *fpointer1 = fopen("test.txt","r");
    char line[255];
    fgets(line,255,fpointer1);
    printf("%s\n", line);
    fclose(fpointer1);
}