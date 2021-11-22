#include <stdio.h>     // for printf()
#include <sys/types.h> // for pid_t
#include <unistd.h>    // for getpid(), getppid()

int main(int argc, char *argv[])
{
    int i;
    // Get the process ID of the current process
    pid_t pid = getpid();
    // Get the process ID of the parent process
    pid_t ppid = getppid();

    printf("\n\t[ CHILD #%s ] [ START ]\n", argv[1]);
    printf("\t[ CHILD #%s ] PID: %d\n", argv[1], pid);
    printf("\t[ CHILD #%s ] PPID: %d\n", argv[1], ppid);

    for (i = 0; i < 5; i++)
        printf("\t[ CHILD #%s ] %d\n", argv[1], (i + 1) * 10);

    printf("\t[ CHILD #%s ] [ END ]\n", argv[1]);

    return 0;
}