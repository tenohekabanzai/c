#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<unistd.h>
#include <time.h>

int main()
{
    int fd[2];

    if(pipe(fd)== -1)
    return 1;

    int pid1 = fork();
    if(pid1==0)
    {
       dup2(fd[1],STDOUT_FILENO);
       close(fd[0]);
       close(fd[1]);
       execlp("ping","ping","-c","3","google.com",NULL);
    }

    int pid2 = fork();
    if(pid2 == -1)
    return 1;

    if(pid2 == 0)
    {
        dup2(fd[0],STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        execlp("grep","grep","rtt",NULL);
    }

    close(fd[0]);
    close(fd[1]);

    waitpid(pid1,NULL,0);
    waitpid(pid2,NULL,0);

    return 0;
}