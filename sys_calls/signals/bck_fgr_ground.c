#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<sys/wait.h>
#include<signal.h>

int main(int argc, char* argv[]){

    int x;
    printf("Input Number: ");
    scanf("%d",&x);
    printf("Result %d*5 =%d\n",x,x*5);
    return 0;
}
