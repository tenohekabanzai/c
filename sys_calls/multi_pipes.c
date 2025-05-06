#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd[3][2];

    // Create all 3 pipes
    for (int i = 0; i < 3; i++) {
        if (pipe(fd[i]) == -1) {
            perror("Pipe creation failed");
            return 1;
        }
    }

    // First fork: create Child 1
    int pid1 = fork();
    if (pid1 < 0) {
        perror("Fork 1 failed");
        return 2;
    }

    if (pid1 == 0) {
        // Child 1 process

        // Close unused pipe ends
        close(fd[0][1]); // reading from parent
        close(fd[1][0]); // writing to child 2
        close(fd[2][0]);
        close(fd[2][1]);

        int x;
        if (read(fd[0][0], &x, sizeof(int)) == -1) {
            perror("Child1 read failed");
            return 3;
        }

        x += 5;

        if (write(fd[1][1], &x, sizeof(int)) == -1) {
            perror("Child1 write failed");
            return 4;
        }

        close(fd[0][0]);
        close(fd[1][1]);
        return 0;
    }

    // Only parent gets here: second fork for Child 2
    int pid2 = fork();
    if (pid2 < 0) {
        perror("Fork 2 failed");
        return 2;
    }

    if (pid2 == 0) {
        // Child 2 process

        // Close unused pipe ends
        close(fd[0][0]);
        close(fd[0][1]);
        close(fd[1][1]); // reading from child 1
        close(fd[2][0]); // writing to parent

        int x;
        if (read(fd[1][0], &x, sizeof(int)) == -1) {
            perror("Child2 read failed");
            return 5;
        }

        x += 5;

        if (write(fd[2][1], &x, sizeof(int)) == -1) {
            perror("Child2 write failed");
            return 6;
        }

        close(fd[1][0]);
        close(fd[2][1]);
        return 0;
    }

    // Parent process

    // Close unused pipe ends
    close(fd[0][0]); // writing to child1
    close(fd[1][0]);
    close(fd[1][1]);
    close(fd[2][1]); // reading from child2

    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (write(fd[0][1], &x, sizeof(int)) == -1) {
        perror("Parent write failed");
        return 7;
    }

    if (read(fd[2][0], &x, sizeof(int)) == -1) {
        perror("Parent read failed");
        return 8;
    }

    printf("Final value received: %d\n", x);

    close(fd[0][1]);
    close(fd[2][0]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return 0;
}