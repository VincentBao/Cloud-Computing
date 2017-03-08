/**********************************
/File Name: Write_Seq_T1_1M.c
/Author: Fujie Bao
/Time: 2/12/2016
**********************************/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int ArrayLen = 10;           //define the length of array is 10;

/***********************************
/function name: write_read()
/function: opem a file, read and write data to the file
***********************************/

void write_read()
{
	int i, j;
	FILE *fp;
	char *q;

	fp = fopen("Write_Seq_T1_1M.txt","wt");
	if(fp == NULL){
		puts("cannot open file");
		exit(0);
	}

	q = (char *) malloc (sizeof(char) * 1000000 * ArrayLen);

	for(j = 0; j < 1000000; j++)
	{
		for(i = 0; i < ArrayLen; i++)
		{
			q[i] = 'a';
			fprintf(fp, "%c", q[i]);
		}

		fprintf(fp, "\n");
	}


	free(q);

	fclose(fp);

}


int main()
{
	int tmp1;
	pthread_t thread1;
	clock_t start, finish;
	double duration;

	int ret_thrd1;

	start = clock();

	ret_thrd1 = pthread_create(&thread1, NULL, (void *)&write_read, NULL);

	if (ret_thrd1 != 0) {
        printf("thread1 failed\n");
    } else {
        printf("thread1 succeed\n");
    }

    tmp1 = pthread_join(thread1, NULL);

    finish = clock();

    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Time to do loop is %f second\n", duration);
    printf("The throughput is %f\n", 1000000 * ArrayLen / duration);
    printf("The latency is %lf\n", duration * 1000 / 1000000 * ArrayLen);

}