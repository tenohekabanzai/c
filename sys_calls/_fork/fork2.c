#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(int argc,char* argv[]){   
    int id = fork();
    if(id==0)
    fork();
    printf("Hello World, %d\n",id);
    
    return 0;
}