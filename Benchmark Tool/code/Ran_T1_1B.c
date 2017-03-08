/**********************************
/File Name: Ran_T1_1B.c
/Author: Fujie Bao
/Time: 2/10/2016
**********************************/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int ArrayLen = 1;            //define the length of array is 10

/**********************************
/function name: random_number(int max, int min)
/function: get a random number between max and min
**********************************/
int random_number(int min, int max)
{
	int i = rand() % (max - min);
	return i;
}

/***********************************
/function name: mem_cpy()
/function: copy the data from a array to another array randomly
***********************************/
void mem_cpy()
{
	int i, j;

	char p = 'a';
	char *q;

	q = (char *) malloc (sizeof(char) * ArrayLen);


	
	for(i = 0; i < 1000000; i++)
	{			
		for(j = 0; j < ArrayLen; j++)
		{
			(char *)memcpy(&q[random_number(0,ArrayLen)], &p, sizeof(char));			
		}
	
		
	}	

	free(q);

}


int main()
{
	int tmp1;
	pthread_t thread1;
	clock_t start, finish;
	double duration;

	int ret_thrd1;

	start = clock();

	ret_thrd1 = pthread_create(&thread1, NULL, (void *)&mem_cpy, NULL);

	if (ret_thrd1 != 0) {
        printf("thread1 failed\n");
    } else {
        printf("thread1 succeed\n");
    }

    tmp1 = pthread_join(thread1, NULL);

    finish = clock();

    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("time to do loop is %f second\n", duration);
    printf("The throughput is %f MB/sec\n", 1000000 * ArrayLen / duration / 1000000);
    printf("The latency is %lf ms\n", duration * 1000 / 1000000 * ArrayLen);
}