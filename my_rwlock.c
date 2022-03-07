#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_rwlock_t rw_lock;
int count;
void * route_write(void * arg) {
    int i = (int)arg;
    while(1) {
        pthread_rwlock_wrlock(&rw_lock);
        printf("route_write thread id: %d %d, count = %d, ++count=%d\n", i, pthread_self(), count, ++count);
        pthread_rwlock_unlock(&rw_lock);
        sleep(1);
    }
}

void * route_read(void * arg) {
    int i = (int)arg;
    while(1) {
        pthread_rwlock_rdlock(&rw_lock);
        printf("route_write thread id: %d %d, count = %d\n", i, pthread_self(), count);
        pthread_rwlock_unlock(&rw_lock);
        sleep(1);
    }
}

int main() {
    pthread_rwlock_init(&rw_lock, NULL);
    pthread_t tid[8];
    for(int i = 0; i < 3; i++) {
        pthread_create(&tid[i], NULL, route_write, (void *)i);
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(&tid[i + 3], NULL, route_read, (void *)i);
    }
    for(int i = 0; i < 8; i++) {
        pthread_join(tid[i], NULL);
    }
    pthread_rwlock_destroy(&rw_lock);
    return 0;
}
