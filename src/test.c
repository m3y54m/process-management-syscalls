#include <stdio.h>     // for printf()
#include <sys/types.h> // for pid_t
#include <unistd.h>    // for getpid(), getppid()

int main(int argc, char *argv[])
{
    int index;
    // Get the process ID of the current process
    pid_t pid = getpid();
    // Get the process ID of the parent process
    pid_t ppid = getppid();

    printf("\n\t[ START: TEST PROGRAM ]\n");
    printf("\tPID: %d\n", pid);
    printf("\tPPID: %d\n", ppid);
    printf("\targc = %d\n", argc);

    // Print the command line arguments
    for (index = 0; index < argc; index++)
        printf("\targv[%d] = %s\n", index, argv[index]);

    printf("\t[ END: TEST PROGRAM ]\n");
    return 0;
}