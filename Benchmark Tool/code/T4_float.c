/**********************************
/File Name: T4_float.c
/Author: Fujie Bao
/Time: 2/8/2016
**********************************/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

/**********************************
/function name: calculator()
/function: execute the float operation
**********************************/
void calculator(){
    float a = 1.0, b = 1.0;
    int i = 0;
    float sum = 0.0;
    float subtraction = 0.0;
    float multiplication = 0.0;
    float deviation = 0.0;

    for(i = 0; i < 100000000; i++){
        sum = a + b;
        subtraction = a - b;
        multiplication = a * b;
        deviation = a / b;
    }
}

//execute the float operation in 4 threads concurrency
int main()
{
	int tmp1, tmp2, tmp3, tmp4;
	pthread_t thread1, thread2, thread3, thread4;

	clock_t start, finish;
	double duration;

	int ret_thrd1, ret_thrd2, ret_thrd3, ret_thrd4;

    start = clock();

	ret_thrd1 = pthread_create(&thread1, NULL, (void *)&calculator, NULL);
	ret_thrd2 = pthread_create(&thread2, NULL, (void *)&calculator, NULL);
	ret_thrd3 = pthread_create(&thread3, NULL, (void *)&calculator, NULL);
	ret_thrd4 = pthread_create(&thread4, NULL, (void *)&calculator, NULL);


    if (ret_thrd1 != 0) {
        printf("thread1 failed\n");
    } else {
        printf("thread1 succeed\n");
    }

    if (ret_thrd2 != 0) {
        printf("thread2 failed\n");
    } else {
        printf("thread2 succeed\n");
    }

    if (ret_thrd3 != 0) {
        printf("thread3 failed\n");
    } else {
        printf("thread3 succeed\n");
    }

    if (ret_thrd4 != 0) {
        printf("thread4 failed\n");
    } else {
        printf("thread4 succeed\n");
    }

    tmp1 = pthread_join(thread1, NULL);

    tmp2 = pthread_join(thread2, NULL);

    tmp3 = pthread_join(thread3, NULL);

    tmp4 = pthread_join(thread4, NULL);
    
    finish = clock();

    duration = (double)(finish - start) / CLOCKS_PER_SEC / 4;
    printf("time to do loop is %f second\n", duration);
    printf("FLOPs per second is %f\n", 7 * 100000000 / duration);

}

