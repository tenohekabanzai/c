#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
#include <time.h>

// 2 processes
// 1 Child takes a string from user and sends it to parent
// parent prints string

int main()
{
    int fd[2];

    if(pipe(fd)== -1)
    return 1;

    int pid = fork();
    if(pid==0)
    {
        close(fd[0]);
        char str[200];

        printf("Input String: ");
        fgets(str,200,stdin);
        str[strlen(str)] = '\0';

        // pass length
        int l = strlen(str)+1;
        if(write(fd[1],&l,sizeof(int))== -1)
        return 2;
        
        if(write(fd[1],str,sizeof(char)*l)== -1)
        return 2;

        close(fd[1]);
    }
    else 
    {
        close(fd[1]);
        int sz=0;
        if(read(fd[0],&sz,sizeof(int))== -1)
        return 3;

        char n[sz];
        
        if(read(fd[0],&n,sizeof(char)*sz)== -1)
        return 3;   

        close(fd[0]);
        printf("String is %s",n);
    }

    return 0;
}