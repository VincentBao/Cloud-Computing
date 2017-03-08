/**********************************
/File Name: T1_int.c
/Author: Fujie Bao
/Time: 2/8/2016
**********************************/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

/**********************************
/function name: calculator()
/function: execute the integer operation
**********************************/
void calculator(){
	int a = 1, b = 1;
	int i = 0;
	int sum = 0;
	int subtraction = 0;
	int multiplication = 0;
	int deviation = 0;

	for(i = 0 ; i < 100000000; i++){
		sum = a + b;
		subtraction = a - b;
		multiplication = a * b;
		deviation = a / b;
	}
}

//calculate the integer operation in 1 thread
int main()
{
	int tmp1;
	pthread_t thread1;
	clock_t start, finish;
	double duration;

	int ret_thrd1;

	start = clock();

	ret_thrd1 = pthread_create(&thread1, NULL, (void *)&calculator, NULL);	

	if (ret_thrd1 != 0) {
        printf("thread1 failed\n");
    } else {
    	printf("thread1 succeed\n");
    }

    tmp1 = pthread_join(thread1, NULL);

    if (tmp1 != 0) {
        printf("cannot join with thread1\n");
	}
    	printf("thread1 end\n");
    finish = clock();

    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("time to do loop is %f second\n", duration);
    printf("IOPs per second is %lf\n", 7 * 100000000 / duration);
}