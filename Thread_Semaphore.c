/*
	1.Write down a simple multiple threaded application with two threads
	2.Each thread increments common global variable for N times
	3.Choose value of N such large that the program demonstrates race condition between two threads
	4.Now, modify the program to avoid race condition by using Semaphore.
*/



#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include <pthread.h>
#include <semaphore.h>


int global_param=0;
sem_t Sem1;

void Function1(void* param);
void Function2(void* param);

void Function2(void* param)
{
	int i=0;
	int* value = (int*)param;
	sem_wait(&Sem1);
	printf("<-- %s = %d --> \r\n", __func__, value);
	for(i=0;i<value;i++)
	{
		printf("<-- *thred2 = %d -->\r", i);
	}
	printf("\n\n\n\n");
	sem_post(&Sem1);
	pthread_exit((void*)2);
}

void Function1(void* param)
{	
	int i=0;
	char* value = (char*)param;
	sem_wait(&Sem1);
	printf("<-- %s = %d --> \r\n", __func__, value);
	for(i=0;i<value;i++)
	{
		printf("<-- #thred1 = %d -->\r", i);
	}
	printf("\n\n\n\n");
	sem_post(&Sem1);
	pthread_exit((void*)1);
}

int main(int argc, char*argv[])
{
	int thread_ret=0;
	pthread_t thrd1, thrd2;
	printf("<-- Simple Multithreaded Application with Mutex to sync....!-->\r\n");
	sem_init(&Sem1, 0, 1);
	//pthread_create
	thread_ret = pthread_create(&thrd1, NULL, (void*)&Function1, (int*)30000);
	if(thread_ret != 0 )
	{
		printf("pthread_craeted Failed!\r\n");
	}
	thread_ret = pthread_create(&thrd2, NULL, (void*)&Function2, (int*)30000);
	if(thread_ret != 0 )
	{
		printf("pthread_craeted Failed!\r\n");
	}
	printf("<-- MAIN EXIT-->\r\n");
	//pthread_distroy
	//pthread_join();	
	sem_destroy(&Sem1);
	pthread_exit(NULL);
	return 0;
}
