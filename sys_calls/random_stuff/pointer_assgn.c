#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* str;
int num;

void create(){
    num = 100;
    str = malloc(sizeof(char)*num);
}

void process(){
    char example[100] = "this is an example\n";
    // str = example; // example persists in RAM as long as process function runs, then it disappears and str points to NULL %%%% MIGHT LEAD TO SEGMENTATION_FAULT
    
    strcpy(str,example); // copies contents of example into str, without changing reference of str pointer.
    printf("%s",str);
}

int main(int argc,char* argv[])
{
    create();
    process();
    free(str);
    return 0;
}