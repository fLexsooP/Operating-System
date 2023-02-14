

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


/**
 * The function to be executed by the child
 */
void child()
{

	/** NOTE: getpid() returns the process id of the caller process **/
	fprintf(stderr, "\n \n Hi! I am the child. My pid is %d. I am immortal!\n", getpid());
	sleep(15);

	if (execlp("yes", "yes", NULL) < 0)
	{
		perror("execlp");
		exit(-1);
	}

}

int main(int argc, char** argv)
{
	/* The process id of the child */
	pid_t child_pid;

	fprintf(stderr, "Hi! I am the parent. My pid is %d. \n", getpid());
	sleep(5);

	/* If the fork failed, then terminate. Otherwise, save the
	 * value returned by fork().
	 */


	if ((child_pid = fork()) < 0)
	{
		perror("fork");
		exit(-1);
	}

	/* Are we a child process ? */
	if (child_pid == 0)
	{
		/* Call the child function */
		child();
	}
	/* We are the parent */
	else
	{
		fprintf(stderr, "\n Hi! I am a parent. Just created a child with pid %d\n", child_pid);
		fprintf(stderr, "I will live for 60 seconds. My child shall live forever!");

		/* Wait for 60 seconds, then die. NEVER CALL WAIT */
		sleep(60);

		exit(0);

	}
	return 0;
}
