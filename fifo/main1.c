#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    
    int result = mkfifo("fifo1", 0777);

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
    int fd = open("fifo1", O_WRONLY);
    printf("Opened FIFO\n");
    int arr[] = {10,20,30,40,50};
    if(write(fd,arr,sizeof(int)*5)== -1)
    {
        printf("Error while writing\n");
        return 2;
    }
    printf("Written into FIFO\n");
    close(fd);



    printf("Opening.........\n");
    fd = open("fifo2",O_RDONLY);
    int sum=0;
    if(read(fd,&sum,sizeof(int))==-1)
    {
        printf("Error while reading\n");
        return 2;
    }
    printf("Sum returned from 2nd process %d,\n",sum);
    close(fd);
    printf("Closed FIFO\n");
    return 0;
}