#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t pid_child;
    pid_child = fork();
    if (pid_child < 0)
    {
        fprintf(stderr, "Fork Failed");
        exit(-1);
    }
    else if (pid_child == 0)
    {
        printf("\n Child Created \n");
        pid_t pid_gc = fork();
        if (pid_gc < 0)
        {
            fprintf(stderr, "Fork Failed");
            exit(-1);
        }
        else if (pid_gc == 0)
        {
            printf("\n Grand Child Created \n");
            sleep(3);
            printf("\n Executing Firefox \n");
            execlp("/snap/firefox/2310/usr/lib/firefox/firefox", "firefox", NULL);
        }
        else
        {
            wait(NULL);
            printf("\n Grand Child Complete \n");
            exit(0);
        }
    }
    else
    {
        wait(NULL);
        printf("\n Child Complete \n");
        exit(0);
    }
}
