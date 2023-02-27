#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int j = 0;

void* thread_func(void* arg) {

    char* message;

    message = (char*)arg;

    for (int i = 0; i < 10; i++) {

        j++;
        printf("%s: j is %d \n", message, j);

    }

    pthread_exit(0);

}

int main(int argc, char* argv[]) {

    pthread_t p1, p2;
    char* message1 = "Thread 1";
    char* message2 = "Thread 2";

    pthread_create(&p1, NULL, thread_func, (void*)message1);
    pthread_create(&p2, NULL, thread_func, (void*)message2);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);


}
