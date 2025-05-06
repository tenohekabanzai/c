#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/wait.h>

int main(int argc,char* argv[]){   
   
    int pid1 = fork();
    if(pid1 == -1)
    return 1;

    if(pid1 ==0){
        sleep(4);
        printf("Finished exec of first child %d\n",getpid());
        return 0;
    }

    int pid2 = fork();
    if(pid2 == -1)
    return 1;

    if(pid2 ==0){
        sleep(1);
        printf("Finished exec of second child %d\n",getpid());
        return 0;
    }

    int pid1_res = waitpid(pid1,NULL,0);
    printf("%d\n",pid1_res);
    int pid2_res = waitpid(pid2,NULL,0);
    printf("%d\n",pid2_res);


}