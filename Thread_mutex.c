/*
	1.Write down a simple multiple threaded application with two threads
	2.Each thread increments common global variable for N times
	3.Choose value of N such large that the program demonstrates race condition between two threads
	4.Now, modify the program to avoid race condition by using mutex.
		a. Create the Mutex
		b. Mutex Lock
		c. Mutex Unlock
		d. Delete Mutex
*/



#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include <pthread.h>


int global_param=0;
pthread_mutex_t mutex1;


void Function1(void* param);
void Function2(void* param);

void Function2(void* param)
{
	int i=0;
	int* value = (int*)param;
	printf("<-- %s = %d --> \r\n", __func__, value);
	pthread_mutex_lock(&mutex1);
	for(i=0;i<value;i++)
	{
		printf("<-- *thred1 = %d -->\r", i);
	}
	printf("\n\n\n\n");
	pthread_mutex_unlock(&mutex1);	
	pthread_exit((void*)2);
}

void Function1(void* param)
{	
	int i=0;
	char* value = (char*)param;
	printf("<-- %s = %d --> \r\n", __func__, value);
	pthread_mutex_lock(&mutex1);
	for(i=0;i<value;i++)
	{
		printf("<-- #thred2 = %d -->\r", i);
	}
	printf("\n\n\n\n");
	pthread_mutex_unlock(&mutex1);
	pthread_exit((void*)1);
}

int main(int argc, char*argv[])
{
	int thread_ret=0;
	pthread_t thrd1, thrd2;
	printf("<-- Simple Multithreaded Application with Mutex to sync....!-->\r\n");
	//pthread_Mutex

	thread_ret =  pthread_mutex_init(&mutex1, NULL);
	if(thread_ret != 0 )
	{
		printf("pthread_mutex_init Failed!\r\n");
	}
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
	pthread_mutex_destroy(&mutex);
	pthread_exit(NULL);
	return 0;
}
