/**********************************
/File Name: Seq_T4_1B.c
/Author: Fujie Bao
/Time: 2/10/2016
**********************************/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int ArrayLen = 100;        //define the length of array is 100

/***********************************
/function name: mem_cpy()
/function: copy the data from a array to another array Sequentially
***********************************/
void mem_cpy()
{
	int i, j;

	char p[ArrayLen];
	char *q;


	q = (char *) malloc (sizeof(char) * ArrayLen * 1000000);
	
	for(j = 0; j < 1000000; j++)
	{
		for(i = 0; i < ArrayLen; i++)
		{
			p[i] = 'a';

			(char *)memcpy(&q[i], &p[i], sizeof(char) * 1000);	
	
		}
	}

	free(q);
}


int main()
{
	int tmp1, tmp2;
	pthread_t thread1, thread2;
	clock_t start, finish;
	double duration;

	int ret_thrd1, ret_thrd2, ret_thrd3, ret_thrd4;

	start = clock();

	ret_thrd1 = pthread_create(&thread1, NULL, (void *)&mem_cpy, NULL);
	ret_thrd2 = pthread_create(&thread2, NULL, (void *)&mem_cpy, NULL);

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
	printf("The throughput is %f MB/sec\n", 1000000 * ArrayLen / duration);
    printf("The latency is %lf ms\n", duration * 1000 / 1000000 * ArrayLen);

}