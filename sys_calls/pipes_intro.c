#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(int argc,char* argv[]){   
    int fd[2];
    if(pipe(fd)== -1)
    {
        printf("Err occured while opening pipe\n");
        return 1;
    }
    int id = fork();
    if(id==0)
    {
        close(fd[0]);
        int x=0;
        printf("Input a number: ");
        scanf("%d",&x);
        if(write(fd[1],&x,sizeof(int))== -1)
        {
            printf("Error occured while writing to pipe!!\n");
            return 2;
        }
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        int y=0;
        if(read(fd[0],&y,sizeof(int))== -1)
        {
            printf("Error occured while writing to pipe!!\n");
            return 3;
        }
        close(fd[0]);
        printf("Read from child process %d\n",y);
    }
}