#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
void * thrd_func(void * arg) {
    int i = (int)arg;
    printf("thread id = %lu, pid = %lu, arg is %d\n;", pthread_self(), getpid(), i);
    return NULL;
}
int main() {
    pthread_t tid;
    printf("In main 1 thread id = %lu, pid = %lu\n", pthread_self(), getpid());
    for(int i = 0; i < 5; i++ ) {
        int ret = pthread_create(&tid, NULL, thrd_func, (void *)i);
        if(ret != 0) {
            printf("pthread_create error\n");
        }
    }
    printf("In main 2 thread is id = %lu, pid = %lu\n", pthread_self(), getpid());
    sleep(1);
    return 0;
}