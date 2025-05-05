#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>


int main()
{
    // using single pipe to handle two way communication ->>> NOT A GOOD PRACTICE
    int fd1[2]; // c->p
    int fd2[2]; // p->c
    if(pipe(fd1)== -1)
    return -1;
    if(pipe(fd2)== -1)
    return -1;

    int id = fork();

    if(id==0)
    {
        close(fd2[1]);
        close(fd1[0]);
        int val = 0;
        if(read(fd2[0],&val,sizeof(int))== -1)
        return -1;
        printf("Val from parent is %d\n",val);
        val*=4;
        if(write(fd1[1],&val,sizeof(int))== -1)
        return -1;

        close(fd1[1]);
        close(fd2[0]);
    }
    else
    {
        close(fd1[1]);
        close(fd2[0]);
        int x = 15;
        if(write(fd2[1],&x,sizeof(int))== -1)
        return -1;
        int val = 0;
        if(read(fd1[0],&val,sizeof(int))== -1)
        return -1;
        wait(NULL);
        printf("Val from child is %d\n",val);
        close(fd1[0]);
        close(fd2[1]);
    }

    return 0;
}
