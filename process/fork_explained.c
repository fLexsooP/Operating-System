#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
	pid_t  pid;
	/* fork another process */
	pid = fork();
	fprintf(stderr, "This is process %d", getpid());
	fprintf(stderr, "\n");
	fprintf(stderr, "pid %d", pid);
	fprintf(stderr, "\n");

	if (pid < 0) { /* error occurred */
		fprintf(stderr, "Fork Failed");
		exit(-1);
	}
	else if (pid == 0) { /* child process */
		sleep(30);
		fprintf(stderr, "This is child process %d", getpid());
		fprintf(stderr, "\n");
		execlp("/bin/ls", "ls", NULL);

		fprintf(stderr, "This is never printed");
		fprintf(stderr, "\n");
	}
	else { /* parent process */
		fprintf(stderr, "This is parent process %d", getpid());
		fprintf(stderr, "\n");
		/* parent will wait for the child to complete */
		wait(NULL);
		printf("\n Child Complete \n");
		exit(0);
	}
}
