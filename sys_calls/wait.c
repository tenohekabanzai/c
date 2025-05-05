#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/wait.h>

int main(int argc,char* argv[]){   
    int id = fork();

    if(id!=0)
    wait(NULL); // wait forces parent to delay exec while child completes execution

    int n = id!=0 ? 6 : 1;

    for(int i=n;i< n+5;i++)
    printf("%d ",i);

    if(id!=0)
    printf("\n");
}