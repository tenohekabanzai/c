#include<stdio.h>
#include<unistd.h>

int main()
{
    int fd[2];
    int arr[] = {1,2,3,4,1,2};
    if(pipe(fd) == -1)
    {
        printf("Error in creating Pipe\n");
        return -1;
    }
    int id = fork();

    if(id==0)
    {
        close(fd[0]);
        
        int n = sizeof(arr)/sizeof(int);
        int sum=0;
        for(int i=0;i<(n/2);i++)
        sum+=arr[i];
        
        write(fd[1],&sum,sizeof(int));
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        
        int n = sizeof(arr)/sizeof(int);
        int sum=0;
        for(int i=(n/2);i<n;i++)
        sum+=arr[i];
        
        int y=0;
        read(fd[0],&y,sizeof(int));
        printf("Sum of 1st half child process: %d\n",y);
        printf("Total Sum: %d\n",y+sum);
        close(fd[0]);
    }
    return 0;
}