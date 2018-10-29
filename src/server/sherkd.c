#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void print_message_function (void *ptr);

int main()
{

    // 被等待线程的返回值
    void *retval; // void函数的指针

    // 定义2个线程
    pthread_t thread1, thread2;

    char *message1 = "thread1";
    char *message2 = "thread2";

    // 线程1和线程2的创建状态
    int create_status_thread1 = pthread_create(&thread1, NULL, (void *)&print_message_function, (void *) message1);
    int create_status_thread2 = pthread_create(&thread2, NULL, (void *)&print_message_function, (void *) message2);

    // 线程创建成功，返回0,失败返回失败号
    if (create_status_thread1 != 0) {

        printf("线程1创建失败\n");
    }

    if (create_status_thread2 != 0) {
        printf("线程2创建失败\n");
    }

    // 主线程以阻塞的方式等待线程thread1的结束
    if(pthread_join(thread1, &retval) != 0){

        printf("the main thread pthread_join thread1 with a error\n");
    }
    printf("thread1 return value(retval) is %d\n", (int)retval);
    printf("thread1 end\n");



    tmp2 = pthread_join(thread1, &retval);
    printf("thread2 return value(retval) is %d\n", (int)retval);
    printf("thread2 return value(tmp) is %d\n", tmp1);
    if (tmp2 != 0) {
        printf("cannot join with thread2\n");
    }

    printf("thread2 end\n");
}

void print_message_function( void *ptr ) {
    int i = 0;
    for (i; i<5; i++) {
        printf("%s:%d\n", (char *)ptr, i);
    }
}