#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(int argc,char* argv[]){   
    int id = fork();
    printf("Hello World, %d\n",id);
    if(id == 0)
    printf("Hello from Child Process\n");
    else
    printf("Hello from Parent Process\n");
    return 0;
}