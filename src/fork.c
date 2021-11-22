#include <stdio.h>     // for printf(), perror()
#include <sys/types.h> // for pid_t
#include <unistd.h>    // for fork()
#include <stdlib.h>    // for exit()
#include <sys/wait.h>  // for wait()

#define MAX_CHILDREN 3

int main(void)
{
    // Get the process ID of the current process
    pid_t main_pid = getpid();

    printf("Main Process ID: %d\n", main_pid);

    pid_t child_pid[MAX_CHILDREN];
    int i;

    for (i = 0; i < MAX_CHILDREN; i++)
    {
        // Create a child process
        child_pid[i] = fork();

        // Check for errors
        if (child_pid[i] == -1)
        {
            perror("fork()");
            // Exit with an error code
            exit(1);
        }
        // If the child process was created successfully
        else if (child_pid[i] == 0)
        {
            printf("\n[ CHILD PROCESS #%d IS CREATED. (PID: %d) ]\n", i, getpid());

            char child_num[2];
            sprintf(child_num, "%d", i+1);

            char *argv[] = {"./test", child_num, NULL};
            // Execute the program
            execv("./test", argv);

            // Exit the child process
            exit(0);
        }
    }

    printf("\n[ PARENT PROCESS OPERATIONS ]\n");

    for (i = 0; i < MAX_CHILDREN; i++)
    {
        // Wait for the child process to finish
        wait(NULL);
        printf("\n[ CHILD PROCESS #%d IS DESTROYED ]\n", i);
    }

    return 0;
}