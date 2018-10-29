/*************************************************************************
    > File Name: sem.c
    > Author: couldtt(fyby)
    > Mail: fuyunbiyi@gmail.com
    > Created Time: 2013年12月15日 星期日 19时25分08秒
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define MAXSIZE 10

int stack[MAXSIZE]; // 生产队列, 存放生产的东西

sem_t sem; // semaphore 信号量

// 生产东西
void provide_data(void) {

    for (int i=0; i< MAXSIZE; i++) {

        stack[i] = i;

        // sem_post是给信号量的值加上一个“1”，
        // 它是一个“原子操作”,即同时对同一个信号量做加“1”操作的两个线程是不会冲突的；而同时对同一个文件进行读和写操作的两个程序就有可能会引起冲突。
        sem_post(&sem); //为信号量加1
    }
}

// 消费
void produce_data(void) {

    int i=0;

    while(i < MAXSIZE) {

        // sem_wait是一个函数，也是一个原子操作，
        // 它的作用是从信号量的值减去一个“1”，但它永远会先等待该信号量为一个非零值才开始做减法。
        // 也就是说，如果你对一个值为2的信号量调用sem_wait()，线程将会继续执行，将信号量的值将减到1。
        sem_wait(&sem);

        printf("%d X %d = %d\n", stack[i], stack[i], stack[i]*stack[i]);

        sleep(1); // 可加可不加，加上的话，可以清楚的看出过程

        ++i;
    }
}

int main(void) {

    // 定义生产者线程和消费者线程
    pthread_t provider, producer;

    sem_init(&sem, 0, 0); //信号量初始化

    // 创建生产者线程和消费者线程
    pthread_create(&provider, NULL, (void *)produce_data, NULL);
    pthread_create(&producer, NULL, (void *)provide_data, NULL);

    // 等待生产者和消费者线程的结束
    pthread_join(provider, NULL);
    pthread_join(producer, NULL);

    sem_destroy(&sem); //销毁信号量

    return 0;
}