#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/wait.h>
#include<signal.h>

int main(int argc, char* argv[]){

    int pid = fork();
    if(pid== -1)
    return 1;

    if(pid==0){
        while(1){
            printf("Some text goes here\n");
            usleep(50000);
        }
    } 
    else {
        sleep(1); // parent sleeps for 1 sec, allowing child process to run.
        kill(pid,SIGKILL); // killing the child process via SIGKILL after 1s.
        wait(NULL);
        printf("Parent process ended\n");
    }

    return 0;
}

