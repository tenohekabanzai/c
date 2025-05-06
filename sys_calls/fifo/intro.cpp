#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    // mkfifo creates a fifo or a named pipe, normally pipes last in memory as long as their parent process runs. fifos are persistent channels for IPC
    int result = mkfifo("myfifo1", 0777);

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
    int fd = open("myfifo1", O_WRONLY);
    printf("Opened FIFO\n");
    int x = 97;
    if(write(fd,&x,sizeof(int))== -1)
    return 2;
    printf("Written into FIFO\n");
    close(fd);
    printf("Closed FIFO\n");
    return 0;
}