/**********************************
/File Name: T2_int.c
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
	int a = 1,b = 1;
	int i = 0;
	int sum = 0;
	int subtraction = 0;
	int multiplication = 0;
	int deviation = 0;
	
	for(i = 0; i < 100000000; i++){
		sum = a + b;
		subtraction = a - b;
		multiplication = a * b;
		deviation = a / b;
	}
}

//execute the integer calculate in 2 threads
int main()
{
	int tmp1, tmp2;
	pthread_t thread1, thread2;

	clock_t start, finish;
	double duration;

	start = clock();

	int ret_thrd1, ret_thrd2;

	ret_thrd1 = pthread_create(&thread1, NULL, (void *)&calculator, NULL);
	ret_thrd2 = pthread_create(&thread2, NULL, (void *)&calculator, NULL);
	
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

    tmp1 = pthread_join(thread1, NULL);

    tmp2 = pthread_join(thread2, NULL);
    
    finish = clock();

    duration = (double)(finish - start) / CLOCKS_PER_SEC / 2;
    printf("time to do loop is %f second\n", duration);
    printf("IOPs per second is %f\n", 7 * 100000000 / duration);


}


