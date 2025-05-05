#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>


int main()
{
    // using single pipe to handle two way communication ->>> NOT A GOOD PRACTICE
    int fd[2];
    if(pipe(fd)== -1)
    return -1;

    int id = fork();

    if(id==0)
    {
        int val = 0;
        if(read(fd[0],&val,sizeof(int))== -1)
        return -1;
        printf("Val from parent is %d\n",val);
        val*=4;
        if(write(fd[1],&val,sizeof(int))== -1)
        return -1;
    }
    else
    {
        
        int x = 5;
        if(write(fd[1],&x,sizeof(int))== -1)
        return -1;
        int val = 0;
        wait(NULL);
        if(read(fd[0],&val,sizeof(int))== -1)
        return -1;
        printf("Val from child is %d\n",val);
    }

    close(fd[0]);
    close(fd[1]);

    return 0;
}
