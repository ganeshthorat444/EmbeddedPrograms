/*Written by Mr.Bruce Wayne.*/


// Program to craete the Shared Memory and used in Different Process
/* steps to create the shared Memory 
   1. create the Structure which u wnt to share and Key to Shm.
   2. shmget(SHM_KEY, sizeof(shm_t), IPC_CREAT|0600);
   3. ptr = (shm_t*) shmat(shmid, NULL, 0); Attached to the pointer where ptr is struct ptr.
   4. shmctl(shmid, IPC_RMID, NULL); to Remove
	if we created the SHM only remove it.
	if we are using the created Only need to attch and deattch 
   5. How to Check Shm is created Run "ipcs -m" check SHM_KEY and memory
*/
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 0x1234
typedef struct shm
{	
	int Count;
}shm_t;
 

int main(void)
{
	int i,ret,shmid,cnt = 100;
	shm_t *ptr;
	printf("Shared Memory between Two Different Processes\r\n");
	
	shmid = shmget(SHM_KEY, sizeof(shm_t), IPC_CREAT|0600);
	if(shmid < 0)
	{
		printf("Shmget Failed !\n");
		exit(1);
	}
	ptr = (shm_t*) shmat(shmid, NULL, 0);
	if(ptr == (void*)-1)
	{
		printf("Shmat Failed !\n");
		exit(2);
	}	
	ptr->Count = 0;
	for(i=0;i<cnt;i++)
	{
		printf("process A : %d\n", ++ptr->Count);
		sleep(1);
	}

	ret = shmctl(shmid, IPC_RMID, NULL);	
	if(ret < 0)                                                                                                                          
        {                                                                                                                                    
                perror("shmctl() failed");                                                                                                   
                _exit(3);                                                             
        }
	
	return 0;
}	
