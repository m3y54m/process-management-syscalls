#include <stdio.h>     // for printf(), perror()
#include <sys/types.h> // for pid_t
#include <unistd.h>    // for fork()
#include <stdlib.h>    // for exit()
#include <sys/wait.h>  // for wait()

int main(void)
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("Fork failed!\n");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("Hello from child!\n");
        char *argv[] = {"./test", "a", "b", "c", NULL};
        execv("./test", argv);
    }
    else
    {
        printf("Hello from parent!\n");
        wait(NULL);
    }

    return 0;
}