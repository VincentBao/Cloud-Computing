//===========================
//Title: Readme.txt
//Author: Fujie Bao
//Date: 17/2/2016
//===========================

The benchmark pakage contains 44 C source files and 3 benchmarks for CPU, memory and Disk.

For the CPU benchmark, it has 8 C source files.
T1_int.c: It operates the sum, substraction, multiplication and diviation with intergers in one thread. It also records the execution time and and calculates the number of integer operations in one seconds.

T1_float.c: It operates the sum, substraction, multiplication and diviation with floats in one thread. It also records the execution time and and calculates the number of float operations in one seconds.

T2_int.c: It operates the sum, substraction, multiplication and diviation with intergers in two threads simultaneously. It also records the execution time and and calculates the number of integer operations in one seconds.

T2_float.c: It operates the sum, substraction, multiplication and diviation with float in two threads simultaneously. It also records the execution time and and calculates the number of float operations in one seconds.

T4_int.c: It operates the sum, substraction, multiplication and diviation with intergers in four threads simultaneously. It also records the execution time and and calculates the number of integer operations in one seconds.

T4_float.c: It operates the sum, substraction, multiplication and diviation with float in four threads simultaneously. It also records the execution time and and calculates the number of float operations in one seconds.

int.c: It executed for 600 seconds to calculate the number of interger operations in 4 threads. It records the operations every second.

float.c: It executed for 600 seconds to calculate the number of float operations in 4 threads. It records the operations every second.

For the memory benchmark, it has 12 C source file.
Seq_T1_1B.c: Every block gets 1B size of space and copies the data from another array sequentially in one thread. And it records the execution time to calculate the throughput and letency of memory.

Seq_T1_1K.c: Every block gets 1K size of space and copies the data from another array sequentially in one thread. And it records the execution time to calculate the throughput and letency of memory.

Seq_T1_1M.c: Every block gets 1M size of space and copies the data from another array sequentially in one thread. And it records the execution time to calculate the throughput and letency of memory.

Seq_T2_1B.c: Every block gets 1B size of space and copies the data from another array sequentially in two threads. And it records the execution time to calculate the throughput and letency of memory.

Seq_T2_1K.c: Every block gets 1K size of space and copies the data from another array sequentially in two thread. And it records the execution time to calculate the throughput and letency of memory.

Seq_T2_1M.c: Every block gets 1M size of space and copies the data from another array sequentially in two thread. And it records the execution time to calculate the throughput and letency of memory.

Ran_T1_1B.c: Every block gets 1B size of space and copies the data from another array randomly in one thread. And it records the execution time to calculate the throughput and letency of memory.

Ran_T1_1K.c: Every block gets 1K size of space and copies the data from another array randomly in one thread. And it records the execution time to calculate the throughput and letency of memory.

Ran_T1_1M.c: Every block gets 1M size of space and copies the data from another array randomly in one thread. And it records the execution time to calculate the throughput and letency of memory.

Ran_T2_1B.c: Every block gets 1B size of space and copies the data from another array randomly in two threads. And it records the execution time to calculate the throughput and letency of memory.

Ran_T2_1K.c: Every block gets 1K size of space and copies the data from another array randomly in two threads. And it records the execution time to calculate the throughput and letency of memory.

Ran_T2_1M.c: Every block gets 1M size of space and copies the data from another array randomly in two threads. And it records the execution time to calculate the throughput and letency of memory.

For the Disk benchmark, it has 24 C source files.
Write_Seq_T1_1B.c: It opens a file and every block gets 1B size of space and then write the data of the block into the file sequentially in one thread. And it records the execution time to calculate the throughput and letency of disk.

Write_Seq_T1_1K.c: It opens a file and every block gets 1K size of space and then write the data of the block into the file sequentially in one thread. And it records the execution time to calculate the throughput and letency of disk.

Write_Seq_T1_1M.c: It opens a file and every block gets 1M size of space and then write the data of the block into the file sequentially in one thread. And it records the execution time to calculate the throughput and letency of disk.

Write_Seq_T2_1B.c: It opens a file and every block gets 1B size of space and then write the data of the block into the file sequentially in two threads. And it records the execution time to calculate the throughput and letency of disk.

Write_Seq_T2_1K.c: It opens a file and every block gets 1K size of space and then write the data of the block into the file sequentially in two threads. And it records the execution time to calculate the throughput and letency of disk.

Write_Seq_T2_1M.c: It opens a file and every block gets 1M size of space and then write the data of the block into the file sequentially in two threads. And it records the execution time to calculate the throughput and letency of disk.

Write_Ran_T1_1B.c: It opens a file and every block gets 1B size of space and then write the data of the block into the file randomly in one thread. And it records the execution time to calculate the throughput and letency of disk.

Write_Ran_T1_1K.c: It opens a file and every block gets 1K size of space and then write the data of the block into the file randomly in one thread. And it records the execution time to calculate the throughput and letency of disk.

Write_Ran_T1_1M.c: It opens a file and every block gets 1M size of space and then write the data of the block into the file randomly in one thread. And it records the execution time to calculate the throughput and letency of disk.

Write_Ran_T2_1B.c: It opens a file and every block gets 1B size of space and then write the data of the block into the file randomly in two threads. And it records the execution time to calculate the throughput and letency of disk.

Write_Ran_T2_1K.c: It opens a file and every block gets 1K size of space and then write the data of the block into the file randomly in two threads. And it records the execution time to calculate the throughput and letency of disk.

Write_Ran_T2_1M.c: It opens a file and every block gets 1M size of space and then write the data of the block into the file randomly in two threads. And it records the execution time to calculate the throughput and letency of disk.

Read_Seq_T1_1B.c: It opens a file and every block gets 1B size of space and then read the data of the block into the file sequentially in one thread. And it records the execution time to calculate the throughput and letency of disk.

Read_Seq_T1_1K.c: It opens a file and every block gets 1K size of space and then read the data of the block into the file sequentially in one thread. And it records the execution time to calculate the throughput and letency of disk.

Read_Seq_T1_1M.c: It opens a file and every block gets 1M size of space and then read the data of the block into the file sequentially in one thread. And it records the execution time to calculate the throughput and letency of disk.

Read_Seq_T2_1B.c: It opens a file and every block gets 1B size of space and then read the data of the block into the file sequentially in two threads. And it records the execution time to calculate the throughput and letency of disk.

Read_Seq_T2_1K.c: It opens a file and every block gets 1K size of space and then read the data of the block into the file sequentially in two threads. And it records the execution time to calculate the throughput and letency of disk.

Read_Seq_T2_1M.c: It opens a file and every block gets 1M size of space and then read the data of the block into the file sequentially in two threads. And it records the execution time to calculate the throughput and letency of disk.

Read_Ran_T1_1B.c: It opens a file and every block gets 1B size of space and then read the data of the block into the file randomly in one thread. And it records the execution time to calculate the throughput and letency of disk.

Read_Ran_T1_1K.c: It opens a file and every block gets 1K size of space and then read the data of the block into the file randomly in one thread. And it records the execution time to calculate the throughput and letency of disk.

Read_Ran_T1_1M.c: It opens a file and every block gets 1M size of space and then read the data of the block into the file randomly in one thread. And it records the execution time to calculate the throughput and letency of disk.

Read_Ran_T2_1B.c: It opens a file and every block gets 1B size of space and then read the data of the block into the file randomly in two threads. And it records the execution time to calculate the throughput and letency of disk.

Read_Ran_T2_1K.c: It opens a file and every block gets 1K size of space and then read the data of the block into the file randomly in two threads. And it records the execution time to calculate the throughput and letency of disk.

Read_Ran_T2_1M.c: It opens a file and every block gets 1M size of space and then read the data of the block into the file randomly in two threads. And it records the execution time to calculate the throughput and letency of disk.