#include <stdio.h>

int main(int argc, char *argv[])
{
    int index;

    printf("\n[ JUST FOR TEST ]\n");

    printf("argc = %d\n", argc);

    for (index = 0; index < argc; index++)
        printf("argv[%d] = %s\n", index, argv[index]);

    return 0;
}