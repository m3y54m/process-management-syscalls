#include <stdio.h>     // for printf(), perror()
#include <sys/types.h> // for pid_t
#include <unistd.h>    // for fork()
#include <stdlib.h>    // for exit()
#include <sys/wait.h>  // for wait()

int main(void)
{
    // Get the process ID of the current process
    pid_t main_pid = getpid();

    printf("Main Process ID: %d\n", main_pid);

    // Fork a child process
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("Fork failed!\n");
        // Exit with an error code
        exit(1);
    }
    else if (pid == 0)
    {
        printf("\n[ THIS IS CHILD PROCESS ]\n");

        char *argv[] = {"./test", "a", "b", "c", NULL};
        // Execute the program
        execv("./test", argv);
    }
    else
    {
        printf("\n[ THIS IS PARENT PROCESS ]\nForked Process ID: %d\n", pid);
        // Wait for child process to finish
        wait(NULL);
    }

    return 0;
}