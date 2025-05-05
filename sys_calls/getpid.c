#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/wait.h>

int main(int argc,char* argv[]){   

    int id = fork();
    
    if(id==0)
    sleep(1); //make the child process sleep for 1s

    printf("Current id %d, parent id %d\n",getpid(),getppid());
    
    int res = wait(NULL); // make the process wait(), now wait() returns the id of child process that has finished exec
    
    if(res!= -1)
    printf("Process with id %d finished exec inside process %d\n",res,getpid());
    if(res== -1) // wait() returns -1 if there are no child processes inside main process
    printf("All child processes finished exec inside process %d\n",getpid());
}