#include<stdio.h>
#include<unistd.h>

int main()
{
    int fd[2];
    if(pipe(fd) == -1)
    {
        printf("Error in creating Pipe\n");
        return -1;
    }
    int id = fork();

    if(id==0)
    {
        close(fd[0]);
        int x=0;
        printf("Input a number: ");
        scanf("%d",&x);
        write(fd[1],&x,sizeof(int));
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        int y=0;
        read(fd[0],&y,sizeof(int));
        printf("value from child process: %d\n",y);
        close(fd[0]);
    }
    return 0;
}