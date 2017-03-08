/**********************************
/File Name: float.c
/Author: Fujie Bao
/Time: 2/8/2016
**********************************/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <signal.h>

static int count = 0;
static long int amount = 0;
static struct itimerval oldtv;

/*********************************
/function name: calculator()
/function: execute the floating operation
*********************************/
void calculator(){
    float a = 1.0, b = 1.0;
    int i = 0;
    float sum = 0.0;

    for(i = 0 ; i < 100000; i++){
        sum = a + b;
        amount += 5;
	}
}

/*********************************
/function name: signal_handler()
/function: execute the calculation every seconds
*********************************/
void signal_handler()
{
	clock_t start, finish;

	start = clock();

	do{
		calculator();
		finish = clock();
	}while(((finish - start) / CLOCKS_PER_SEC) <= 1);
	printf("%d seconds ", ++count);
	printf("%ld instructions\n", amount);

}


/*********************************
/function name: set_timer()
/function: clock
*********************************/
void set_timer()
{
	struct itimerval itv;
	itv.it_interval.tv_sec = 1;
	itv.it_interval.tv_usec = 0;
	itv.it_value.tv_sec = 1;
	itv.it_value.tv_usec = 0;
	setitimer(ITIMER_REAL, &itv, &oldtv);
}


/*********************************
/function name: second_clock()
/function: timer
*********************************/
void second_clock()
{	
	signal(SIGALRM, signal_handler);
	set_timer();
	while(count <= 600);
	exit(0);
}

int main()
{
	int tmp1, tmp2, tmp3, tmp4;
	pthread_t thread1, thread2, thread3, thread4;
	clock_t start, finish;
	double duration;

	int ret_thrd1, ret_thrd2, ret_thrd3, ret_thrd4;


	ret_thrd1 = pthread_create(&thread1, NULL, (void *)&second_clock, NULL);
	ret_thrd2 = pthread_create(&thread2, NULL, (void *)&second_clock, NULL);
	ret_thrd3 = pthread_create(&thread3, NULL, (void *)&second_clock, NULL);
	ret_thrd4 = pthread_create(&thread4, NULL, (void *)&second_clock, NULL);

	start = clock();

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

    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("time to do loop is %f second\n", duration);

}