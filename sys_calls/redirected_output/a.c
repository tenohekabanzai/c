#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>

int main()
{
    int id = fork();

    if(id==0)
    {
        int file = open("results.txt",O_WRONLY | O_CREAT,0777);
        if(file == -1)
        return 2;
        
        int file2 = dup2(file,STDOUT_FILENO); // duplicating the file descriptor for results.txt into STDOUT
        close(file);

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