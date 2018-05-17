#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define COUNT 1000

int main(int argc, char* argv[])
{
	int cnt=0;
	char filename[25] = {0};
	if(argc < 2)
	{
		printf("Please enter the valid arguments : ./a.out <Filename> \r\n");
		exit(-1);
	}
	strcpy(filename,argv[1]);
	int fd =0;
	printf("Application Which write the Numbers from 1-1000 in %s !\r\n", filename);
	fd = open(filename,O_WRONLY | O_CREAT | O_TRUNC ,0777);	
	if(fd < 0 )
	{
		printf("file Opening/Creation Failed!\r\n");
		exit(1);
	}
	char buffer[12] = {0};
	for(cnt=0;cnt<COUNT;cnt++)
	{
		memset(buffer, 0x0, sizeof(buffer));
		sprintf(buffer, "%d" ,cnt+1);
		write(fd,buffer, strlen(buffer));
		lseek(fd, 0, SEEK_SET);
		sleep(1);
	}
	close(fd);
	
	
}
