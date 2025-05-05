#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main(int argc,char* argv[]){   
    int arr[]={1,2,3,4,1,2,7,7};
    int fd[2];
    if(pipe(fd)== -1)
    {
        printf("Err occured while opening pipe\n");
        return 1;
    }
    int id = fork();
    if(id== -1)
    {
        printf("Fork failed!!");
        return 2;
    }
    if(id==0)
    {
        close(fd[0]);
        int n = sizeof(arr)/sizeof(int);
        int sum=0;
        for(int i=0;i<(n/2);i++)
        sum+=arr[i];
        if(write(fd[1],&sum,sizeof(int))== -1)
        {
            printf("Error occured while writing to pipe!!\n");
            return 2;
        }
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        int y=0;
        int n = sizeof(arr)/sizeof(int);
        int sum=0;
        for(int i=(n/2);i<n;i++)
        sum+=arr[i];
        if(read(fd[0],&y,sizeof(int))== -1)
        {
            printf("Error occured while writing to pipe!!\n");
            return 3;
        }
        close(fd[0]);
        printf("Sum of first half from child process %d\n",y);
        printf("Sum of second half from parent process %d\n",sum);
        printf("Tot Sum %d\n",y+sum);
    }
}