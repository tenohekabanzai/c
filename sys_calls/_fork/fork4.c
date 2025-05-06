#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(int argc,char* argv[]){   
    
    int id1 = fork();
    int id2 = fork();
    
    if(id1 == 0)
    {
        if(id2 ==0)
        printf("Process is y\n");
        else
        printf("Process is x\n");
    }
    else
    {
        if(id2 ==0)
        printf("Process is z\n");
        else
        printf("Process is Parent\n");   
    }
    
    return 0;
}