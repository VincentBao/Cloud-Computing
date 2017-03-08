/**********************************
/File Name: Write_Ran_T2_1K.c
/Author: Fujie Bao
/Time: 2/12/2016
**********************************/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int ArrayLen = 10;            //define the length of array is 500;

/***********************************
/function name: write_read()
/function: opem a file, read and write data to the file randomly
***********************************/
int random_number(int min, int max)
{
	int i = rand() % (max - min) ;
	return i;
}


void write_read()
{
	int i, j;
	FILE *fp;
	char *q;

	fp = fopen("Write_Ran_T2_1K.txt","wt");
	if(fp == NULL){
		puts("cannot open file");
		exit(0);
	}



	q = (char *) malloc (sizeof(char) * 1000 * ArrayLen); 		


	for(i = 0; i < 1000000; i++)
	{
		j = random_number(1, ArrayLen);
		q[j] = 'a';
		fprintf(fp, "%c\n", q[j]);
	}

	free(q);

	fclose(fp);

}


int main()
{
	int tmp1, tmp2;
	pthread_t thread1, thread2;
	clock_t start, finish;
	double duration;

	int ret_thrd1, ret_thrd2;

	start = clock();

	ret_thrd1 = pthread_create(&thread1, NULL, (void *)&write_read, NULL);
	ret_thrd2 = pthread_create(&thread2, NULL, (void *)&write_read, NULL);


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
    printf("The throughput is %f\n", 1000000 * ArrayLen / duration / 1000);
    printf("The latency is %lf\n", duration * 1000 / 1000000 * ArrayLen);

}