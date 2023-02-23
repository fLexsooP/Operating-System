#include <unistd.h>
#include <pthread.h>
#include <stdio.h>

void* thread_func(void* arg) {

	printf("New thread\n");
	return NULL;
}

int main() {

	pthread_t tid_original_thread;
	tid_original_thread = pthread_self();

	printf("Thread id of original thread %lu\n", tid_original_thread);

	pthread_t tid_new_thread;

	pthread_create(&tid_new_thread, NULL, thread_func, NULL);

	printf("Thread id of created thread %lu\n", tid_new_thread);
	sleep(30);
	pthread_join(tid_new_thread, NULL);

	printf("Original thread\n");

	return 0;
}
