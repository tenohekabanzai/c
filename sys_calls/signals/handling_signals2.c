#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/wait.h>
#include<signal.h>

// custom signal hndler
void handle_sigtstp(int sig){
    printf("Custom SIGTSTP handler invoked,Stop not allowed\n");
}

// custom signal handler for SIGCONT
void handle_sigcont(int sig){
    printf("Hello1\n");
    printf("Input Number: ");
    fflush(stdout);
}

int main(int argc, char* argv[]){
    
    struct sigaction sa;
    sa.sa_handler = &handle_sigcont;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGCONT,&sa,NULL); // custom signal handler

    // signal(SIGTSTP,&handle_sigtstp);

    int x;
    printf("Hello2\n");
    printf("Input Number: ");
    scanf("%d",&x);
    printf("Result %d*5 =%d\n",x,x*5);
    return 0;
}
