
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* thread_func(void* arg) {

	printf("Process id written from new thread %d\n", getpid());
	return NULL;
}

int main() {

	printf("Process id written from original thread %d\n", getpid());
	pthread_t tid_new_thread;

	pthread_create(&tid_new_thread, NULL, thread_func, NULL);

	pthread_join(tid_new_thread, NULL);

	return 0;
}
