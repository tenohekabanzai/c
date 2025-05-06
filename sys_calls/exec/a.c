#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
    int id = fork();

    if(id==0)
    {
        // exelcp completely replaces the other functions in child process
        int err = execlp("ping","ping","-c","3","google.com",NULL);
        if(err == -1)
        {
            printf("Could not find program to execute\n");
            return 2;
        }
        printf("This will not be printed!!!!");
    }
    else
    {
        int wstatus;
        wait(&wstatus);
        if(WIFEXITED(wstatus))
        {
            int statusCode = WEXITSTATUS(wstatus);
            if(statusCode==0)
            printf("Success!!\n");
            else
            {
                printf("Failure!!\n");
                return 3;
            }
        }
    }
    return 0;
}