#define _GNU_SOURC
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>

#define MaxSocket_count 32000

pthread_mutex_t mutex1;

struct Socket_data
{
	pthread_t threadID;
	int SocketID;
};

void Function1(void* param);
void Function1(void* param)
{
	/* Now ask for a message from the user, this message
	 * will be read by server
	 */
	//pthread_mutex_lock(&mutex1);
	int n=0;
	struct Socket_data* data =param;
	int SocketID = data->SocketID;
	pthread_t threadID = pthread_self();
	char buffer[256];
	bzero(buffer,256);
	sprintf(buffer,"hi_%d_%d\n",threadID,SocketID);
	//	printf("%s\r\n", buffer);
	/* Send message to the server*/
	while(1)
	{
		printf("%s\r\n", buffer);
		n = write(SocketID, buffer, strlen(buffer));
		if (n < 0) {
			printf("ERROR writing to socket");
			exit(1);
		}
		pthread_yield();
	//	sleep(1);
	}
	//pthread_mutex_unlock(&mutex1);

}

int main(int argc, char *argv[]) 
{
	int portno, n, Socket_count, i, count;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	int thread_ret=0;
	pthread_t thrd1;
	struct Socket_data* data = (struct Socket_data*)malloc(sizeof(struct Socket_data));

	if (argc < 4) {
		fprintf(stderr,"usage:  %s hostname port No_of_sockets\n", argv[0]);
		exit(0);
	}

	portno = atoi(argv[2]);
	Socket_count = atoi(argv[3]);
	if((MaxSocket_count > Socket_count) && (Socket_count <= 0))
	{
		printf("Please Enter the Socket_count in the range 0-%d\r\n", MaxSocket_count);
		exit(2);
	}
	printf("<-- Simple Multithreaded Application to write on Sockets....!-->\r\n");
	/* Create a socket point */
	int *sockfd = (int *)malloc(Socket_count * sizeof(int));
	if(sockfd == NULL)
	{
		printf("Malloc Failed for Socketfd[]\n");
		exit(2);
	}
	thread_ret =  pthread_mutex_init(&mutex1, NULL);
	if(thread_ret != 0 )
	{
		printf("pthread_mutex_init Failed!\r\n");
	}

	printf("sockfd Allocated Successfully!\r\n");
	for(i=0;i<Socket_count;i++)
	{
		sockfd[i] = socket(AF_INET, SOCK_STREAM, 0);

		printf("sockfd[i] = %d \n", sockfd[i]);

		if (sockfd[i] < 0) {
			perror("ERROR opening socket");
			exit(1);
		}

		server = gethostbyname(argv[1]);
		if (server == NULL) {
			fprintf(stderr,"ERROR, no such host\n");
			exit(0);
		}

		bzero((char *) &serv_addr, sizeof(serv_addr));
		serv_addr.sin_family = AF_INET;
		bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
		serv_addr.sin_port = htons(portno);
		//printf("Now connect to the server\r\n");

		/* Now connect to the server */
		if (connect(sockfd[i], (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
			perror("ERROR connecting\r\n");
			exit(1);
		}
		printf("connected to the server port = %d \r\n",ntohs(serv_addr.sin_port));
		data->SocketID = sockfd[i];
		thread_ret = pthread_create(&thrd1, NULL, (void*)&Function1, data);
		//	printf("Main threadID = %d \n", thrd1);
		if(thread_ret != 0 )
		{
			printf("pthread_craeted Failed!\r\n");
			printf("<--Count = %d-->\r\n",count);
			break;
		}
		count++;

	}

	printf("<-- MAIN EXIT-->\r\n");
	//pthread_distroy
	//pthread_join();       
	pthread_mutex_destroy(&mutex1);
	pthread_exit(NULL);
	return 0;
}
