#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>

int main(int argc,char* argv[])
{
    mkfifo("myfifo1",0777);
    return 0;
}