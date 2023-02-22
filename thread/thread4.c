#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>
#include <pthread.h>
#include <unistd.h>

void* thread(void* arg)
{
	sleep(1);
	printf("New Thread calls for self id: %lu\n", pthread_self());
	printf("New Thread tid/pid: %lu\n", syscall(SYS_gettid));
	printf("New Thread tgid: %u\n", getpid());
	sleep(60);
	return 0;
}

int main()
{
	pthread_t tid;

	printf("Main proccess: %u\n", getpid());

	pthread_create(&tid, NULL, thread, NULL);

	printf("Main process created new thread: %lu\n", tid);

	pthread_join(tid, NULL);

	return 0;
}
