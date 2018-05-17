#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <error.h>
#include <signal.h>


#define COUNT 50

int main(int argc, char* argv[])
{
	int cnt=0,sz=0;
	int Count_inFile;
	char filename[25] = {0};
	int fd =0;
	char buffer[12] = {0};
	FILE *getPIDS;
	char line[130];
	pid_t killpid;
	if(argc < 2)
	{
		printf("Please enter the valid arguments : ./a.out <Filename> \r\n");
		exit(-1);
	}
	strcpy(filename,argv[1]);
	printf("Application Which write the Numbers from 1-1000 in %s !\r\n", filename);

	while(Count_inFile != COUNT)
	{
		fd = open(filename,O_RDONLY,0777);	
		if(fd < 0 )
		{
			printf("file Opening/Creation Failed!\r\n");
			exit(1);
		}
		memset(buffer, 0x0, sizeof(buffer));
		sz = read(fd, buffer, 5);
		buffer[sz] = '\0';
		printf("\r\nBuffer = %s , Sz= %d ", buffer, sz);
		Count_inFile = atoi(buffer);
		printf("Count_inFile = %d ", Count_inFile);
		close(fd);
		sleep(1);
	}
	printf("Count_inFile = %d \r\n", Count_inFile);

	getPIDS = popen("pidof -x write","r");
	while (fgets(line,sizeof line,getPIDS)) {
		printf("KILL PID: %s",line);
		killpid = atoi(line);
		kill(killpid,SIGKILL);
	}	

	return 0;
}
