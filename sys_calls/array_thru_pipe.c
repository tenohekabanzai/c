#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include <time.h>

// 2 processes
// 1 Child generates random nos and send them to parent
// parent sums all nos 

int main()
{
    int fd[2];

    if(pipe(fd)== -1)
    return 1;

    int pid = fork();
    if(pid==0)
    {
        close(fd[0]);
        int n = 5;
        int arr[n];
        srand(time(NULL) + getpid());
        for (int i = 0; i < n; i++) 
        arr[i] = rand() % 100 + 1; 

        if(write(fd[1],&n,sizeof(int))== -1)
        return 2;
        
        if(write(fd[1],arr,sizeof(int)*5)== -1)
        return 2;

        close(fd[1]);
    }
    else 
    {
        close(fd[1]);
        int sum=0;
        int n=0;
        
        if(read(fd[0],&n,sizeof(int))== -1)
        return 3;

        for(int i=0;i<n;i++)
        {
            int curr=0;
            if(read(fd[0],&curr,sizeof(int))== -1)
            return 3;
            printf("curr is %d\n",curr);
            sum+=curr;
        }
        close(fd[0]);
        printf("Sum is %d\n",sum);
    }

    return 0;
}