#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{	
	int pid;
	printf("Process Creation Application\n");
	pid = fork();
	if(pid == 0)
	{
		printf(" Child Process Created\n");
		sleep(10);
	
	}
	else
	{
	printf("Parent Process \n");
		sleep(10);
	
	}
	return 0;
}

