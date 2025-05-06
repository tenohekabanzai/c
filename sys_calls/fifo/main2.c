#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{

    int result = mkfifo("fifo2", 0777);

    if (result == 0) {
        printf("FIFO created successfully\n");
    } else {
        if (errno == EEXIST) {
            printf("FIFO already exists\n");
        } else {
            perror("Could not create FIFO");
            return 1;
        }
    }

    printf("Opening.........\n");
    int fd = open("fifo1", O_RDONLY);
    printf("Opened FIFO\n");
    int sum=0;
    for(int i=0;i<5;i++)
    {
        int curr=0;
        if(read(fd,&curr,sizeof(int))== -1)
        {
            printf("Error while reading\n");
            return -1;
        }
        else
        sum+=curr;
    }
    printf("Sum is %d\n",sum);
    close(fd);


    printf("Opening.........\n");
    fd = open("fifo2",O_WRONLY);
    if(write(fd,&sum,sizeof(int))== -1)
    return -1;

    printf("Written sum into FIFO\n");
    close(fd);
    printf("Closed FIFO\n");
    return 0;
}