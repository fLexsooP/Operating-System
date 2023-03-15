#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>


int data = 0;
pthread_t t1, t2;
sem_t mySemaphore;

void* thread1_func(void* param)
{
	sem_wait(&mySemaphore);
	int a = data;

	a++;

	data = a;

	sem_post(&mySemaphore);

	pthread_exit(0);
}

void* thread2_func(void* param)
{

	sem_wait(&mySemaphore);
	int b = data;

	b--;

	data = b;

	sem_post(&mySemaphore);

	pthread_exit(0);
}

int main(int argc, char* argv[])
{
	pthread_attr_t attr; /* Set of thread attributes */

	/* Get the default attributes */
	pthread_attr_init(&attr);


	sem_init(&mySemaphore, 0, 10);


	/* create the thread */
	pthread_create(&t1, &attr, thread1_func, NULL);
	pthread_create(&t2, &attr, thread2_func, NULL);
	/* wait for the thread to exit */
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	fprintf(stderr, "data = %d\n", data);
	sem_destroy(&mySemaphore);


} //End of main()
