#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void handle_sigusr1(int sig){
    printf("\n5 seconds over!!\n");
}

int main(int argc,char* argv[]){
    int pid = fork();
    if(pid == -1)
    return 1;
    if(pid == 0){
        sleep(5);
        kill(getppid(),SIGUSR1);
    }
    else{
        
        struct sigaction sa = {0};
        sa.sa_flags = SA_RESTART;
        sa.sa_handler = &handle_sigusr1;
        sigaction(SIGUSR1,&sa,NULL);

        int x;
        printf("Result of 3x5: ");
        scanf("%d",&x);
        if(x == 15)
        printf("Right!\n");
        else
        printf("Wrong!\n");
    }
    return 0;
}