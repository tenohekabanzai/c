#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(int argc,char* argv[]){   
    fork();
    fork();
    printf("Hello World\n");    
    return 0;
}