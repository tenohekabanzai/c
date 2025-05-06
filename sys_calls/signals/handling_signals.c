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

int main(int argc, char* argv[]){    

    signal(SIGTSTP,&handle_sigtstp);

    int x;
    printf("Hello2\n");
    printf("Input Number: ");
    scanf("%d",&x);
    printf("Result %d*5 =%d\n",x,x*5);
    return 0;
}
