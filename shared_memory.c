#include<stdio.h>
#include<unistd.h>

typedef struct abc
{
	int a;
}abc_t;

int main(void)
{
	printf("Shared Memory\r\n");
	abc_t* ptr ;
	int i, pid;
	ptr = (abc_t*) malloc(sizeof(abc_t));
	ptr->a=0;
	pid = fork();
	if(pid == 0 )
	{
		for(i=0;i<10;i++)
		{
		printf("value = %d \n", ++ptr->a);
		}
	}
	else{
		for(i=0;i<10;i++)
		{
		printf("Value Child = %d \n", --ptr->a);
		}
	}
	
	return 0;
}
