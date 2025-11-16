#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>  // ? Added header for pid_t

int main() {
    pid_t pid;          // ? Correct type declaration
    pid = fork();       // Create a new process

    if (pid == 0) {     // Child process
        printf("Child Process:\n");
        printf("PID = %d, PPID = %d\n", getpid(), getppid());
    } 
    else if (pid > 0) { // Parent process
        printf("Parent Process:\n");
        printf("PID = %d, PPID = %d\n", getpid(), getppid());
    } 
    else {              // Error case
        printf("Fork failed!\n");
    }
    return 0;
}

